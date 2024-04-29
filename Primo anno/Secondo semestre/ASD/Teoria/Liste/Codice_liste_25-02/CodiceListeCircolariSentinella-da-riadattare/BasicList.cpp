#include <iostream>

#include "BasicList.h"

using namespace lst;

void lst::create_empty(basic_list& list)
{
   cell* aux = new cell;
   aux->next = aux;
   list = aux;
}

void lst::head_insert(basic_list& list, DataType new_value) {
	cell* aux = new cell;
	aux->payload = new_value;
	cell* tmp = list->next;
	list->next = aux;
	aux->next = tmp;
}


void lst::print_list(std::ostream& output_stream, basic_list list) {
	cell* aux = list->next; // devo saltare la sentinella
	while (aux != list) {
		WriteData(output_stream, aux->payload);
		aux = aux->next;
		output_stream << std::endl;
	}
}

void lst::read_list(std::istream& input_stream, basic_list& list) {
	// list = emptyList;
	create_empty(list); // non posso usare list = emptyList; sono liste con sentinella!!!
	DataType d;
	while (ReadData(input_stream, d)) {
		head_insert(list, d);
	}
}

bool lst::isEmpty(basic_list& list){
	// Poiche' e' lista con sentinella, esiste sempre una prima cella
	// dunque verifico che la cella dopo la sentinella non esiste (nullptr)
	return (list->next == nullptr);
}
