#include <stdio.h>
#include <string.h>
 
#define FAYL "products.txt"
 
void oqish()
{
    FILE *f = fopen(FAYL, "r");
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
 
    f = fopen(FAYL, "a");
    if (f == NULL) {
        printf("Faylni ochib bo'lmadi!\n");
        return;
    }
    fprintf(f, "%s %d %d\n", nom, narx, miqdor);
    fclose(f);
 
    printf("Mahsulot muvaffaqiyatli qo'shildi!\n");
}
 
void hisobot()
{
    FILE *f = fopen(FAYL, "r");
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
 
void kamQolgan()
{
    FILE *f = fopen(FAYL, "r");
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
 
void engQimmat()
{
    FILE *f = fopen(FAYL, "r");
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
 
void engArzon()
{
    FILE *f = fopen(FAYL, "r");
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
    int tanlov = -1;
 
    while (tanlov != 0) {
        printf("\n===== MAHSULOTLAR BOSHQARUVI =====\n\n");
        printf("1. Mahsulotlarni ko'rish\n");
        printf("2. Yangi mahsulot qo'shish\n");
        printf("3. Umumiy hisobot\n");
        printf("4. Kam qolgan mahsulotlar\n");
        printf("5. Eng qimmat mahsulot\n");
        printf("6. Eng arzon mahsulot\n");
        printf("0. Chiqish\n\n");
        printf("Tanlovingiz: ");
 
        if (scanf("%d", &tanlov) != 1) {
            printf("Noto'g'ri tanlov!\n");
            scanf("%*s");
            tanlov = -1;
            continue;
        }
 
        switch (tanlov) {
            case 1: oqish(); break;
            case 2: qoshish(); break;
            case 3: hisobot(); break;
            case 4: kamQolgan(); break;
            case 5: engQimmat(); break;
            case 6: engArzon(); break;
            case 0: printf("Dastur tugadi.\n"); break;
            default: printf("Noto'g'ri tanlov!\n");
        }
    }
    return 0;
}
 