#define _CRT_SECURE_NO_WARNINGS

#include"header.h"
void izborKorisnik() {
	int izbor;
	printf("!Korisnicki Izbornik!\n");
	printf("[1] Pregled svih automobila\n");
	printf("[2] Pretrazivanje automobila\n");
	printf("[3] Sortiranje automobila (kilometraza - UZLAZNO)\n");
	printf("[4] Sortiranje automobila (kilometraza - SILAZNO)\n");
	printf("[5] Sortiranje automobila (godiste - UZLAZNO)\n");
	printf("[6] Sortiranje automobila (godiste - SILAZNO)\n");
	printf("[7] Sortiranje automobila (snaga- UZLAZNO)\n");
	printf("[8] Sortiranje automobila (snaga- SILAZNO)\n");
	printf("[9] Pretraga automobila po obliku karoserije\n");
	printf("[10] Kupovina automobila\n");
	printf("[11] Izlaz iz programa\n");
	scanf("%d", &izbor);
	if (izbor < 1 && izbor>4) {
		printf("Krivi broj unesen!");
		return izborKorisnik();
	}
	switch (izbor) {
		FILE* auti = NULL;
		AUTO* mobil = { NULL };
	case 1:
		auti = fopen("auti.txt", "r");
		if (auti == NULL) {
			perror("Greska pri otvaranju datoteke");
			return;
		}
		pregledAutomobila();
		fclose(auti);
		break;
	case 2:
		auti = fopen("auti.txt", "r");
		if (auti == NULL) {
			perror("Greska pri otvaranju datoteke");
			return;
		}
		pretraziAute();
		fclose(auti);
		break;
		int broj;
	case 3:
		scanAuto(&mobil, &broj);
		printf("Automobili sortirani po kilometrazi (UZLAZNO)\n");
		sortirajKilometrazaUzlazno(mobil, broj);
		printAuto(mobil, broj);
		free(mobil);
		break;
	case 4:
		scanAuto(&mobil, &broj);
		printf("Automobili sortirani po kilometrazi (SILAZNO)\n");
		sortirajKilometrazuSilazno(mobil, broj);
		printAuto(mobil, broj);
		free(mobil);
	case 11:
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
	}


}