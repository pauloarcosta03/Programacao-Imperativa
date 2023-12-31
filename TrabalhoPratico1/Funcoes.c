/*
* Paulo Alexandre Rodrigues da Costa
* a29851@alunos.ipca.pt
* 
* Afonso Teixeira Ferreira
* a27981@alunos.ipca.pt
* 
* David Jo�o Martins Lopes
* a26017@alunos.ipca.pt
* 
* 22/11/2023
*
* Implementa��o de todas as fun��es do Trabalho Pr�tico 1
*
* UC: PI
*/

#pragma warning (disable: 4996)

#include <stdio.h>
#include <string.h>
#include "Header.h"

// T�PICO 1
#pragma region IMPORTA��ES
/// <summary>
/// Importa pacientes de um ficheiro CSV
/// </summary>
/// <param name="pacientes"></param>
/// <param name="filename"></param>
/// <returns></returns>
int ImportarPacientes(Paciente pacientes[], char filename[]) {
	FILE* fp;
	fp = fopen(filename, "r");
	if (fp == NULL) return 0;

	int i = 0;
	while (1)
	{
		fscanf(fp, "%d;%[^;];%ld\n", &pacientes[i].numPaciente, pacientes[i].nome, &pacientes[i].tel);
		if (feof(fp)) break;
		i++;
	}
	fclose(fp);
	return 1;
}

/// <summary>
/// Importa dieta dos pacientes de um ficheiro CSV
/// </summary>
/// <param name="dieta"></param>
/// <param name="filename"></param>
/// <returns></returns>
int DietaPaciente(Dieta dietas[], char filename[]) {
	FILE* fp;
	fp = fopen(filename, "r");
	if (fp == NULL) return 0;

	char dataString[N];

	struct tm data = { 0 };

	int i = 0;
	while (1)
	{
		fscanf(fp, "%d;%[^;];%d;%[^;];%d", &dietas[i].numPaciente, dataString, &dietas[i].refeicao, dietas[i].ali, &dietas[i].cal);

		//converte as strings struct tm
		sscanf(dataString, "%d/%d/%d", &data.tm_mday, &data.tm_mon, &data.tm_year);

		//ajusta os valores para os valores esperados na struct tm
		data.tm_mon -= 1; //Para o m�s ficar 0-11
		data.tm_year -= 1900; //Para o ano come�ar em 1900

		//converter para a vari�vel time_t
		dietas[i].data = mktime(&data);

		if (feof(fp)) break;
		i++;
	}
	fclose(fp);
	return 1;
}

/// <summary>
/// Importa planos nutricionais de um ficheiro CSV
/// </summary>
/// <param name="planos"></param>
/// <param name="filename"></param>
/// <param name="pacientes"></param>
/// <returns></returns>
int ImportarPlanos(Plano planos[], char filename[], Paciente pacientes[]) {
	FILE* fp;
	fp = fopen(filename, "r");
	if (fp == NULL) return 0;

	//strings que ser�o recebidas para depois converter para time_t
	char dataInicioString[N];
	char dataFimString[N];

	//structs tm auxiliares para converter para time_t
	struct tm dataInicio = {0};
	struct tm dataFim = {0};

	int i = 0;
	while (1)
	{
		
		fscanf(fp, "%d;%[^;];%[^;];%d;%d;%d\n", &planos[i].numPaciente, dataInicioString, dataFimString, &planos[i].refeicao, &planos[i].minCal, &planos[i].maxCal);

		//converte as strings struct tm
		sscanf(dataInicioString, "%d/%d/%d", &dataInicio.tm_mday, &dataInicio.tm_mon, &dataInicio.tm_year);
		sscanf(dataFimString, "%d/%d/%d", &dataFim.tm_mday, &dataFim.tm_mon, &dataFim.tm_year);

		//ajusta os valores para os valores esperados na struct tm
		dataInicio.tm_mon -= 1; //Para o m�s ficar 0-11
		dataInicio.tm_year -= 1900; //Para o ano come�ar em 1900

		dataFim.tm_mon -= 1; //Para o m�s ficar 0-11
		dataFim.tm_year -= 1900; //Para o ano come�ar em 1900

		//converter para a vari�vel time_t
		planos[i].dataInicio = mktime(&dataInicio);
		planos[i].dataFim = mktime(&dataFim);

		//AssociaPlano(planos[i], pacientes);
		if (feof(fp)) break;
		i++;
	}
	fclose(fp);
	return 1;
}
#pragma endregion

