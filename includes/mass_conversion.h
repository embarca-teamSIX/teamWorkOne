#ifndef MASS_CONVERSION_H
#define MASS_CONVERSION_H

typedef enum {
    CONVERSION_OK = 0x00,
    CONVERSION_ERROR = 0x01,
    CONVERSION_INVALID_VALUE = 0x02
} conversion_status_t;

conversion_status_t kg_to_g(double kg, double *g);
conversion_status_t kg_to_ton(double kg, double *ton);
conversion_status_t g_to_kg(double g, double *kg);

#endif 