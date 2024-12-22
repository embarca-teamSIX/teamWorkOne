#ifndef CONVERSOR_H
#define CONVERSOR_H

typedef enum 
{
    CONVERSION_OK = 0x00,
    CONVERSION_INVALID_VALUE = 0x01,
} return_code_data;

return_code_data bit_to_byte(char numero[], char *resultado);

return_code_data bit_to_kb(char numero[], char *resultado);

return_code_data bit_to_mb(char numero[], char *resultado);

return_code_data bit_to_gb(char numero[], char *resultado);

return_code_data bit_to_tb(char numero[], char *resultado);

return_code_data byte_to_bit(char numero[], char *resultado);

return_code_data byte_to_kb(char numero[], char *resultado);

return_code_data byte_to_mb(char numero[], char *resultado);

return_code_data byte_to_gb(char numero[], char *resultado);

return_code_data byte_to_tb(char numero[], char *resultado);

return_code_data kb_to_bit(char numero[], char *resultado);

return_code_data kb_to_byte(char numero[], char *resultado);

return_code_data kb_to_mb(char numero[], char *resultado);

return_code_data kb_to_gb(char numero[], char *resultado);

return_code_data kb_to_tb(char numero[], char *resultado);

return_code_data mb_to_bit(char numero[], char *resultado);

return_code_data mb_to_byte(char numero[], char *resultado);

return_code_data mb_to_kb(char numero[], char *resultado);

return_code_data mb_to_gb(char numero[], char *resultado);

return_code_data mb_to_tb(char numero[], char *resultado);

return_code_data gb_to_bit(char numero[], char *resultado);

return_code_data gb_to_byte(char numero[], char *resultado);

return_code_data gb_to_kb(char numero[], char *resultado);

return_code_data gb_to_mb(char numero[], char *resultado);

return_code_data gb_to_tb(char numero[], char *resultado);

return_code_data tb_to_bit(char numero[], char *resultado);

return_code_data tb_to_byte(char numero[], char *resultado);

return_code_data tb_to_kb(char numero[], char *resultado);

return_code_data tb_to_mb(char numero[], char *resultado);

return_code_data tb_to_gb(char numero[], char *resultado);

#endif