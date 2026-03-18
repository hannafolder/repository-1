#include <stdio.h>
#include <ctype.h>

#define OUT 0
#define IN  1

int main() {
    char c;
    int nl, nw, nc, state;

    state = OUT;
    nl = nw = nc = 0;

    printf("=== WORD COUNTER ===\n");
    printf("Masukkan teks (Tekan Ctrl+D di Linux atau Ctrl+Z di Windows untuk selesai):\n\n");

    while ((c = getchar()) != EOF) {
        nc++;

        if (c == '\n') {
            nl++;
        }

        if (isspace(c)) {
            state = OUT;
        } 
        else if (state == OUT) {
            state = IN;
            nw++;
        }
    }

    printf("\n\n--- HASIL ANALISIS ---\n");
    printf("Jumlah Karakter : %d\n", nc);
    printf("Jumlah Kata      : %d\n", nw);
    printf("Jumlah Baris     : %d\n", nl);

    return 0;
}
