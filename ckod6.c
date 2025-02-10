
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void buyuk_kucuk(char *ilkyazilan, char *metin);//programin fonksiyonu gormesini sagladim

int main() {
    char ilkyazilan[100];
    char metin[100]; // kullanicinin girdigi veriyi tutmak icin bir dizi olusturuyoruz

    printf("Bir metin giriniz:\n\n");
    fgets(ilkyazilan,sizeof(ilkyazilan), stdin);//satirin okunmasini sagladim. 
    size_t x = strlen(ilkyazilan);//metnin uzunlugunu bulmak istedim

    if (ilkyazilan[x - 1] == '\n') {//bir \n varsa 0 ile degistiririm. fgets satirin tamamini okur ama eger metin daha uzun ise bu donusum ise yarar,baska satirlari da gormesini saglar
        ilkyazilan[x - 1] = '\0';
    }

    strcpy(metin, ilkyazilan);//ilkyazilan metin'e kopyalandi.
    buyuk_kucuk(ilkyazilan, metin);//fonksiyonu belirttim
    printf("%s\n", metin);

    return 0;
}
void buyuk_kucuk(char *ilkyazilan, char *metin) {

    while (*ilkyazilan != '\0') {//satirdaki sey eger bos bi karakter degil ise
        if (isupper(*ilkyazilan)) {//buyuk harf olup olmadigina baktim
            *metin = tolower(*ilkyazilan);//kucuk harfe cevirmesini istedim
        }
        else if (islower(*ilkyazilan)) {//kucuk harf olup olmadigina baktim
            *metin = toupper(*ilkyazilan);//buyuk harfe cevirmesini istedim
        }
        else {
            *metin = *ilkyazilan;//harf degil ise kopyalar ve devam eder.
        }
        ilkyazilan++;
        metin++;
    }
    *metin = '\0';//metin dizisini sonlandirmam gerekirdi.
}
