/**
 * @file oficina.c
 * @author Vitor
 * @brief 
 * @version 0.1
 * @date 2022-04-14
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "oficina.h"

/**###### ÁREA de FUNÇOES PRIVADAS #####
 */

void inicializarVetorCarros(Oficina *of,int dim){
    for (int i = 0; i < dim; i++)
    {
        of->carros[i].livre=LIVRE;
    }
    
}

/**
 * @brief Procura a primeira casa livre no array viaturas
 * 
 * @param o 
 * @return int indice livre, ou -1 se está cheio
 */
int procuraPosLivre(Oficina *o, int dim){
    for (int i = 0; i < dim; i++)
    {
        if(o->carros[i].livre==LIVRE)
            return i;
    }
    return NOK;
}


/**###### ÁREA de FUNÇOES PUBLICAS #####
 */


Oficina* newOficina(char *nome,int ano){
    Oficina *o;
    o=malloc(sizeof(Oficina));
    inicializarVetorCarros(o,DIM_OFICINA);
    o->ano=ano;
    o->nome=malloc(sizeof(char)*(strlen(nome)+1));
    strcpy(o->nome,nome);
    return o;
}


void freeOficina(Oficina *o){
    free(o->nome);//Libertar memória alocada ao ponteiro nome
    for (int i = 0; i < DIM_OFICINA; i++)
    {
        if(o->carros[i].livre==LIVRE)
            continue;
        free(o->carros[i].marca);
        free(o->carros[i].modelo);
        free(o->carros[i].matricula);
    }
    
    free(o);//Libertar da estrutura
}


int insereViatura(Oficina *o, char* marca, char* modelo, char* matricula, int ano){
    int indice=procuraPosLivre(o,DIM_OFICINA);
    if (indice==NOK)
        return NOK;
    //alocar memoria para os ponteiros
    o->carros[indice].marca=malloc(sizeof(char)*(strlen(marca)+1));
    strcpy(o->carros[indice].marca,marca);
    o->carros[indice].modelo=malloc(sizeof(char)*(strlen(modelo)+1));
    strcpy(o->carros[indice].modelo,modelo);
    o->carros[indice].matricula=malloc(sizeof(char)*(strlen(matricula)+1));
    strcpy(o->carros[indice].matricula,matricula);

    //Acertar as outras variaveis
    o->carros[indice].id=indice;
    o->carros[indice].ano=ano;
    o->carros[indice].livre=OCUPADO;
    return indice;
}


void listarViaturas(Oficina *o){
    PRINT_RESUMO_OFICINA(o->nome,o->ano);
    for (int i = 0; i < DIM_OFICINA; i++)
    {
        if (o->carros[i].livre==LIVRE)
            continue;
        PRINT_VIATURA(o->carros[i].id,o->carros[i].marca,o->carros[i].modelo,o->carros[i].matricula,o->carros[i].ano);
    }
    
}

void apagarViatura(Oficina *o, int id){
    //aceder ao array carros no indice id
    //passar o campo livre=LIVRE
    //fazer o free da marca modelo e matricula
}
