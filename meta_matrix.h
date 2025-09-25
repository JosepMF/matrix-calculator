#include "matrixlib.h"

#ifndef META_MATRIX
#define META_MATRIX

int get_left_row_zeros(int row, struct matrix_s* matrix_obj);
void order_by_left_zeros(struct matrix_s* matrix_obj);
void echelon_matrix(struct matrix_s* matrix_obj);

#endif