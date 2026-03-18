#include <stdio.h>
#include <stdlib.h>

int ambilSaldo() {
    FILE *fp = fopen("saldo.txt", "r");
    int saldo = 0;
    if (fp == NULL) {
        return 0;
    }
    fscanf(fp, "%d", &saldo);
    fclose(fp);
    return saldo;
}

void simpanSaldo(int saldo) {
    FILE *fp = fopen("saldo.txt", "w");
    fprintf(fp, "%d", saldo);
    fclose(fp);
}

void catatRiwayat(char *jenis, int jumlah) {
    FILE *fp = fopen("riwayat.txt", "a"); 
    fprintf(fp, "[%s] : Rp%d\n", jenis, jumlah);
    fclose(fp);
}

int main() {
    int pilihan, nominal;
    int saldo = ambilSaldo();

    while (1) {
        printf("\n=== BANK UNTAR DIGITAL ===\n");
        printf("1. Cek Saldo\n");
        printf("2. Setor Tunai (Menabung)\n");
        printf("3. Tarik Tunai\n");
        printf("4. Lihat Riwayat Transaksi\n");
        printf("5. Keluar\n");
        printf("Pilih menu: ");
        scanf("%d", &pilihan);

        switch (pilihan) {
            case 1:
                printf("\nSaldo Anda saat ini: Rp%d\n", saldo);
                break;

            case 2:
                printf("Masukkan nominal setoran: Rp");
                scanf("%d", &nominal);
                if (nominal > 0) {
                    saldo += nominal;
                    simpanSaldo(saldo);
                    catatRiwayat("SETOR", nominal);
                    printf("Setoran berhasil!\n");
                } else {
                    printf("Nominal tidak valid!\n");
                }
                break;

            case 3:
                printf("Masukkan nominal tarikan: Rp");
                scanf("%d", &nominal);
                if (nominal > saldo) {
                    printf("Maaf, saldo Anda tidak mencukupi!\n");
                } else if (nominal <= 0) {
                    printf("Nominal tidak valid!\n");
                } else {
                    saldo -= nominal;
                    simpanSaldo(saldo);
                    catatRiwayat("TARIK", nominal);
                    printf("Penarikan berhasil! Silakan ambil uang Anda.\n");
                }
                break;

            case 4:
                printf("\n--- RIWAYAT TRANSAKSI ---\n");
                FILE *fp = fopen("riwayat.txt", "r");
                if (fp == NULL) {
                    printf("Belum ada riwayat.\n");
                } else {
                    char baris[100];
                    while (fgets(baris, sizeof(baris), fp)) {
                        printf("%s", baris);
                    }
                    fclose(fp);
                }
                break;

            case 5:
                printf("Terima kasih telah menggunakan layanan kami.\n");
                exit(0);

            default:
                printf("Pilihan tidak tersedia.\n");
        }
    }

    return 0;
}
