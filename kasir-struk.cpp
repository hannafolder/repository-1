#include <stdio.h>
#include <string.h>
#include <time.h>

typedef struct {
    char namaBarang[50];
    int harga;
    int jumlah;
    int total;
} Transaksi;

void cetakStruk(Transaksi belanja[], int n, int subtotal, int diskon, int totalBayar) {
    FILE *fptr;
    fptr = fopen("struk.txt", "w");

    if (fptr == NULL) {
        printf("Gagal mencetak struk ke file!\n");
        return;
    }

    time_t t = time(NULL);
    struct tm tm = *localtime(&t);

    fprintf(fptr, "==========================================\n");
    fprintf(fptr, "           UNTAR MART - JAKARTA           \n");
    fprintf(fptr, "      Tanggal: %02d-%02d-%04d %02d:%02d\n", tm.mday, tm.mon + 1, tm.year + 1900, tm.hour, tm.min);
    fprintf(fptr, "==========================================\n");
    fprintf(fptr, "%-20s %-5s %-10s\n", "Item", "Qty", "Harga");
    
    for (int i = 0; i < n; i++) {
        fprintf(fptr, "%-20s %-5d Rp%d\n", belanja[i].namaBarang, belanja[i].jumlah, belanja[i].total);
    }

    fprintf(fptr, "------------------------------------------\n");
    fprintf(fptr, "Subtotal    : Rp%d\n", subtotal);
    fprintf(fptr, "Diskon      : Rp%d\n", diskon);
    fprintf(fptr, "TOTAL AKHIR : Rp%d\n", totalBayar);
    fprintf(fptr, "==========================================\n");
    fprintf(fptr, "      Terima Kasih Telah Berbelanja!      \n");

    fclose(fptr);
    printf("\nStruk telah berhasil dicetak ke 'struk.txt'!\n");
}

int main() {
    int n;
    int subtotal = 0, diskon = 0, totalBayar;
    Transaksi daftarBelanja[50];

    printf("=== SISTEM KASIR POS ===\n");
    printf("Masukkan jumlah jenis barang: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("\nBarang ke-%d\n", i + 1);
        printf("Nama Barang  : ");
        getchar();
        fgets(daftarBelanja[i].namaBarang, 50, stdin);
        daftarBelanja[i].namaBarang[strcspn(daftarBelanja[i].namaBarang, "\n")] = 0;
        printf("Harga Satuan : ");
        scanf("%d", &daftarBelanja[i].harga);
        printf("Jumlah Beli  : ");
        scanf("%d", &daftarBelanja[i].jumlah);

        daftarBelanja[i].total = daftarBelanja[i].harga * daftarBelanja[i].jumlah;
        subtotal += daftarBelanja[i].total;
    }

    if (subtotal >= 500000) {
        diskon = subtotal * 0.10;
    } else if (subtotal >= 100000) {
        diskon = subtotal * 0.05;
    } else {
        diskon = 0;
    }

    totalBayar = subtotal - diskon;

    printf("\nTotal Belanja: Rp%d", subtotal);
    printf("\nPotongan Diskon: Rp%d", diskon);
    printf("\nTotal yang Harus Dibayar: Rp%d", totalBayar);

    cetakStruk(daftarBelanja, n, subtotal, diskon, totalBayar);

    return 0;
}
