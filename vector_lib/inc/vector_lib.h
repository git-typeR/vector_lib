/**
 * @file vector_lib.h
 * @author typeR
 * @brief 
 * @version 0.1
 * @date 2018-11-03
 * 
 * @copyright Copyright (c) 2018
 * 
 */
#ifndef VECTOR_LIB_H
#define VECTOR_LIB_H

#include <stdint.h>
#include "vector_system.h"

// special macro
#define INNER_PROD_ORTH         (0)
#define INNER_PROD_PARA_FWD     (1)
#define INNER_PROD_PARA_RVS     (-1)


typedef enum {
    VECTOR_ORTHGONAL = 0x10,
    VECTOR_NON_ORTHGONAL,
    VECTOR_PARALLEL  = 0x20,
    VECTOR_NON_PARALLEL,
    VECTOR_INTERSECT = 0x30,
    VECTOR_SKEW,
}VECTOR_RELATION_T;


typedef int32_t VEC_COMPO_INT_T;

typedef struct vector_t{
    VEC_COMPO_INT_T x;
    VEC_COMPO_INT_T y;
    VEC_COMPO_INT_T z;
} VECTOR_T;



// scalar multiplication
extern VECTOR_RESULT_T vector_scr_mul(const VECTOR_T* data1, VEC_COMPO_INT_T scalar, VECTOR_T* output);
// addition
extern VECTOR_RESULT_T vector_add(const VECTOR_T* data1, const VECTOR_T* data2, VECTOR_T* output);
// subtract
extern VECTOR_RESULT_T vector_sub(const VECTOR_T* data1, const VECTOR_T* data2, VECTOR_T* output);
// inner production
extern VECTOR_RESULT_T vector_inner_prod(const VECTOR_T* data1, const VECTOR_T* data2, VEC_COMPO_INT_T* output);
// outer production
extern VECTOR_RESULT_T vector_outer_prod(const VECTOR_T* data1, const VECTOR_T* data2, VECTOR_T* output);
// determinant
extern VECTOR_RESULT_T vector_det(const VECTOR_T* data1, const VECTOR_T* data2, VEC_COMPO_INT_T* output);
// transposition
extern VECTOR_RESULT_T trans(const VECTOR_T* data1, const VECTOR_T* output);
// norm
extern VECTOR_RESULT_T vector_norm(const VECTOR_T* data1, VEC_COMPO_INT_T* output);
// projection
extern VECTOR_RESULT_T vector_proj(const VECTOR_T* data1, const VECTOR_T* data2, VECTOR_T* output);
// orthogonal
extern VECTOR_RELATION_T judge_orth_vector(const VECTOR_T* data1, const VECTOR_T* data2);
// parallel
extern VECTOR_RELATION_T judge_para_vector(const VECTOR_T* data1, const VECTOR_T* data2);
// copy data1 to data2
extern VECTOR_RESULT_T copy_vector(const VECTOR_T* data1, VECTOR_T* data2);
// initialization
extern VECTOR_RESULT_T init_vector(VECTOR_T* data1);

#endif // VECTOR_LIB_H
