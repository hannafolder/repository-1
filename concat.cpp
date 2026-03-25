#include <stdio.h>
#include <string.h>
// Program untuk menggabungkan 2 kata yang diinput oleh user menggunakan fungsi strcat
int main(){
    char s[201];
    char t[101];
    
    scanf("%s", s);
    scanf("%s", t);
    
    strcat(s, t);
    
    printf("%s\n", s);
}
