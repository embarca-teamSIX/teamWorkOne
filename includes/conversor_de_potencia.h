#ifndef CONVERSOR_UNID_POTENCIA_H
#define CONVERSOR_UNID_POTENCIA_H

typedef enum{
    SUCESSFUL_OPERATION = 0x00,
    ERROR = 0x01,
    INVALID_INPUT = 0x10
} return_code_potencia;

return_code_potencia watts_para_kilowatts(double watts, double *kilowatts);
return_code_potencia watts_para_cv(double watts, double *cv);
return_code_potencia kilowatts_para_watts(double kilowatts, double *watts);
return_code_potencia kilowatts_to_cv(double kilowatts, double *cv);
return_code_potencia cv_para_watts(double cv, double *watts);
return_code_potencia cv_para_kilowatts(double cv, double *kilowatts);

#endif