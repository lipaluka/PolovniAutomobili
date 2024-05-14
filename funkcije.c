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

void readString(char* prompt, char* buffer, int size) {
    printf("%s", prompt);
    if (fgets(buffer, size, stdin)) {
        size_t len = strlen(buffer);
        if (len > 0 && buffer[len - 1] == '\n') {
            buffer[len - 1] = '\0';
        }
    }
}