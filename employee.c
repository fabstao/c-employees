/**************************************************
* Fabian Salamanca (C) 2020                       *
* fsalaman@gmail.com                              *
* Read and write employee struct to binary file   *
**************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "binaryfio.h"

void showemp(employee *emp, int *j);

int main(int argc, char *argv[]){
	if(argc < 4) {
		printf("\nERROR: Uso: %s <Nombre> <NSS> <RFC>\n", argv[0]);
		exit(1);
	}
	else {
		char *nombre="employees.fabdb";
		printf("\nLeyendo base de datos de empleados\n");
		int *j=malloc(sizeof(int));
		fbread(nombre,j);
		char *name=malloc(sizeof(char)*100);
		char *SSN=malloc(sizeof(char)*15);
		char *TaxID=malloc(sizeof(char)*15);
		//employee miemp = { tamn+1, name, SSN, TaxID };
		employee miemp;
		miemp.id = 1 + *j;
 		strcpy(miemp.name,argv[1]);
        strcpy(miemp.SSN,argv[2]);
		strcpy(miemp.TaxID,argv[3]);
		printf("\nGuardando datos de empleado\n");
		fsaveemp(&miemp,nombre);
		employee *todos = fbread(nombre,j);
		showemp(todos,j);
		free(name);
		free(SSN);
		free(TaxID);
		free(todos);
		return 0;
	}
}

void showemp(employee *emp, int *j) {
	printf("Empleados registrados:\n");
	printf("______________________\n\n");
	for(int i=0; i<*j;i++) {
		printf("Empleado %d : %s | %s | %s\n",emp[i].id,emp[i].name,emp[i].SSN,emp[i].TaxID);
	}
	printf("______________________\n\n");
}
