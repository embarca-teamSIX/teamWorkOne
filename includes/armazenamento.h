#ifndef CONVERSOR_H
#define CONVERSOR_H

typedef enum 
{
    CONVERSION_OK = 0x00,
    CONVERSION_FAILED = 0x01,
    CONVERSION_INVALID_VALUE = 0x02,
} return_code_data;

return_code_data bit_to_byte(double numero, double *resultado);

return_code_data bit_to_kb(double numero, double *resultado);

return_code_data bit_to_mb(double numero, double *resultado);

return_code_data bit_to_gb(double numero, double *resultado);

return_code_data bit_to_tb(double numero, double *resultado);

return_code_data byte_to_bit(double numero, double *resultado);

return_code_data byte_to_kb(double numero, double *resultado);

return_code_data byte_to_mb(double numero, double *resultado);

return_code_data byte_to_gb(double numero, double *resultado);

return_code_data byte_to_tb(double numero, double *resultado);

return_code_data kb_to_bit(double numero, double *resultado);

return_code_data kb_to_byte(double numero, double *resultado);

return_code_data kb_to_mb(double numero, double *resultado);

return_code_data kb_to_gb(double numero, double *resultado);

return_code_data kb_to_tb(double numero, double *resultado);

return_code_data mb_to_bit(double numero, double *resultado);

return_code_data mb_to_byte(double numero, double *resultado);

return_code_data mb_to_kb(double numero, double *resultado);

return_code_data mb_to_gb(double numero, double *resultado);

return_code_data mb_to_tb(double numero, double *resultado);

return_code_data gb_to_bit(double numero, double *resultado);

return_code_data gb_to_byte(double numero, double *resultado);

return_code_data gb_to_kb(double numero, double *resultado);

return_code_data gb_to_mb(double numero, double *resultado);

return_code_data gb_to_tb(double numero, double *resultado);

return_code_data tb_to_bit(double numero, double *resultado);

return_code_data tb_to_byte(double numero, double *resultado);

return_code_data tb_to_kb(double numero, double *resultado);

return_code_data tb_to_mb(double numero, double *resultado);

return_code_data tb_to_gb(double numero, double *resultado);

#endif