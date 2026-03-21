#include <stdio.h>

char papan[3][3] = {{'1','2','3'}, {'4','5','6'}, {'7','8','9'}};
char pemain = 'X';

void cetakPapan() {
    printf("\n-------------\n");
    for (int i = 0; i < 3; i++) {
        printf("| ");
        for (int j = 0; j < 3; j++) {
            printf("%c | ", papan[i][j]);
        }
        printf("\n-------------\n");
    }
}

int cekMenang() {
    for (int i = 0; i < 3; i++) {
        if (papan[i][0] == papan[i][1] && papan[i][1] == papan[i][2]) return 1;
        if (papan[0][i] == papan[1][i] && papan[1][i] == papan[2][i]) return 1;
    }
    if (papan[0][0] == papan[1][1] && papan[1][1] == papan[2][2]) return 1;
    if (papan[0][2] == papan[1][1] && papan[1][1] == papan[2][0]) return 1;
    
    return 0;
}

int main() {
    int pilihan, baris, kolom, totalLangkah = 0;
    
    while (1) {
        cetakPapan();
        printf("Pemain %c, masukkan nomor kotak: ", pemain);
        scanf("%d", &pilihan);

        baris = (pilihan - 1) / 3;
        kolom = (pilihan - 1) % 3;

        if (pilihan < 1 || pilihan > 9 || papan[baris][kolom] == 'X' || papan[baris][kolom] == 'O') {
            printf("Langkah tidak valid! Coba lagi.\n");
            continue;
        }

        papan[baris][kolom] = pemain;
        totalLangkah++;

        if (cekMenang()) {
            cetakPapan();
            printf("Selamat! Pemain %c MENANG!\n", pemain);
            break;
        }

        if (totalLangkah == 9) {
            cetakPapan();
            printf("Permainan SERI!\n");
            break;
        }

        pemain = (pemain == 'X') ? 'O' : 'X';
    }

    return 0;
}

