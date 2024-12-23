/*
Módulo de funções para conversão de unidades de potência
Unidades disponíveis para conversão: Watts, kWatts e Cavalo-Vapor
*/

#include "conversor_de_potencia.h"

//Função para conversão de Watts para kWatts
return_code_potencia watts_para_kilowatts(double watts, double *kilowatts) {
    if (kilowatts == NULL){
        return ERROR;
    }

    else if (watts < 0){
        return INVALID_INPUT;
    }

    *kilowatts = watts / 1000;
    return SUCESSFUL_OPERATION;
}

//Função para conversão de Watts para Cavalo-Vapor
return_code_potencia watts_para_cv(double watts, double *cv) {
    if (cv == NULL){
        return ERROR;
    }

    else if (watts < 0){
        return INVALID_INPUT;
    }

    *cv = watts / 735.5;
    return SUCESSFUL_OPERATION;
}

//Função para conversão de kWatts para Watts
return_code_potencia kilowatts_para_watts(double kilowatts, double *watts) {
    if (watts == NULL){
        return ERROR;
    }

    else if (kilowatts < 0){
        return INVALID_INPUT;
    }
    
    *watts = kilowatts * 1000;
    return SUCESSFUL_OPERATION;
}

//Função para conversão de kWatts para Cavalo-Vapor
return_code_potencia kilowatts_to_cv(double kilowatts, double *cv){
    if (cv == NULL){
        return ERROR;
    }

    else if (kilowatts < 0){
        return INVALID_INPUT;
    }

    *cv = kilowatts / 0.7355;
    return SUCESSFUL_OPERATION;
}

//Função para conversão de Cavalo-Vapor para Watts
return_code_potencia cv_para_watts(double cv, double *watts){
    if (watts == NULL){
        return ERROR;
    }

    else if (cv < 0){
        return INVALID_INPUT;
    }

    *watts = cv * 735.5;
    return SUCESSFUL_OPERATION;
}

//Função para conversão de Cavalo-Vapor para kWatts
return_code_potencia cv_para_kilowatts(double cv, double *kilowatts){
    if (kilowatts == NULL){
        return ERROR;
    }

    else if (cv < 0){
        return INVALID_INPUT;
    }

    *kilowatts = cv * 0.7355;
    return SUCESSFUL_OPERATION;
}





