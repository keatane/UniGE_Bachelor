// set.h
// IMPLEMENTAZIONE DEL TIPO DI DATO INSIEMI BASATA SU LISTE SEMPLICI COLLEGATA
// 
// Created by Kevin Cattaneo on 07/12/2020
//

#ifndef set_h
#define set_h

// TIPI

typedef int Base_Type;


typedef struct cell Base_Elem; // dettagli nascosti

typedef Base_Elem* Set; // Set è una lista

// a questo punto ragioniamo su quali siano le prorpietà di un insieme

// Insieme:
// collezione di elementi omogenei 
// senza ripetizioni
// non necessariamente ordinata

//PROTIPI DELLE FUNZIONI

void create_empty_set(Set &);
void insert_in_set(Base_Type, Set &);
void empty_set(Set &);

bool is_in_set(Base_Type, const Set &);
void print_set(const Set&);

bool is_empty_set(const Set&);

// funzioni binarie

Set union_set(const Set &, const Set &);
Set inters_set(const Set &, const Set &);


#endif /* set_h */
