/**
 * @file oficina.h
 * @author Vitor
 * @brief Implementa as funções para gerir Oficina
 * @version 0.1
 * @date 2022-04-14
 * 
 * @copyright Copyright (c) 2022
 */
#ifndef OFICINA_H
#define OFICINA_H

#define OK 1
#define NOK -1
#define LIVRE 1
#define OCUPADO 0
#define DIM_OFICINA 5

//Constantes Escrita
#define PRINT_RESUMO_OFICINA(NOME,ANO) printf("##### Oficina %s (ANO:%d) ######\n",NOME,ANO)
#define PRINT_VIATURA(I,M,Mo,Ma,A) printf("[%i] %s %s (%s) - %d\n",I,M,Mo,Ma,A)

typedef struct _carro{
    int id;//Será o indice onde está guardado
    char *marca;
    char *modelo;
    char *matricula;
    int ano;
    //Campo de controle
    int livre;//1=está livre -- 0=não está livre
}Carro;

typedef struct _oficina{
    char *nome;
    int ano;//ano de criação da Oficina
    Carro carros[DIM_OFICINA];
}Oficina;

/**
 * @brief Cria uma Oficina e devolve ponteiro para a mesma
 * 
 * @param nome da Oficina
 * @param ano de Criação da Oficina
 * @return Oficina* Ponteiro
 */
Oficina* newOficina(char *nome,int ano);

/**
 * @brief Liberta a memória alocada a uma oficina
 * 
 * @param o Oficina a limpar
 */
void freeOficina(Oficina *o);

/**
 * @brief Insere uma Viatura no Registo da Oficina
 * 
 * @param o Oficina
 * @param marca 
 * @param modelo 
 * @param matricula 
 * @param ano 
 * @return int Devolve id da viatura, ou 0 (NOK) caso não seja possível inserir
 */
int insereViatura(Oficina *o, char* marca, char* modelo, char* matricula, int ano);

/**
 * @brief Lista todas as viaturas da Oficina
 * 
 * @param o 
 */
void listarViaturas(Oficina *o);

/**
 * @brief Apaga uma viatura
 * 
 * @param o Oficina
 * @param id da viatura a apagar
 */
void apagarViatura(Oficina *o, int id);

#endif