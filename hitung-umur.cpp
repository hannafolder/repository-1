#include <stdio.h>

int main() {
    int tglLahir, blnLahir, thnLahir;
    int tglSkrg, blnSkrg, thnSkrg;
    int umurThn, umurBln, umurHari;

    printf("=== PROGRAM HITUNG UMUR ===\n");

    printf("Masukkan Tanggal Lahir (DD MM YYYY): ");
    scanf("%d %d %d", &tglLahir, &blnLahir, &thnLahir);

    printf("Masukkan Tanggal Sekarang (DD MM YYYY): ");
    scanf("%d %d %d", &tglSkrg, &blnSkrg, &thnSkrg);

    umurThn = thnSkrg - thnLahir;

    if (blnSkrg < blnLahir) {
        umurThn--;
        umurBln = 12 + blnSkrg - blnLahir;
    } else {
        umurBln = blnSkrg - blnLahir;
    }

    if (tglSkrg < tglLahir) {
        umurBln--; 
        if (umurBln < 0) {
            umurBln = 11;
            umurThn--;
        }
        umurHari = 30 + tglSkrg - tglLahir;
    } else {
        umurHari = tglSkrg - tglLahir;
    }

    printf("\nUmur Anda saat ini: %d Tahun, %d Bulan, %d Hari\n", umurThn, umurBln, umurHari);

    return 0;
}
