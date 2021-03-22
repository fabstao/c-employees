/**************************************************
* Fabian Salamanca (C) 2020                       *
* fsalaman@gmail.com                              *
* employee struct needs to be defined             *
**************************************************/

typedef struct {
	int id;
	char name[100];
	char SSN[15];
	char TaxID[15];
} employee;


void checkferror(FILE *fptr) {
	if( fptr == NULL ) {
		perror("ERROR: ");
		exit(1);
	}
	if(ferror(fptr)) {
		printf("\nERROR: File I/O error\n");
		exit(1);
	}
}

void fsaveemp(employee *saveemp, char *nombre) {
	FILE *fptr;
	int tamano=sizeof(*saveemp);
	fptr=fopen(nombre,"ab");
	checkferror(fptr);
	fwrite(saveemp,tamano,1,fptr);
	checkferror(fptr);
	fclose(fptr);
}

employee* fbread(char *nombre, int *j) {
	FILE *fptr;
	employee leeremp = { };
	employee *aleeremp=malloc(sizeof(leeremp));
	size_t tamano=sizeof(leeremp);
	fptr=fopen(nombre,"rb");
	checkferror(fptr);
	int i=0;
	printf("\nLeyendo archivo:\n");
	while(fread(&leeremp,tamano,1,fptr)) {
		checkferror(fptr);
		aleeremp = realloc(aleeremp,(i+1)*sizeof(leeremp));
		aleeremp[i] = leeremp;	
		//printf("Empleado: %i : %s |  %s | %s\n",aleeremp[i].id,aleeremp[i].name,aleeremp[i].SSN,aleeremp[i].TaxID);
		i++;
	}
	fclose(fptr);
	*j=i;
	return aleeremp;
}
