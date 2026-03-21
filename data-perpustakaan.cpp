#include <stdio.h>
#include <string.h>

struct Buku {
    char judul[100];
    char pengarang[50];
    int tahun;
    int tersedia;
};

int main() {
    int n, i;

    printf("=== SISTEM DATA BUKU PERPUSTAKAAN ===\n");
    printf("Masukkan jumlah buku yang ingin didata: ");
    scanf("%d", &n);
    getchar();

    struct Buku perpus[n];

    for (i = 0; i < n; i++) {
        printf("\nData Buku ke-%d\n", i + 1);
        printf("Judul Buku    : ");
        fgets(perpus[i].judul, sizeof(perpus[i].judul), stdin);
        perpus[i].judul[strcspn(perpus[i].judul, "\n")] = 0;

        printf("Nama Pengarang: ");
        fgets(perpus[i].pengarang, sizeof(perpus[i].pengarang), stdin);
        perpus[i].pengarang[strcspn(perpus[i].pengarang, "\n")] = 0;

        printf("Tahun Terbit  : ");
        scanf("%d", &perpus[i].tahun);
        perpus[i].tersedia = 1;
        getchar();
    }

    printf("\n%-3s | %-25s | %-20s | %-5s | %-10s\n", "No", "Judul", "Pengarang", "Thn", "Status");
    printf("----------------------------------------------------------------------------\n");
    for (i = 0; i < n; i++) {
        printf("%-3d | %-25s | %-20s | %-5d | %s\n", 
               i + 1, 
               perpus[i].judul, 
               perpus[i].pengarang, 
               perpus[i].tahun,
               perpus[i].tersedia ? "Tersedia" : "Dipinjam");
    }

    return 0;
}

