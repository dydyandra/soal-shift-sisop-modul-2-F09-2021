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

        char *unzipPets[]={"unzipping", "-d", "/home/dyandra/modul2/petshop", "/home/dyandra/Downloads/pets.zip", NULL};
        execute("/bin/unzip", unzipPets);

        DIR *directory;
        directory=opendir("/home/dyandra/modul2/petshop");
         if(directory!=NULL){
             struct dirent *infolder;
             while((infolder = readdir(directory)) != NULL){
                 if(infolder->d_type == DT_DIR){
                     char base[100] = "/home/dyandra/modul2/petshop/";
                     strcat(base, infolder->d_name);
                     char *listPets[] = {"rm", "-r", "-f", base, NULL};
                     execute("/bin/rm", listPets);
                 }
             }

         }


    }

    else{
        while((wait(&signal))>0){

        }
    }
}

void moveFiles(){
    int signal;
    pid_t child_id;
    child_id=fork();
        
    char *argv[]={"mkdir", "-p", "/home/dyandra/modul2/petshop/cat", NULL};
    execute("/bin/mkdir", argv);

    char *argv2[]={"mkdir", "-p", "/home/dyandra/modul2/petshop/dog", NULL};
    execute("/bin/mkdir", argv2);
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