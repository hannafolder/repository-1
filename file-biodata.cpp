#include <stdio.h>
#include <string.h>

int main() {
    char nama[50], alamat[100], hobi[50], ttl[50];
    FILE *file;

    printf("=== BIODATA ===\n");
    
    printf("Nama Lengkap: ");
    fgets(nama, sizeof(nama), stdin);
    nama[strcspn(nama, "\n")] = 0;

    printf("Tempat, Tgl Lahir: ");
    fgets(ttl, sizeof(ttl), stdin);
    ttl[strcspn(ttl, "\n")] = 0;

    printf("Alamat: ");
    fgets(alamat, sizeof(alamat), stdin);
    alamat[strcspn(alamat, "\n")] = 0;

    printf("Hobi: ");
    fgets(hobi, sizeof(hobi), stdin);
    hobi[strcspn(hobi, "\n")] = 0;

    // Menampilkan di terminal
    printf("\nBerhasil dibuat! Cek file 'kartu_nama.txt'\n");

    // Menyimpan ke file
    file = fopen("kartu_nama.txt", "w");
    
    if (file == NULL) {
        printf("Gagal membuat file!\n");
        return 1;
    }

    fprintf(file, "========================================\n");
    fprintf(file, "           KARTU IDENTITAS              \n");
    fprintf(file, "========================================\n");
    fprintf(file, " NAMA   : %-30s \n", nama);
    fprintf(file, " TTL    : %-30s \n", ttl);
    fprintf(file, " ALAMAT : %-30s \n", alamat);
    fprintf(file, " HOBI   : %-30s \n", hobi);

    fclose(file);

    return 0;
}

