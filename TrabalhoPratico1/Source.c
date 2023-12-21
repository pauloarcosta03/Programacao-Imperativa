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
	MediaCalorias mediacal[N];

	ImportarPacientes(pacientes, "Pacientes1.csv");

	ImportarPlanos(planos, "Planos1.csv", pacientes);

	DietaPaciente(dietas, "Dietas1.csv");

	int result = NumPacientesPassaLim(dietas, 4, 119, dietas[2].data);

	result;

	Paciente pacientesOrd[N];

	ListaPacientesCalMais(planos, 3, dietas, 4, pacientes, 3, pacientesOrd);

	pacientesOrd;
}