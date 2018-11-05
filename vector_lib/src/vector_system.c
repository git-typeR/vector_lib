#include "vector_system.h"


static VEC_ERRO_T s_error_flag = 0;


/**
 * @brief 
 * 
 * @return VECTOR_RESULT_T 
 */
VECTOR_RESULT_T vector_init_error(void)
{
    s_error_flag = 0;
    return VECTOR_SUCCESS;
}

/**
 * @brief 
 * 
 * @param error_flag 
 * @return VECTOR_RESULT_T 
 */
VECTOR_RESULT_T vector_clear_error(VEC_ERRO_T error_flag)
{
    s_error_flag &=~error_flag;
    return VECTOR_SUCCESS;
}

/**
 * @brief 
 * 
 * @param error_flag 
 * @return VECTOR_RESULT_T 
 */
VECTOR_RESULT_T vector_write_error(VEC_ERRO_T error_flag)
{
    s_error_flag |= error_flag;
    return VECTOR_SUCCESS;
}

/**
 * @brief 
 * 
 * @return VEC_ERRO_T 
 */
VEC_ERRO_T vector_read_error(void)
{
    return s_error_flag;
}
