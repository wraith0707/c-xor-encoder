#include <stdio.h>
#include <stdlib.h>

int main() {
    char veriname[30];
    char key = 0x5A; // XOR Anahtarı
    int i;
    int secenek;

    printf("----- XOR Sifreleme Programi -----\n");
    printf("1 - XOR Encoder (Sifrele)\n");
    printf("2 - XOR Decoder (Coz)\n");
    printf("Seciminiz: ");
    scanf("%d", &secenek);

    printf("Lutfen Metninizi Giriniz: ");
    scanf("%29s", veriname);

    switch(secenek) {
        case 1: 
            for(i = 0; veriname[i] != '\0'; i++) { 
                veriname[i] = veriname[i] ^ key;
            }
            printf("Sifreli (Gizlenmis) Hali: %s\n", veriname);
            break;

        case 2:
            for(i = 0; veriname[i] != '\0'; i++) {
                veriname[i] = veriname[i] ^ key;
            }
            printf("Cozulmus (Orijinal) Hali : %s\n", veriname);
            break;

        default:
            printf("[!] Gecersiz secim yaptiniz!\n");
            break;
    }

    return 0;
}
