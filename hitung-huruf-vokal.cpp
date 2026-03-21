#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char teks[100];
    int i, vokal = 0;

    printf("Masukkan teks: ");
    fgets(teks, sizeof(teks), stdin);

    for (i = 0; teks[i] != '\0'; i++) {
        char c = tolower(teks[i]);
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            vokal++;
        }
    }

    printf("Jumlah huruf vokal: %d\n", vokal);

    return 0;
}

