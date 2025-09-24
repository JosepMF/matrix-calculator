#include <stdio.h>
#include <stdlib.h>
#include "matrixlib.h"

// crea una matriz
void create_matrix(int col, int row, struct matrix_s *matrix_obj)
{
    matrix_obj->col = col;
    matrix_obj->row = row;

    matrix_obj->matrix = malloc(sizeof(float) * col * row);
}

// inserta un valor en la fila y columna indicada de la matriz
void insert_value(int col, int row, float value, struct matrix_s* matrix_obj)
{
    matrix_obj->matrix[matrix_obj->col*row + col] = value;
} 

// toma un valor de la matriz dado su columna y fila
float get_value_from_matrix(int row, int col, struct matrix_s* matrix_obj)
{
    return matrix_obj->matrix[matrix_obj->col*row + col];
}

// pinta por pantalla la matriz
void print_matrix(struct matrix_s *matrix_obj)
{
    for (int i = 0; i < matrix_obj->row * matrix_obj->col; i++)
    {
        if(i % matrix_obj->col == 0 && i != 0) printf("\n");
        printf("%f ", matrix_obj->matrix[i]);
    }
}

// rellena la matriz con datos que inserte el usuario desde terminal 
void fill_matrix(struct matrix_s* matrix_obj)
{
    float value;

    for (int i = 0; i < matrix_obj->row; i++)
    {
        for (int j = 0; j < matrix_obj->col; j++)
        {
            printf("Elemento va a ser agregado a r=%d c=%d => ", i, j);
            scanf("%f", &value);

            matrix_obj->matrix[matrix_obj->col*i + j] = value;
        }
    }
}

// multiplicar fila por un numero dado
void scale_row(int row, float n, struct matrix_s* matrix_obj)
{
    for (int i = 0; i < matrix_obj->col; i++) {
        matrix_obj->matrix[row*matrix_obj->col + i] *= n;
    }
}

// suma un multiplo de una fila a otra f2 -> f2 + a*f1
void add_multiple_row(int r1, int r2, float n, struct matrix_s* matrix_obj)
{
    for (int i = 0; i < matrix_obj->col; i++)
    {
        matrix_obj->matrix[matrix_obj->col*r2 + i] += n * matrix_obj->matrix[matrix_obj->col*r1 + i];
    }
}

// intercambia una fila por otra f1 <---> f2
void swap_rows(int r1, int r2, struct matrix_s* matrix_obj)
{
    float buffer;

    for (int i = 0; i < matrix_obj->col; i++)
    {
        buffer = matrix_obj->matrix[matrix_obj->col*r1 + i];
        matrix_obj->matrix[matrix_obj->col*r1 + i] = matrix_obj->matrix[matrix_obj->col*r2 + i];
        matrix_obj->matrix[matrix_obj->col*r2 + i] = buffer;
    }
}

