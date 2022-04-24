/**
 * @file ui.h
 * @author Vitor
 * @brief Funções para UI
 * @version 0.1
 * @date 2022-04-14
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef UI_H
#define UI_H



/**
 * @brief Devolve um inteiro solicitado ao utilizador
 *
 * @param prompt Pedido a ser apresentado ao utilizador
 * @return int inteiro introduzido pelo User. Caso o inteiro seja inválido é retornado 0
 */
int readInt(char *prompt);

int menuPrincipal();

int menuViaturas();

int menuManutencao();

int menuConsultas();


#endif