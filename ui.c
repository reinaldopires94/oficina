/**
 * @file ui.c
 * @author Vitor
 * @brief Implementação das Funções de UI
 * @version 0.1
 * @date 2022-04-14
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include "ui.h"
#define MAX_INPUT 1024
#define ASK_OPTION "Insira a sua opção"
#define PRINT_WRONG_OPTION printf("Opção Errada!!!\n")

int readInt(char *prompt)
{
    int c;
    char input[MAX_INPUT];
    printf("%s->", prompt);
    fgets(input, MAX_INPUT, stdin);
    c = atoi(input);
    return c;
}

int menuPrincipal()
{
    int opt = 0;
    printf("#### MENU PRINCIPAL ####\n");
    printf("1 - Menu Viaturas\n");
    printf("2 - Menu Manutenção\n");
    printf("3 - Menu Consultas\n");
    printf("------------\n");
    printf("9 - Sair\n");
    do
    {
        opt = readInt(ASK_OPTION);
        if (opt != 1 && opt != 2 && opt != 3 && opt != 9)
            PRINT_WRONG_OPTION;
        else
            break;
    } while (1);
    return opt;
}

int menuViaturas()
{
    int opt = 0;
    printf("#### MENU VIATURAS ####\n");
    printf("1 - Inserir Viatura\n");
    printf("2 - Listar Viaturas\n");
    printf("3 - Apagar viatura\n");
    printf("------------\n");
    printf("8 - Voltar ao menu Principal\n");
    printf("9 - Sair\n");
    do
    {
        opt = readInt(ASK_OPTION);
        if (opt != 1 && opt != 2 && opt != 3 && opt != 8 && opt != 9)
            PRINT_WRONG_OPTION;
        else
            break;
    } while (1);
    return opt;
}