#pragma region CONVERS�ES
/// <summary>
/// Converte time_t para string
/// </summary>
/// <param name="data"></param>
/// <param name="dataString"></param>
/// <param name="tamString"></param>
/// <returns></returns>
int ConverteDataString(time_t data, char dataString[], int tamString) {

	//converte data numa struct
	struct tm *dataStruct = localtime(&data);

	//traduz a struct numa string
	if(strftime(dataString, tamString, "%d/%m/%Y", dataStruct) == 0) return 0;

	return 1;
}

/// <summary>
/// Converte string para time_t
/// </summary>
/// <param name="data"></param>
/// <param name="dataString"></param>
/// <param name="tamString"></param>
/// <returns></returns>
time_t ConverteDataTimet(char dataString[]) {

	//converte data numa struct
	struct tm dataStruct = { 0 };

	time_t data;

	//converte as strings struct tm
	sscanf(dataString, "%d/%d/%d", &dataStruct.tm_mday, &dataStruct.tm_mon, &dataStruct.tm_year);

	//ajusta os valores para os valores esperados na struct tm
	dataStruct.tm_mon -= 1; //Para o m�s ficar 0-11
	dataStruct.tm_year -= 1900; //Para o ano come�ar em 1900

	//converter para a vari�vel time_t
	data = mktime(&dataStruct);

	return data;
}

/// <summary>
/// Converte enum refei��o para string
/// </summary>
/// <param name="refeicao"></param>
/// <param name="refeicaoString"></param>
/// <returns></returns>
int ConverteRefeicaoString(int refeicao, char refeicaoString[]) {
	if (refeicao == 0) strcpy(refeicaoString, "PA");
	if (refeicao == 1) strcpy(refeicaoString, "A");
	if (refeicao == 2) strcpy(refeicaoString, "J");

	return 1;
}
#pragma endregion

//T�PICO 2

/// <summary>
/// Conta o n� de pacientes que ultrapassaram um limite de calorias num determinado dia
/// </summary>
/// <param name="dietas"></param>
/// <param name="tamDietas"></param>
/// <param name="calMax"></param>
/// <param name="dataDieta"></param>
/// <returns></returns>
int NumPacientesPassaLim(Dieta dietas[], int tamDietas, Paciente pacientes[], int tamPacientes, int calMax, time_t dataDieta) {
	int pacientesCalMais = 0;
	int calPaciente = 0;
	//Corre todas as dietas de um paciente
	for (int i = 0; i < tamPacientes; i++)
	{
		calPaciente = 0;

		for (int j = 0; j < tamDietas; j++)
		{
			if (dietas[j].numPaciente == pacientes[i].numPaciente && dietas[i].data == dataDieta)
			{
				calPaciente += dietas[j].cal;
			}
		}
		if (calPaciente > calMax) pacientesCalMais++;
	}
	return pacientesCalMais;
}

//T�PICO 3

/// <summary>
/// Conta o n� de pacientes que ultrapassaram o limite de calorias do plano
/// </summary>
/// <param name="planos"></param>
/// <param name="tamPlanos"></param>
/// <param name="dietas"></param>
/// <param name="tamDietas"></param>
/// <returns></returns>
int ListaPacientesCalMais(Plano planos[], int tamPlanos, Dieta dietas[], int tamDietas, Paciente pacientes[], int tamPacientes, Paciente arrayOrdPacientes[]) {
	int pacientesCalMais = 0;

	int posArray = 0;

	int calPaciente = 0;
	
	//Corre os planos
	for (int i = 0; i < tamPlanos; i++)
	{
		calPaciente = 0;
		
		//Corre as dietas (para somar todas as calorias)
		for (int j = 0; j < tamDietas; j++)
		{
			if (planos[i].numPaciente == dietas[j].numPaciente && planos[i].refeicao == dietas[j].refeicao && planos[i].dataInicio <= dietas[j].data && planos[i].dataFim >= dietas[j].data)
			{
				calPaciente = calPaciente + dietas[j].cal;
			}
		}


		//corre os pacientes ignorando os duplicados(para guardar o paciente certo no array)
		if ((calPaciente > planos[i].maxCal || calPaciente < planos[i].minCal) && calPaciente != 0 && ExisteNmrPaciente(pacientes, tamPacientes, planos[i].numPaciente)) {
			for (int p = 0; p < tamPacientes; p++)
			{
				if (planos[i].numPaciente == pacientes[p].numPaciente && !ExisteNmrPaciente(arrayOrdPacientes, posArray+1, planos[i].numPaciente)) {
					arrayOrdPacientes[posArray] = pacientes[p];
					posArray++;
					break;
				}
			}
		}
	}

	//ordena por ordem decrescente
	for (int i = 0; i < posArray + 1; i++)
	{
		for (int j = 0; j < tamPacientes; j++) {
			if (arrayOrdPacientes[i].numPaciente > arrayOrdPacientes[j].numPaciente)
			{
				Paciente aux = arrayOrdPacientes[i];
				arrayOrdPacientes[i] = arrayOrdPacientes[j];
				arrayOrdPacientes[j] = aux;
			}
		}
	}

	//pacientes;
	return pacientesCalMais;
}

