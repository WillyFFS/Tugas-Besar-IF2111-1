#include <stdio.h>
#include <stdlib.h>
#include "ADT/matriks.h"
#include "game_2048.h"

void run_2048() {
    // KAMUS LOKAL
    // Variabel untuk game
    Matriks board;
    int i, point_i, point_j, score=0;
    boolean wrong = false, loop = true;

    // Variabel placeholder untuk input
    Word kode, command2;
    int inputint;
    

    // ALGORITMA
    MakeMatriks(4, 4, &board);

    while (!isMatriksFull(board) && loop) {
        clearScreen();
        if (wrong) printf("Masukkan kode yang benar!");
        else { // GENERATE NEW RANDOM NUMBER ON POINT
            point_i = randint(0, 3); point_j = randint(0, 3);
            while (Elmt(board, point_i, point_j) != 0) {
                point_i = randint(0, 3); point_j = randint(0, 3);
            }

            if (randint(0, 100) % 20 == 0) Elmt(board,point_i,point_j) = 4;
            else Elmt(board,point_i,point_j) = 2;
        }

        // Display game info ke player
        printf("\n\n"); displayMatriks(board);
        printf("(W) Atas  (A) Kiri  (S) Bawah  (D) Kanan\n\nENTER COMMAND : ");
        scan("%c", &kode, &command2, &inputint);

        // Main algo buat gamenya
        wrong = false;
        if (ValidateCommand(kode, "W")) {
            for (i=0; i<board.NKolEff; i++) geserMatriksAtas(&board, false);
            geserMatriksAtas(&board, true);
            for (i=0; i<board.NKolEff; i++) geserMatriksAtas(&board, false);
        }
        else if (ValidateCommand(kode, "A")) {
            for (i=0; i<board.NKolEff; i++) geserMatriksKiri(&board, false);
            geserMatriksKiri(&board, true);
            for (i=0; i<board.NKolEff; i++) geserMatriksKiri(&board, false);

        }
        else if (ValidateCommand(kode, "S")) {
            for (i=0; i<board.NKolEff; i++) geserMatriksBawah(&board, false);
            geserMatriksBawah(&board, true);
            for (i=0; i<board.NKolEff; i++) geserMatriksBawah(&board, false);

        }
        else if (ValidateCommand(kode, "D")) {
            for (i=0; i<board.NKolEff; i++) geserMatriksKanan(&board, false);
            geserMatriksKanan(&board, true);
            for (i=0; i<board.NKolEff; i++) geserMatriksKanan(&board, false);
        }
        else if (ValidateCommand(kode, "QUIT")) loop = false;
        else wrong = true;
    }
}