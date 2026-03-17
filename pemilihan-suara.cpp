#include <stdio.h>
#include <string.h>

#define MAX_VOTERS 100

typedef struct {
    char nim[15];
    int sudahMemilih; // 0 jika belum, 1 jika sudah
} Pemilih;

int suaraKandidat1 = 0;
int suaraKandidat2 = 0;
int suaraKandidat3 = 0;
int suaraTidakSah = 0;

Pemilih daftarPemilih[MAX_VOTERS];
int jumlahPemilihTerdaftar = 0;

int cekStatus(char nimInput[]) {
    for (int i = 0; i < jumlahPemilihTerdaftar; i++) {
        if (strcmp(daftarPemilih[i].nim, nimInput) == 0) {
            return 1;
        }
    }
    return 0;
}

void tampilkanMenu() {
    printf("\n--- PEMILIHAN KETUA HIMPUNAN ---\n");
    printf("1. Kandidat A: Budi\n");
    printf("2. Kandidat B: Siti\n");
    printf("3. Kandidat C: Andi\n");
    printf("0. Lihat Hasil (Admin Only)\n");
    printf("Pilihan Anda: ");
}

int main() {
    int pilihan, mode;
    char nim[15];

    while (1) {
        printf("\n=== SISTEM E-VOTING UNTAR ===\n");
        printf("Masukkan NIM Anda: ");
        scanf("%s", nim);

        if (cekStatus(nim)) {
            printf("MAAF! NIM %s sudah menggunakan hak suaranya.\n", nim);
            continue;
        }

        tampilkanMenu();
        scanf("%d", &pilihan);

        if (pilihan == 0) {
            char pass[10];
            printf("Masukkan Password Admin: ");
            scanf("%s", pass);
            if (strcmp(pass, "admin123") == 0) {
                printf("\n--- HASIL PERHITUNGAN SUARA ---\n");
                printf("Budi : %d\n", suaraKandidat1);
                printf("Siti : %d\n", suaraKandidat2);
                printf("Andi : %d\n", suaraKandidat3);
                printf("Total Suara Masuk: %d\n", jumlahPemilihTerdaftar);
                break; // Keluar dari program setelah melihat hasil
            } else {
                printf("Password Salah!\n");
                continue;
            }
        }

        switch (pilihan) {
            case 1: suaraKandidat1++; break;
            case 2: suaraKandidat2++; break;
            case 3: suaraKandidat3++; break;
            default: suaraTidakSah++; break;
        }

        strcpy(daftarPemilih[jumlahPemilihTerdaftar].nim, nim);
        daftarPemilih[jumlahPemilihTerdaftar].sudahMemilih = 1;
        jumlahPemilihTerdaftar++;

        printf("Terima kasih! Suara Anda telah direkam secara anonim.\n");
    }

    return 0;
}
