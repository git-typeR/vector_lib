#ifndef ROTATION_MATRIX_LIB_H
#define ROTATION_MATRIX_LIB_H

#include <stdint.h>
#include "vector_lib.h"

typedef enum {
    ROT_MAT_SUCCESS,
    ROT_MAT_FAILURE,
} ROT_MAT_RESULT_T;

typedef int32_t ROT_MAT_T;

#define MAX_ROT_MAT_ROW 3
#define MAX_ROT_MAT_COL 3




extern ROT_MAT_RESULT_T rotate_vector(ROT_MAT_T rot_matrix[MAX_ROT_MAT_ROW][MAX_ROT_MAT_COL], VECTOR_T* in_vector, VECTOR_T* out_vector);


#endif // ROTATION_MATRIX_LIB_H
