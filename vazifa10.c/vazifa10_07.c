#include <stdio.h>
#include <string.h>
 
void engArzon()
{
    FILE *f = fopen("products.txt", "r");
    char nom[50], minNom[50] = "";
    int narx, miqdor, minNarx = 0, minMiqdor = 0, jami = 0;
 
    if (f == NULL) {
        printf("Fayl mavjud emas!\n");
        return;
    }
 
    while (fscanf(f, "%49s %d %d", nom, &narx, &miqdor) == 3) {
        if (jami == 0 || narx < minNarx) {
            strcpy(minNom, nom);
            minNarx = narx;
            minMiqdor = miqdor;
        }
        jami++;
    }
    fclose(f);
 
    if (jami == 0) {
        printf("Fayl bo'sh!\n");
        return;
    }
 
    printf("\n===== ENG ARZON MAHSULOT =====\n\n");
    printf("Nomi: %s\n", minNom);
    printf("Narxi: %d so'm\n", minNarx);
    printf("Miqdori: %d ta\n", minMiqdor);
}
 
int main()
{
    engArzon();
    return 0;
}