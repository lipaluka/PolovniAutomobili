#define _CRT_SECURE_NO_WARNINGS
#include"header.h"

void izborGlavni() {
    int izbor;
    char unos[10];

    do {
        printf("Dobrodosli u aplikaciju!!\n");
        printf("1. Korisnicki izbornik\n");
        printf("2. Administratorski izbornik\n");
        printf("3. IZLAZ IZ PROGRAMA\n");
        printf("/////////////////////////////////\n");
        scanf("%9s", unos);
        if (sscanf(unos, "%d", &izbor) != 1 || izbor < 1 || izbor > 3) {
            printf("Greska pri unosu!\n");
            continue;
        }
        switch (izbor) {
        case 1:
            izborKorisnik();
            break;
        case 2:
            izborAdmin();
            break;
        case 3:
            if (krajPrograma() == 0) {
                printf("Kraj programa, stisnite bilo koju tipku");
                getchar();
                getchar();
            }
            else {
                printf("Za povratak na pocetni izbornik pritisnite bilo koju tipku");
                getchar();
                getchar();
                izborGlavni();
            }
            break;
        default:
            printf("Nepostojeci izbor\n");
            break;
        }
    } while (izbor != 3);
}

