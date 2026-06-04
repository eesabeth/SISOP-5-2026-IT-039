# SISOP-5-2026-IT-039
## Laporan Resmi Modul 5 Sisop oleh Elisabeth L. S. S. | 039
note: belum bisa solve maaf ya mas bochsnya ngeblank terus..

### Soal 2
### Penjelasan
Pada soal 2, kita diminta melengkapkan file `kernel.asm` dan `kernel.c` untuk membuka Last Gift dari Asisten di Bochs Emulator. Beberapa steps yang diminta adalah:  
a. Mendownload file `template.zip` untuk mendapatkan file-file yang dibutuhkan  
b. Melengkapkan fungsi `_getChar` di file `kernel.asm`  
c. Melengkapi file `kernel.c`, sehingga berhasil membuat instruksi **check**  
d. Melengkapi file `kernel.c`, sehingga berhasil menjalankan fitur **add**  
e. Melengkapi file `kernel.c`, sehingga berhasil menjalankan fitur **sub**  
f. Melengkapi file `kernel.c`, sehingga berhasil menjalankan fitur **fac**  
g. Melengkapi file `kernel.c`, sehingga berhasil menjalankan fitur **season**  
h. Melengkapi file `kernel.c`, sehingga berhasil menjalankan fitur **triangle**  
i. Melengkapi file `kernel.c`, sehingga berhasil menjalankan fitur **clear** dan **help**

#### a. Mendownload file `template.zip` untuk mendapatkan file-file yang dibutuhkan
```
gdown "https://drive.google.com/file/d/14rOog6VbT6sxjp3s_GJoTW7hgE6FAtmo/view?usp=sharing"
unzip template zip
```
Hasil:

#### b. Melengkapkan fungsi `_getChar` di file `kernel.asm`
```
_getChar:
	mov ah, 0x00
	int 0x16
	mov ah, 0x00
	ret
```
: Mengisi register `ah` dengan nilai **0x00**. Nilai **0x00** ini adalah sandi atau perintah untuk BIOS agar program berhenti sementara dan menunggu user memberi input lagi ke program.  
: `int` untuk *interrupt*, `0x16` adalah sandi khusus BIOS untuk mengurus Keyboard Services.  
: Setelah tombol ditekan, register `ah` sekarang berisi scan code (sisa data dari BIOS tadi). Dalam aturan compiler C 16-bit, *return value* sebuah fungsi selalu dibaca dari register gabungan `ax` (yang terdiri dari ah dan al).  
: `ret` untuk *return*, mengakhiri fungsi Assembly dan mengembalikan kendali ke program C yang memanggilnya.

#### c. Melengkapi file `kernel.c`, sehingga berhasil membuat instruksi **check**  

#### d. Melengkapi file `kernel.c`, sehingga berhasil menjalankan fitur **add** 
#### e. Melengkapi file `kernel.c`, sehingga berhasil menjalankan fitur **sub** 
#### f. Melengkapi file `kernel.c`, sehingga berhasil menjalankan fitur **fac** 
#### g. Melengkapi file `kernel.c`, sehingga berhasil menjalankan fitur **season**  
#### h. Melengkapi file `kernel.c`, sehingga berhasil menjalankan fitur **triangle** 
#### i. Melengkapi file `kernel.c`, sehingga berhasil menjalankan fitur **clear** dan **help**

