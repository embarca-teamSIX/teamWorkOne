#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "armazenamento.h"

return_code_data bit_to_byte(char numero[], char *resultado) {
    for(int i=0; numero[i] != '\0'; i++) {
        if(numero[i] < '0' || numero[i] > '9') {
            printf("\nErro! Valor inválido. \n");
            system("Pause");
            return CONVERSION_INVALID_VALUE;
        }
    }

    double valor = atof(numero) / 8;

    sprintf(resultado, "%.0lf", valor);

    return CONVERSION_OK;
}

return_code_data bit_to_kb(char numero[], char *resultado) {
    for(int i=0; numero[i] != '\0'; i++) {
        if(numero[i] < '0' || numero[i] > '9') {
            printf("\nErro! Valor inválido. \n");
            system("Pause");
            return CONVERSION_INVALID_VALUE;
        }
    }
    
    double valor = atof(numero) / 8000;

    sprintf(resultado, "%.0lf", valor);

    return CONVERSION_OK;
}

return_code_data bit_to_mb(char numero[], char *resultado) {
    for(int i=0; numero[i] != '\0'; i++) {
        if(numero[i] < '0' || numero[i] > '9') {
            printf("\nErro! Valor inválido. \n");
            system("Pause");
            return CONVERSION_INVALID_VALUE;
        }
    }

    double valor = atof(numero) / 8000000;

    sprintf(resultado, "%.0lf", valor);

    return CONVERSION_OK;
}

return_code_data bit_to_gb(char numero[], char *resultado) {
    for(int i=0; numero[i] != '\0'; i++) {
        if(numero[i] < '0' || numero[i] > '9') {
            printf("\nErro! Valor inválido. \n");
            system("Pause");
            return CONVERSION_INVALID_VALUE;
        }
    }

    double valor = atof(numero) / 8000000000;

    sprintf(resultado, "%.0lf", valor);

    return CONVERSION_OK;
}

return_code_data bit_to_tb(char numero[], char *resultado) {
    for(int i=0; numero[i] != '\0'; i++) {
        if(numero[i] < '0' || numero[i] > '9') {
            printf("\nErro! Valor inválido. \n");
            system("Pause");
            return CONVERSION_INVALID_VALUE;
        }
    }

    double valor = atof(numero) / 8000000000000;

    sprintf(resultado, "%.0lf", valor);

    return CONVERSION_OK;
}

return_code_data byte_to_bit(char numero[], char *resultado) {
    for(int i=0; numero[i] != '\0'; i++) {
        if(numero[i] < '0' || numero[i] > '9') {
            printf("\nErro! Valor inválido. \n");
            system("Pause");
            return CONVERSION_INVALID_VALUE;
        }
    }

    double valor = atof(numero) * 8;

    sprintf(resultado, "%.0lf", valor);

    return CONVERSION_OK;
}

return_code_data byte_to_kb(char numero[], char *resultado) {
    for(int i=0; numero[i] != '\0'; i++) {
        if(numero[i] < '0' || numero[i] > '9') {
            printf("\nErro! Valor inválido. \n");
            system("Pause");
            return CONVERSION_INVALID_VALUE;
        }
    }

    double valor = atof(numero) / 1000;

    sprintf(resultado, "%.0lf", valor);

    return CONVERSION_OK;
}

return_code_data byte_to_mb(char numero[], char *resultado) {
    for(int i=0; numero[i] != '\0'; i++) {
        if(numero[i] < '0' || numero[i] > '9') {
            printf("\nErro! Valor inválido. \n");
            system("Pause");
            return CONVERSION_INVALID_VALUE;
        }
    }

    double valor = atof(numero) / pow(1000, 2);

    sprintf(resultado, "%.0lf", valor);

    return CONVERSION_OK;
}

return_code_data byte_to_gb(char numero[], char *resultado) {
    for(int i=0; numero[i] != '\0'; i++) {
        if(numero[i] < '0' || numero[i] > '9') {
            printf("\nErro! Valor inválido. \n");
            system("Pause");
            return CONVERSION_INVALID_VALUE;
        }
    }

    double valor = atof(numero) / pow(1000, 3);

    sprintf(resultado, "%.0lf", valor);

    return CONVERSION_OK;
}

return_code_data byte_to_tb(char numero[], char *resultado) {
    for(int i=0; numero[i] != '\0'; i++) {
        if(numero[i] < '0' || numero[i] > '9') {
            printf("\nErro! Valor inválido. \n");
            system("Pause");
            return CONVERSION_INVALID_VALUE;
        }
    }

    double valor = atof(numero) / pow(1000, 4);

    sprintf(resultado, "%.0lf", valor);

    return CONVERSION_OK;
}

