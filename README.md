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
```
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
```
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


### d. Memindahkan hasil extract ke dalam direktori yang telah dibuat pada soal 1a (hanya file yang dimasukkan)


### e. Membuat daemon yang menjalankan soal 1a-1d yang berjalan pada tanggal 9 April pukul 16:22


### f. Membuat daemon untuk membuat file zip dari folder Musyik, Fylm, dan Pyoto dengan nama Lopyu_Stevany.zip yang berjalan pada tanggal 9 April pukul 16:22


### Output
### Kendala yang dialami

## Penjelasan No. 2


### Output
### Kendala yang dialami

## Penjelasan No. 2


### Output
### Kendala yang dialami
