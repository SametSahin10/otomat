#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE *openFile(char DIR[]);
int findLineCount(FILE *fp);
float creditInsertionUI();
float productSelectionUi();

struct Kasa {
    int yirmiBesKurusSayisi;
    int elliKurusSayisi;
    int birTLSayisi;
};

struct Urun {
    int urunId;
    char urunAd[50];
    int urunStokSayisi;
    float urunFiyat; //Left as string intentionally for future Kurus-TL conversion.
    char urunFiyatTipi[10];
};

struct Kasa kasa;

struct Urun su;
struct Urun cay;
struct Urun kahve;
struct Urun cikolata;
struct Urun biskuvi;

int main(void) {
    const char DIR[] = "urunler.txt";
    FILE *fp;
    fp = openFile(DIR);

    int lineCount = findLineCount(fp);
    fp = openFile(DIR);
    char lines[lineCount][50];

    for(int i = 0; i < lineCount; i++) {
        fgets(lines[i], 50, fp);
    }

    fclose(fp);

    sscanf(lines[0], "%d,%d,%d", &kasa.yirmiBesKurusSayisi, &kasa.elliKurusSayisi, &kasa.birTLSayisi);
    sscanf(lines[1], "%d,%[^,],%d,%f%s", &su.urunId, su.urunAd, &su.urunStokSayisi, &su.urunFiyat, su.urunFiyatTipi);
    sscanf(lines[2], "%d,%[^,],%d,%f%s", &cay.urunId, cay.urunAd, &cay.urunStokSayisi, &cay.urunFiyat, cay.urunFiyatTipi);
    sscanf(lines[3], "%d,%[^,],%d,%f%s", &kahve.urunId, kahve.urunAd, &kahve.urunStokSayisi, &kahve.urunFiyat, kahve.urunFiyatTipi);
    sscanf(lines[4], "%d,%[^,],%d,%f%s", &cikolata.urunId, cikolata.urunAd, &cikolata.urunStokSayisi, &cikolata.urunFiyat, cikolata.urunFiyatTipi);
    sscanf(lines[5], "%d,%[^,],%d,%f%s", &biskuvi.urunId, biskuvi.urunAd, &biskuvi.urunStokSayisi, &biskuvi.urunFiyat, biskuvi.urunFiyatTipi);

//    printf("%d %s %d %f %s\n", su.urunId, su.urunAd, su.urunStokSayisi, su.urunFiyat, su.urunFiyatTipi);
//    printf("%d %s %d %f %s\n", cay.urunId, cay.urunAd, cay.urunStokSayisi, cay.urunFiyat, cay.urunFiyatTipi);
//    printf("%d %s %d %f %s\n", kahve.urunId, kahve.urunAd, kahve.urunStokSayisi, kahve.urunFiyat, kahve.urunFiyatTipi);
//    printf("%d %s %d %f %s\n", cikolata.urunId, cikolata.urunAd, cikolata.urunStokSayisi,cikolata.urunFiyat, cikolata.urunFiyatTipi);
//    printf("%d %s %d %f %s\n", biskuvi.urunId, biskuvi.urunAd, biskuvi.urunStokSayisi, biskuvi.urunFiyat, biskuvi.urunFiyatTipi);

    //User Interface
    float insertedAmount;
    float amountToPay;
    float change;
    insertedAmount = creditInsertionUI();
    amountToPay = productSelectionUi();
    change = insertedAmount - amountToPay;

    printf("Atilan para: %.2f\n", insertedAmount);
    printf("Odenmesi gereken ucret: %.2f\n", amountToPay);
    printf("Para ustu: %.2f\n", change);

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
    return lineCount;
}

float creditInsertionUI() {
    float insertedAmount = 0;
    int choice;
    do {
        printf("* %s", "25 Kurus ekle (1)\n");
        printf("* %s", "50 Kurus ekle (2)\n");
        printf("* %s", "1 TL ekle (3)\n");
        printf("* %s", "Bitis (4)\n");
        printf("%s", "\n");
        printf("x %s", "Reset (9)\n");

//        fgets(&choice, 10, stdin);
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                insertedAmount += 0,25;
                break;
            case 2:
                insertedAmount += 0,50;
                break;
            case 3:
                insertedAmount += 1;
                break;
            case 4:
                break;
            case 9:
                insertedAmount = 0;
                printf("Secimler iptal edildi");
                break;
            default:
                printf("%s", "\n");
                printf("Lutfen gecerli bir secim yapiniz\n\n");
        }
    } while (choice != 9 && choice != 4);
    return insertedAmount;
}

float productSelectionUi() {
    float amountToPay = 0;
    float priceOfProduct;
    int numOfSuPurchased = 0;
    int numOfCayPurchased = 0;
    int numOfKahvePurchased = 0;
    int numOfCikolataPurchased = 0;
    int numOfBiskuviPurchased = 0;
    int choice;

    do {
        printf("* %s", "Su (1)\n");
        printf("* %s", "Cay (2)\n");
        printf("* %s", "Kahve (3)\n");
        printf("* %s", "Cikolata (4)\n");
        printf("* %s", "Biskuvi (5)\n");
        printf("* %s", "Bitis (6)\n");
        printf("%s", "\n");
        printf("x %s", "Reset (9)\n");

        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (strcmp(su.urunFiyatTipi, "Kurus") == 0) {
                    priceOfProduct = su.urunFiyat / 100;
                } else {
                    priceOfProduct = su.urunFiyat;
                }
                numOfSuPurchased++;
                amountToPay += priceOfProduct;
                break;
            case 2:
                if (strcmp(cay.urunFiyatTipi, "Kurus") == 0) {
                    priceOfProduct = cay.urunFiyat / 100;
                } else {
                    priceOfProduct = cay.urunFiyat;
                }
                numOfCayPurchased++;
                amountToPay += priceOfProduct;
                break;
            case 3:
                if (strcmp(kahve.urunFiyatTipi, "Kurus") == 0) {
                    priceOfProduct = kahve.urunFiyat / 100;
                } else {
                    priceOfProduct = kahve.urunFiyat;
                }
                numOfKahvePurchased++;
                amountToPay += priceOfProduct;
                break;
            case 4:
                if (strcmp(cikolata.urunFiyatTipi, "Kurus") == 0) {
                    priceOfProduct = cikolata.urunFiyat / 100;
                } else {
                    priceOfProduct = cikolata.urunFiyat;
                }
                numOfCikolataPurchased++;
                amountToPay += priceOfProduct;
                break;
            case 5:
                if (strcmp(biskuvi.urunFiyatTipi, "Kurus") == 0) {
                    priceOfProduct = biskuvi.urunFiyat / 100;
                } else {
                    priceOfProduct = biskuvi.urunFiyat;
                }
                numOfBiskuviPurchased++;
                amountToPay += priceOfProduct;
                break;
            case 6:
                break;
            case 9:
                printf("Secimler iptal edildi");
                numOfSuPurchased = 0;
                numOfCayPurchased = 0;
                numOfKahvePurchased = 0;
                numOfCikolataPurchased = 0;
                numOfBiskuviPurchased = 0;
                break;
            default:
                printf("%s", "\n");
                printf("Lutfen gecerli bir secim yapiniz\n\n");
        }
    } while (choice != 9 && choice != 6);

    su.urunStokSayisi -= numOfSuPurchased;
    cay.urunStokSayisi -= numOfCayPurchased;
    kahve.urunStokSayisi -= numOfKahvePurchased;
    cikolata.urunStokSayisi -= numOfCikolataPurchased;
    biskuvi.urunStokSayisi -= numOfBiskuviPurchased;
    return amountToPay;
}
