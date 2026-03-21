#include <stdio.h>

struct Barang {
    char nama[50];
    int jumlah;
    float harga;
};

int main() {
    int n;
    printf("--- SISTEM INVENTARIS GUDANG ---\n");
    printf("Masukkan jumlah jenis barang: ");
    scanf("%d", &n);

    struct Barang gudang[n];

    for(int i = 0; i < n; i++) {
        printf("\nBarang ke-%d\n", i+1);
        printf("Nama: "); scanf("%s", gudang[i].nama);
        printf("Stok: "); scanf("%d", &gudang[i].jumlah);
        printf("Harga: "); scanf("%f", &gudang[i].harga);
    }

    printf("\n--- LAPORAN STOK GUDANG ---\n");
    printf("ID\tNama\tStok\tHarga\n");
    for(int i = 0; i < n; i++) {
        printf("%d\t%s\t%d\t%.2f\n", i+1, gudang[i].nama, gudang[i].jumlah, gudang[i].harga);
    }
    return 0;
}
