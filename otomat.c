#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

float creditInsertionUI(void);
float productSelectionUi(void);
int checkForMoneyJam(void);
void processChange(float totalAmountOfChange);
float totalOfSafe(void);

struct Kasa {
    int yirmiBesKurusSayisi;
    int elliKurusSayisi;
    int birTLSayisi;
};

struct Urun {
    int urunId;
    char urunAd[50];
    int urunStokSayisi;
    float urunFiyat;
    char urunFiyatTipi[10];
};

struct Kasa kasa;

struct Urun su;
struct Urun cay;
struct Urun kahve;
struct Urun cikolata;
struct Urun biskuvi;

float insertedAmount = 0;
float amountToPay = 0;
float change;

char urunler[] = "20,20,10\n"
                 "1,su,30,50 Kurus\n"
                 "2,cay,20,1 TL\n"
                 "3,kahve,15,1.5 TL\n"
                 "4,cikolata,50,1.75 TL\n"
                 "5,biskuvi,100,2 TL";

int main(void) {
    sscanf(urunler, "%d,%d,%d"
                    "%d,%[^,],%d,%f %[^\n]"
                    "%d,%[^,],%d,%f %[^\n]"
                    "%d,%[^,],%d,%f %[^\n]"
                    "%d,%[^,],%d,%f %[^\n]"
                    "%d,%[^,],%d,%f %s",

                    &kasa.yirmiBesKurusSayisi, &kasa.elliKurusSayisi, &kasa.birTLSayisi
                    ,&su.urunId, su.urunAd, &su.urunStokSayisi, &su.urunFiyat, su.urunFiyatTipi
                    ,&cay.urunId, cay.urunAd, &cay.urunStokSayisi, &cay.urunFiyat, cay.urunFiyatTipi
                    ,&kahve.urunId, kahve.urunAd, &kahve.urunStokSayisi, &kahve.urunFiyat, kahve.urunFiyatTipi
                    ,&cikolata.urunId, cikolata.urunAd, &cikolata.urunStokSayisi, &cikolata.urunFiyat, cikolata.urunFiyatTipi
                    ,&biskuvi.urunId, biskuvi.urunAd, &biskuvi.urunStokSayisi, &biskuvi.urunFiyat, biskuvi.urunFiyatTipi);

    printf("%d,%d,%d\n", kasa.yirmiBesKurusSayisi, kasa.elliKurusSayisi, kasa.birTLSayisi);
    printf("%d %s %d %.2f %s\n", su.urunId, su.urunAd, su.urunStokSayisi, su.urunFiyat, su.urunFiyatTipi);
    printf("%d %s %d %.2f %s\n", cay.urunId, cay.urunAd, cay.urunStokSayisi, cay.urunFiyat, cay.urunFiyatTipi);
    printf("%d %s %d %.2f %s\n", kahve.urunId, kahve.urunAd, kahve.urunStokSayisi, kahve.urunFiyat, kahve.urunFiyatTipi);
    printf("%d %s %d %.2f %s\n", cikolata.urunId, cikolata.urunAd, cikolata.urunStokSayisi,cikolata.urunFiyat, cikolata.urunFiyatTipi);
    printf("%d %s %d %.2f %s\n", biskuvi.urunId, biskuvi.urunAd, biskuvi.urunStokSayisi, biskuvi.urunFiyat, biskuvi.urunFiyatTipi);
    printf("%s", "\n");

    //User Interface
    do {
        insertedAmount = creditInsertionUI();
    } while (insertedAmount == 0);

    do {
        amountToPay = productSelectionUi();
    } while (amountToPay == 0);

    change = insertedAmount - amountToPay;
    printf("%s", "\n");
    printf("Yuklenen para: %.2f\n", insertedAmount);
    printf("Odenmesi gereken ucret: %.2f\n", amountToPay);
    printf("Para ustu: %.2f\n", change);
    processChange(change);
    return 0;
}

