#include <stdio.h>
#include <string.h>

int main() {
    char tugas[100];
    int pilihan;
    FILE *file;

    while(1) {
        printf("\n=== TO-DO LIST ===\n");
        printf("1. Tambah Tugas\n");
        printf("2. Lihat Semua Tugas\n");
        printf("3. Keluar\n");
        printf("Pilih menu: ");
        scanf("%d", &pilihan);
        getchar(); 

        if (pilihan == 1) {
            file = fopen("todo.txt", "a");
            printf("Tulis tugas baru: ");
            fgets(tugas, sizeof(tugas), stdin);
            fprintf(file, "- %s", tugas);
            fclose(file);
            printf("Tugas berhasil disimpan!\n");
        } 
        else if (pilihan == 2) {
            file = fopen("todo.txt", "r");
            if (file == NULL) {
                printf("Belum ada tugas terdaftar.\n");
                continue;
            }
            printf("\n--- TO DO LIST ---\n");
            char baris[100];
            while (fgets(baris, sizeof(baris), file)) {
                printf("%s", baris);
            }
            fclose(file);
        } 
        else if (pilihan == 3) {
            break;
        } 
        else {
            printf("Pilihan tidak valid!\n");
        }
    }

    return 0;
}

