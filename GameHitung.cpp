#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int soal = 1, jawaban, benar, salah = 0, skor = 0;
    int maxOperand, op1, op2, hasil;
    char operasi;
    
    srand(time(NULL));

    while (soal <= 9 && salah < 3) {
        if (soal <= 3) {
            maxOperand = 10;
            benar = 5;
        } else if (soal <= 6) {
            maxOperand = 30;
            benar = 10;
        } else {
            maxOperand = 60;
            benar = 15;
        }

        op1 = rand() % maxOperand + 1;
        op2 = rand() % maxOperand + 1;
        int randOp = rand() % 4; // 0:+, 1:-, 2:*, 3:/

        switch(randOp) {
            case 0: operasi = '+'; hasil = op1 + op2; break;
            case 1: operasi = '-'; hasil = op1 - op2; break;
            case 2: operasi = '*'; hasil = op1 * op2; break;
            case 3: operasi = '/'; 
                if (op2 == 0) op2 = 1; 
                hasil = op1 / op2; 
                operasi = '/'; 
                break;
        }

        printf("Soal %d: %d %c %d = ", soal, op1, operasi, op2);
        scanf("%d", &jawaban);

        if (jawaban == hasil) {
            skor += benar;
            printf("Benar! Skor +%d. Total skor: %d\n", benar, skor);
        } else {
            salah++;
            printf("Salah! Jawaban benar: %d. Kesalahan: %d/3\n", hasil, salah);
        }

        soal++;
        printf("\n");
    }

    printf("Game selesai!\n");
    printf("Skor akhir: %d\n", skor);

    return 0;
}