return_code_data kb_to_bit(char numero[], char *resultado) {
    for(int i=0; numero[i] != '\0'; i++) {
        if(numero[i] < '0' || numero[i] > '9') {
            printf("\nErro! Valor inválido. \n");
            system("Pause");
            return CONVERSION_INVALID_VALUE;
        }
    }

    double valor = atof(numero) * 1000 * 8;

    sprintf(resultado, "%.0lf", valor);

    return CONVERSION_OK;
}

return_code_data kb_to_byte(char numero[], char *resultado) {
    for(int i=0; numero[i] != '\0'; i++) {
        if(numero[i] < '0' || numero[i] > '9') {
            printf("\nErro! Valor inválido. \n");
            system("Pause");
            return CONVERSION_INVALID_VALUE;
        }
    }

    double valor = atof(numero) * 1000;

    sprintf(resultado, "%.0lf", valor);

    return CONVERSION_OK;
}

return_code_data kb_to_mb(char numero[], char *resultado) {
    for(int i=0; numero[i] != '\0'; i++) {
        if(numero[i] < '0' || numero[i] > '9') {
            printf("\nErro! Valor inválido. \n");
            system("Pause");
            return CONVERSION_INVALID_VALUE;
        }
    }

    double valor = atof(numero) / 1000;

    sprintf(resultado, "%.0lf", valor);

    return CONVERSION_OK;
}

return_code_data kb_to_gb(char numero[], char *resultado) {
    for(int i=0; numero[i] != '\0'; i++) {
        if(numero[i] < '0' || numero[i] > '9') {
            printf("\nErro! Valor inválido. \n");
            system("Pause");
            return CONVERSION_INVALID_VALUE;
        }
    }

    double valor = atof(numero) / pow(1000, 2);

    sprintf(resultado, "%.0lf", valor);

    return CONVERSION_OK;
}

return_code_data kb_to_tb(char numero[], char *resultado) {
    for(int i=0; numero[i] != '\0'; i++) {
        if(numero[i] < '0' || numero[i] > '9') {
            printf("\nErro! Valor inválido. \n");
            system("Pause");
            return CONVERSION_INVALID_VALUE;
        }
    }

    double valor = atof(numero) / pow(1000, 3);

    sprintf(resultado, "%.0lf", valor);

    return CONVERSION_OK;
}

return_code_data mb_to_bit(char numero[], char *resultado) {
    for(int i=0; numero[i] != '\0'; i++) {
        if(numero[i] < '0' || numero[i] > '9') {
            printf("\nErro! Valor inválido. \n");
            system("Pause");
            return CONVERSION_INVALID_VALUE;
        }
    }

    double valor = atof(numero) * pow(1000, 2) * 8;

    sprintf(resultado, "%.0lf", valor);

    return CONVERSION_OK;
}

return_code_data mb_to_byte(char numero[], char *resultado) {
    for(int i=0; numero[i] != '\0'; i++) {
        if(numero[i] < '0' || numero[i] > '9') {
            printf("\nErro! Valor inválido. \n");
            system("Pause");
            return CONVERSION_INVALID_VALUE;
        }
    }

    double valor = atof(numero) * pow(1000, 2);

    sprintf(resultado, "%.0lf", valor);

    return CONVERSION_OK;
}

return_code_data mb_to_kb(char numero[], char *resultado) {
    for(int i=0; numero[i] != '\0'; i++) {
        if(numero[i] < '0' || numero[i] > '9') {
            printf("\nErro! Valor inválido. \n");
            system("Pause");
            return CONVERSION_INVALID_VALUE;
        }
    }

    double valor = atof(numero) * 1000;

    sprintf(resultado, "%.0lf", valor);

    return CONVERSION_OK;
}

return_code_data mb_to_gb(char numero[], char *resultado) {
    for(int i=0; numero[i] != '\0'; i++) {
        if(numero[i] < '0' || numero[i] > '9') {
            printf("\nErro! Valor inválido. \n");
            system("Pause");
            return CONVERSION_INVALID_VALUE;
        }
    }

    double valor = atof(numero) / 1000;

    sprintf(resultado, "%.0lf", valor);

    return CONVERSION_OK;
}

return_code_data mb_to_tb(char numero[], char *resultado) {
    for(int i=0; numero[i] != '\0'; i++) {
        if(numero[i] < '0' || numero[i] > '9') {
            printf("\nErro! Valor inválido. \n");
            system("Pause");
            return CONVERSION_INVALID_VALUE;
        }
    }

    double valor = atof(numero) / pow(1000, 2);

    sprintf(resultado, "%.0lf", valor);

    return CONVERSION_OK;
}

