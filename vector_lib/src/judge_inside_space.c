#include <stdint.h>
#include "judge_inside_space.h"



static const int32_t cube_space[MAX_COMPO_SET][MAX_EDGE] = {
    {UPPER_THRESH_X, LOWER_THRESH_X},
    {UPPER_THRESH_Y, LOWER_THRESH_Y},
    {UPPER_THRESH_Z, LOWER_THRESH_Z}
};

int32_t judge_inside_space(VECTOR_T* vector)
{
    uint8_t i = 0;
    uint8_t j = 0;
    uint8_t k = 0;

#if 0
    for (i = 0; i < MAX_EDGE; i++) {
        for (j = 0; j < MAX_COMPO_SET; j++) {
             cube_space[][];
        }
    }
#endif
}
