#define _CRT_SECURE_NO_WARNINGS
#include"header.h"

int adminPrijava(ADMIN* admin) {
	ADMIN prijava;
	printf("Unesi korisnicko ime: ");
	scanf("%49s", prijava.ime); 
	printf("Unesi lozinku: ");
	scanf("%49s", prijava.lozinka); 

	if (strcmp(prijava.ime, admin->ime) == 0 && strcmp(prijava.lozinka, admin->lozinka) == 0) {
		return 1;
	}
	else {
		return 0;
	}
}

int izborAdmin() {
	srand((unsigned)time(NULL));
	size_t pokusaji = 0;
	ADMIN admin = { "Luka2502", "123321" };

	while (adminPrijava(&admin) == 0 && pokusaji < 3) {
		pokusaji++;
		printf("Pogresno ime ili lozinka, pokusajte ponovno!!\n");
		if (pokusaji == 3) {
			printf("Iskoristili ste sve pokusaje, pokusajte ponovno kasnije\n");
			return 1;
		}
	}

	if (pokusaji < 3) {
		printf("Uspjesna prijava, dobrodosao %s\n", admin.ime);
	}
	int izbor;

	printf("ADMINISTRATORSKI IZBORNIK\n");
	printf("[1] Dodavanje Automobila\n");
	printf("[2] Brisanje Automobila\n");
	printf("[3] Uredjivanje Automobila\n");
	printf("[4] Izlaz iz Programa\n");
	scanf("%d", &izbor);

	switch (izbor) {
		FILE* auti = NULL;
		static int novi_id = 100000;
		AUTO mobil = { NULL };
	case 1:
		auti = fopen("auti.txt", "a+"); 
		if (auti == NULL) {
			perror("Greska pri otvaranju datoteke");
			return 1;
		}
		int tren_id = 0;
		while (fscanf(auti, "%d", &tren_id) == 1) {
			// Skakanje preko ostatka reda u datoteci
			char buffer[256];
			fgets(buffer, sizeof(buffer), auti);
		}
		
		novi_id = (tren_id > 0) ? tren_id + 1 : novi_id;

		mobil.id = novi_id;

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

		fprintf(auti, "%d\n%19s\n%19s\n%14s\n%9s\n%14s\n%14s\n%d\n%d\n%d\n%d\n",
			mobil.id, mobil.marka, mobil.model, mobil.karoserija, mobil.pogon,
			mobil.motor, mobil.boja, mobil.konji, mobil.newtonm, mobil.kilometraza, mobil.godiste);

		fclose(auti);
		novi_id++;
		break;
		int sifra;
	case 2:
		printf("Unesi ID automobila za brisanje: ");
		int iddel;
		scanf("%d", &iddel);
		getchar(); 

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
		break;
	case 3:
		printf("Unesi ID automobila za uredjivanje: ");
		int idedit;
		scanf("%d", &idedit);
		getchar(); 

		temp = fopen("temp.txt", "w"); 
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
		break;
	case 4:
		izbor = krajPrograma();
		if (izbor == 0) {
			printf("Kraj programa, stisnite bilo koju tipku");
			_getch();
		}
		else {
			printf("Za povratak na pocetni izbornik pritisnite bilo koju tipku");
			_getch();
			izborGlavni();
		}
		break;

	default:
		printf("Nepostojeci izbor!");
		break;
		return 0;
	}
}