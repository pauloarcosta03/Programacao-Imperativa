/*
* Paulo Alexandre Rodrigues da Costa
* a29851@alunos.ipca.pt
* 22/11/2023
* 
* Trabalho Prático 1
* 
* UC: PI
*/

#include "Header.h"
#include <stdio.h>

int main() {
	
	Paciente pacientes[N];

	int result = ImportarPacientes(pacientes, "Pacientes1.csv");

	printf("%s\n", pacientes[1].numPaciente);
	
	pacientes;
	
	/*-------------------------------------------*/
	Dieta Dietas[N];

	int result2 = DietaPaciente(Dietas, "InfoPacientes.csv");

	printf("%s\n", Dietas[1].numPaciente);

	Dietas;

}