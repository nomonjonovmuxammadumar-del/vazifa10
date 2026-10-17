#include <stdio.h>
 
void hisobot()
{
    FILE *f = fopen("products.txt", "r");
    char nom[50];
    int narx, miqdor;
    int turlar = 0, jamiMiqdor = 0;
    long long jamiQiymat = 0;
 
    if (f == NULL) {
        printf("Fayl mavjud emas!\n");
        return;
    }
 
    while (fscanf(f, "%49s %d %d", nom, &narx, &miqdor) == 3) {
        turlar++;
        jamiMiqdor += miqdor;
        jamiQiymat += (long long)narx * miqdor;
    }
    fclose(f);
 
    if (turlar == 0) {
        printf("Fayl bo'sh!\n");
        return;
    }
 
    printf("\n===== UMUMIY HISOBOT =====\n\n");
    printf("Mahsulot turlari: %d ta\n", turlar);
    printf("Jami mahsulot miqdori: %d ta\n", jamiMiqdor);
    printf("Ombordagi jami qiymat: %lld so'm\n", jamiQiymat);
}
 
int main()
{
    hisobot();
    return 0;
}
 