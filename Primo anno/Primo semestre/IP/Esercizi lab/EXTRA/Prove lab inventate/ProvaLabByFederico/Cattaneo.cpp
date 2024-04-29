#include <iostream>
#include "queue.h"

// Definizione di funzioni

void crea_concessionaria(concessionaria& c){
	c.head = nullptr;
	c.tail = nullptr;
}

bool empty(concessionaria& c){
	return (c.head == nullptr);
}

void enqueue(concessionaria& c, Auto a){
	cell* aux = new cell;
	aux->content.casa = a.casa;
	aux->content.modello = a.modello;
	aux->content.dataArrivo.anno = a.dataArrivo.anno;
	aux->content.dataArrivo.mese = a.dataArrivo.mese;
	aux->content.dataArrivo.giorno = a.dataArrivo.giorno;
	aux->next = nullptr;
	
	if (empty(c)){
		c.head = aux;
		c.tail = aux;
	}
	else{
		c.tail->next = aux;
		c.tail = aux;
	}
}

Auto dequeue(concessionaria& c){
	if (empty(c))
		throw std::string("concessionaria vuota");
	
	cell* temp = c.head;
	Auto removed;
	removed.casa = temp->content.casa;
	removed.modello = temp->content.modello;
	removed.dataArrivo.anno = temp->content.dataArrivo.anno;
	removed.dataArrivo.mese = temp->content.dataArrivo.mese;
	removed.dataArrivo.giorno = temp->content.dataArrivo.giorno;
	c.head = c.head->next;
	delete temp;
	return removed;
}

void read_concessionaria(concessionaria& c){
	while(true){
		std::cout << "Inserisci auto:\n";
		Auto a;
		std::cout << "Casa di produzione: ";
		std::cin >> a.casa;
		std::cout << "Modello: ";
		std::cin >> a.modello;
		std::cout << "Data di arrivo, anno: ";
		std::cin >> a.dataArrivo.anno;
		std::cout << "Data di arrivo, mese: ";
		std::cin >> a.dataArrivo.mese;
		std::cout << "Data di arrivo, giorno: ";
		std::cin >> a.dataArrivo.giorno; 
		
		// Inserimento nella queue
		enqueue(c,a);
		
		std::cout << "Ancora? (s/n)\n";
		char ans;
		std::cin >> ans;
		if (ans == 'n') return;
	}
}

void print(const concessionaria& c){
	cell* temp = c.head;
	while (temp != nullptr){
		std::cout << temp->content.modello << std::endl;
		temp = temp->next;
	}
}


bool is_in(concessionaria& c, Auto a){
	cell* temp = c.head;
	while (temp!=nullptr){
		if ((temp->content.casa == a.casa)&&
			(temp->content.modello == a.modello)&&
			(temp->content.dataArrivo.anno == a.dataArrivo.anno)&&
			(temp->content.dataArrivo.mese == a.dataArrivo.mese)&&
			(temp->content.dataArrivo.giorno == a.dataArrivo.giorno))
				return true;
		temp = temp->next;
	}
	// Auto non trovata
	return false;
}

int check_old(concessionaria& c, data d){
	cell* temp = c.head;
	int counter = 0;
	while (temp!=nullptr){
		if (temp->content.dataArrivo.anno < d.anno)
			counter++;
		else if ((temp->content.dataArrivo.anno == d.anno)&&
				(temp->content.dataArrivo.mese < d.mese))
				counter++;
		else if((temp->content.dataArrivo.anno == d.anno)&&
				(temp->content.dataArrivo.mese == d.mese)&&
				(temp->content.dataArrivo.giorno < d.giorno))
				counter++;
		temp = temp->next;
	}
	return counter;
}

Auto sold(concessionaria& c, Auto a){
	cell* temp = c.head;
	while (temp!=nullptr){
		if ((temp->content.casa == a.casa)&&
			(temp->content.modello == a.modello)&&
			(temp->content.dataArrivo.anno == a.dataArrivo.anno)&&
			(temp->content.dataArrivo.mese == a.dataArrivo.mese)&&
			(temp->content.dataArrivo.giorno == a.dataArrivo.giorno))
			{
				Auto removed = temp->content;
				cell*prec = temp->next;
				delete temp;
				return removed;
			}
		cell* prec = temp;
		temp = temp->next;
	}
	std::cout << "Auto non trovata" << std::endl;
	return a;
}

void transfer_auto(concessionaria& c, concessionaria& k, Auto a){
	if (!is_in(c,a))
		throw std::string("auto non presente per il trasferimento");
	else{
		enqueue(k,a);
		std::cout << "Auto trasferita: " << sold(c,a).modello << std::endl;
	}
}

void transfer_last_auto(concessionaria& c, concessionaria& k, int n){
	cell* temp = c.head;
	for (int i=0; i<n; ++i){
		transfer_auto(c,k,temp->content);
		temp = temp->next;
	}
}

void transfer_old_auto(concessionaria& c, concessionaria& k, data d){
	cell* temp = c.head;
	while (temp!=nullptr){
		if (temp->content.dataArrivo.anno < d.anno)
			transfer_auto(c,k,temp->content);
		else if ((temp->content.dataArrivo.anno == d.anno)&&
				(temp->content.dataArrivo.mese < d.mese))
				transfer_auto(c,k,temp->content);
		else if((temp->content.dataArrivo.anno == d.anno)&&
				(temp->content.dataArrivo.mese == d.mese)&&
				(temp->content.dataArrivo.giorno < d.giorno))
				transfer_auto(c,k,temp->content);
		temp = temp->next;
	}
}
void sort(concessionaria& c){
	for (cell* i = c.head; i != nullptr; i = i->next){
		cell* youngest = i;
		for (cell* j = i->next; j != nullptr; j = j->next){
			if ((j->content.dataArrivo.anno < youngest->content.dataArrivo.anno)||
				((j->content.dataArrivo.anno == youngest->content.dataArrivo.anno)&&
				(j->content.dataArrivo.mese < youngest->content.dataArrivo.mese))||
				((j->content.dataArrivo.anno == youngest->content.dataArrivo.anno)&&
				(j->content.dataArrivo.mese == youngest->content.dataArrivo.mese)&&
				(j->content.dataArrivo.giorno < youngest->content.dataArrivo.giorno)))
				youngest = j;
		}
	Auto temp = i->content;
	i->content = youngest->content;
	youngest->content = temp;
	}
}
