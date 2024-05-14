#define _CRT_SECURE_NO_WARNINGS
#include "header.h"

void dodajAuto() {
    FILE* auti = fopen("auti.txt", "r+");
    if (auti == NULL) {
        perror("Greska pri otvaranju datoteke");
        return;
    }

    AUTO mobil;
    int najveci_id = 0;
    int trenutni_id;

    while (fscanf(auti, "%d", &trenutni_id) == 1) {
        if (trenutni_id > najveci_id) {
            najveci_id = trenutni_id;
        }

        char buffer[256];
        fgets(buffer, sizeof(buffer), auti);
    }

    mobil.id = najveci_id + 1;

    printf("\nUnesi marku: ");
    scanf("%19s", mobil.marka);
    printf("\nUnesi model: ");
    scanf("%19s", mobil.model);
    printf("\nUnesi karoseriju: ");
    scanf("%14s", mobil.karoserija);
    printf("\nUnesi pogon: ");
    scanf("%9s", mobil.pogon);
    printf("\nUnesi motor: ");
    scanf("%14s", mobil.motor);
    printf("\nUnesi boju: ");
    scanf("%14s", mobil.boja);
    printf("\nUnesi broj konjskih snaga: ");
    scanf("%d", &mobil.konji);
    printf("\nUnesi broj njutn metara: ");
    scanf("%d", &mobil.newtonm);
    printf("\nUnesi kilometrazu: ");
    scanf("%d", &mobil.kilometraza);
    printf("\nUnesi godiste: ");
    scanf("%d", &mobil.godiste);

    fseek(auti, 0, SEEK_END);
    fprintf(auti, "%d\n%19s\n%19s\n%14s\n%9s\n%14s\n%14s\n%d\n%d\n%d\n%d\n",
        mobil.id, mobil.marka, mobil.model, mobil.karoserija, mobil.pogon,
        mobil.motor, mobil.boja, mobil.konji, mobil.newtonm, mobil.kilometraza, mobil.godiste);

    fclose(auti);
}
