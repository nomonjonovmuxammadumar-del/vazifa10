#include <stdio.h>
 
void kamQolgan()
{
    FILE *f = fopen("products.txt", "r");
    char nom[50];
    int narx, miqdor, topildi = 0, jami = 0;
 
    if (f == NULL) {
        printf("Fayl mavjud emas!\n");
        return;
    }
 
    printf("\n===== KAM QOLGAN MAHSULOTLAR =====\n\n");
    while (fscanf(f, "%49s %d %d", nom, &narx, &miqdor) == 3) {
        jami++;
        if (miqdor <= 5) {
            printf("%s — %d ta (narxi: %d so'm)\n", nom, miqdor, narx);
            topildi = 1;
        }
    }
    fclose(f);
 
    if (jami == 0)
        printf("Fayl bo'sh!\n");
    else if (!topildi)
        printf("Kam qolgan mahsulot yo'q.\n");
}
 
int main()
{
    kamQolgan();
    return 0;
}
 