/* First, the standard lib includes, alphabetically ordered */
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "abb.h" /* TAD abb */


void print_help(char *program_name) {
    /* Print the usage help of this program. */
    printf("Usage: %s <input file path>\n\n",
           program_name);
}

char *parse_filepath(int argc, char *argv[]) {
    /* Parse the filepath given by command line argument. */
    char *result = NULL;

    if (argc < 2) {
        print_help(argv[0]);
        exit(EXIT_FAILURE);
    }

    result = argv[1];

    return (result);
}

abb abb_from_file(const char *filepath) {
    FILE *file = NULL;
    abb read_tree;

    read_tree = abb_empty();
    file = fopen(filepath, "r");
    if (file == NULL) {
        fprintf(stderr, "File does not exist.\n");
        exit(EXIT_FAILURE);
    }
    unsigned int i = 0u;
    unsigned int size = 0u;
    int res = 0;
    res = fscanf(file, " %u ", &size);
    if (res != 1) {
        fprintf(stderr, "Invalid format.\n");
        exit(EXIT_FAILURE);
    }
    while (i < size) {
        abb_elem elem;
        res = fscanf(file," %d ", &(elem));
        if (res != 1) {
            fprintf(stderr, "Invalid array.\n");
            exit(EXIT_FAILURE);
        }
        read_tree = abb_add(read_tree, elem);

       ++i;
    }
    fclose(file);
    return read_tree;
}

int main(int argc, char *argv[]) {
    char *filepath = NULL;

    /* parse the filepath given in command line arguments */
    filepath = parse_filepath(argc, argv);

    /* parse the file to obtain an abb with the elements */
    abb tree = abb_from_file(filepath);

    unsigned int option;
    do {
        do {
            printf("* 1 ........ Mostrar árbol por pantalla\n");
            printf("* 2 ........ Agregar un elemento\n");
            printf("* 3 ........ Eliminar un elemento\n");
            printf("* 4 ........ Chequear existencia de elemento\n");
            printf("* 5 ........ Mostrar longitud del árbol\n");
            printf("* 6 ........ Mostrar raiz, máximo y mínimo del árbol\n");
            printf("* 7 ........ Salir\n\n");
            printf("Elija la operación a realizar: ");
            scanf("%u", &option);
            
            if(option < 1 || 7 < option) printf("Opción no disponible\n\n");
        } while(option < 1 || 7 < option);

        if(option == 1) {
            unsigned int ord;
            do {
                printf("* 1 ........ Print IN ORDER\n");
                printf("* 2 ........ Print PRE ORDER\n");
                printf("* 3 ........ Print POS ORDER\n");
                printf("Elija la forma de recorrer el arreglo: ");
                scanf("%u", &ord);
                
                if(ord < 1 || 3 < ord) printf("Opción no disponible\n\n");
            } while(ord < 1 || 3 < ord);
            printf("\nTree: ");
            abb_dump(tree, ord-1);
            if (abb_is_empty(tree)) printf("Árbol vacío");
            printf("\n\n");
        }
        else if(option == 2) {
            unsigned int n_to_add;
            printf("Ingrese el valor a agregar: ");
            scanf("%u", &n_to_add);
            tree = abb_add(tree, n_to_add);
            printf("\nNew tree: ");
            abb_dump(tree, ABB_IN_ORDER);
            printf("\n\n");
        }
        else if(option == 3) {
            unsigned int n_to_remove;
            printf("Ingrese el valor a eliminar: ");
            scanf("%u", &n_to_remove);
            tree = abb_remove(tree, n_to_remove);
            if (abb_is_empty(tree)) printf("\nNew tree: Árbol vacío");
            else printf("\nNew tree: ");
            abb_dump(tree, ABB_IN_ORDER);
            printf("\n\n");
        }
        else if(option == 4) {
            unsigned int n_exists;
            printf("Ingrese el valor a verificar: ");
            scanf("%u", &n_exists);
            abb_exists(tree, n_exists)
                ? printf("\nExiste en el árbol\n")
                : printf("\nNo existe en el árbol\n");
            printf("\n");
        }
        else if(option == 5) {
            printf("\nLa longitud del árbol es de %d\n\n", abb_length(tree));
        }
        else if(option == 6) {
            abb_length(tree) == 0
                ? printf("\nNo tiene raíz, mínimo ni máximo, es un árbol vacío\n\n")
                : printf("\nraiz: %d\n minimo: %d\n maximo: %d\n\n", abb_root(tree),
                                                             abb_min(tree),
                                                             abb_max(tree));
        }
        else if(option == 7) {
            printf("\nHasta la próxima!\n\n");
        }
    } while(option != 7);

    tree = abb_destroy(tree);

    return (EXIT_SUCCESS);
}
