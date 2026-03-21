#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char kata[100];
    int i, panjang, palindrom = 1;

    printf("Masukkan kata: ");
    scanf("%s", kata);

    panjang = strlen(kata);

    for (i = 0; i < panjang / 2; i++) {
        if (tolower(kata[i]) != tolower(kata[panjang - 1 - i])) {
            palindrom = 0;
            break;
        }
    }

    if (palindrom) {
        printf("Palindrom\n");
    } else {
        printf("Bukan Palindrom\n");
    }

    return 0;
}
