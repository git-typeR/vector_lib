/**
 * @file vector_lib.c
 * @author typeR
 * @brief 
 * @version 0.1
 * @date 2018-11-03
 * 
 * @copyright Copyright (c) 2018
 * 
 */

#include <string.h>
#include <math.h>
#include "vector_lib.h"




uint32_t g_error_flag = 0;

/**
 * @brief 
 * 
 * @param data1 
 * @param scalar 
 * @param output 
 * @return VECTOR_RESULT_T 
 */
VECTOR_RESULT_T vector_scr_mul(const VECTOR_T* data1, VEC_COMPO_INT_T scalar, VECTOR_T* output)
{
    VECTOR_RESULT_T result = VECTOR_FAILURE;

    output->x = scalar * data1->x;
    output->y = scalar * data1->y;
    output->z = scalar * data1->z;

    result = VECTOR_SUCCESS;
    return result;

}
/**
 * @brief 
 * 
 * @param data1 
 * @param data2 
 * @param output 
 * @return VECTOR_RESULT_T 
 */
VECTOR_RESULT_T vector_add(const VECTOR_T* data1, const VECTOR_T* data2, VECTOR_T* output)
{
    VECTOR_RESULT_T result = VECTOR_FAILURE;

    output->x = data1->x + data2->x;
    output->y = data1->y + data2->y;
    output->z = data1->z + data2->z;

    result = VECTOR_SUCCESS;
    
    return result;
}


/**
 * @brief 
 * 
 * @param data1 
 * @param data2 
 * @param output 
 * @return VECTOR_RESULT_T 
 */
VECTOR_RESULT_T vector_sub(const VECTOR_T* data1, const VECTOR_T* data2, VECTOR_T* output)
{
    VECTOR_RESULT_T result = VECTOR_FAILURE;
    
    output->x = data1->x - data2->x;
    output->y = data1->y - data2->y;
    output->z = data1->z - data2->z;

    result = VECTOR_SUCCESS;
    
    return result;
}

/**
 * @brief 
 * 
 * @param data1 
 * @param data2 
 * @param output 
 * @return VECTOR_RESULT_T 
 */
VECTOR_RESULT_T vector_inner_prod(const VECTOR_T* data1, const VECTOR_T* data2, VEC_COMPO_INT_T* output)
{
    VECTOR_RESULT_T result = VECTOR_FAILURE;

    *output = (data1->x * data2->x) + (data1->y * data2->y) + (data1->z * data2->z);

    result = VECTOR_SUCCESS;
    
    return result;

}

/**
 * @brief 
 * 
 * @param data1 
 * @param data2 
 * @param output 
 * @return VECTOR_RESULT_T 
 */
VECTOR_RESULT_T vector_outer_prod(const VECTOR_T* data1, const VECTOR_T* data2, VECTOR_T* output)
{
    VECTOR_RESULT_T result = VECTOR_FAILURE;

    output->x = (data1->y * data2->z) - (data1->z * data2->y);
    output->y = (data1->z * data2->x) - (data1->x * data2->z);
    output->z = (data1->x * data2->y) - (data1->y * data2->x);
    
    result = VECTOR_SUCCESS;

    return result;

}

/**
 * @brief 
 * 
 * @param data1 
 * @param data2 
 * @param output 
 * @return VECTOR_RESULT_T 
 */

VECTOR_RESULT_T vector_det(const VECTOR_T* data1, const VECTOR_T* data2, VEC_COMPO_INT_T* output)
{
    VECTOR_RESULT_T result = VECTOR_FAILURE;


    result = VECTOR_SUCCESS;
    return result;

}

/**
 * @brief 
 * 
 * @param data1 
 * @param output 
 * @return VECTOR_RESULT_T 
 */
VECTOR_RESULT_T VEC_COMPO_INT_Trans(const VECTOR_T* data1, const VECTOR_T* output)
{
    VECTOR_RESULT_T result = VECTOR_FAILURE;

    result = VECTOR_SUCCESS;
    return result;

}

/**
 * @brief 
 * 
 * @param data1 
 * @param output 
 * @return VECTOR_RESULT_T 
 */
VECTOR_RESULT_T vector_norm(const VECTOR_T* data1, VEC_COMPO_INT_T* output)
{
    VECTOR_RESULT_T result = VECTOR_FAILURE;
    vector_inner_prod(data1, data1, output);

    *output = (VEC_COMPO_INT_T)sqrt((double)*output);

    result = VECTOR_SUCCESS;
    return result;

}

/**
 * @brief 
 * 
 * @param data1 
 * @param output 
 * @return VECTOR_RESULT_T 
 */
VECTOR_RESULT_T vector_proj(const VECTOR_T* data1, VECTOR_T* output)
{
    VECTOR_RESULT_T result = VECTOR_FAILURE;

    result = VECTOR_SUCCESS;
    return result;

}

/**
 * @brief 
 * 
 * @param data1 
 * @param data2 
 * @return VECTOR_RESULT_T 
 */
VECTOR_RESULT_T judge_vector_orth(const VECTOR_T* data1, const VECTOR_T* data2)
{
    VECTOR_RESULT_T result = VECTOR_FAILURE;
    VEC_COMPO_INT_T ans = (VEC_COMPO_INT_T)INNER_PROD_PARA_FWD;

    vector_inner_prod(data1, data2, &ans);
    if (ans == INNER_PROD_ORTH) {
        result = VECTOR_ORTHGONAL;
    } else {
        result = VECTOR_NON_ORTHGONAL;
    }

    return result;
}

/**
 * @brief 
 * 
 * @param data1 
 * @param data2 
 * @return VECTOR_RESULT_T 
 */
VECTOR_RESULT_T judge_vector_para(const VECTOR_T* data1, const VECTOR_T* data2)
{
    VECTOR_RESULT_T result = VECTOR_FAILURE;
    VEC_COMPO_INT_T ans    = (VEC_COMPO_INT_T)INNER_PROD_ORTH;

    vector_inner_prod(data1, data2, &ans);
    if ((ans == INNER_PROD_PARA_FWD) || (ans == INNER_PROD_PARA_RVS)) {
        result = VECTOR_PARALLEL;
    } else {
        result = VECTOR_NON_PARALLEL;
    }

    return result;

}

/**
 * @brief 
 * 
 * @param data1 
 * @param data2 
 * @return VECTOR_RESULT_T 
 */
VECTOR_RESULT_T copy_vector(const VECTOR_T* data1, VECTOR_T* data2)
{
    VECTOR_RESULT_T result = VECTOR_FAILURE;

    memcpy(data2, data1, sizeof(VECTOR_T));

    result = VECTOR_SUCCESS;
    return result;
}

/**
 * @brief 
 * 
 * @param data1 
 * @return VECTOR_RESULT_T 
 */
VECTOR_RESULT_T init_vector(VECTOR_T* data1)
{
    VECTOR_RESULT_T result = VECTOR_FAILURE;

    memset(data1, 0, sizeof(VECTOR_T));

    result = VECTOR_SUCCESS;
    return result;

}
