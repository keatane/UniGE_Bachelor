/*
 * malloc_play.c: bizzarro programma per studiare il comportamento delle system call
 *                malloc(), realloc() e free().
 *
 * versione 1.5 del 14/03/2021
 *
 * Programma sviluppato a supporto del laboratorio di
 * Architettura dei Calcolatori del corso di laurea triennale
 * in Informatica classe L-31 presso l'Universita` degli Studi di
 * Genova, anno accademico 2020/2021.
 *
 * Copyright (C) 2013-2021 by Giovanni Chiola <chiolag@acm.org>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 */

#include<stdlib.h>
#include<stdio.h>

/*** Just playing with the malloc(), realloc(), free()
 *** system calls in order to guess how memory management
 *** is implemented on this machine. If you get SEGMENTATION
 *** FAULT while addressing unallocated heap memory, just run
 *** the program with different "min" and/or "max" values,
 *** explicitly given on the command line through argv[]
 ***/
int main(int argc, char**argv){
    unsigned char *p, *q, *oldp;
    int sz=1, min=-16, max=60;

#define check_pointer(p) if ( p == NULL ) { \
            printf("could not allocate p\n"); \
            exit(0); \
          }

#define print_array(a,f,t,n) { int i, j=1; \
            for ( i = f ; i <= t ; i++, j = (j+1)%4 ) \
                printf("%s[%3d]=%3hhu%c",n,i,a[i],j?'\t':'\n'); \
            printf("\n"); \
          }
        // stampa stringa[indice] = valore array in i, dove:
        // n = lettera stringa, %3d è i con uno spacing di 3 posti
        // notare %3hhu%c la conversione in int del char presente nella stringa a[i]
        // infine controllo se ho raggiunto la stampa di 4 valori per andare a capo (ogni 4)

    if ( argc > 1 )
        sscanf(argv[1],"%d",&sz);
      //  sscanf prende dal primo argomento i valori, per poi distribuirli nei seguenti
 	// sscanf(argv[1],"%d",&sz); prende un decimal integer (int) da argv[1] e lo mette in sz
    if ( sz <= 0 )
        sz = 1;
    else if ( sz > 300 )
        sz = 300;
    if ( argc > 2 )
        sscanf(argv[2],"%d",&min);
    if ( min > -1 )
        min = -1;
    else if ( min < -50 )
        min = -50;
    if ( argc > 3 )
        sscanf(argv[3],"%d",&max);
    if ( max < sz )
        max = sz;
    else if ( max > (sz+100) )
        max = sz+100;
    printf("... allocating %d unsigned chars to pointer p, min=%d, max=%d\n\n",sz,min,max);
    p = (unsigned char*)malloc(sz); // alloco una quantità di memoria pari a sz byte (1 (unsigned) char = 1 byte)
    check_pointer(p)
    *p = 'p';
    print_array(p,min,max,"p") // presso p[0] avrò la codifica ASCII di 'p', qualsiasi altro accesso ad altri indici consistono in overflow, cioè raggiungo area riservata ad altri dati che non c'entrano con p!
    printf("\n... allocating %d more unsigned chars to a different pointer q\n\n",sz);
    q = (unsigned char*)malloc(sz);
    check_pointer(q)
    *q = 'q';
    print_array(q,3*min,max,"q") // alloco come per p, ma partendo da alcuni caratteri dopo
    print_array(p,min,max,"p")
    sz += 4;
    printf("\n... reallocating %d unsigned chars to p\n\n",sz);
    oldp = p; // nuovo puntatore al puntatore p (stessa area di memoria)
    p = (unsigned char*)realloc((void*)p,sz); // espando il puntatore p
    // notare che se vi è un overflow e devo raggiungere celle non contigue nello heap, per quanto p
    // possa puntare a nuove celle di memoria, oldp rimane ancora sulle precedenti
    check_pointer(p)
    sprintf(p,"startp"); // nuova stringa inserita nel puntatore
    print_array(p,min,max,"p")
    print_array(oldp,min,max,"oldp")
    sz += 35;
    printf("\n... reallocating %d unsigned chars to p\n\n",sz);
    p = (unsigned char*)realloc((void*)p,sz); // nuovo ridimensionamento
    check_pointer(p)
    sprintf(p,"modifiedp"); // nuova stringa inserita
    print_array(p,min,max,"p")
    print_array(oldp,min,max,"oldp")
    sz -= 35;
    printf("\n... reallocating %d unsigned chars to p (again)\n\n",sz);
    p = (unsigned char*)realloc((void*)p,sz); // ridimensionamento: occhio che vengono tolti 35 byte
    check_pointer(p)
    print_array(p,min,max,"p")
    print_array(oldp,min,max,"oldp")
    printf("\n... freeing p\n\n");
    free((void*)p); // libero la porzione allocata a p
    print_array(p,min,max,"p")
    printf("\n... freeing q\n\n");
    free((void*)q); // libero la porzione allocata a q
    print_array(q,3*min,max,"q")
/*** see also what happens if you uncomment the following instruction and explain why ***/
/*
    free((void*)oldp); -=-=- free(): double free detected (doppia chiamata di free su uno stesso puntatore o chiamata di free su puntatore null (che è conseguente alla seconda chiamata su un punt free))
    Il motivo è perchè oldp punta a p, se libero p allora anche oldp non punta più a nulla
*/
    exit(0);
}
