/**
 * En esta librería habrán algoritmos aplicados a matrices a partir de operaciones elementales
 * y funciones que doten iinformación sobre la matriz
 * 
*/

#include <stdio.h>
#include "matrixlib.h"
#include "meta_matrix.h"

// devuelve el número de 0 a la izquierda que hay desde el inicio de la fila hasta el primer elemento no nulo de esta 
int get_left_row_zeros(int row, struct matrix_s* matrix_obj)
{
    int n_zeros = 0;
    
    for (int i = 0; i < matrix_obj->col; i++)
    {
        if (get_value_from_matrix(row, i, matrix_obj) != 0.0) break; // si el valor encontrado es diferente a 0 rompe el bucle 

        n_zeros++;
    }

    return n_zeros;
}


void order_by_left_zeros(struct matrix_s* matrix_obj)
{
    /**
     * ordenena la matriz en función del número de 0 de cada fila. Mayor número de ceros, más a bajo estará la fila
     * Si la fila r1 tiene más ceros que la fila r2, estas se intercambiarán de posición
     *  */  
    for (int i = 0; i < matrix_obj->row; i++)
    {
        for (int j = 0; j < matrix_obj->row; j++) {
            if (get_left_row_zeros(i, matrix_obj) < get_left_row_zeros(j, matrix_obj))
            {
                swap_rows(i,j,matrix_obj);
            }
        }
    }
}

void echelon_matrix(struct matrix_s* matrix_obj)
{
    order_by_left_zeros(matrix_obj);

    for (int i = 0; i < matrix_obj->row; i++)
    {
        int pibot_col = get_left_row_zeros(i, matrix_obj);
        float pibot_number = get_value_from_matrix(i, pibot_col, matrix_obj);

        if (pibot_col == matrix_obj->col) continue; // si hay el mismo número de ceros que de columnas pasa

        for (int j = i + 1; j < matrix_obj->row; j++)
        {
            float down_pibot_number = get_value_from_matrix(j, pibot_col, matrix_obj);

            if(down_pibot_number == 0) continue; // si el elemento debajo de la fila es 0 se rompe el bucle ya que no habrán más numeros no nulos a bajo

            add_multiple_row(i,j,-down_pibot_number/pibot_number,matrix_obj);
        }
    }    
}