/// <summary>
/// Verifica se j� existe um paciente com o mesmo n�
/// </summary>
/// <param name="pacientes"></param>
/// <param name="tamPacientes"></param>
/// <param name="numPaciente"></param>
/// <returns></returns>
bool ExisteNmrPaciente(Paciente pacientes[], int tamPacientes, int numPaciente) {

	for (int i = 0; i < tamPacientes; i++)
	{
		if (pacientes[i].numPaciente == numPaciente) return true;
	}

	return false;
}

/// <summary>
/// Adiciona o plano a um paciente
/// </summary>
/// <param name="plano"></param>
/// <param name="pacientes"></param>
int AssociaPlano(Plano plano, Paciente pacientes[]) {
	for (int i = 0; i < N; i++)
	{
		if(plano.numPaciente == pacientes[i].numPaciente) {
			//Procura um sitio vazio no array de planos para preencher com um plano novo
			for (int j = 0; j < N; j++)
			{
				if (pacientes[i].planos[j].numPaciente <= 0)
				{
					pacientes[i].planos[j] = plano;
					return 1;
				}
			}
			return 0;
		}
	}
	return 0;
}

//T�PICO 4

/// <summary>
/// Lista plano por refeicao
/// </summary>
/// <param name="planos"></param>
/// <param name="detalhes"></param>
/// <param name="tamPlanos"></param>
/// <param name="numPaciente"></param>
/// <param name="refeicao"></param>
/// <param name="dataMin"></param>
/// <param name="dataMax"></param>
/// <returns></returns>
int ListarPlanoPorRefeicao(Plano planos[], Plano detalhes[], int tamPlanos, int numPaciente, Refeicao refeicao, time_t dataMin, time_t dataMax) {
	int contaDetalhes = 0;
	for (int i = 0; i < tamPlanos; i++) {
		if (planos[i].numPaciente == numPaciente && planos[i].refeicao == refeicao && dataMin <= planos[i].dataInicio && dataMax >= planos[i].dataFim) {
			detalhes[contaDetalhes].numPaciente = planos[i].numPaciente;
			detalhes[contaDetalhes].dataInicio = planos[i].dataInicio;
			detalhes[contaDetalhes].dataFim = planos[i].dataFim;
			detalhes[contaDetalhes].minCal = planos[i].minCal;
			detalhes[contaDetalhes].maxCal = planos[i].maxCal;
			detalhes[contaDetalhes].refeicao = planos[i].refeicao;
			contaDetalhes++;
		}
	}return 1;

}

//T�PICO 5

