#define _CRT_SECURE_NO_WARNINGS

#include"header.h"
void izborKorisnik() {
	int izbor;
	printf("!Korisnicki Izbornik!\n");
	printf("[1] Pregled svih automobila\n");
	printf("[2] Pretrazivanje automobila\n");
	printf("[3] Sortiranje automobila (cijena - UZLAZNO)\n");
	printf("[4] Sortiranje automobila (cijena - SILAZNO)\n");
	printf("[5] Sortiranje automobila (kilometraza - UZLAZNO)\n");
	printf("[6] Sortiranje automobila (kilometraza - SILAZNO)\n");
	printf("[7] Sortiranje automobila (godiste - UZLAZNO)\n");
	printf("[8] Sortiranje automobila (godiste - SILAZNO)\n");
	printf("[9] Sortiranje automobila (snaga- UZLAZNO)\n");
	printf("[10] Sortiranje automobila (snaga- SILAZNO)\n");
	printf("[11] Pretraga automobila po obliku karoserije\n");
	printf("[12] Kupovina automobila\n");
	printf("[13] Izlaz iz programa\n");
	scanf("%d", &izbor);
	if (izbor < 1 && izbor>4) {
		printf("Krivi broj unesen!");
		return izborKorisnik();
	}
	switch (izbor) {
	case 1:
		pregledAutomobila();
		break;
	case 2:
		pretraziAute();
		break;
	case 13:
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