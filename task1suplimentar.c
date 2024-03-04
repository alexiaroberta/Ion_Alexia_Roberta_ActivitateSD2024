#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>

//Alexia Ion -> A si I
struct Cantina {
	char* denumire;
	int nrAngajati;
	int nrPreparate;
	float* preturi;
};

struct Cantina citire(struct Cantina* c) {
	if (c != NULL) {
		char denumireCantina[100];
		int nrAngajatiCantina;
		int nrPreparateCantina;
		float pret;
		printf("Introduceti denumirea cantinei: ");
		scanf("%s", denumireCantina);
		(*c).denumire = (char*)malloc(sizeof(char*) * (strlen(denumireCantina) + 1));
		strcpy((*c).denumire, denumireCantina);
		printf("Introduceti nr de angajati: ");
		scanf("%d", &nrAngajatiCantina);
		(*c).nrAngajati = nrAngajatiCantina;
		printf("Introduceti nr de preparate: ");
		scanf("%d", &nrPreparateCantina);
		if (nrPreparateCantina > 0) {
			(*c).nrPreparate = nrPreparateCantina;
			(*c).preturi = (float*)malloc(sizeof(float) * nrPreparateCantina);
			printf("Introduceti preturile: \n");
			for (int i = 0; i < nrPreparateCantina; i++) {
				scanf("%f", &pret);
				(*c).preturi[i] = pret;
			}
		}
		else {
			(*c).nrPreparate = 0;
		}
		return *c;
	}
}

float mediePreturi(struct Cantina* c) {
	if (c != NULL) {
		float suma = 0;
		for (int i = 0; i < (*c).nrPreparate; i++) {
			suma += (*c).preturi[i];
		}
		return suma / (*c).nrPreparate;
	}
}

int modificareNrAngajati(struct Cantina* c, int nrNouAngajati) {
	if (nrNouAngajati > 0) {
		(*c).nrAngajati = nrNouAngajati;
	}
	return (*c).nrAngajati;
}

void afisare(struct Cantina* c) {
	if (c != NULL) {
		printf("Denumire cantina: %s", (*c).denumire);
		printf("\nNr angajati: %d", (*c).nrAngajati);
		printf("\nNr de preparate: %d", (*c).nrPreparate);
		if ((*c).nrPreparate > 0) {
			printf("\nPreturi:\n");
			for (int i = 0; i < (*c).nrPreparate; i++) {
				printf("%.2f ", (*c).preturi[i]);
			}
		}
	}
}

void main() {
	struct Cantina c1;
	struct Cantina* c = &c1;
	citire(c);
	afisare(c);
	printf("\nMedie preturi: %.2f", mediePreturi(c));
	printf("\nDupa modificarea nr de angajati: \n");
	modificareNrAngajati(c, 6);
	afisare(c);
	free(c1.denumire);
	free(c1.preturi);
}