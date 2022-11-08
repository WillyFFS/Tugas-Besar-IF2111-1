/* File : functions.h */

#ifndef MASTER_FUNCTIONS_H
#define MASTER_FUNCTIONS_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "ADT/mesinkata.h"
#include "ADT/mesinkarakter.h"

#define MAX_INT 2147483647

unsigned randint(unsigned lower_bound, unsigned upper_bound);
/* PREKONDISI : Angka lower_bound dan upper_bound tidak negatif (>0)*/
/* Menghasilkan angka random diantara lower_bound sampai upper_bound dengan menggunakan proses 
 * efek kupu-kupu silang. Seed didapatkan dari mengambil waktu lokal dan elemen 
 * randomness yang didapat dari assignment pointer */

int katatoint(Word W);
/* Mengkonversi kata ke integer. Jika kata bukan integer make akan mengembalikan -9999. */

void scan(char* str, Word* W1, Word* W2, int* x);
/* Implementasi dari scanf pada library stdio.h, hanya dapat menerima 3 buah tipe input, 2 Kata dan 1 int, dan setiap 
   pemanggilan harus menyertakan pointer ke semua elemen walaupun elemen tersebut tidak ingin di-inputkan.
 * %c untuk Command 1 kata; %s untuk 1 buah string dengan spasi (banyak kata); %d untuk integer
 * I.S. : W1, W2, dan x sembarang, str berupa elemen tipe aja yang akan diinputkan
 * F.S. : Setidaknya salah satu dari W1, W2, atau x berisikan dengan input user

/* CONTOH PEMANGGILAN
 * 1. scan("%c", &W1, &W2, &x) 
        Akan menerima 1 buah command dan hanya ditaruh di W1, W2 dan x sembarang
 * 2. scan("%c %d", &W1, &W2, &x) 
        Akan menerima 1 buah command dan 1 buah int, command akan ditaruh di 
        W1 dan integer akan ditaruh di x, W2 sembarang 
 * 3. scan("%s",  &W1, &W2, &x) 
        Akan menerima 1 buah line input yang akan ditaruh di W1, W2 dan x sembarang
 * 4. scan("%d",  &W1, &W2, &x) 
        Akan menerima 1 buah integer yang akan ditaruh di x, W1 dan W2 sembarang 
 * 5. scan("", &W1, &W2, &x)
        W1, W2, dan x sembarang, ngapain panggil gituan gak guna */

boolean ValidateCommand(Word W1, char* str);
/* Membandingkan Word W1 dengan string str, mengembalikan true apabila W1 sama dengan str */

char* WordToString(Word W);
/* Membuat string dari Word */

void clearScreen();
/* Mengapus seluruh isi dari command line. Hanya berguna untuk OS Linux. 
   I.S. : Sembarang, command line bisa memiliki isi atau kosong 
   F.S. : Command line kosong */

char* concatString(char* str1, char* str2);
/* Menggabungkan 2 buah string menjadi 1 string, mengembalikan pointer ke string hasil gabungan */

#endif