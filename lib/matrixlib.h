#ifndef MATRIXLIB
#define MATRIXLIB

/**
 * Estructura que guarda tanto las dimensiones de la matriz (row, col) como el puntero a el primer elemento de esta
 * @warning *matrix es un puntero a un valor ghuardado en el heap, es requerido que al finalizar el programa se libere la memoria con free()
 * 
*/
struct matrix_s
{
    int col;
    int row;
    float *matrix;
};

void create_matrix(int col, int row, struct matrix_s *matrix_obj);
void print_matrix(struct matrix_s *matrix_obj);
void insert_value(int col, int row, float value, struct matrix_s* matrix_obj);
void fill_matrix(struct matrix_s* matrix_obj);
void scale_row(int row, float n, struct matrix_s* matrix_obj);
void add_multiple_row(int r1, int r2, float n, struct matrix_s* matrix_obj);
void swap_rows(int r1, int r2, struct matrix_s* matrix_obj);
float get_value_from_matrix(int row, int col, struct matrix_s* matrix_obj);

#endif