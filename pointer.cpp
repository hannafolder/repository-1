#include <stdio.h>
void tukar(int *a, int *b) {
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int x = 100;
    int y = 200;

    printf("--- Sebelum Ditukar ---\n");
    printf("Nilai x: %d\n", x);
    printf("Nilai y: %d\n\n", y);

    tukar(&x, &y);

    printf("--- Setelah Ditukar ---\n");
    printf("Nilai x: %d\n", x);
    printf("Nilai y: %d\n", y);

    return 0;
}
