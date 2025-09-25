/**
 * @author Josep Malonda Ferriol
 * 
*/

#include <stdio.h>
#include <stdlib.h>

#include "../lib/matrixlib.h"
#include "../lib/meta_matrix.h"

int main()
{
    // manejador del programa
    int running_program = 1;

    // variables del programa
    int r, r1, r2;
    float n;

    // manejador de opciones del programa
    int option;

    // inicializando la variable matrix_obj
    struct matrix_s matrix_obj;

    int col, row; // variables de tamaño de la matriz

    // preguntar al usuario por las medidas de la matriz
    printf("Columns number: ");
    scanf("%d", &col);

    printf("Rows number: ");
    scanf("%d", &row);
    
    // creamos la matriz respecto de col y row  
    create_matrix(col, row, &matrix_obj);

    // rellenamos la matriz
    fill_matrix(&matrix_obj);

    while (running_program)
    {
        // visualizar la matriz
        print_matrix(&matrix_obj);

        // seleccionar opción
        printf("\nSelecciona una opción de las siguientes:\n");
        printf("0 -> intercambiar columna, 1 -> multiplicar numero por columna, 2 -> sumar multiplo de columna, 3 -> limpiar consola, 4 -> salir, 5 -> test\n");
        printf("-> ");

        scanf("%d", &option);

        switch (option)
        {
        case 0:
            printf("seleccione las filas a cambiar r1 <---> r2: \n");
            
            printf("r1=");
            scanf("%d", &r1);

            printf("r2=");
            scanf("%d", &r2);

            swap_rows(r1, r2, &matrix_obj);

            printf("Se han intercambiado las filas %d y %d \n", r1, r2);
            
            break;

        case 1:
            printf("seleccione la fila a multiplicar: ");
            scanf("%d", &r);

            printf("inserte el numero a multiplicar: ");
            scanf("%f", &n);

            scale_row(r, n, &matrix_obj);

            printf("Se ha multiplicado %f a la fila %d \n", n, r);
        
            break;
        case 2:
            printf("Seleccione las filas a sumar y el numero a multiplicar f2 -> f2 + n*f1\n");

            printf("r1=");
            scanf("%d", &r1);

            printf("r2=");
            scanf("%d", &r2);

            printf("n=");
            scanf("%f", &n);

            add_multiple_row(r1, r2, n, &matrix_obj);

            break;
        case 3:
            printf("\033[2J\033[H");

            break;
        case 4:
            printf("Cerrando programa...");
            running_program = 0;
            break;
        case 5:
            echelon_matrix(&matrix_obj);
            break;
        default:
            printf("Comando no valido\n");
            break;
        }
    }
    
    // al finalizar el programa, importante vaciar la memoria de la matriz
    free(matrix_obj.matrix);

    return 0;
}
