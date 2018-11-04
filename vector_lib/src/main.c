/**
 * @file main.c
 * @author typeR
 * @brief 
 * @version 0.1
 * @date 2018-11-03
 * 
 * @copyright Copyright (c) 2018
 * 
 */

/**************************************************************************//**
*                         INCLUDE
******************************************************************************/
#include <stdio.h>
#include <stdint.h>
#include "vector_lib.h"
#include "rotation_matrix_lib.h"

/**************************************************************************//**
*                         MAIN
******************************************************************************/

int main(void)
{
    VECTOR_T vector_A = {0,2,3};   
    VECTOR_T vector_B = {4,0,0};   
    VECTOR_T vector_C = {0,0,0};
    VECTOR_T vector_D = {0,0,0};

    ROT_MAT_T rot_mat[MAX_ROT_MAT_ROW][MAX_ROT_MAT_COL] = {{1,0,0},{0,1,0},{0,0,1}};
    int32_t* pD;

    VEC_COMPO_INT_T  ans = 0;
    VECTOR_RESULT_T  rc  = 0;
    pD = (int32_t*)&vector_D;

    vector_D.x = 1;
    vector_D.y = 10;
    vector_D.z = 100;
    
    rotate_vector(rot_mat, &vector_A, &vector_D);
    printf("%p\n", &(vector_D));
    printf("%p, %p, %p\n", &(vector_D), pD+1, pD+2);
    printf("%p, %p, %p\n", &(vector_D.x), &(vector_D.y), &(vector_D.z));
    printf("%3d, %3d, %3d\n", vector_D.x, vector_D.y, vector_D.z);

    vector_scr_mul(&vector_A, 10, &vector_C);
    printf("scalar multiplication\n");
    printf("%2d ",  vector_C.x);
    printf("%2d ",  vector_C.y);
    printf("%2d\n", vector_C.z);

    vector_add(&vector_A, &vector_B, &vector_C);
    printf("addition\n");
    printf("%2d ",  vector_C.x);
    printf("%2d ",  vector_C.y);
    printf("%2d\n", vector_C.z);

    vector_sub(&vector_A, &vector_B, &vector_C);
    printf("subtract\n");
    printf("%2d ",  vector_C.x);
    printf("%2d ",  vector_C.y);
    printf("%2d\n", vector_C.z);

    vector_inner_prod(&vector_A, &vector_B, &ans);
    printf("Inner product\n");
    printf("%2d\n", ans);

    vector_outer_prod(&vector_A, &vector_B, &vector_C);
    printf("Outer product\n");
    printf("%2d ",  vector_C.x);
    printf("%2d ",  vector_C.y);
    printf("%2d\n", vector_C.z);

    vector_norm(&vector_C, &ans);
    printf("Area of parallelogram\n");
    printf("%2d\n", ans);

    vector_norm(&vector_A, &ans);
    printf("Norm of vector_A\n");
    printf("%2d\n", ans);

    printf("Judge orthogonal\n");
    rc = judge_vector_orth(&vector_A, &vector_B); 
    if (rc == VECTOR_ORTHGONAL) {
        printf("vector_A and vector_B are orthogonal.\n");
    } else if (rc == VECTOR_NON_ORTHGONAL){
        printf("vector_A and vector_B are NOT orthogonal.\nCheck other relations.\n");
    } else {
        // do nothing
    }

    printf("Judge parallel\n");
    rc = judge_vector_para(&vector_A, &vector_B); 
    if(rc == VECTOR_PARALLEL) {
        printf("vector_A and vector_B are parallel.\n");
    } else if (rc == VECTOR_NON_PARALLEL){
        printf("vector_A and vector_B are NOT parallel.\nCheck other relations.\n");
    } else {
        // do nothing
    }

    return (0);
}