/// <summary>
/// Calcula media das calorias de uma refei��o
/// </summary>
/// <param name="dietas"></param>
/// <param name="numDietas"></param>
/// <param name="pacientes"></param>
/// <param name="numPacientes"></param>
/// <param name="refeicao"></param>
/// <param name="mc"></param>
/// <param name="dataMin"></param>
/// <param name="dataMax"></param>
/// <returns></returns>
int calcularMediaCalorias(Dieta dietas[], int numDietas, Paciente pacientes[], int numPacientes, Refeicao refeicao, MediaCalorias mc[], time_t dataMin, time_t dataMax) {
	double somaCalorias = 0;
	int numRefeicoes = 0;

	int posMedia = 0;

	for (int j = 0; j < numPacientes; j++)
	{

		// Calcule a soma das calorias para a refei��o e paciente espec�ficos
		for (int i = 0; i < numDietas; i++) {
			if (dietas[i].numPaciente == pacientes[j].numPaciente && dietas[i].refeicao == refeicao && dietas[i].data >= dataMin && dietas[i].data <= dataMax) {
				somaCalorias += dietas[i].cal;
				numRefeicoes++;
			}
		}

		// Calcule a m�dia de calorias se houver pelo menos uma refei��o
		if (numRefeicoes > 0) {
			mc[posMedia].numPaciente = pacientes[j].numPaciente;
			mc[posMedia].mediaCal = somaCalorias/numRefeicoes;
			mc[posMedia].refeicao = refeicao;

			numRefeicoes = 0;
			posMedia++;
		}
	}

}

//T�PICO 6

/// <summary>
/// Desenha a tabela para cada dieta com plano associado registada (FULLSCREEN)
/// </summary>
/// <param name="dietas"></param>
/// <param name="tamDietas"></param>
/// <param name="pacientes"></param>
/// <param name="tamPacientes"></param>
/// <param name="planos"></param>
/// <param name="tamPlanos"></param>
void TabelaDietas(Dieta dietas[], int tamDietas, Paciente pacientes[], int tamPacientes, Plano planos[], int tamPlanos) {

	Paciente pacienteTemp;
	Plano planoTemp;
	int caloriasRefeicao = 0;

	char refeicao[N];
	char dataInicio[N];
	char dataFim[N];

	bool saltarDieta = false;
	bool temPlano = false;

	//Escreve o cabe�alho da tabela
	printf("+---------------------------------------------------------------------------------------------------------------------------------------------------------------+\n");
	printf("|	NP	|	Paciente	|	Refeicao	|	Data Inicio	|	Data Fim	|	Min	|	Max	|	Consumo	|\n");
	printf("|---------------------------------------------------------------------------------------------------------------------------------------------------------------|\n");


	for (int i = 0; i < tamDietas; i++)
	{
		caloriasRefeicao += dietas[i].cal;

		//Se existir outra dieta no mesmo dia e na mesma refeicao, incrementa calorias
		for (int j = 0; j < tamDietas; j++)
		{
			if (dietas[i].numPaciente == dietas[j].numPaciente && dietas[i].refeicao == dietas[j].refeicao && dietas[i].data == dietas[j].data)
			{
				if (i == j) continue;

				//Se j� escreveu esta linha, salta para a pr�xima
				if (i > j) {
					saltarDieta = true;
					break;
				}
				caloriasRefeicao += dietas[j].cal;
			}
		}

		//Procura as infos do paciente na dieta atual
		for (int j = 0; j < tamPacientes; j++)
		{
			if (dietas[i].numPaciente == pacientes[j].numPaciente) {
				pacienteTemp = pacientes[j];
				break;
			}
		}

		temPlano = false;
		//Procura as infos do plano a que corresponde a dieta
		for (int j = 0; j < tamPlanos; j++)
		{
			if (dietas[i].numPaciente == planos[j].numPaciente && dietas[i].refeicao == planos[j].refeicao && planos[j].dataInicio <= dietas[i].data && planos[j].dataFim >= dietas[i].data) {
				planoTemp = planos[j];
				temPlano = true;
				break;
			} 
		}

		// salta para a proxima linha caso j� tenha escrito esta dieta ou a dieta n�o tenha plano associado
		if (saltarDieta || !temPlano) {
			saltarDieta = false;
			caloriasRefeicao = 0;
			continue;
		}

		// converte a refei��o para string para ser mostrada
		ConverteRefeicaoString(dietas[i].refeicao, refeicao);

		//organiza as datas para dia/mes/ano
		ConverteDataString(planoTemp.dataInicio, dataInicio, N);

		ConverteDataString(planoTemp.dataFim, dataFim, N);

		printf("|	%d	|	%s		|	%s		|	%s	|	%s	|	%d	|	%d	|	%d	|\n", dietas[i].numPaciente, pacienteTemp.nome, refeicao, dataInicio, dataFim, planoTemp.minCal, planoTemp.maxCal, caloriasRefeicao);
		caloriasRefeicao = 0;
	}
	printf("+---------------------------------------------------------------------------------------------------------------------------------------------------------------+\n");
}