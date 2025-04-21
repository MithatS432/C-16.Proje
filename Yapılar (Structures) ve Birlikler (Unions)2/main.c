#include <stdio.h>
#include <string.h>

// enum ve typedef
typedef enum {
    OTOMOBIL,
    MOTOSIKLET,
    KAMYON
} AracTuru;

typedef union {
    int yolcuSayisi;
    float yukKapasitesi;
} AracOzelligi;

typedef struct {
    char marka[30];
    AracTuru tur;
    AracOzelligi ozellik;
    char *plaka; // yapý içinde pointer
} Arac;

// Fonksiyona yapý pointer'ý geçirme
void aracYazdir(const Arac *a) {
    printf("Marka: %s\n", a->marka);
    printf("Plaka: %s\n", a->plaka);

    switch (a->tur) {
        case OTOMOBIL:
            printf("Tur: Otomobil, Yolcu Sayisi: %d\n", a->ozellik.yolcuSayisi);
            break;
        case MOTOSIKLET:
            printf("Tur: Motosiklet, Yolcu Sayisi: %d\n", a->ozellik.yolcuSayisi);
            break;
        case KAMYON:
            printf("Tur: Kamyon, Yuk Kapasitesi: %.2f ton\n", a->ozellik.yukKapasitesi);
            break;
    }
}

int main() {
    Arac a1 = {"Toyota", OTOMOBIL, .ozellik.yolcuSayisi = 5, "34ABC123"};
    Arac a2 = {"MAN", KAMYON, .ozellik.yukKapasitesi = 12.5, "06DEF456"};

    aracYazdir(&a1);
    printf("----\n");
    aracYazdir(&a2);

    return 0;
}
