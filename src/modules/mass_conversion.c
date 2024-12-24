#include "../../includes/mass_conversion.h"

conversion_status_t kg_to_g(double kg, double *g) {
    if (kg < 0) {
        return CONVERSION_INVALID_VALUE;
    }
    *g = kg * 1000;
    return CONVERSION_OK;
}

conversion_status_t kg_to_ton(double kg, double *ton) {
    if (kg < 0) {
        return CONVERSION_INVALID_VALUE;
    }
    *ton = kg / 1000;
    return CONVERSION_OK;
}

conversion_status_t g_to_kg(double g, double *kg) {
    if (g < 0) {
        return CONVERSION_INVALID_VALUE;
    }
    *kg = g / 1000;
    return CONVERSION_OK;
}