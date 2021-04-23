# soal-shift-sisop-modul-2-F09-2021 #

### Anggota kelompok:
Anggota | NRP
------------- | -------------
Muthia Qurrota Akyun | 05111940000019
Ifanu Antoni | 05111940000064
Dyandra Paramitha W. | 05111940000119

### Soal
1. [File Soal 1] | [Penjelasan No. 1](https://github.com/dydyandra/soal-shift-sisop-modul-2-F09-2021#penjelasan-no-1)
2. [File Soal 2] | [Penjelasan No. 2](https://github.com/dydyandra/soal-shift-sisop-modul-2-F09-2021#penjelasan-no-2)
3. [File Soal 3] | [Penjelasan No. 3](https://github.com/dydyandra/soal-shift-sisop-modul-2-F09-2021#penjelasan-no-3)

## Penjelasan No. 1
Pada suatu masa, hiduplah seorang Steven yang hidupnya pas-pasan. Steven punya pacar, namun sudah putus sebelum pacaran. Ketika dia galau memikirkan mantan, ia selalu menonton https://www.youtube.com/watch?v=568DH_9CMKI untuk menghilangkan kesedihannya. 
Di lain hal Steven anak yang tidak amat sangat super membenci matkul sisop, beberapa jam setelah diputus oleh pacarnya dia menemukan wanita lain bernama Stevany, namun Stevany berkebalikan dengan Steven karena menyukai sisop. Steven ingin terlihat jago matkul sisop demi menarik perhatian Stevany.
Pada hari ulang tahun Stevany, Steven ingin memberikan Stevany zip berisikan hal-hal yang disukai Stevany. Steven ingin isi zipnya menjadi rapi dengan membuat folder masing-masing sesuai extensi.

### a. Membuat direktori Musyik untuk mp3, Fylm untuk mp4, dan Pyoto untuk jpg
Untuk membuat direktori Musyik, Fylm, dan Pyoto, kami menggunakan fungsi berikut. 
```c
void makeFolder(){
    char *argv[] = {"mkdir", "/home/muthia/modul2/Musyik", NULL};
    char *argv2[] = {"mkdir", "/home/muthia/modul2/Fylm", NULL};
    char *argv3[] = {"mkdir", "/home/muthia/modul2/Pyoto", NULL};
    execute("/bin/mkdir", argv);
    execute("/bin/mkdir", argv2);
    execute("/bin/mkdir", argv3);
}
```
Mendeklarasikan char pointer argv, argv2, dan argv3 untuk meletakkan command sebelum dieksekusi dengan execv. Kemudian dieksekusi dengan perintah `execute("/bin/mkdir", argv)`. Lalu fungsi dipanggil pada int main. 

### b. Mengunduh musik, film, dan foto sesuai dengan link yang telah disediakan
Untuk mengunduh musik, film, dan foto, kami menggunakan fungsi berikut.
```c
void downloadFiles(){
    char *argv[] = {"wget", "-q", " --no-check-certificate", "https://drive.google.com/uc?id=1ZG8nRBRPquhYXq_sISdsVcXx5VdEgi-J&export=download", "-O", "Musik_for_Stevany.zip", NULL};
    char *argv1[] = {"wget", "-q", "--no-check-certificate", "https://drive.google.com/uc?id=1ktjGgDkL0nNpY-vT7rT7O6ZI47Ke9xcp&export=download", "-O", "Film_for_Stevany.zip", NULL};
    char *argv2[] = {"wget","-q", "--no-check-certificate", "https://drive.google.com/uc?id=1FsrAzb9B5ixooGUs0dGiBr-rC7TS9wTD&export=download","-O", "Foto_for_Stevany.zip",NULL};
    execute("/bin/wget", argv);
    execute("/bin/wget", argv1);
    execute("/bin/wget", argv2);
}
```

### c. Meng-extract zip dari folder yang telah diunduh
Untuk meng-extract file zip, kami menggunakan fungsi extractMusik() untuk meng-extract musik, extractFilm() untuk meng-extract film, dan extractFoto() untuk meng-extract foto.
Berikut contoh salah satu fungsi yang kami gunakan 
```c
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
    char *argv3[] = {"remove", "-rf", "/home/muthia/modul2/MUSIK", NULL};
    execute("/bin/rm", argv3);
}
```
Fungsi diatas bertujuan untuk meng-extract file musik pada direktori `/home/muthia/modul2` kemudian memindahkan hasil extract ke dalam direktori yang telah dibuat pada soal 1a.

### d. Memindahkan hasil extract ke dalam direktori yang telah dibuat pada soal 1a (hanya file yang dimasukkan)
Untuk memindahkan hasil extract ke dalam direktori Musyik, Fylm, dan Pyoto, kami menggunakan fungsi yang sama seperti yang ada pada soal 1c. Perintah `directory = opendir("/home/muthia/modul2/MUSIK")` digunakan untuk membuka direktori MUSIK kemudian dicek apakah direktori sudah terbuka atau belom. Lalu memindahkan file yang ada didalam direktori ke direktori Musyik dengan perintah berikut.
```c
char *argv2[] = {"rename", base, "/home/muthia/modul2/Musyik", NULL};
execute("/bin/mv", argv2);
```
Apabila semua file telah dipindahkan, maka direktori lama akan dihapus, yaitu direktori MUSIK, menggunakan perintah berikut.
```
char *argv3[] = {"remove", "-rf", "/home/muthia/modul2/MUSIK", NULL};
execute("/bin/rm", argv3);
```

### e. Membuat daemon yang menjalankan soal 1a-1d yang berjalan pada tanggal 9 April pukul 16:22
```c
        now = time(NULL);
        
        ts = localtime(&now);
        strftime(buf, sizeof(buf), "%m-%d %H:%M", ts);
        
        if(strcmp(buf, "04-09 16:22") == 0 && flag == 0){
            flag = 1;
            int signal;
            pid_t child_id;
            child_id=fork();

            if(child_id<0){
                exit(EXIT_FAILURE);
            }

            if(child_id==0){
                makeFolder();
                downloadFiles();
                _exit(1);
            }
            else{
                while((wait(&signal))>0){
                    sleep(10);
                    extractMusik();
                    extractFoto();
                    extractFilm();
           	 }
            }
```
Perintah `ts = localtime(&now)` dan `strftime(buf, sizeof(buf), "%m-%d %H:%M", ts)` digunakan untuk menge-print waktu sekarang dengan format "ddd yyyy-mm-dd hh:mm:ss zzz"
Bila `strcmp(buf, "04-09 16:22") == 0 && flag == 0` maka fungsi makeFolder() dan downloadFiles() akan dipanggil untuk membuat folder baru dan mengunduh file. `sleep(10)` digunakan untuk menunggu program menyelesaikan unduhan file selama 10 detik agar tidak terjadi error. Kemudian fungsi extractMusik(), extractFoto(), dan extractFilm() akan dipanggil untuk meng-extract file dari file zip.

### f. Membuat daemon untuk membuat file zip dari folder Musyik, Fylm, dan Pyoto dengan nama Lopyu_Stevany.zip yang berjalan pada tanggal 9 April pukul 22:22
Untuk membuat file zip dari folder Musyik, Fylm, dan Pyoto dengan nama Lopyu_Stevany.zip kami menggunakan fungsi zipFiles().
```c
void zipFiles(){
    char *argv[] = {"zip", "-rmvq", "Lopyu_Stevany.zip", "Musyik", "Fylm", "Pyoto", NULL};
    execute("/bin/zip", argv);
}
```
Fungsi ini akan dipanggil di int main 
```c
if(strcmp(buf, "04-09 22:22") == 0){
    zipFiles();
    _exit(1);
}
```
Fungsi tersebut akan membuat zip dengan nama Lopyu_Stevany.zip pada tanggal 9 April pukul 22:22

### Output
### Kendala yang dialami

## Penjelasan No. 2
Loba bekerja di sebuah petshop terkenal, suatu saat dia mendapatkan zip yang berisi banyak sekali foto peliharaan dan Ia diperintahkan untuk mengkategorikan foto-foto peliharaan tersebut. Loba merasa kesusahan melakukan pekerjaanya secara manual, apalagi ada kemungkinan ia akan diperintahkan untuk melakukan hal yang sama. Kita adalah teman baik Loba dan Ia meminta bantuan kita untuk membantu pekerjaannya.

Untuk file lengkap dapat dilihat di: [Soal 2 Lengkap](https://github.com/dydyandra/soal-shift-sisop-modul-2-F09-2021/blob/master/soal2/soal2.c)

Karena tidak diperbolehkan menggunakan system(), mkdir(), dan rename(), untuk mengeksekusi kami menggunakan execv() dan fork(). Untuk mempermudah, kami menggunakan _utility function_ yang dinamakan `execute` sebagai berikut. fungsi ini akan kami panggil setiap kali akan menggunakan `execv`, tujuannya agar tidak harus melakukan `fork` yang banyak di dalam fungsi-fungsi utama. 
```c
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
```
### a. Mengextract zip yang telah didownload dan menghapus file yang tidak dibutuhkan
Untuk mengekstrak zip dan mengapus file yang tidak dibutuhkan, kami menggunakan satu fungsi sekaligus. 
```c
/* fungsi untuk nomor 2a*/
void unzipFiles(){
    int signal;
    pid_t child_id;
    child_id=fork();

    if (child_id < 0){
        exit(EXIT_FAILURE);
    }

    if (child_id==0){
        /* untuk membuat direktori Petshop baru */
        char *mkPetshop[]={"make-directory", "-p", "/home/dyandra/modul2/petshop", NULL};
        execute("/bin/mkdir", mkPetshop);

        /* untuk meng-unzip file pets.zip */
        char *unzipPets[]={"unzipping","-q", "-d", "/home/dyandra/modul2/petshop", "/home/dyandra/Downloads/pets.zip", NULL};
        execute("/bin/unzip", unzipPets);

        /* directory listing */
        DIR *directory;
        directory=opendir("/home/dyandra/modul2/petshop");
        if(directory!=NULL){
            struct dirent *infolder;
            while((infolder = readdir(directory)) != NULL){
                if(strcmp(infolder->d_name, ".") != 0 && strcmp(infolder->d_name, "..") !=0){
                    if(infolder->d_type == DT_DIR){
                        char base[99] = "/home/dyandra/modul2/petshop/";
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
        // parent's process
        while((wait(&signal))>0){}
    }
}
```

```
        char *mkPetshop[]={"make-directory", "-p", "/home/dyandra/modul2/petshop", NULL};
        execute("/bin/mkdir", mkPetshop);
        
        char *unzipPets[]={"unzipping","-q", "-d", "/home/dyandra/modul2/petshop", "/home/dyandra/Downloads/pets.zip", NULL};
        execute("/bin/unzip", unzipPets);
```
digunakan untuk membuat folder `petshop`, dimana zip akan diekstrak ke dalam folder tersebut. Kemudian, zip dengan path `/home/dyandra/Downloads/pets.zip` akan diekstrak menuju path destinasi `/home/dyandra/modul2/petshop`. 

```
        /* directory listing */
        DIR *directory;
        directory=opendir("/home/dyandra/modul2/petshop");
        if(directory!=NULL){
            struct dirent *infolder;
            while((infolder = readdir(directory)) != NULL){
                if(strcmp(infolder->d_name, ".") != 0 && strcmp(infolder->d_name, "..") !=0){
                    if(infolder->d_type == DT_DIR){
                        char base[99] = "/home/dyandra/modul2/petshop/";
                        strcat(base, infolder->d_name);
                        char *listPets[] = {"rm", "-r", "-f", base, NULL};
                        execute("/bin/rm", listPets);
                    }
                }  
            }

        }

        closedir(directory);
    }
```
Untuk menghapus file yang tidak digunakan, menggunakan directory listing seperti di atas, dimana direktori Petshop akan dibuka, dan dibaca isinya satu per satu. Apabila tipe dari file yaitu DT_DIR (yang berarti bertipe direktori dan bukan file reguler), kita akan mencari path dari file tersebut menggunakan strcat dan kemudian diremove menggunakan `/bin/rm` (menggunakan juga utility function di atas yang telah dibuat). Directory listing bekerja secara iteratif sehingga semua file yang tidak diperlukan akan dibuang. 



**Untuk nomor 2b-2e, kami menggunakan satu fungsi, yaitu:**
```c
void moveFiles(){
    int signal;
    pid_t child_id;
    child_id=fork();

    if (child_id < 0){
        exit(EXIT_FAILURE); // Jika gagal membuat proses baru, akan berhenti
    }

    if (child_id == 0){
        DIR *directory;
        directory=opendir("/home/dyandra/modul2/petshop");
        if(directory != NULL){
            struct dirent *infolder;
            while((infolder = readdir(directory)) != NULL){
                if(infolder->d_type == DT_REG){
                    char *a, *d, *b, *c;
                    char copy[99], copy2[99], copy3[99];
                    char base2[99], base3[99];
                    char animal[25], name[25], age[25];
                    int i;

                    // printf("%s ", infolder->d_name);
                    // char *token = strtok(infolder->d_name, ";");

                    /* untuk menghapus ekstensi jpg */
                    char *fileName = infolder->d_name;
                    int length=strlen(fileName);
                    char newName[length];
                    sliceStr(fileName, newName, 0, length-5); 

                    a=strtok_r(newName, "_", &c);
                    for(;a!=NULL;a=strtok_r(NULL, "_", &c)){
                        i= 0;
                        char base[99] = "/home/dyandra/modul2/petshop/";
                        strcpy(copy, infolder->d_name);
                        strcpy(base2, base);
                        strcpy(base3, base);
                        strcpy(copy2, infolder->d_name);
                        strcpy(copy3, infolder->d_name);
                        b=strtok_r(a, ";", &d);
                        for (; b!=NULL; b=strtok_r(NULL, ";", &d)){
                            if (i == 0) {
                                strcpy(animal, b);
                            }
                            if (i == 1) {
                                strcpy(name, b);
                            }
                            if (i == 2){
                                strcpy(age, b);
                            }
                            i=i+1;
                        }
                    
                        /* untuk membuat folder baru */
                        // printf("%s\n", a);
                        strcat(base, animal);
                        // printf("%s\n", base);
                        char *mkFolder[] = {"make-directory", "-p", base, NULL};
                        execute("/bin/mkdir", mkFolder);
                        
                        /* untuk file handling 2e */
                        char txtLoc[99], txtPath[99];
                        strcpy(txtLoc, base);
                        strcpy(txtPath, txtLoc);

                        char namePerAnimal[99], nama[99];
                        strcpy(namePerAnimal, name);

                        /* buat ngecopy file ke dalam tiap folder */
                        // strcat(name, ".jpg");
                        strcat(base2, copy2);
                        char *copytoFolder[] = {"cp", "-r", base2, base, NULL};
                        execute("/bin/cp", copytoFolder);

                        /* buat rename setiap file */
                        strcat(name, ".jpg");
                        strcpy(base3, base);
                        strcat(base3, "/");
                        strcat(base3, copy2);
                        strcat(base, "/");
                        strcat(base, name);
                        // printf("%s %s\n", base3, base);
                        char *renameFile[] = {"mv", base3, base, NULL};
                        execute("/bin/mv", renameFile);
                        // close(fptr);  

                        /* untuk memasukkan elemen file ke dalam txt */
                        strcat(txtPath, "/keterangan.txt");

                        strcpy(nama, "nama : ");
                        strcat(nama, namePerAnimal);
                        strcat(nama, "\n");
                        strcat(nama,"umur : ");
                        strcat(nama, age);
                        strcat(nama," tahun\n\n");
 
                        FILE *fPtr = fopen(txtPath, "a");
                        fputs(nama, fPtr);
                        fclose(fPtr);

                }
            }

                /* untuk menghapus file yang tidak diperlukan */
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
        // parent's process
        while((wait(&signal))>0){


        }
    }
}
```

Untuk pengerjaan 2b-2e, kami memanfaatkan directory listing. Saat file-file di dalam folder Petshop masih dibaca, yang pertama dilakukan adalah memotong eksensi ".jpg" yang ada pada setiap file menggunakan fungsi `sliceStr`: 
```
void sliceStr(const char *str, char *buffer, size_t start, size_t end){
    size_t j = 0;
    for(size_t i = start; i<=end; ++i){
        buffer[j++] = str[i];
    }
    buffer[j] = 0;
}
```
dan memisahkan judul berdasarkan jenis, nama, dan umur peliharaan. Untuk melakukan ini kami menggunakan:
```c
                    a=strtok_r(newName, "_", &c);
                    for(;a!=NULL;a=strtok_r(NULL, "_", &c)){
                        i= 0;
                        char base[99] = "/home/dyandra/modul2/petshop/";
                        strcpy(copy, infolder->d_name);
                        strcpy(base2, base);
                        strcpy(base3, base);
                        strcpy(copy2, infolder->d_name);
                        strcpy(copy3, infolder->d_name);
                        b=strtok_r(a, ";", &d);
                        for (; b!=NULL; b=strtok_r(NULL, ";", &d)){
                            if (i == 0) {
                                strcpy(animal, b);
                            }
                            if (i == 1) {
                                strcpy(name, b);
                            }
                            if (i == 2){
                                strcpy(age, b);
                            }
                            i=i+1;
                        }
                        
                        //kode lain
                      }
```
dengan memanfaatkan `strtok_r`, string pada judul dipisah, yang pertama dengan delimiter `"_"` dan pada loop kedua delimiter ";". Ketika menggunakan delimiter ";", string akan dipisah menjadi 3 bagian. dari 3 bagian ini, sesuai dengan indexnya akan dimasukkan ke dalam variabel animal, name, dan age. 

### b. Membuat folder sesuai dengan jenis binatang peliharaan yang ada. 
Setelah memisahkan string, dari nilai dalam variabel animal bisa digunakan untuk membuat folder/directory baru dengan cara menambahkan variabel animal ke dalam array base yang berisi path Petshop: 
```c
                        /* untuk membuat folder baru */
                        // printf("%s\n", a);
                        strcat(base, animal);
                        // printf("%s\n", base);
                        char *mkFolder[] = {"make-directory", "-p", base, NULL};
                        execute("/bin/mkdir", mkFolder)
```
Karena letak kode ini masih di dalam loop, command akan berjalan secara iteratif, sehingga agar tidak terjadi dobel pembuatan folder menggunakan `-p` pada `/bin/mkdir`. 

### c. Memindahkan foto-foto ke dalam folder sesuai dengan kategorinya, dan di rename menggunakan nama peliharaan. 
### d. Apabila ada foto dengan dua peliharaan di dalamnya, foto dimasukkan ke dalam kedua folder sesuai kategori, dan direname sesuai jenis peliharaannya. 
Untuk memindahkan foto ke dalam folder menggunakan `/bin/cp`: 
```c
                        /* buat ngecopy file ke dalam tiap folder */
                        strcat(base2, copy2);
                        char *copytoFolder[] = {"cp", "-r", base2, base, NULL};
                        execute("/bin/cp", copytoFolder);
```
char array copy2 berisi nama tiap file, yang kemudian akan ditambahkan ke dalam path Petshop yang kita punya, agar bisa dicopy menuju path tiap folder. 

Bagian bawah ini untuk merename file-file pada setiap folder. Dikarenakan sebelumnya sudah menemukan nilai untuk variabel name, variabel tersebut ditambah dengan ekstensi jpg dijadikan sebagai path baru dimana file sebelumnya akan dipindah. Untuk merename sendiri bisa menggunakan `/bin/mv`. 
```c
                        /* buat rename setiap file */
                        strcat(name, ".jpg");
                        strcpy(base3, base);
                        strcat(base3, "/");
                        strcat(base3, copy2);
                        strcat(base, "/");
                        strcat(base, name);
                        // printf("%s %s\n", base3, base);
                        char *renameFile[] = {"mv", base3, base, NULL};
                        execute("/bin/mv", renameFile);
```

**nomor 2c dan 2d dilakukan secara bersamaan pada dua fungsi ini**
Untuk meremove file-file di luar folder-folder kategori (bekas copy untuk soal 2c), kami menggunakan `/bin/rm` untuk menghapus file-file tersebut, apabila ternyata file dalam path Petshop berupa file reguler biasa dan bukan direktori (karena apabila file di folder Petshop berupa direktori artinya file tersebut merupakan folder kategori yang telah dibuat). Kami masih menggunakan directory listing atas, akan tetapi untuk meremove sudah di luar looping pemisahan string. 
```c
                if (infolder->d_type == DT_REG){
                    char path[99] = "/home/dyandra/modul2/petshop/";
                    strcat(path, infolder->d_name);
                    // printf("%s\n", path);
                    char *removeFile[] = {"remove file","-r", "-f", path, NULL};
                    execute("/bin/rm", removeFile);
                }
            }
 ```


### e. Membuat file 'keterangan.txt' dalam setiap folder yang berisi nama dan umur setiap peliharaan di dalam folder. 
Sebelumnya di atas sudah mengcopy nilai beberapa variabel ke dalam variabel baru untuk digunakan di bawah, yaitu: 
```c
                        /* untuk file handling 2e */
                        char txtLoc[99], txtPath[99];
                        strcpy(txtLoc, base);
                        strcpy(txtPath, txtLoc);

                        char namePerAnimal[99], nama[99];
                        strcpy(namePerAnimal, name);

```
Kemudian, untuk memasukkan file txt sendiri dengan cara membuat path baru berisi "keterangan.txt", dan kemudian memasukkan nilai dalam variabel name, dan age pada file dengan format yang telah ditentukan. Setelah file selesai diappend, file akan ditutup kembali. Untuk memasukkan file juga masih di dalam looping pemisahan string yang awal. 
```c
                        /* untuk memasukkan elemen file ke dalam txt */
                        strcat(txtPath, "/keterangan.txt");

                        strcpy(nama, "nama : ");
                        strcat(nama, namePerAnimal);
                        strcat(nama, "\n");
                        strcat(nama,"umur : ");
                        strcat(nama, age);
                        strcat(nama," tahun\n\n");
 
                        FILE *fPtr = fopen(txtPath, "a");
                        fputs(nama, fPtr);
                        fclose(fPtr);
```



### Output
<img src="https://github.com/dydyandra/soal-shift-sisop-modul-2-F09-2021/blob/master/screenshot/soal2/1.png" width="450"> | <img src="https://github.com/dydyandra/soal-shift-sisop-modul-2-F09-2021/blob/master/screenshot/soal2/2.png" width="450"> 

Isi dari contoh folder: Cat & Dog beserta keterangan.txt di setiap folder. Salah satu contoh foto dimana terdapat 2 jenis peliharaan yaitu cat;ava;6_dog;walter;6.jpg. Dapat terlihat bahwa dalam folder Cat terdapat keterangan nama ava dan gambar ava.jpg dan dalam folder Dog terdapat juga gambar yang sama dengan nama walter.jpg dan keterangan nama walter di txt.
<img src="https://github.com/dydyandra/soal-shift-sisop-modul-2-F09-2021/blob/master/screenshot/soal2/3.png"> | <img src="https://github.com/dydyandra/soal-shift-sisop-modul-2-F09-2021/blob/master/screenshot/soal2/4.png"> 

Jumlah gambar dalam setiap folder (dengan menggunakan script yang diberikan oleh Asisten Dosen): 
<img src="https://github.com/dydyandra/soal-shift-sisop-modul-2-F09-2021/blob/master/screenshot/soal2/5.png"> 

### Kendala yang dialami
- Sebelumnya, kami menggunakan strtok biasa untuk melakukan pemisahan string, akan tetapi ternyata nilai pada variabel yang akan dipisah ikut berubah apabila menggunakan strtok. Sehingga kami akhirnya menggunakan strtok_r untuk pemisahan string. [Referensi](https://stackoverflow.com/questions/15961253/c-correct-usage-of-strtok-r#:~:text=The%20strtok_r()%20function%20is,that%20parse%20the%20same%20string)

## Penjelasan No. 3
Ranora adalah mahasiswa Teknik Informatika yang saat ini sedang menjalani magang di perusahan ternama yang bernama “FakeKos Corp.”, perusahaan yang bergerak dibidang keamanan data. Karena Ranora masih magang, maka beban tugasnya tidak sebesar beban tugas pekerja tetap perusahaan. Di hari pertama Ranora bekerja, pembimbing magang Ranora memberi tugas pertamanya untuk membuat sebuah program.

Untuk melakukan no.3 kami menggunakan daemon process, dikarenakan program terus berjalan di background dengan waktu tertentu. 
Untuk file lengkap dapat dilihat di: [Soal 3 Lengkap](https://github.com/dydyandra/soal-shift-sisop-modul-2-F09-2021/blob/master/soal3/soal3.c)
### a. membuat sebuah direktori dengan nama sesuai timestamp [YYYY-mm-dd_HH:ii:ss] setiap 40 detik.
Untuk membuat sebuah direktori sesuai timestamp memanfaatkan library yaitu `#include<time.h`>, dan menggunakan strftime untuk mengonversi waktu ke string dengan format yang telah ditentukan. String ini akan dimasukkan ke dalam array baru. 
```c
      time_t now;
        struct tm *ts;
        now = time(NULL);
        ts = localtime(&now);
        char temp[99];
        // char format[] = "%Y-%m-%d_%X";
        strftime(temp, sizeof(temp), "%Y-%m-%d_%X", ts);
 ```
 Dalam child process, untuk membuat direktori menggunakan `execv("/bin/mkdir")` sesuai dengan array `temp` di atas, yang akan dicopy ke dalam char array `base` yang berisi path folder. 
 ```c
             if (child_id2 = fork() == 0){
                 /* 3a untuk membuat folder/direktori baru */
                strcat(base, temp);
                char *makedir[] = {"make directory", base, NULL};
                execv("/bin/mkdir", makedir);

            }
 ```
 
 Karena harus dibuat setiap 40 detik menggunakan `sleep(40)` pada program utama. 
 
### b. Mendownload 10 gambar untuk setiap direktori yang terbuat dari https://picsum.photos/, dimana gambar akan didownload setiap 5 detik. Setiap gambar diberi nama format timestamp [YYYY-mm-dd_HH:ii:ss] dan gambar tersebut berbentuk persegi dengan ukuran (n%1000) + 50 pixel dimana n adalah detik Epoch Unix.
Untuk 2b, kami menggunakan fungsi yaitu `downloadPicture` yang akan dipanggil di main.
Di main sendiri, dikarenakan harus mendownload sebanyak 10 kali setiap 5 detik, cara pemanggilan yaitu: 
```c
                for (int i = 0; i < 10; i++){
                    /* 3b untuk mendownload gambar*/
                    downloadPicture(temp);
                    sleep(5); // tunggu untuk mendownload selama 5 detik
                }
```
yang dilakukan pada Parent's process apabila child process yang membuat direktori telah selesai. 


Fungsi downloadPicture sendiri adalah sebagai berikut:
```c
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
      execv("/bin/wget", download);

    // }
  } 
//   else{
//     while(wait(&status));
//   }
}
```
Untuk mencari epoch unix dan nama file kami menggunakan `time.h` kembali. Untuk mencari epoch unix dengan mencari waktu sekarang dengan `time(NULL)`, dan kemudian memasukkan nilai dari variabel tersebut ke dalam rumus yang telah ditentukan untuk ukuran. 
Untuk nama file sama dengan 3a menggunakan `strftime`. 

Untuk mendapatkan url download menggunakan `sprintf(url, "https://picsum.photos/%d", size);`, sesuai dengan ukuran yang ditemukan tadi di atas, dan didownload ke dalam path sesuai dengan url tadi menggunakan `/bin/wget`. 

### c. Membuat sebuah file "status.txt" pada setiap direktori yang telah terisi 10 gambar yang berisi pesan "Download Success" akan tetapi dengan teknik Caesar Cipher dengan shift 5 dan kemudian direktori tersebut dizip. 
Untuk membuat file status.txt dilakukan dalam main, dengan cara menambahkan `/status.txt` pada path di setiap direktori, dan membuka file tersebut. Kemudian, hasil dari message yang telah dikonversi dengan algoritma Caesar Cipher dimasukkan ke dalam file, dan kemudian file akan diclose. 
```c
                strcat(base, temp);
                char message[100], ch;
                int i, key=5;
                char folder[99];
                char txt[99]="/status.txt";
                strcpy(folder, base);
                strcat(folder, txt);
                FILE *fPtr = fopen(folder, "w");

                strcat(message, "Download Success");
                for(i = 0; message[i] != '\0'; i++){
                    ch = message[i];

                    if(ch >= 'a' && ch <= 'z'){
                        ch+=key;

                        if (ch > 'z'){
                          ch-= 'z' - 'a' + 1;
                        }

                        message[i] = ch;
                      }

                      else if (ch >= 'A' && ch <= 'Z'){
                        ch+=key;

                        if (ch > 'Z'){
                          ch-= 'Z' - 'A' + 1;
                        }

                        message[i] = ch;
                      }

                      fputc(ch, fPtr);
                }

                fclose(fPtr);
```


Setelah file txt masuk ke direktori, file akan dizip. Untuk zip file menggunakan fungsi yang kemudian akan di call ke dalam main. 
```c
void zipFiles(char *path){
  // char base[99]="/home/dyandra/modul2/";
  char pathzip[99];
  strcpy(pathzip, path);
  strcat(pathzip, ".zip");
  

  char *zipping[] = {"zipping folder", "-rmq", pathzip, path, NULL};
  execv("/bin/zip", zipping);
  
}
```

### d. Membuat program "Killer" yang dapat menterminasi semua program yang sedang berjalan
### e. Membuat 2 mode untuk run program, yaitu dengan argumen "-z" yang bisa menghentikan semua operasi apabila Killer dijalankan, dan "-x" yang menghentikan operasi apabila satu direktori selesai dizip apabila Killer dijalankan. 
2d dan 2e dilakukan bersamaan. 
Untuk membuat program "Killer" kami menggunakan fungsi baru. Kami juga menggunakan File untuk membuat file killer tersebut. 
```c
void killerProgram(char mode[], int pid){
  FILE *fPtr;
  char killerFile[99] = "killer.sh";
  fPtr = fopen(killerFile, "w");

  if(strcmp(mode, "-x") == 0){
    fprintf(fPtr, "#!/bin/bash\nkill %d\nrm killer\n", pid);
  }
  else if (strcmp(mode, "-z") == 0){
    fprintf(fPtr, "#!/bin/bash\nkillall -9 ./soal3\nrm killer\n");
  }

  int signal;
  if(fork() == 0){
    if(fork() == 0){
      char *run[] = {"chmod", "u+x", killerFile, NULL};
      execv("/bin/chmod", run);
    }
    else{
      while(wait(&signal)){
        char *rename[] = {"mv", killerFile, "killer", NULL};
        execv("/bin/mv", rename);
      }
    }
  }

  fclose(fPtr);
  
}
```

Fungsi ini akan menerima 2 parameter, yaitu yang pertama argumen mode, yaitu "-x" atau "-z" sesuai dengan soal 3e. 

Apabila string ternyata "-x", dengan menggunakan `fprintf`, akan memasukkan ` "#!/bin/bash\nkill %d\nrm killer\n"` ke dalam file yang telah dibuka, dengan `%d` yaitu parameter PID yang diambil dari main. 
Untuk PID ini sendiri didapatkan dari fungsi `getpid()` yang dipanggil saat fork child pertama di main. 

Apabila ternyata "-z", dengan menggunakan `fprintf` juga akan memasukkan `#!/bin/bash\nkillall -9 ./soal3\nrm killer\n` ke dalam file yang telah dibuka. Karena -z akan menghentikan program sekaligus, bisa langsung dengan command `killall -9 ./soal3` pada bash, maka dari itu di file dimasukkan langsung command tersebut. 

Untuk mengeksekusi file tersebut menggunakan `chmod u+x`, yaitu:
```c
      char *run[] = {"chmod", "u+x", killerFile, NULL};
      execv("/bin/chmod", run);
```
dan file Killer.sh yang telah dibuat ini akan direname menjadi killer saja sehingga saat akan menghentikan program dapat langsung menggunakan command `./killer` saja pada terminal, yaitu: 
```c
       char *rename[] = {"mv", killerFile, "killer", NULL};
        execv("/bin/mv", rename);
```


Fungsi `killerProgram` ini dimasukkan ke dalam main untuk dipanggil, akan tetapi dimasukkan pada saat proses daemonnya, dan di luar while loop untuk eksekusi program utama. 


### Output
#### Saat mode -X
<img src="https://github.com/dydyandra/soal-shift-sisop-modul-2-F09-2021/blob/master/screenshot/soal3/x1.png">
<img src="https://github.com/dydyandra/soal-shift-sisop-modul-2-F09-2021/blob/master/screenshot/soal3/x2.png">
<img src="https://github.com/dydyandra/soal-shift-sisop-modul-2-F09-2021/blob/master/screenshot/soal3/x3.png">
<img src="https://github.com/dydyandra/soal-shift-sisop-modul-2-F09-2021/blob/master/screenshot/soal3/x4.png">
Dapat terlihat dari gambar-gambar di atas bahwa folder berhasil terbuat setiap 40 detik, gambar terbuat setiap 5 detik di setiap folder, dan proses berhenti setelah folder telah di zip saat mengerun killer (dapat dilihat dari `ps aux | grep ./soal3`).

#### Saat mode -Z
<img src="https://github.com/dydyandra/soal-shift-sisop-modul-2-F09-2021/blob/master/screenshot/soal3/z1.png">
<img src="https://github.com/dydyandra/soal-shift-sisop-modul-2-F09-2021/blob/master/screenshot/soal3/z2.png">
<img src="https://github.com/dydyandra/soal-shift-sisop-modul-2-F09-2021/blob/master/screenshot/soal3/z3.png">
Dapat terlihat dari gambar-gambar di atas bahwa folder berhasil terbuat setiap 40 detik, gambar terbuat setiap 5 detik di setiap folder, dan proses berhenti secara langsung saat mengerun killer (dapat dilihat dari `ps aux | grep ./soal3`)

### Isi zip
Terdapat 10 gambar di zip dan terdapat status.txt yang berisi tulisan "Download Success" yang telah dienkripsi menggunakan Algoritma Caesar Cipher. 
<img src="https://github.com/dydyandra/soal-shift-sisop-modul-2-F09-2021/blob/master/screenshot/soal3/status.png">

### Kendala yang dialami
- Mode `-x` tidak mau menghentikan program apabila dijalankan, dan proses di background apabila di check dengan `ps aux | grep ./soal3` tetap terus berjalan. Hal ini ternyata disebabkan oleh terlalu banyak fork() yang dilakukan pada program, sehingga banyak proses yang masih terus berjalan walaupun telah di kill oleh -x. Untuk mencegah ini, kami tidak menggunakan *utility function* seperti pada nomor 2, dan tetap menggunakan `execv` saja, dan juga mempermudah proses di utama sehingga hanya ada 2 proses yang terlibat, yaitu child process yang akan membuat directory dan parent untuk bagian yang lainnya. 
- Algoritma caesar-cipher tidak kami ketahui sebelumnya, akan tetapi teratasi setelah mendapatkan referensi dari google. Referensi algoritma yang kami gunakan yaitu: [Referensi](https://www.thecrazyprogrammer.com/2016/11/caesar-cipher-c-c-encryption-decryption.html)
