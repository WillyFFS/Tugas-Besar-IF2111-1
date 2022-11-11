#include "../../src/ADT/array.h"

int main() {
    TabWord T;
    int i=1;
    printf("Array ADT Driver\n");
    printf("Make empty List T.");
    MakeEmpty(&T);
    printf("Test isEmpty (1 true 0 false, expected 1): %d\n",IsEmpty(T));
    printf("Test isFull (1 true 0 false, expected 0): %d\n",IsFull(T));
    printf("Test nbElmt (expected 0): %d\n",NbElmt(T));
    printf("Test MaxNbEl (expected 100): %d\n",MaxNbEl(T));
    printf("Test GetFirstIdx (expected 1): %d\n",GetFirstIdx(T));
    printf("Test GetLastIdx (=nbElmt, expected 0): %d\n",GetLastIdx(T));
    printf("Test displayArray. Expected \"Tabel kosong\"\n");
    DisplayArray(T);printf("\n");
    Word w;
    w.Length = 2;
    w.TabWord[0] = 'H';
    w.TabWord[1] = 'i';
    printf("Test GetElmtIdx (input \"Hi\"; expected -999): %d\n",GetElmtIdx(T,w));
    SetEl (&T,1,w);
    printf("Insert word \"Hi\" to T with SetEl.");
    printf("Test isEmpty (1 true 0 false, expected 0): %d\n",IsEmpty(T));
    printf("Test GetElmtIdx (input \"Hi\"; expected 1): %d\n",GetElmtIdx(T,w));
    printf("Test nbElmt (expected 1): %d\n",NbElmt(T));
    printf("Test GetLastIdx (=nbElmt, expected 1): %d\n",GetLastIdx(T));
    printf("Test displayArray. Expected one word \"Hi\"\n");
    DisplayArray(T);printf("\n");
    Word w2;
    w2 = GetElmt(T,1);
    printf("Test GetElmt. Input idx 1. Expected word \"Hi\":\n");
    displayWord(w2);
    printf("Test SetTab from T to T2.\n");
    TabWord T2;
    SetTab(T,&T2);
    printf("Test nbElmt T2 (expected 1): %d\n",NbElmt(T));
    printf("Test GetLastIdx T2 (=nbElmt, expected 1): %d\n",GetLastIdx(T));
    printf("Test displayArray T2. Expected one word \"Hi\"\n");
    DisplayArray(T2);printf("\n");
    w2.TabWord[1] = 'u';
    SetEl(&T,2,w2); printf("Test SetEl on T2. Input id 2, input word \"Hu\"\n");
    printf("Test nbElmt T2 (expected 2): %d\n",NbElmt(T));
    printf("Test displayArray T2. Expected two word \"Hi\" & \"Hu\" \n");
    DisplayArray(T2);printf("\n");
    SetNeff(&T2,1);printf("Test SetNeff on T2. Input id 1\n");
    printf("Test nbElmt T2 (expected 1): %d\n",NbElmt(T));
    printf("Test displayArray T2. Expected one word \"Hi\"\n");
    DisplayArray(T2);printf("\n");
    printf("Test isIdxEff T2 (input 1;1 true 0 false, expected 1): %d\n",IsIdxEff(T2,1));
    printf("Test isIdxEff T2 (input 5;1 true 0 false, expected 0): %d\n",IsIdxEff(T2,100));
    printf("Test isIdxValid T2 (input 100;1 true 0 false, expected 1): %d\n",IsIdxValid(T2,100));
    printf("Test isIdxValid T2 (input 0;1 true 0 false, expected 0): %d\n",IsIdxValid(T2,0));
    printf("Test isIdxValid T2 (input 101;1 true 0 false, expected 0): %d\n",IsIdxValid(T2,101));
    TabWord T3;
    T3.Neff = 100;
    printf("Created T3 with full elements");
    printf("Test isFull T3 (1 true 0 false, expected 1): %d\n",IsFull(T));
    w2.TabWord[1] = 'a';
    InsertLast(&T,w2);printf("Test InsertLast on T. Input word \"Ha\"\n");
    printf("Test nbElmt T (expected 2): %d\n",NbElmt(T));
    printf("Test displayArray T. Expected two word \"Hi\" & \"Ha\" \n");
    DisplayArray(T);printf("\n");
    w2 = GetElmt(T,2);
    printf("Test GetElmt T. Input idx 2. Expected word \"Ha\":\n");
    displayWord(w2);
    DeleteAt(&T,1);printf("Test DeleteAt on T. Input idx 1. Expected T with one word \"Ha\"\n");
    printf("Test nbElmt T (expected 1): %d\n",NbElmt(T));
    printf("Test displayArray T. Expected one wprd \"Ha\" \n");
    DisplayArray(T);printf("\n");
    return 0;
}