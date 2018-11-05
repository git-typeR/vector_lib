#ifndef VECTOR_SYSTEM_H
#define VECTOR_SYSTEM_H

#include <stdint.h>

// error flag
#define ADD_VEC_INVALID_SIZE (1u<<0)
#define SUB_VEC_INVALID_SIZE (1u<<1)
#define MUL_VEC_INVALID_SIZE (1u<<2)
#define PROJ_ZERO_DIV        (1u<<3)

typedef enum {
    VECTOR_SUCCESS,
    VECTOR_FAILURE,
}VECTOR_RESULT_T;


typedef uint32_t VEC_ERRO_T;

extern VECTOR_RESULT_T vector_init_error(void);

extern VECTOR_RESULT_T vector_clear_error(VEC_ERRO_T error_flag);

extern  VECTOR_RESULT_T vector_write_error(VEC_ERRO_T error_flag);

extern  VEC_ERRO_T vector_read_error(void);

#endif // VECTOR_SYSTEM_H
