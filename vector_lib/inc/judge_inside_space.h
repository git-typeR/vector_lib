#ifndef JUDGE_INSIDE_SPACE_H
#define JUDGE_INSIDE_SPACE_H

#include <stdint.h>

#define MAX_EDGE         (2)
#define MAX_COMPO_SET    (3)

#define UPPER_THRESH_X   ( 1)
#define LOWER_THRESH_X   (-1)
#define UPPER_THRESH_Y   ( 1)
#define LOWER_THRESH_Y   (-1)
#define UPPER_THRESH_Z   ( 1)
#define LOWER_THRESH_Z   (-1)


extern int32_t judge_inside_space(VECTOR_T* vector);

#endif // JUDGE_INSIDE_SPACE_H
