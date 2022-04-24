/**
 * @author Vitor
 * @date 2022-04-14
 * @brief Projeto Oficina
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ui.h"
#include "oficina.h"
#define TRUE 1
#define FALSE 0

void processaMenuViaturas(Oficina *o)
{
    int opt;
    int id;//Id da viatura

    while (TRUE)
    {
        opt = menuViaturas();
        system("clear");
        switch (opt)
        {
        case 1: // Inserir Viaturas
            //É necessário pedir dados ao user
            id = insereViatura(o, "Mercedes", "CLASS E", "AA34BB", 2020);
            if (id == NOK)
                printf("ERRO.Viatura não inserida!!!!\n");
            else
                printf("Viatura Inserida e atribuido ID=%d\n", id);
            break;
        case 2: // Listar Viaturas
            listarViaturas(o);
            break;
        case 3: // Apagar Viatura
            printf("-Apagar viatura-\n");
            break;
            //Procurar Viatura (recebe a matricula)
        case 8:     // Voltar ao menu principal
            return; // sair do menu viaturas
        case 9:
            freeOficina(o);     // sair
            exit(EXIT_SUCCESS); // sair da aplicação
        }
    }
}

int main(int argc, char const *argv[])
{
    int opt;    // Opção de menu
    Oficina *o; // ponteiro que aponta para estrutura Oficina
    o = newOficina("TPSI1021 CAS", 2021);
    // printf("NOME:%s ---- ANO:%d\n",o->nome,o->ano);

    while (TRUE)
    {
        opt = menuPrincipal();
        system("clear");
        switch (opt)
        {
        case 1: // ir menu viaturas
            processaMenuViaturas(o);
            break;
        case 2: // ir menu Manutenção
            printf("-Menu Manutenção-\n");
            break;
        case 3: // ir menu consultas
            printf("-Menu consultas-\n");
            break;
        case 9:
            freeOficina(o);      // sair
            return EXIT_SUCCESS; // sair da aplicação
        }
    }
    return EXIT_SUCCESS;
}