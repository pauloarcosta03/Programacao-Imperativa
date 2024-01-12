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
    MediaCalorias mediacal[N];

    ImportarPacientes(pacientes, "Pacientes1.csv");

    ImportarPlanos(planos, "Planos1.csv", pacientes);

    DietaPaciente(dietas, "Dietas1.csv");

    /*int result = NumPacientesPassaLim(dietas, 4, 119, dietas[2].data);

    result;

    Paciente pacientesOrd[N];

    ListaPacientesCalMais(planos, 3, dietas, 4, pacientes, 3, pacientesOrd);

    pacientesOrd;

    Plano detalhes[N];
    ListarPlanoPorRefeicao(planos, detalhes, 3, 1, PequenoAlmoco, ConverteDataTimet("1/1/2023"), ConverteDataTimet("2/1/2023"));

    detalhes;

    MediaCalorias mc[N];
    calcularMediaCalorias(dietas, 4, pacientes, 3, PequenoAlmoco, mc, ConverteDataTimet("1/1/2023"), ConverteDataTimet("2/1/2023"));
    mc;*/

    TabelaDietas(dietas, 4, pacientes, 3, planos, 3);
}