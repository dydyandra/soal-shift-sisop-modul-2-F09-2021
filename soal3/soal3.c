#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <syslog.h>
#include <string.h>
#include <time.h>
#include <wait.h>

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

void downloadPicture(char *path){
  pid_t child_id;
  int status;
  child_id = fork();

  if (child_id == 0){
    // for (int i = 0;i<10; i++){
        char basicDir[99] = "/home/dyandra/modul2/";
        char url[99];
        char base[99];
        time_t seconds;
        seconds = time(NULL);

        int size = (seconds%1000)+50; // image size

        time_t now;
        struct tm *ts;
        now = time(NULL);
        ts = localtime(&now);
        char buffer[99];
        strftime(buffer, sizeof(buffer), "%Y-%m-%d_%X", ts);

    
        sprintf(url, "https://picsum.photos/%d", size);
      // printf("%s\n",url);

        strcpy(base, basicDir);
        strcat(base, path);
        strcat(base, "/");
        strcat(base, buffer);
        // printf("%s\n", path);
      
      // printf("%s\n", base);

      char *download[]={"wget", "-bq", url, "-O", base, NULL};
      execute("/bin/wget", download);

    // }
  } 
  else{
    while(wait(&status));
  }
}

int main() {
  pid_t pid, sid;        // Variabel untuk menyimpan PID

  pid = fork();     // Menyimpan PID dari Child Process

  /* Keluar saat fork gagal
  * (nilai variabel pid < 0) */
  if (pid < 0) {
    exit(EXIT_FAILURE);
  }

  /* Keluar saat fork berhasil
  * (nilai variabel pid adalah PID dari child process) */
  if (pid > 0) {
    exit(EXIT_SUCCESS);
  }

  umask(0);

  sid = setsid();
  if (sid < 0) {
    exit(EXIT_FAILURE);
  }

  if ((chdir("/home/dyandra/modul2/")) < 0) {
    exit(EXIT_FAILURE);
  }

  close(STDIN_FILENO);
  close(STDOUT_FILENO);
  close(STDERR_FILENO);

  while (1) {
        int status, status1;
        char base[99] = "/home/dyandra/modul2/";
        time_t now;
        struct tm *ts;
        now = time(NULL);
        ts = localtime(&now);
        char temp[99];
        // char format[] = "%Y-%m-%d_%X";
        strftime(temp, sizeof(temp), "%Y-%m-%d_%X", ts);

        pid_t child_id;
        child_id = fork();
        if (child_id == 0){
            // buat download
            strcat(base, temp);
            char *makedir[] = {"make directory", base, NULL};
            execute("/bin/mkdir", makedir);

            pid_t child_id2;
            if (child_id2 = fork() == 0){
                for (int i = 0; i < 10; i++){
                    downloadPicture(temp);
                    sleep(5);
                }

                // pid_t child_id3;
                // if(child)_id3 = fork() == 0){
                    
                // }
            }

            // else{
            //     while(wait(&status1));
            // }
        }
        else{
            while(wait(&status));
        }
    sleep(40);
  }
}