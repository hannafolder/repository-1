#include <stdio.h>
#include <string.h>

int nilaiRomawi(char r) {
    switch (r) {
        case 'I': return 1;
        case 'V': return 5;
        case 'X': return 10;
        case 'L': return 50;
        case 'C': return 100;
        case 'D': return 500;
        case 'M': return 1000;
        default: return 0;
    }
}

int main() {
    char romawi[20];
    int total = 0, i;

    printf("Masukkan angka Romawi (Huruf Kapital): ");
    scanf("%s", romawi);

    for (i = 0; i < strlen(romawi); i++) {
        int s1 = nilaiRomawi(romawi[i]);

        if (i + 1 < strlen(romawi)) {
            int s2 = nilaiRomawi(romawi[i + 1]);

            if (s1 >= s2) {
                total = total + s1;
            } 
            else {
                total = total + (s2 - s1);
                i++; 
            }
        } else {
            total = total + s1;
        }
    }

    printf("Nilai desimal: %d\n", total);
    return 0;
}

