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

// Nomor 1a
void makeFolder(){
    char *argv[] = {"mkdir", "/home/muthia/modul2/Musyik", NULL};
    char *argv2[] = {"mkdir", "/home/muthia/modul2/Fylm", NULL};
    char *argv3[] = {"mkdir", "/home/muthia/modul2/Pyoto", NULL};
    execute("/bin/mkdir", argv);
    execute("/bin/mkdir", argv2);
    execute("/bin/mkdir", argv3);
}

// Nomor 1b
void downloadFiles(){

    // makeFolder();
    char *argv[] = {"wget", "-q", " --no-check-certificate", "https://drive.google.com/uc?id=1ZG8nRBRPquhYXq_sISdsVcXx5VdEgi-J&export=download", "-O", "Musik_for_Stevany.zip", NULL};
    char *argv1[] = {"wget", "-q", "--no-check-certificate", "https://drive.google.com/uc?id=1ktjGgDkL0nNpY-vT7rT7O6ZI47Ke9xcp&export=download", "-O", "Film_for_Stevany.zip", NULL};
    char *argv2[] = {"wget","-q", "--no-check-certificate", "https://drive.google.com/uc?id=1FsrAzb9B5ixooGUs0dGiBr-rC7TS9wTD&export=download","-O", "Foto_for_Stevany.zip",NULL};
    execute("/bin/wget", argv);
    execute("/bin/wget", argv1);
    execute("/bin/wget", argv2);
}

// Nomor 1c dan 1d
void extractMusik(){

    char *argv[] = {"extract","-q", "/home/muthia/modul2/Musik_for_Stevany.zip", NULL};
    execute("/bin/unzip", argv);
    DIR* directory;
    directory = opendir("/home/muthia/modul2/MUSIK");
    if(directory!=NULL){
        struct dirent *infolder;
        while((infolder=readdir(directory))!=NULL){
            if(strcmp(infolder->d_name, ".") != 0 && strcmp(infolder->d_name, "..") != 0){
                char base[99] = "/home/muthia/modul2/MUSIK/";
                strcat(base, infolder->d_name);
                char *argv2[] = {"rename", base, "/home/muthia/modul2/Musyik", NULL};
                execute("/bin/mv", argv2);
            }
        }
    }
    char *argv3[] = {"remove", "-rf", "/home/muthia/modul2/MUSIK", "/home/muthia/modul2/Musik_for_Stevany.zip", NULL};
    execute("/bin/rm", argv3);

}

void extractFilm(){

    char *argv[] = {"extract","-q", "/home/muthia/modul2/Film_for_Stevany.zip", NULL};
    execute("/bin/unzip", argv);
    DIR* directory;
    directory = opendir("/home/muthia/modul2/FILM");
    if(directory!=NULL){
        struct dirent *infolder;
        while((infolder=readdir(directory))!=NULL){
            if(strcmp(infolder->d_name, ".") != 0 && strcmp(infolder->d_name, "..") != 0){
                char base[99] = "/home/muthia/modul2/FILM/";
                strcat(base, infolder->d_name);
                char *argv2[] = {"rename", base, "/home/muthia/modul2/Fylm", NULL};
                execute("/bin/mv", argv2);
            }
        }
    }
    char *argv3[] = {"remove", "-rf", "/home/muthia/modul2/FILM", "/home/muthia/modul2/Film_for_Stevany.zip", NULL};
    execute("/bin/rm", argv3);
        // renameFiles();
}

void extractFoto(){

    char *argv[] = {"extract","-q", "/home/muthia/modul2/Foto_for_Stevany.zip", NULL};
    execute("/bin/unzip", argv);
    DIR* directory;
    directory = opendir("/home/muthia/modul2/FOTO");
    if(directory!=NULL){
        struct dirent *infolder;
        while((infolder=readdir(directory))!=NULL){
            if(strcmp(infolder->d_name, ".") != 0 && strcmp(infolder->d_name, "..") != 0){
                char base[99] = "/home/muthia/modul2/FOTO/";
                strcat(base, infolder->d_name);
                char *argv2[] = {"rename", base, "/home/muthia/modul2/Pyoto", NULL};
                execute("/bin/mv", argv2);
            }
        }
    }
//    closedir(directory);
    char *argv3[] = {"remove", "-rf", "/home/muthia/modul2/FOTO",  "/home/muthia/modul2/Foto_for_Stevany.zip", NULL};
    execute("/bin/rm", argv3);

}

// Nomor 1f
void zipFiles(){
    char *argv[] = {"zip", "-rmvq", "Lopyu_Stevany.zip", "Musyik", "Fylm", "Pyoto", NULL};
    execute("/bin/zip", argv);

    DIR *directory;
    directory=opendir("/home/muthia/modul2");
    if (directory!=NULL){
        struct dirent *infolder;
        while(infolder=readdir(directory)){
            if(strstr(infolder->d_name, ".zip")!= NULL){
                char base[99] = "/home/muthia/modul2";
                strcat(base, infolder->d_name);
                char *argv2[]={"remove", "-rf", base, NULL};
                execute("/bin/rm", argv2);
            }
        }
        
    }
    closedir(directory);
}

int main(){
    int signal;
    pid_t child_id;
    child_id=fork();

    if(child_id<0){
        exit(EXIT_FAILURE);
    }

    if(child_id==0){

        makeFolder();
        downloadFiles();
        extractMusik();
        extractFoto();
        extractFilm();

    }
    else{
        while((wait(&signal))>0){
            zipFiles();
        }
    }

}
