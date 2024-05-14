#define _CRT_SECURE_NO_WARNINGS
#include"header.h"

void izborGlavni() {
	int izbor;
	do {
		printf("Dobrodosli u aplikaciju!!\n");
		printf("1. Korisnicki izbornik.\n");
		printf("2. Administratorski izbornik.\n");
		printf("3. IZLAZ IZ PROGRAMA.\n");
		printf("/////////////////////////////////\n");

		scanf("%d", &izbor);
		if (izbor < 1 || izbor > 3) {
			printf("Greska pri unosu!");
		}
	
	} while (izbor < 1 || izbor>3);
	switch (izbor) {
	case 1:
		izborKorisnik();
		break;
	case 2:
		izborAdmin();
		break;
	case 3:
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

