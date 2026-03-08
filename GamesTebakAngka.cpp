#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    int secret, guess, attempts = 0;

    srand(time(0));
    secret = rand() % 20 + 1;

    printf("Games Tebak Angka 1-20\n");
    do {
        printf("Tuliskan tebakanmu antara 1-20 \n");
        scanf("%d", &guess);
        attempts++;

        if (guess < secret) {
            printf("Lebih tinggi\n");
        } else if (guess > secret) {
            printf("Lebih rendah\n");
        } else {
            printf("Betul\n");
        }
    } while (guess != secret);
    return 0;
}