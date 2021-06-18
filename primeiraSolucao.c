#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define tamanho 18

typedef struct Pauta{
    int idDeEstudante;
    int ano;
    char disciplina[191];
    double nota;
}Pauta;

/**
 * Estrutura basica de um estudante
 * */
typedef struct Estudante
{
    int id;
    char nome[191];
    char apelido[191];
    int nivel;
}Estudante;

//lista de estudantes 
typedef struct ListaEstudantes
{
    int tamanhoDaLista;
    Estudante estudantes[tamanho];
}ListaEstudantes;

//lista de pautas 
typedef struct ListaPauta
{
    int tamanhoDaLista;
    Pauta pautas[tamanho];
}ListaPauta;
Estudante pesquisarEstudante(ListaEstudantes *lista,int id);

void ordenarPautaPorNota(ListaPauta *pautas){
    int i,j;
    Pauta temp;
    for ( i = 0; i < pautas->tamanhoDaLista; i++)
    {
        for ( j = i; j < pautas->tamanhoDaLista ; j++)
        {
            if (pautas->pautas[j].nota < pautas->pautas[i].nota )
            {
                temp = pautas->pautas[i];
                pautas->pautas[i] = pautas->pautas[j];
                pautas->pautas[j]  = temp;
            }
        }
    }
}

void ordenarEstudantesPorNota(ListaEstudantes *estudantes,ListaPauta * pautas){
    ordenarPautaPorNota(pautas);
    int i;
    for ( i = 0; i < estudantes->tamanhoDaLista; i++)
    {
        imprimirEstudante (pesquisarEstudante(estudantes,pautas->pautas[i].idDeEstudante));
    }
}

Estudante estudanteCom3menorNota(ListaEstudantes *estudantes, ListaPauta *pautas){
    int i,j;
    Pauta temp;
    for ( i = 0; i < pautas->tamanhoDaLista; i++)
    {
        for ( j = i; j < pautas->tamanhoDaLista ; j++)
        {
            if (pautas->pautas[j].nota > pautas->pautas[i].nota )
            {
                temp = pautas->pautas[i];
                pautas->pautas[i] = pautas->pautas[j];
                pautas->pautas[j]  = temp;
            }
        }
    }
    return pesquisarEstudante(estudantes,pautas->pautas[2].idDeEstudante);
}

Estudante pesquisarEstudante(ListaEstudantes *lista,int id){
    int i;
    for ( i = 0; i < lista->tamanhoDaLista; i++)
    {
        if (lista->estudantes[i].id == id)
        {
            return lista->estudantes[i];
        }
        
    }
 Estudante estudante;
 estudante.id = -1;
    return estudante;
}

/**
 * @@ função que so imprime estudante
 * @param Estudante estudante
 * @return void
 * */
void imprimirEstudante(Estudante estudante){
    printf("Id: %i \n",estudante.id);
    printf("Nome completo: %s %s \n",&estudante.nome,&estudante.apelido);
    printf("Nível: %i \n",estudante.nivel);
}
/**
 * @@ função que so imprime pauta de um estudante
 * @param Pauta pauta
 * @return void
 * */
void imprimirPauta(Pauta pauta){
    printf("Disciplina: %s \n",&pauta.disciplina);
    printf("Nota: %f \n", pauta.nota);
    printf("Ano: %i \n", pauta.ano);
    printf("Id do estudante : %i \n", pauta.idDeEstudante);
}
/**
 * @@ funcao que imprime todos estudantes cadastrados na lista
 * @param ListaEstudantes estudantes
 * @return void
 * */
void imprimirListaDeEstudantes(ListaEstudantes estudantes){
    int i;
    for ( i = 0; i < estudantes.tamanhoDaLista ; i++)
    {
        imprimirEstudante(estudantes.estudantes[i]);
        printf(".............................\n");
    }
}

/**
 * @@ funcao que imprime pauta de todos estudantes
 * @param ListaEstudantes estudantes
 * @return void
 * */
void imprimirListaDePauta(ListaPauta pautas){
    int i;
    for ( i = 0; i < pautas.tamanhoDaLista ; i++)
    {
        imprimirPauta(pautas.pautas[i]);
        printf(".............................\n");
    }
}
/**
 * funcao que inicializa o primeiro elemento da lista
 * @param ListaEstudantes *lista
 * 
 * */
void inicializarLista(ListaEstudantes *lista){
    lista->tamanhoDaLista  = 0;   
}
/**
 * funcao que inicializa o primeiro elemento da pauta
 * @param ListaPauta *pautas
 * 
 * */
void inicializarListaDePauta(ListaPauta *pautas){
    pautas->tamanhoDaLista  = 0;   
}

/**
 * @@ Função que adiciona estudante a lista de estudantes
 * @param ListaEstudantes *lista
 * @param char nome[]
 * @param char apelido[]
 * @param int nivel
 **/
void adicionarEstudante(ListaEstudantes *lista,char nome[], char apelido[], int nivel){
    Estudante estudante;
    strcpy(estudante.nome,nome);
    strcpy(estudante.apelido,apelido);
    estudante.nivel = nivel;
    estudante.id  = lista->tamanhoDaLista + 1;
    lista->estudantes[lista->tamanhoDaLista]  = estudante;
    lista->tamanhoDaLista ++;
}


/**
 * @@ Função que adiciona estudante a lista de estudantes
 * @param ListaEstudantes *lista
 * @param char nome[]
 * @param char apelido[]
 * @param int nivel
 **/
void adicionarPauta(ListaPauta *lista,int idEstudante,char disciplina[], double nota, int ano){
    Pauta pauta;
    strcpy(pauta.disciplina,disciplina);
    pauta.ano = ano;
    pauta.idDeEstudante = idEstudante;
    pauta.nota = nota;
    lista->pautas[lista->tamanhoDaLista]  = pauta;
    lista->tamanhoDaLista ++;
}

int main(){
ListaPauta pautas;
ListaEstudantes estudantes;
inicializarLista(&estudantes);
inicializarListaDePauta(&pautas);
adicionarEstudante(&estudantes,"Dias1","Carvalho",3);
adicionarEstudante(&estudantes,"Dia2","Carvalho",4);
adicionarEstudante(&estudantes,"Dias3","Carvalho",1);
adicionarEstudante(&estudantes,"Dia4","Carvalho",4);
adicionarEstudante(&estudantes,"Dias5","Carvalho",2);
adicionarEstudante(&estudantes,"Dia6","Carvalho",1);

adicionarPauta(&pautas,1,"Matemática",1,2021);
adicionarPauta(&pautas,2,"Matemática",140.55,2021);
adicionarPauta(&pautas,3,"Matemática",130.5,2021);
adicionarPauta(&pautas,4,"Matemática",10.55,2021);
adicionarPauta(&pautas,5,"Matemática",130.55,2021);
adicionarPauta(&pautas,6,"Matemática",0.55,2021);

//imprimir lista de todos estudantes.
imprimirListaDeEstudantes(estudantes);
//Ordenar estudantes por nota
ordenarEstudantesPorNota(&estudantes,&pautas);
//imprimirListaDeEstudantes(estudantes);
//imprimir estudante com a 3 maior nota.
imprimirEstudante(estudanteCom3menorNota(&estudantes,&pautas));

}








