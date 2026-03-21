#include <stdio.h>

int main() {
    int kursi[5][2] = {0}; // 5 baris, 2 kolom (Total 10 kursi)
    int b, k, pilih;

    while(1) {
        printf("\n--- RESERVASI KERETA EKSPRES ---\n");
        printf("Denah Kursi (0:Kosong, 1:Isi):\n");
        for(int i=0; i<5; i++) {
            for(int j=0; j<2; j++) printf("[%d] ", kursi[i][j]);
            printf("\n");
        }

        printf("\n1. Pesan Kursi\n2. Keluar\nPilih: ");
        scanf("%d", &pilih);

        if(pilih == 2) break;

        printf("Pilih Baris (0-4) dan Kolom (0-1): ");
        scanf("%d %d", &b, &k);

        if(b>=0 && b<5 && k>=0 && k<2) {
            if(kursi[b][k] == 0) {
                kursi[b][k] = 1;
                printf("Berhasil dipesan!\n");
            } else {
                printf("Maaf, kursi sudah terisi.\n");
            }
        } else {
            printf("Posisi tidak valid!\n");
        }
    }
    return 0;
}

