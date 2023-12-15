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
	Plano planos[N];
	Dieta dietas[N];

	int result = ImportarPacientes(pacientes, "Pacientes1.csv");

	result = ImportarPlanos(planos, "Planos1.csv", pacientes);

	result = DietaPaciente(dietas, "Dietas1.csv");

	Paciente pacientesOrd[N];

	result = ListaPacientesCalMais(planos, 3, dietas, 4, pacientes, 3, pacientesOrd);

	pacientes;

}