float creditInsertionUI(void) {
    int choice;

    do {
        if (insertedAmount != 0) {
            printf("\n");
            printf("Kullanilabilir kredi: %.2f\n\n", insertedAmount);
        }
        printf("* %s", "25 Kurus ekle (1)\n");
        printf("* %s", "50 Kurus ekle (2)\n");
        printf("* %s", "1 TL ekle (3)\n");
        printf("* %s", "Bitis (4)\n");
        printf("%s", "\n");
        printf("x %s", "Reset (9)\n");

        scanf("%d", &choice);
        switch (choice) {
            case 1:
                insertedAmount += 0.25;
                break;
            case 2:
                insertedAmount += 0.50;
                break;
            case 3:
                insertedAmount += 1;
                break;
            case 4:
                break;
            case 9:
                insertedAmount = 0;
                printf("%s", "\n");
                printf("%s", "Secimler iptal edildi\n\n");
                break;
            default:
                printf("%s", "\n");
                printf("Lutfen gecerli bir secim yapiniz\n");
        }
    } while (choice != 9 && choice != 4);

    if (insertedAmount != 0) {
        printf("\n");
        printf("Kullanilabilir kredi: %.2f\n\n", insertedAmount);
    }
    return insertedAmount;
}

float productSelectionUi(void) {
    float priceOfProduct;
    int numOfSuPurchased = 0;
    int numOfCayPurchased = 0;
    int numOfKahvePurchased = 0;
    int numOfCikolataPurchased = 0;
    int numOfBiskuviPurchased = 0;
    int choice;
    printf("%s", "Urun secimi yapiniz.\n\n");

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
                printf("%s", "\n");
                printf("%s", "Secimler iptal edildi\n\n");
                numOfSuPurchased = 0;
                numOfCayPurchased = 0;
                numOfKahvePurchased = 0;
                numOfCikolataPurchased = 0;
                numOfBiskuviPurchased = 0;
                amountToPay = 0;
                return amountToPay;
            default:
                printf("%s", "\n");
                printf("Lutfen gecerli bir secim yapiniz\n\n");
        }
    } while (choice != 9 && choice != 6);

    int moneyJamResult = checkForMoneyJam();

    if (moneyJamResult == 1) {
        printf("%s", "\n");
        printf("%s", "Para sıkışması gerceklesti\n\n");
        numOfSuPurchased = 0;
        numOfCayPurchased = 0;
        numOfKahvePurchased = 0;
        numOfCikolataPurchased = 0;
        numOfBiskuviPurchased = 0;
        insertedAmount = 0;
        amountToPay = 0;
        return amountToPay;
    }

    su.urunStokSayisi -= numOfSuPurchased;
    cay.urunStokSayisi -= numOfCayPurchased;
    kahve.urunStokSayisi -= numOfKahvePurchased;
    cikolata.urunStokSayisi -= numOfCikolataPurchased;
    biskuvi.urunStokSayisi -= numOfBiskuviPurchased;
    return amountToPay;
}

int checkForMoneyJam(void) {
    srand(time(NULL));
    int randomNumber = rand() % 4 + 1;
    printf("Random number is: %d", randomNumber);
    if (randomNumber == 2) {
        //Enlight the red LED.
        //Reset everthing. Do not charge for any product.
        return 1; //Means we have some money jammed.
    } else {
        //Enlight the green LED.
        return 0; //No money jammed. Everthing's cool.
    }
}

void processChange(float totalAmountOfChange) {
    float total = totalOfSafe();
    if (totalAmountOfChange > total) {
        printf("%s", "Kasada yeterli para yoktur.");
        return;
        //Show warning on Display (Kasada yeterli para yoktur)
    }

    while (totalAmountOfChange >= 1) {
        if (kasa.birTLSayisi > 0) {
            totalAmountOfChange--;
            kasa.birTLSayisi--;
        } else {
            break;
        }
    }

    while (totalAmountOfChange >= 0.50) {
        if (kasa.elliKurusSayisi > 0) {
            totalAmountOfChange -= 0.50;
            kasa.elliKurusSayisi--;
        } else {
            break;
        }
    }

    while (totalAmountOfChange >= 0.25) {
        if (kasa.yirmiBesKurusSayisi > 0) {
            totalAmountOfChange -= 0.25;
            kasa.yirmiBesKurusSayisi--;
        } else {
            break;
        }
    }

    sprintf(urunler, "%d,%d,%d ", kasa.yirmiBesKurusSayisi, kasa.elliKurusSayisi, kasa.birTLSayisi);
    //write to array instead of file
}

float totalOfSafe(void) {
    float total = 0;
    total += (kasa.birTLSayisi * 1) + (kasa.elliKurusSayisi * 0.50) + (kasa.yirmiBesKurusSayisi * 0.25);
    return total;
}