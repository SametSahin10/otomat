#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE *openFile(char DIR[]);
int findLineCount(FILE *fp);

int main(void) {
    struct Kasa {
        int yirmiBesKurusSayisi;
        int elliKurusSayisi;
        int birTLSayisi;
    };

    struct Urun {
        int urunId;
        char urunAd[50];
        int urunStokSayisi;
        char urunFiyat[10]; //Left as string intentionally for future Kurus-TL conversion.
        char urunFiyatTipi[10];
    };

    const char DIR[] = "urunler.txt";
    FILE *fp;
    fp = openFile(DIR);
    if (fp == NULL) {
        printf("%s", "fp is null\n");
    } else {
        printf("%s", "fp is not null\n");
    }

    int lineCount = findLineCount(fp);
    fp = openFile(DIR);
    char lines[lineCount][50];

    for(int i = 0; i < lineCount; i++) {
        fgets(lines[i], 50, fp);
    }

    fclose(fp);

    struct Kasa kasa;
    sscanf(lines[0], "%d,%d,%d", &kasa.yirmiBesKurusSayisi, &kasa.elliKurusSayisi, &kasa.birTLSayisi);
    printf("Yirmi bes kurus sayisi: %d\n", kasa.yirmiBesKurusSayisi);
    printf("Elli kurus sayisi: %d\n", kasa.elliKurusSayisi);
    printf("Bir TL sayisi: %d\n", kasa.birTLSayisi);

    struct Urun su;
    struct Urun cay;
    struct Urun kahve;
    struct Urun cikolata;
    struct Urun biskuvi;

    sscanf(lines[1], "%d,%[^,],%d,%s%s", &su.urunId, su.urunAd, &su.urunStokSayisi, su.urunFiyat, su.urunFiyatTipi);
    sscanf(lines[2], "%d,%[^,],%d,%s%s", &cay.urunId, cay.urunAd, &cay.urunStokSayisi, cay.urunFiyat, cay.urunFiyatTipi);
    sscanf(lines[3], "%d,%[^,],%d,%s%s", &kahve.urunId, kahve.urunAd, &kahve.urunStokSayisi, kahve.urunFiyat, kahve.urunFiyatTipi);
    sscanf(lines[4], "%d,%[^,],%d,%s%s", &cikolata.urunId, cikolata.urunAd, &cikolata.urunStokSayisi, cikolata.urunFiyat, cikolata.urunFiyatTipi);
    sscanf(lines[5], "%d,%[^,],%d,%s%s", &biskuvi.urunId, biskuvi.urunAd, &biskuvi.urunStokSayisi, biskuvi.urunFiyat, biskuvi.urunFiyatTipi);

    printf("%s", "\n");
    printf("UrunId: %d\nUrunAd: %s\nUrunStokSayisi: %d\nurunFiyat: %s\nUrunFiyatTipi: %s\n", su.urunId, su.urunAd, su.urunStokSayisi, su.urunFiyat, su.urunFiyatTipi);
    printf("%s", "\n");
    printf("UrunId: %d\nUrunAd: %s\nUrunStokSayisi: %d\nurunFiyat: %s\nUrunFiyatTipi: %s\n", cay.urunId, cay.urunAd, cay.urunStokSayisi, cay.urunFiyat, cay.urunFiyatTipi);
    printf("%s", "\n");
    printf("UrunId: %d\nUrunAd: %s\nUrunStokSayisi: %d\nurunFiyat: %s\nUrunFiyatTipi: %s\n", kahve.urunId, kahve.urunAd, kahve.urunStokSayisi, kahve.urunFiyat, kahve.urunFiyatTipi);
    printf("%s", "\n");
    printf("UrunId: %d\nUrunAd: %s\nUrunStokSayisi: %d\nurunFiyat: %s\nUrunFiyatTipi: %s\n", cikolata.urunId, cikolata.urunAd, cikolata.urunStokSayisi, cikolata.urunFiyat, cikolata.urunFiyatTipi);
    printf("%s", "\n");
    printf("UrunId: %d\nUrunAd: %s\nUrunStokSayisi: %d\nurunFiyat: %s\nUrunFiyatTipi: %s\n", biskuvi.urunId, biskuvi.urunAd, biskuvi.urunStokSayisi, biskuvi.urunFiyat, biskuvi.urunFiyatTipi);

    return 0;
}

FILE *openFile(char DIR[]) {
    FILE *fp = fopen(DIR, "r+");
    if(fp == NULL) {
        printf("%s", "fp is null");
    }
    return fp;
}

int findLineCount(FILE *fp) {
    int lineCount = 0;
    int c;
    while ((c = fgetc(fp)) != EOF) {
        if ((char) c == '\n') {
            lineCount++;
        }
    }
    printf("Line count is: %d\n", lineCount);
    return lineCount;
}
