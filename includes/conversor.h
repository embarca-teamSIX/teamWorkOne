#ifndef CONVERSOR_H
#define CONVERSOR_H

/**
 * @file conversor.h
 * @brief Declarações das funções para conversão entre unidades de comprimento.
 *
 * Este arquivo contém as assinaturas das funções utilizadas para realizar conversões
 * entre as unidades de comprimento: metros, centímetros e milímetros.
 * As funções operam diretamente sobre os parâmetros passados por referência.
 *
 * @author [Seu Nome]
 * @date [Data de Criação]
 */

/**
 * @brief Converte metros para centímetros.
 *
 * Esta função converte o valor em metros para centímetros.
 *
 * @param metro Ponteiro para o valor em metros que será convertido para centímetros.
 */
void metroParaCentimetro(double *metro);

/**
 * @brief Converte metros para milímetros.
 *
 * Esta função converte o valor em metros para milímetros.
 *
 * @param metro Ponteiro para o valor em metros que será convertido para milímetros.
 */
void metroParaMilimetro(double *metro);

/**
 * @brief Converte centímetros para metros.
 *
 * Esta função converte o valor em centímetros para metros.
 *
 * @param centimetro Ponteiro para o valor em centímetros que será convertido para metros.
 */
void centimetroParaMetro(double *centimetro);

/**
 * @brief Converte milímetros para metros.
 *
 * Esta função converte o valor em milímetros para metros.
 *
 * @param milimetro Ponteiro para o valor em milímetros que será convertido para metros.
 */
void milimetroParaMetro(double *milimetro);

#endif // CONVERSOR_H
