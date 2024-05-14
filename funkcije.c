#define _CRT_SECURE_NO_WARNINGS
#include"header.h"

int krajPrograma() {
    int kraj;
    char unos[3];
    printf("Jeste li sigurni da zelite izaci?\n");
    scanf("%2s", unos);

    if (strcmp(unos, "da") == 0 || strcmp(unos, "DA") == 0 || strcmp(unos, "Da") == 0) {
        kraj = 0;
    }
    else if (strcmp(unos, "ne") == 0 || strcmp(unos, "NE") == 0 || strcmp(unos, "Ne") == 0) {
        kraj = 1;
    }
    else {
        printf("Trebate unijeti da ili ne!!");
        return krajPrograma();
    }
    return kraj;
}

void pregledAutomobila() {
    FILE* auti = fopen("auti.txt", "r");
    if (auti == NULL) {
        perror("Greska pri otvaranju datoteke");
        return;
    }

    AUTO mobil;
    while (fscanf(auti, "%d", &mobil.id) == 1) {
   
        fscanf(auti, "%19s", mobil.marka);
        fscanf(auti, "%19s", mobil.model);
        fscanf(auti, "%14s", mobil.karoserija);
        fscanf(auti, "%9s", mobil.pogon);
        fscanf(auti, "%14s", mobil.motor);
        fscanf(auti, "%14s", mobil.boja);
        fscanf(auti, "%d", &mobil.konji);
        fscanf(auti, "%d", &mobil.newtonm);
        fscanf(auti, "%d", &mobil.kilometraza);
        fscanf(auti, "%d", &mobil.godiste);

        printf("ID: %d\n", mobil.id);
        printf("Marka: %s\n", mobil.marka);
        printf("Model: %s\n", mobil.model);
        printf("Karoserija: %s\n", mobil.karoserija);
        printf("Pogon: %s\n", mobil.pogon);
        printf("Motor: %s\n", mobil.motor);
        printf("Boja: %s\n", mobil.boja);
        printf("Konjske snage: %d\n", mobil.konji);
        printf("Newton-metri: %d\n", mobil.newtonm);
        printf("Kilometraza: %d\n", mobil.kilometraza);
        printf("Godiste: %d\n", mobil.godiste);
        printf("---------------------------------\n");
    }

    fclose(auti);
}

