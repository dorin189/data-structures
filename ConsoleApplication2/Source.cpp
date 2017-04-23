#include <iostream>

struct fruct {
	char* denumire;
	float gramaj;
	int nrZile;
};


void afisareFruct(fruct mar) {
	printf("fructul %s are un %5.2f gramaj si %d \n", mar.denumire, mar.gramaj, mar.nrZile);
}

void freeMemory(fruct mar) {
	free(mar.denumire);
}




void pointer(int *b) {
	*b = 3;
}

fruct *citireVectorFructe(int nr) {
	fruct *fructe;
	fructe = (fruct*)malloc(sizeof(fruct)*(nr));

	for (int i = 0; i < nr; i++) {
		printf("Denumire: ");
		char aux[20];
		scanf("%s", &aux);
		fructe[i].denumire = (char*)malloc(sizeof(char)*(strlen(aux) + 1));
		strcpy(fructe[i].denumire, aux);
		printf("Gramaj: ");
		scanf("%f", &fructe[i].gramaj);
		printf("Nr. zile: ");
		scanf("%d", &fructe[i].nrZile);
	}

	return fructe;

}

void afisareVectorFructe(fruct *fruct, int nr) {
	for (int i = 0; i < nr; i++) {
		printf("%s %5.2f %d \n", fruct[i].denumire, fruct[i].gramaj, fruct[i].nrZile);
	}
}

void freeVector(fruct *fructe, int nr) {
	for (int i = 0; i < nr; i++) {
		free(fructe[i].denumire);
	}
	free(fructe);
}

void main() {
	/*fruct mar;
	mar.denumire = (char*)malloc(sizeof(char)*(strlen("mar") + 1));
	strcpy(mar.denumire, "mar");
	mar.gramaj = 100;
	mar.nrZile = 3;
	afisareFruct(mar);
	freeMemory(mar);*/
	//int c = 2;
	//int *b = &c;
	//*b = 4;
	//

	//printf("ddssdsd %d- cuukyu %d buului %d \n\n", &c, *(b), &b);

	//int a = 2;
	//pointer(&a);
	//printf("%d", a);
	//
	//const int nrFructe = 10;
	//fruct fructe[nrFructe];
	//
	//for (int i = 0; i < nrFructe;i++) {
	//	fructe[i].denumire = (char*)malloc(sizeof(char)*(strlen("mar") + 1));
	//	strcpy(fructe[i].denumire, "mar");
	//	fructe[i].gramaj = 10;
	//	fructe[i].nrZile = 4;
	//}

	//afisareVectorFructe(fructe, nrFructe);

	const int nrFructe = 3;
	fruct *fructeDinamic;

	fructeDinamic = citireVectorFructe(nrFructe);
	afisareVectorFructe(fructeDinamic, nrFructe);
	freeVector(fructeDinamic, nrFructe);
}
