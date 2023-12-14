/*
* Paulo Alexandre Rodrigues da Costa
* a29851@alunos.ipca.pt
* 22/11/2023
* 
* Trabalho Pr�tico 1
* 
* UC: PI
*/

#include "Header.h"
#include <stdio.h>

int main() {
	Paciente pacientes[N];
	Plano planos[N];
	Dieta dietas[N];
	Plano detalhes[N];

	ImportarPacientes(pacientes, "Pacientes1.csv");

	ImportarPlanos(planos, "Planos1.csv", pacientes);

	DietaPaciente(dietas, "Dietas1.csv");

	/*printf("Existem %d pacientes que ultrapassaram o limite m�ximo de calorias numa refei��o.\n", NumPacientesCalMais(planos, 3, dietas, 4));*/

	// Supondo que voc� j� tenha importado os planos nutricionais usando a fun��o ImportarPlanos

	ListarPlanoPorRefeicao(planos,detalhes,3,1,"pequeno almo�o");
		printf("Paciente: %d\n",detalhes[0].numPaciente);
		printf("Refeicao: %s\n", detalhes[0].refeicao);
		printf("Data: %s\n", detalhes[0].data);
		printf("Minimo Calorias: %d\n", detalhes[0].minCal);
		printf("Maximo Calorias: %d\n", detalhes[0].maxCal);
}