return_code_data gb_to_bit(char numero[], char *resultado) {
    for(int i=0; numero[i] != '\0'; i++) {
        if(numero[i] < '0' || numero[i] > '9') {
            printf("\nErro! Valor inválido. \n");
            system("Pause");
            return CONVERSION_INVALID_VALUE;
        }
    }

    double valor = atof(numero) * pow(1000, 3) * 8;

    sprintf(resultado, "%.0lf", valor);

    return CONVERSION_OK;
}

return_code_data gb_to_byte(char numero[], char *resultado) {
    for(int i=0; numero[i] != '\0'; i++) {
        if(numero[i] < '0' || numero[i] > '9') {
            printf("\nErro! Valor inválido. \n");
            system("Pause");
            return CONVERSION_INVALID_VALUE;
        }
    }

    double valor = atof(numero) * pow(1000, 3);

    sprintf(resultado, "%.0lf", valor);

    return CONVERSION_OK;
}

return_code_data gb_to_kb(char numero[], char *resultado) {
    for(int i=0; numero[i] != '\0'; i++) {
        if(numero[i] < '0' || numero[i] > '9') {
            printf("\nErro! Valor inválido. \n");
            system("Pause");
            return CONVERSION_INVALID_VALUE;
        }
    }

    double valor = atof(numero) * pow(1000, 2);

    sprintf(resultado, "%.0lf", valor);

    return CONVERSION_OK;
}

return_code_data gb_to_mb(char numero[], char *resultado) {
    for(int i=0; numero[i] != '\0'; i++) {
        if(numero[i] < '0' || numero[i] > '9') {
            printf("\nErro! Valor inválido. \n");
            system("Pause");
            return CONVERSION_INVALID_VALUE;
        }
    }

    double valor = atof(numero) * 1000;

    sprintf(resultado, "%.0lf", valor);

    return CONVERSION_OK;
}

return_code_data gb_to_tb(char numero[], char *resultado) {
    for(int i=0; numero[i] != '\0'; i++) {
        if(numero[i] < '0' || numero[i] > '9') {
            printf("\nErro! Valor inválido. \n");
            system("Pause");
            return CONVERSION_INVALID_VALUE;
        }
    }

    double valor = atof(numero) / 1000;

    sprintf(resultado, "%.0lf", valor);

    return CONVERSION_OK;
}

return_code_data tb_to_bit(char numero[], char *resultado) {
    for(int i=0; numero[i] != '\0'; i++) {
        if(numero[i] < '0' || numero[i] > '9') {
            printf("\nErro! Valor inválido. \n");
            system("Pause");
            return CONVERSION_INVALID_VALUE;
        }
    }

    double valor = atof(numero) * pow(1000, 4) * 8;

    sprintf(resultado, "%.0lf", valor);

    return CONVERSION_OK;
}

return_code_data tb_to_byte(char numero[], char *resultado) {
    for(int i=0; numero[i] != '\0'; i++) {
        if(numero[i] < '0' || numero[i] > '9') {
            printf("\nErro! Valor inválido. \n");
            system("Pause");
            return CONVERSION_INVALID_VALUE;
        }
    }

    double valor = atof(numero) * pow(1000, 4);

    sprintf(resultado, "%.0lf", valor);

    return CONVERSION_OK;
}

return_code_data tb_to_kb(char numero[], char *resultado) {
    for(int i=0; numero[i] != '\0'; i++) {
        if(numero[i] < '0' || numero[i] > '9') {
            printf("\nErro! Valor inválido. \n");
            system("Pause");
            return CONVERSION_INVALID_VALUE;
        }
    }

    double valor = atof(numero) * pow(1000, 3);

    sprintf(resultado, "%.0lf", valor);

    return CONVERSION_OK;
}

return_code_data tb_to_mb(char numero[], char *resultado) {
    for(int i=0; numero[i] != '\0'; i++) {
        if(numero[i] < '0' || numero[i] > '9') {
            printf("\nErro! Valor inválido. \n");
            system("Pause");
            return CONVERSION_INVALID_VALUE;
        }
    }

    double valor = atof(numero) * pow(1000, 2);

    sprintf(resultado, "%.0lf", valor);

    return CONVERSION_OK;
}

return_code_data tb_to_gb(char numero[], char *resultado) {
    for(int i=0; numero[i] != '\0'; i++) {
        if(numero[i] < '0' || numero[i] > '9') {
            printf("\nErro! Valor inválido. \n");
            system("Pause");
            return CONVERSION_INVALID_VALUE;
        }
    }

    double valor = atof(numero) * 1000;

    sprintf(resultado, "%.0lf", valor);

    return CONVERSION_OK;
}