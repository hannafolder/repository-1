#include <stdio.h>
int main(){
    int detik, jam, menit;
    scanf("%d",&detik);
    jam = detik/3600;
    menit = (detik%3600)/60;
    detik = detik%60;
    printf("%d:%d:%d",jam,menit,detik);
}
