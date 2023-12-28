/*
* Paulo Alexandre Rodrigues da Costa
* a29851@alunos.ipca.pt
* 
* Afonso Teixeira Ferreira
* a27981@alunos.ipca.pt
* 
* David João Martins Lopes
* a26017@alunos.ipca.pt
* 
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

	ImportarPacientes(pacientes, "Pacientes1.csv");

	ImportarPlanos(planos, "Planos1.csv", pacientes);

	DietaPaciente(dietas, "Dietas1.csv");

	int result = NumPacientesPassaLim(dietas, 4, pacientes, 4, 100, dietas[0].data);

	result;
}