void dodajAuto() {
    FILE* auti = fopen("auti.txt", "r+");
    if (auti == NULL) {
        perror("Greska pri otvaranju datoteke");
        return;
    }

    AUTO mobil;
    int noviID = 0;
    int trenutniID;

    while (fscanf(auti, "%d", &trenutniID) == 1) {
        if (trenutniID > noviID) {
            noviID = trenutniID;
        }

        char buffer[256];
        fgets(buffer, sizeof(buffer), auti);
    }

    mobil.id = noviID + 1;

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

void obrisiAuto() {
    printf("Unesi ID automobila za brisanje: ");
    int iddel;
    scanf("%d", &iddel);
    getchar();
    FILE* auti = fopen("auti.txt", "r+");
    if (auti == NULL) {
        perror("Greska pri otvaranju datoteke");
        return;
    }
    FILE* temp = fopen("temp.txt", "w");
    if (temp == NULL) {
        perror("Greska pri otvaranju temp datoteke");
        return 1;
    }

    auti = fopen("auti.txt", "r");
    if (auti == NULL) {
        perror("Greska pri otvaranju datoteke");
        fclose(temp);
        return 1;
    }

    int id;
    while (fscanf(auti, "%d", &id) == 1) {
        fgetc(auti);
        if (id == iddel) {

            char buffer[256];
            for (int i = 0; i < 10; i++) {
                fgets(buffer, sizeof(buffer), auti);
            }
            continue;
        }
        fprintf(temp, "%d\n", id);
        for (int i = 0; i < 10; i++) {
            char buffer[256];
            if (fgets(buffer, sizeof(buffer), auti)) {
                fputs(buffer, temp);
            }
        }
    }

    fclose(auti);
    fclose(temp);
    remove("auti.txt");
    rename("temp.txt", "auti.txt");

    printf("Automobil (ID %d) je obrisan.\n", iddel);
}

void urediAuto() {
    FILE* auti = fopen("auti.txt", "r");
    if (auti == NULL) {
        perror("Greska pri otvaranju datoteke");
        return;
    }

    FILE* temp = fopen("temp.txt", "w");
    if (temp == NULL) {
        perror("Greska pri otvaranju temp datoteke");
        fclose(auti);
        return;
    }

    printf("Unesi ID automobila za uredjivanje: ");
    int idedit;
    scanf("%d", &idedit);
    getchar();

    AUTO mobil;
    int id;
    int found = 0;

    while (fscanf(auti, "%d", &id) == 1) {
        fgetc(auti);
        fscanf(auti, "%19s", mobil.marka);
        fscanf(auti, "%19s", mobil.model);
        fscanf(auti, "%14s", mobil.karoserija);
        fscanf(auti, "%9s", mobil.pogon);
        fscanf(auti, "%14s", mobil.motor);
        fscanf(auti, "%14s", mobil.boja);
        fscanf(auti, "%d", &mobil.konji);
        fscanf(auti, "%d", &mobil.newtonm);
        fscanf(auti, "%d", &mobil.kilometraza);
        fscanf(auti, "%d", &mobil.godiste);
        fgetc(auti);

        if (id == idedit) {
            found = 1;
            printf("Izaberi polje za uredjivanje:\n");
            printf("1. Marka\n2. Model\n3. Karoserija\n4. Pogon\n5. Motor\n6. Boja\n7. Konji\n8. Newtonm\n9. Kilometraza\n10. Godiste\n");
            int izborPolja;
            scanf("%d", &izborPolja);
            getchar();

            switch (izborPolja) {
            case 1:
                printf("Unesi novu marku: ");
                scanf("%19s", mobil.marka);
                break;
            case 2:
                printf("Unesi novi model: ");
                scanf("%19s", mobil.model);
                break;
            case 3:
                printf("Unesi novu karoseriju: ");
                scanf("%14s", mobil.karoserija);
                break;
            case 4:
                printf("Unesi novi pogon: ");
                scanf("%9s", mobil.pogon);
                break;
            case 5:
                printf("Unesi novi motor: ");
                scanf("%14s", mobil.motor);
                break;
            case 6:
                printf("Unesi novu boju: ");
                scanf("%14s", mobil.boja);
                break;
            case 7:
                printf("Unesi novi broj konjskih snaga: ");
                scanf("%d", &mobil.konji);
                break;
            case 8:
                printf("Unesi novi broj njutn metara: ");
                scanf("%d", &mobil.newtonm);
                break;
            case 9:
                printf("Unesi novu kilometrazu: ");
                scanf("%d", &mobil.kilometraza);
                break;
            case 10:
                printf("Unesi novo godiste: ");
                scanf("%d", &mobil.godiste);
                break;
            default:
                printf("Nepostojeci izbor.\n");
                break;
            }
        }

        fprintf(temp, "%d\n%19s\n%19s\n%14s\n%9s\n%14s\n%14s\n%d\n%d\n%d\n%d\n",
            id, mobil.marka, mobil.model, mobil.karoserija, mobil.pogon,
            mobil.motor, mobil.boja, mobil.konji, mobil.newtonm, mobil.kilometraza, mobil.godiste);
    }

    fclose(auti);
    fclose(temp);

    if (found) {
        remove("auti.txt");
        rename("temp.txt", "auti.txt");
        printf("Automobil sa ID %d je uredjen.\n", idedit);
    }
    else {
        remove("temp.txt");
        printf("Automobil sa ID %d nije pronadjen.\n", idedit);
    }
}
 
void pretraziAute() {
    FILE* auti = fopen("auti.txt", "r");
    if (auti == NULL) {
        perror("Greska pri otvaranju datoteke");
        return;
    }

    printf("Izaberi kriterij pretrage:\n");
    printf("1. ID\n2. Marka\n");
    int izbor;
    scanf("%d", &izbor);
    getchar();

    AUTO mobil;
    int id;
    char marka[20];
    int found = 0;

    switch (izbor) {
    case 1:
        printf("Unesi ID automobila: ");
        scanf("%d", &id);
        while (fscanf(auti, "%d", &mobil.id) == 1) {
            fgetc(auti);
            fscanf(auti, "%19s", mobil.marka);
            fscanf(auti, "%19s", mobil.model);
            fscanf(auti, "%14s", mobil.karoserija);
            fscanf(auti, "%9s", mobil.pogon);
            fscanf(auti, "%14s", mobil.motor);
            fscanf(auti, "%14s", mobil.boja);
            fscanf(auti, "%d", &mobil.konji);
            fscanf(auti, "%d", &mobil.newtonm);
            fscanf(auti, "%d", &mobil.kilometraza);
            fscanf(auti, "%d", &mobil.godiste);
            fgetc(auti);

            if (mobil.id == id) {
                found = 1;
                printf("Automobil pronadjen:\n");
                printf("ID: %d\nMarka: %s\nModel: %s\nKaroserija: %s\nPogon: %s\nMotor: %s\nBoja: %s\nKonji: %d\nNewtonm: %d\nKilometraza: %d\nGodiste: %d\n",
                    mobil.id, mobil.marka, mobil.model, mobil.karoserija, mobil.pogon,
                    mobil.motor, mobil.boja, mobil.konji, mobil.newtonm, mobil.kilometraza, mobil.godiste);
                break;
            }
        }
        if (!found) {
            printf("Automobil (ID %d) nije pronadjen.\n", id);
        }
        break;

    case 2:
        printf("Unesi marku automobila: ");
        scanf("%19s", marka);
        while (fscanf(auti, "%d", &mobil.id) == 1) {
            fgetc(auti);
            fscanf(auti, "%19s", mobil.marka);
            fscanf(auti, "%19s", mobil.model);
            fscanf(auti, "%14s", mobil.karoserija);
            fscanf(auti, "%9s", mobil.pogon);
            fscanf(auti, "%14s", mobil.motor);
            fscanf(auti, "%14s", mobil.boja);
            fscanf(auti, "%d", &mobil.konji);
            fscanf(auti, "%d", &mobil.newtonm);
            fscanf(auti, "%d", &mobil.kilometraza);
            fscanf(auti, "%d", &mobil.godiste);
            fgetc(auti);

            if (strcmp(mobil.marka, marka) == 0) {
                found = 1;
                printf("Automobil pronadjen:\n");
                printf("ID: %d\nMarka: %s\nModel: %s\nKaroserija: %s\nPogon: %s\nMotor: %s\nBoja: %s\nKonji: %d\nNewtonm: %d\nKilometraza: %d\nGodiste: %d\n",
                    mobil.id, mobil.marka, mobil.model, mobil.karoserija, mobil.pogon,
                    mobil.motor, mobil.boja, mobil.konji, mobil.newtonm, mobil.kilometraza, mobil.godiste);
            }
        }
        if (!found) {
            printf("Automobili marke %s nisu pronadjeni.\n", marka);
        }
        break;

    default:
        printf("Nepostojeci izbor.\n");
        break;
    }

    fclose(auti);
}