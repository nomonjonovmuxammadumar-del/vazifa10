#include <stdio.h>
#include <string.h>
 
void engQimmat()
{
    FILE *f = fopen("products.txt", "r");
    char nom[50], maxNom[50] = "";
    int narx, miqdor, maxNarx = 0, maxMiqdor = 0, jami = 0;
 
    if (f == NULL) {
        printf("Fayl mavjud emas!\n");
        return;
    }
 
    while (fscanf(f, "%49s %d %d", nom, &narx, &miqdor) == 3) {
        if (jami == 0 || narx > maxNarx) {
            strcpy(maxNom, nom);
            maxNarx = narx;
            maxMiqdor = miqdor;
        }
        jami++;
    }
    fclose(f);
 
    if (jami == 0) {
        printf("Fayl bo'sh!\n");
        return;
    }
 
    printf("\n===== ENG QIMMAT MAHSULOT =====\n\n");
    printf("Nomi: %s\n", maxNom);
    printf("Narxi: %d so'm\n", maxNarx);
    printf("Miqdori: %d ta\n", maxMiqdor);
}
 
int main()
{
    engQimmat();
    return 0;
}