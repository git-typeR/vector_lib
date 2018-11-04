
#include "rotation_matrix_lib.h"
#include "vector_lib.h"




ROT_MAT_RESULT_T rotate_vector(ROT_MAT_T rot_matrix[MAX_ROT_MAT_ROW][MAX_ROT_MAT_COL], VECTOR_T* in_vector, VECTOR_T* out_vector)
{
    ROT_MAT_RESULT_T result = ROT_MAT_FAILURE;

#ifdef ROT_TRANSFORM_CALC_METHOD_1
    out_vector->x = rot_matrix[0][0] * in_vector->x + rot_matrix[0][1] * in_vector->y + rot_matrix[0][2] * in_vector->z;
    out_vector->y = rot_matrix[1][0] * in_vector->x + rot_matrix[1][1] * in_vector->y + rot_matrix[1][2] * in_vector->z;
    out_vector->z = rot_matrix[2][0] * in_vector->x + rot_matrix[2][1] * in_vector->y + rot_matrix[2][2] * in_vector->z;

    result = ROT_MAT_SUCCESS;

#elif ROT_TRANSFORM_CALC_METHOD_2
    uint8_t  row_index = 0;
    uint8_t  col_index = 0;
    int32_t* pin_vector  = (int32_t*)in_vector;
    int32_t* pout_vector = (int32_t*)out_vector;

    for (row_index = 0; row_index < MAX_ROT_MAT_ROW; row_index++) {
        for (col_index = 0; col_index < MAX_ROT_MAT_COL; col_index++) {
            *(pout_vector + row_index) = rot_matrix[row_index][col_index] * (*pin_vector + col_index);
        }        
    }
    
    result = ROT_MAT_SUCCESS;
#endif // ROT_TRANSFORM_CALC_METHOD_2


    return result;
}