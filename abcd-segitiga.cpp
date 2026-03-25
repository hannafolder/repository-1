// Hanna Nathalia 825250015
#include <stdio.h>

int main() {
    char ch = 'A'; // huruf pertama yang dicetak
    int i, j, k; // i = loop baris, j = loop huruf di baris, k = loop untuk spasi
    int n = 4; // jumlah baris

    for(i = 1; i <= n; i++) {
        for(k = 1; k <= n - i; k++) {
            printf("  ");
        }

        for(j = 1; j <= i; j++) {
            printf("%c ", ch);
            ch++;
        }
        printf("\n");
    }

    return 0;
}
