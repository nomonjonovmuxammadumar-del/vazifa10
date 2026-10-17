#include <stdio.h>
 
void qoshish()
{
    FILE *f;
    char nom[50];
    int narx, miqdor;
 
    printf("Mahsulot nomi (bitta so'z): ");
    scanf("%49s", nom);
    printf("Narxi: ");
    scanf("%d", &narx);
    printf("Miqdori: ");
    scanf("%d", &miqdor);
 
    f = fopen("products.txt", "a");
    if (f == NULL) {
        printf("Faylni ochib bo'lmadi!\n");
        return;
    }
    fprintf(f, "%s %d %d\n", nom, narx, miqdor);
    fclose(f);
 
    printf("Mahsulot muvaffaqiyatli qo'shildi!\n");
}
 
int main()
{
    qoshish();
    return 0;
}
 