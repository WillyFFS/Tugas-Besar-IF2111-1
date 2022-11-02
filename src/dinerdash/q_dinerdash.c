#include "q_dinerdash.h"

/* ********* AKSES (Selektor) ********* */
/* Jika q adalah Queue, maka akses elemen : */
#define IDX_HEAD(q) (q).idxHead
#define IDX_TAIL(q) (q).idxTail
#define     HEAD(q) (q).buffer[(q).idxHead]
#define     TAIL(q) (q).buffer[(q).idxTail]

/* *** Kreator *** */
void CreateQueue(Queue *q) {
/* I.S. sembarang */
/* F.S. Sebuah q kosong terbentuk dengan kondisi sbb: */
/* - Index head bernilai IDX_UNDEF */
/* - Index tail bernilai IDX_UNDEF */
/* Proses : Melakukan alokasi, membuat sebuah q kosong */
    IDX_HEAD(*q) = IDX_UNDEF;
    IDX_TAIL(*q) = IDX_UNDEF;
}

/* ********* Prototype ********* */
boolean isEmpty(Queue q) {
/* Mengirim true jika q kosong: lihat definisi di atas */
    return (IDX_HEAD(q) == IDX_UNDEF && IDX_TAIL(q) == IDX_UNDEF);
}
boolean isFull(Queue q) {
/* Mengirim true jika tabel penampung elemen q sudah penuh */
/* yaitu IDX_TAIL akan selalu di belakang IDX_HEAD dalam buffer melingkar*/
    return (IDX_HEAD(q) == 0 && (IDX_TAIL(q)) == CAPACITY - 1);
}

int length(Queue q) {
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika q kosong. */
    if (isEmpty(q)) {
        return 0;
    } else {
        return (IDX_TAIL(q) - IDX_HEAD(q)) + 1;;
    }
}
/* *** Primitif Add/Delete *** */
void enqueue(Queue *q, ElType val) {
/* Proses: Menambahkan val pada q dengan aturan FIFO */
/* I.S. q mungkin kosong, tabel penampung elemen q TIDAK penuh */
/* F.S. val menjadi TAIL yang baru, IDX_TAIL "mundur" dalam buffer melingkar. */
    if (isEmpty(*q)) {
        (*q).idxHead = 0;
        (*q).idxTail = 0;
    } else { // *q is not empty
        if (IDX_TAIL(*q) == CAPACITY - 1) { // elemen mentok kanan, geser dulu
            for (int i=(*q).idxHead = 0; i <= (*q).idxTail; i++) {
                (*q).buffer[i-(*q).idxHead] = (*q).buffer[i];
            }
            (*q).idxTail -= (*q).idxHead;
            (*q).idxHead = 0;
        }
        (*q).idxTail = (*q).idxTail + 1;
    }
    (*q).buffer[(*q).idxTail] = val;
}

void dequeue(Queue *q, ElType *val) {
/* Proses: Menghapus val pada q dengan aturan FIFO */
/* I.S. q tidak mungkin kosong */
/* F.S. val = nilai elemen HEAD pd I.S., IDX_HEAD "mundur";
        q mungkin kosong */
    *val = HEAD(*q);
    if (IDX_HEAD(*q) == IDX_TAIL(*q)) {
        IDX_HEAD(*q) = IDX_UNDEF;
        IDX_TAIL(*q) = IDX_UNDEF;
    } else {
        IDX_HEAD(*q)++;
    }
}

/* *** Display Queue *** */
void displayQueueFood(Queue q) {
/* Proses : Menuliskan isi Queue dengan traversal */
/* I.S. q boleh kosong */
/* F.S. Jika q kosong akan dicetak: */
/*
Makanan | Durasi memasak | Ketahanan | Harga      
---------------------------------------------     
        |                |           | 
*/
/* Contoh : jika ada tiga elemen Food akan dicetak: */
/*
Makanan | Durasi memasak | Ketahanan | Harga      
---------------------------------------------  
M0      | 2              | 3         | 15000
M1      | 3              | 1         | 15000
M2      | 1              | 4         | 15000
*/
    printf("Makanan | Durasi memasak | Ketahanan | Harga\n");
    printf("---------------------------------------------\n");
    if (isEmpty(q)) {
        printf("        |                |           |         \n");
    } else {
        for (int i = IDX_HEAD(q); i <= IDX_TAIL(q); i++) {
            printf("%s      | %d              | %d         | %d \n", q.buffer[i].makanan, q.buffer[i].durasi, q.buffer[i].ketahanan, q.buffer[i].harga);
        }
    } 
    printf("\n");
}

void displayQueueCooked(Queue q) {
/* Proses : Menuliskan isi Queue dengan traversal */
/* I.S. q boleh kosong */
/* F.S. Jika q tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada dua makanan yang sedang dimasak */
/*
Makanan | Sisa durasi memasak
-----------------------------
M0      | 1
M1      | 3

*/
/* Jika Queue kosong */
/*
Makanan | Sisa durasi memasak
-----------------------------
*/
    printf("Makanan | Sisa durasi memasak\n");
    printf("-----------------------------\n");
    if (isEmpty(q)) {
        printf("        |   \n");
    } else {
        for (int i = IDX_HEAD(q); i <= IDX_TAIL(q); i++) {
            printf("%s      | %d               \n", q.buffer[i].makanan, q.buffer[i].durasi);
        }
    }
    printf("\n");
}

void displayQueueRTS(Queue q) {
/* Proses : Menuliskan isi Queue dengan traversal */
/* I.S. q boleh kosong */
/* F.S. Jika q tidak kosong dan memiliki 1 elemen */
/*
Makanan | Sisa ketahanan makanan
---------------------------------
M2      | 4
*/
/* Jika Queue kosong : akan dicetak */
/*
Makanan | Sisa ketahanan makanan
---------------------------------
*/
    printf("Makanan | Sisa ketahanan memasak\n");
    printf("---------------------------------\n");
    if (isEmpty(q)) {
        printf("        |         \n");
    } else {
        for (int i = IDX_HEAD(q); i <= IDX_TAIL(q); i++) {
            printf("%s      | %d           \n", q.buffer[i].makanan, q.buffer[i].ketahanan);
        }
    }
    printf("\n");
}