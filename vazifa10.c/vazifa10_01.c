 #include <stdio.h>
 
void oqish()
{
    FILE *f = fopen("products.txt", "r");
    char nom[50];
    int narx, miqdor, soni = 0;
 
    if (f == NULL) {
        printf("Fayl mavjud emas!\n");
        return;
    }
 
    printf("\n===== MAHSULOTLAR =====\n\n");
    while (fscanf(f, "%49s %d %d", nom, &narx, &miqdor) == 3) {
        printf("Nomi: %s\n", nom);
        printf("Narxi: %d so'm\n", narx);
        printf("Miqdori: %d ta\n", miqdor);
        printf("-----------------------\n");
        soni++;
    }
    fclose(f);
 
    if (soni == 0)
        printf("Fayl bo'sh!\n");
}
 
int main()
{
    oqish();
    return 0;
}
 