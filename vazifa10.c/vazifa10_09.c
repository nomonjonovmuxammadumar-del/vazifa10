#include <stdio.h>
#include <stdlib.h>
 


int qatorlarSoni(const char *fayl)
{
    FILE *f = fopen(fayl, "r");
    int c, soni = 0;
 
    if (f == NULL)
        return -1;
    while ((c = fgetc(f)) != EOF)
        if (c == '\n')
            soni++;
    fclose(f);
    return soni;
}
 

void nusxa(const char *manba, const char *nishon)
{
    FILE *a = fopen(manba, "r");
    FILE *b = fopen(nishon, "w");
    int c;
 
    if (a == NULL || b == NULL) {
        if (a) fclose(a);
        if (b) fclose(b);
        return;
    }
    while ((c = fgetc(a)) != EOF)
        fputc(c, b);
    fclose(a);
    fclose(b);
}
 
void sarlavha(const char *matn)
{
    printf("\n########## %s ##########\n", matn);
}
 
int main()
{
    int tugri = 0, jami = 0;
 
    setvbuf(stdout, NULL, _IONBF, 0); 
 
    nusxa("products.txt", "products.bak");
 
    
    sarlavha("Kompilyatsiya");
    system("gcc -Wall -o 2_oqish 2_oqish.c");
    system("gcc -Wall -o 3_qoshish 3_qoshish.c");
    system("gcc -Wall -o 4_hisobot 4_hisobot.c");
    system("gcc -Wall -o 5_kamQolgan 5_kamQolgan.c");
    system("gcc -Wall -o 6_engQimmat 6_engQimmat.c");
    system("gcc -Wall -o 7_engArzon 7_engArzon.c");
    system("gcc -Wall -o 8_menyu 8_menyu.c");
    printf("Tayyor.\n");
 
    
    sarlavha("2. oqish");
    system("./2_oqish");
    sarlavha("4. hisobot");
    system("./4_hisobot");
    sarlavha("5. kamQolgan");
    system("./5_kamQolgan");
    sarlavha("6. engQimmat");
    system("./6_engQimmat");
    sarlavha("7. engArzon");
    system("./7_engArzon");
 
    
    sarlavha("3. qoshish");
    int oldin = qatorlarSoni("products.txt");
    system("printf 'Sabzi\\n3000\\n1\\n' | ./3_qoshish");
    int keyin = qatorlarSoni("products.txt");
    jami++;
    if (keyin == oldin + 1) {
        printf("[OK] Eski ma'lumotlar saqlandi (%d -> %d qator)\n", oldin, keyin);
        tugri++;
    } else {
        printf("[XATO] Qatorlar soni: %d -> %d\n", oldin, keyin);
    }
    nusxa("products.bak", "products.txt");
 
    
    sarlavha("Bo'sh fayl");
    FILE *f = fopen("products.txt", "w");
    if (f) fclose(f);
    system("./2_oqish");
    system("./4_hisobot");
    system("./5_kamQolgan");
    system("./6_engQimmat");
    system("./7_engArzon");
 
    
    sarlavha("Fayl mavjud emas");
    remove("products.txt");
    system("./2_oqish");
    system("./4_hisobot");
 
    
    nusxa("products.bak", "products.txt");
    remove("products.bak");
    jami++;
    if (qatorlarSoni("products.txt") == 7) {
        printf("\n[OK] products.txt tiklandi (7 qator)\n");
        tugri++;
    } else {
        printf("\n[XATO] products.txt tiklanmadi\n");
    }
 
    
    sarlavha("8. menyu");
    system("printf '1\\n9\\n0\\n' | ./8_menyu | tail -n 15");
 
    printf("\n===== NATIJA: %d/%d avtomatik tekshiruv o'tdi =====\n", tugri, jami);
    return 0;
}
 