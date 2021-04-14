#include<sys/types.h>
#include<sys/wait.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<dirent.h>
#include<unistd.h>

void execute(char script[], char *argv[]){
    int status;
    pid_t child_id;
    child_id=fork();

    if(child_id==0){
        execv(script, argv);
    }else{
        while((wait(&status))>0){}
    }
}

void sliceStr(const char *str, char *buffer, size_t start, size_t end){
    size_t j = 0;
    for(size_t i = start; i<=end; ++i){
        buffer[j++] = str[i];
    }
    buffer[j] = 0;
}

void unzipFiles(){
    int signal;
    pid_t child_id;
    child_id=fork();

    if (child_id < 0){
        exit(EXIT_FAILURE);
    }

    if (child_id==0){
        char *mkPetshop[]={"make-directory", "-p", "/home/dyandra/modul2/petshop", NULL};
        execute("/bin/mkdir", mkPetshop);

        char *unzipPets[]={"unzipping","-q", "-d", "/home/dyandra/modul2/petshop", "/home/dyandra/Downloads/pets.zip", NULL};
        execute("/bin/unzip", unzipPets);

        DIR *directory;
        directory=opendir("/home/dyandra/modul2/petshop");
        if(directory!=NULL){
            struct dirent *infolder;
            while((infolder = readdir(directory)) != NULL){
                if(strcmp(infolder->d_name, ".") != 0 && strcmp(infolder->d_name, "..") !=0){
                    if(infolder->d_type == DT_DIR){
                        char base[100] = "/home/dyandra/modul2/petshop/";
                        strcat(base, infolder->d_name);
                        char *listPets[] = {"rm", "-r", "-f", base, NULL};
                        execute("/bin/rm", listPets);
                    }
                }  
            }

        }
        closedir(directory);
    }

    else{
        while((wait(&signal))>0){}
    }
}


void moveFiles(){
    int signal;
    pid_t child_id;
    child_id=fork();

    if (child_id == 0){
        DIR *directory;
        directory=opendir("/home/dyandra/modul2/petshop");
        if(directory != NULL){
            struct dirent *infolder;
            while((infolder = readdir(directory)) != NULL){
                if(infolder->d_type == DT_REG){
                    char *a, *b, *c, *d;
                    char copy[99], copy2[99], copy3[99];
                    char base2[99], base3[99];
                    char *fileName = infolder->d_name;
                    int length=strlen(fileName);
                    char newName[length];
                    int i;
                    char animal[25];
                    char name[25];
                    char age[25];

                    // printf("%s ", infolder->d_name);
                    // char *token = strtok(infolder->d_name, ";");
                    sliceStr(fileName, newName, 0, length-5);
                    for (a=strtok_r(newName, "_", &c);\
                         a!=NULL; a=strtok_r(NULL, "_", &c)){
                        i = 0;
                        char base[99] = "/home/dyandra/modul2/petshop/";
                        strcpy(copy, infolder->d_name);
                        strcpy(base2, base);
                        strcpy(base3, base);
                        strcpy(copy2, infolder->d_name);
                        strcpy(copy3, infolder->d_name);
                            for (b=strtok_r(a, ";", &d); \
                                b!=NULL; b=strtok_r(NULL, ";", &d)){
                                if (i == 0) strcpy(animal, b);
                                if (i == 1) strcpy(name, b);
                                if (i == 2) strcpy(age, b);
                                i=i+1;
                            }
                    
                        // printf("%s\n", token);
                        strcat(base, animal);
                        // printf("%s\n", base);
                        char *mkFolder[] = {"make-directory", "-p", base, NULL};
                        execute("/bin/mkdir", mkFolder);
                        char txtLoc[99];
                        strcpy(txtLoc, base);
                        char fileTXT[99];
                        strcpy(fileTXT, strcat(txtLoc,"/keterangan.txt"));    

                        strcat(name, ".jpg");
                        strcat(base2, copy2);
                        char *copytoFolder[] = {"cp", "-r", base2, base, NULL};
                        execute("/bin/cp", copytoFolder);

                        strcpy(base3, base);
                        strcat(base3, "/");
                        strcat(base3, copy2);
                        strcat(base, "/");
                        strcat(base, name);
                        // printf("%s %s\n", base3, base);
                        
                        char *renameFile[] = {"mv", base3, base, NULL};
                        execute("/bin/mv", renameFile);
                        // close(fptr);  
                }
            }

                if (infolder->d_type == DT_REG){
                    char path[99] = "/home/dyandra/modul2/petshop/";
                    strcat(path, infolder->d_name);
                    // printf("%s\n", path);
                    char *removeFile[] = {"remove file","-r", "-f", path, NULL};
                    execute("/bin/rm", removeFile);
                }
            }

        }
     
    closedir(directory);
    }
    else{
        while((wait(&signal))>0){


        }
    }
}


int main(){
    int signal;
    pid_t child_id;
    child_id=fork();

    if(child_id<0){
        exit(EXIT_FAILURE);
    }

    if(child_id==0){
        unzipFiles();
        moveFiles();
    }
    else{
        ((wait(&signal))>0);
    }

}