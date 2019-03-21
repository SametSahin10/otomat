#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE *openFile(char dir[]);
int findLineCount(FILE *fp);

int main(void) {
    struct Kasa {
        int YirmiBesKurusSayisi;
        int ElliKurusSayisi;
        int BirTLSayisi;
    };

    struct Kasa kasa;

    const char dir[] = "C_Projects/otomat/urunler.txt";
    FILE *fp;
    fp = openFile(dir);
    int lineCount = findLineCount(fp);
    fp = openFile(dir);
    char lines[lineCount][50];

    for(int i = 0; i < lineCount; i++) {
        fgets(lines[i], 50, fp);
    }

    fclose(fp);

    char bozukParaSayilari[3][10];
    char urunBilgileri[4][50];

    char delim[] = ",";
    char *p = strtok(lines[0], delim);
    while (p != NULL) {
        for (int i = 0; i < 3; i++) {
            strcpy(bozukParaSayilari[i], p);
            p = strtok(NULL, delim);
        }
    }

    for(int i = 0; i < 3; i++) {
        printf("%s ", bozukParaSayilari[i]);
    }

    return 0;
}

FILE *openFile(char dir[]) {
    FILE *fp = fopen(dir, "r+");
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
