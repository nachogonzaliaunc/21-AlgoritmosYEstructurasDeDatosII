#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define ARRAY_SIZE 4

struct bound_data {
    bool is_upperbound;
    bool is_lowerbound;
    bool exists;
    unsigned int where;
};


struct bound_data check_bound(int value, int arr[], unsigned int length) {
    struct bound_data res;

    // initialize the structure
    res.is_upperbound = true;
    res.is_lowerbound = true;
    res.exists = false;
    res.where = 0;

    for (unsigned int i = 0; i < length; i++) {
        // check if its an upper bound
        if (value < arr[i]) {
            res.is_upperbound = res.is_upperbound && false;
        }
        // check if its an lower bound
        else if (value > arr[i]) {
            res.is_lowerbound = res.is_lowerbound && false;
        }
        // check if the value belongs to the array
        if (value == arr[i]) {
            res.exists = true;
            res.where = i;      // in this case, it takes the last occurrence
        }
    }

    return res;
}


int main(void) {
    int a[ARRAY_SIZE];

    // ask the user to input the length of the array
    unsigned int length = printf("Ingrese el largo del arreglo: ");
    scanf("%u", &length);

    printf("\n");

    // ask the user to input the elements of the array
    for (unsigned int i = 0; i < length; i++) {
        printf("Ingrese el valor de la posicion %d: ", i);
        scanf("%d", &a[i]);
    }

    // print the array
    printf("\nEl arreglo ingresado es: [");
    for (unsigned int i = 0; i < length-1; i++) {
        printf("%d, ", a[i]);
    }
    printf("%d]\n\n", a[length-1]);

    // ask the user to the value for compare
    int value = printf("Ingrese el valor a comparar: ");
    scanf("%d", &value);
    printf("\n");

    struct bound_data result = check_bound(value, a, ARRAY_SIZE);

    // print the ressults
    if (result.is_upperbound) {
        result.exists 
            ? printf("El valor es maximo y existe en el arreglo en la posicion %d\n", result.where) 
            : printf("El valor es cota superior\n");
    }
    else if (result.is_lowerbound) {
        result.exists
            ? printf("El valor es minimo y existe en el arreglo en la posicion %d\n", result.where)
            : printf("El valor es cota inferior\n"); 
    }
    else {
        result.exists
            ? printf("El elemento no es cota superior, cota inferior, maximo o minimo, pero si esta en el arreglo en la posicion %d\n", result.exists)
            : printf("El elemento no es cota superior, cota inferior, maximo o minimo\n");
    }

    return EXIT_SUCCESS;
}