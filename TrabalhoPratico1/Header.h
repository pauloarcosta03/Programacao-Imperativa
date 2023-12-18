/*
* Paulo Alexandre Rodrigues da Costa
* a29851@alunos.ipca.pt
* 22/11/2023
*
* Trabalho Pr�tico 1
*
* UC: PI
*/
#pragma once

#include <stdbool.h>
#include <time.h>

#define N 25
#define M 50

typedef enum Refeicao {
	PequenoAlmoco,
	Almoco,
	Jantar
} Refeicao;

// Struct do plano nutricional
typedef struct Plano {
	int numPaciente;
	Refeicao refeicao;
	int minCal;
	int maxCal;
	time_t dataInicio;
	time_t dataFim;
} Plano;

typedef struct Dieta {
	int numPaciente;
	char data[M];
	Refeicao refeicao;
	char ali[M];
	int cal;
	//time_t data;
} Dieta;

// struct da informa��o do Paciente
typedef struct Paciente {
	int numPaciente;
	char nome[N];
	long tel;
	Plano planos[N];
} Paciente;

//struct das medias das calorias dos pacientes
typedef struct MediaCalorias {
	int numPaciente;
	float mediaCal;
	Refeicao refeicao;
} MediaCalorias;


//Importa pacientes de um ficheiro CSV
// Importa pacientes de um ficheiro CSV
int ImportarPacientes(Paciente pacientes[], char filename[]);

// Importa planos nutricionais de um ficheiro CSV
int ImportarPlanos(Plano planos[], char filename[], Paciente pacientes[]);

// Importa dietas de um ficheiro CSV
int DietaPaciente(Dieta dietas[], char filename[]);

// Conta o n� de pacientes que ultrapassaram o limite de calorias
int NumPacientesCalMais(Plano planos[], int tamPlanos, Dieta dietas[], int tamDietas);

// Lista o Plano por refeicao de um paciente
int ListarPlanoPorRefeicao(Plano planos[], Plano detalhes[], int tamPlanos, int numPaciente, Refeicao refeicao);

int calcularMediaCalorias(Dieta dietas[], int numDietas, Paciente pacientes[], int numPacientes, Refeicao refeicao, MediaCalorias mc[]);

// Conta o n� de pacientes que ultrapassaram um limite de calorias
int NumPacientesPassaLim(Dieta dietas[], int tamDietas, int calMax, char dataMin[], char dataMax);

// Verifica se um paciente com o mesmo n� existe num array
bool ExisteNmrPaciente(Paciente pacientes[], int tamPacientes, int numPaciente);

// Lista por ordem decrescente os pacientes que ultrapassaram os limites do plano
int ListaPacientesCalMais(Plano planos[], int tamPlanos, Dieta dietas[], int tamDietas, Paciente pacientes[], int tamPacientes, Paciente arrayOrdPacientes[]);