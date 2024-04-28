#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include "data.h"

void
print_data(data_t d) {
    printf("NOMBRE: %s\n"
           "EDAD  : %d años\n"
           "ALTURA: %d cm\n\n",
           d.name, d.age, d.height);
}

int main(void) {

    data_t messi = {"Leo Messi", 36, 169};
    print_data(messi);

    printf("name-size  : %lu bytes\n"
           "age-size   : %lu bytes\n"
           "height-size: %lu bytes\n"
           "data_t-size: %lu bytes\n\n", sizeof(messi.name),
                                         sizeof(messi.age),
                                         sizeof(messi.height),
                                         sizeof(messi.name) + sizeof(messi.age) + sizeof(messi.height));


    unsigned int *p = NULL;
    data_t *q = NULL;

    printf("Memory directions: \n");
    p = &messi.age;
    printf("name memory address  : %p\n", (void *) p);
    p = &messi.age;
    printf("age memory address   : %p\n", (void *) p);
    p = &messi.height;
    printf("height memory address: %p\n", (void *) p);
    q = &messi;
    printf("data_t memory address: %p\n\n", (void *) q);

    printf("Memory indexes: \n");
    p = &messi.age;
    printf("name memory address  : %lu\n", (uintptr_t) p);
    p = &messi.age;
    printf("age memory address   : %lu\n", (uintptr_t) p);
    p = &messi.height;
    printf("height memory address: %lu\n", (uintptr_t) p);
    printf("data_t memory address: %lu\n", (uintptr_t) q);

    return EXIT_SUCCESS;
}

/*
    La salida por pantalla es la siguiente:
    
    NOMBRE: Leo Messi
    EDAD  : 36 años
    ALTURA: 169 cm

    name-size  : 30 bytes
    age-size   : 4 bytes
    height-size: 4 bytes
    data_t-size: 38 bytes

    Memory directions: 
    name memory address  : 0x7ffe42897240
    age memory address   : 0x7ffe42897240
    height memory address: 0x7ffe42897244
    data_t memory address: 0x7ffe42897220

    Memory indexes: 
    name memory address  : 140730014724672
    age memory address   : 140730014724672
    height memory address: 140730014724676
    data_t memory address: 140730014724640
*/
/*
    La suma de los miembros de la estructura coincide con el total de memoria utilizada.
    El tamaño del campo name es el mismo independientemente del string que alberga. (siempre y cuando NAME_MAXSIZE < 30)
    Las direcciones de memoria son continuas, pero su disposición es la siguiente:
    | data_t | name & age | heigth |
*/