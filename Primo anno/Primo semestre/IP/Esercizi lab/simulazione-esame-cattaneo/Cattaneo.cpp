#include "contact.h"
#include <math.h>

void headInsert(ContactList& l, Gprmc r){
	
	cell* aux = new cell;
	aux->data = r;
	aux->next = l;
	l = aux;
}


void leggiGps(std::string nomefile, ContactList & t)
{
	t = nullptr;
	std::ifstream f;
	f.open(nomefile);
	
	if (f.is_open() == false)
		throw std::string("file not opened");
		
	Gprmc aux;
	while (readGpsRecord(f,aux)){
		headInsert(t,aux);

	}
	f.close();
}

void scriviGps(ContactList & t)
{
	ContactList c = t;
	while(c != nullptr){
		writeGpsRecord(c->data);
		c = c->next;
	}
}

void convDateTime(Gprmc & r)
{
	r.aaaa = r.date%100;
	r.aaaa += 2000;
	r.date /= 100;
	r.mm = r.date%100;
	r.date /= 100;
	r.gg = r.date%100;
	
	r.s = r.time%100;
	r.time /= 100;
	r.m = r.time%100;
	r.time /= 100;
	r.h = r.time%100;
	
	// l'alternativa è procedere con un ciclo
}


void sort(ContactList & c)
{
	for(cell* i = c; i->next != nullptr; i = i->next)
	{
		cell* smallest = i->next;
		
		for (cell* j=i->next; j != nullptr; j=j->next)
		{
			if (dist(i->data,smallest->data) > dist(i->data,j->data))
				smallest = j;
			
		}
		
		Gprmc tmp = smallest->data;
		smallest->data = i->next->data; // tenendo presente che il primo  (i->data) deve essere lasciato invariato
		i->next->data = tmp;
	}
}


void baricentro(ContactList c, float &latB, float & lonB)
{
	float sommaLat = 0.0;
	float sommaLon = 0.0; 
	int counter = 0;
	while (c != nullptr){
		sommaLat += c->data.lat;
		sommaLon += c->data.lon;
		counter++;
		c = c->next;
	}
	
	latB = sommaLat/counter;
	lonB = sommaLon/counter;
}

float dist(Gprmc r1, Gprmc r2){
	float d = 0.0;
	// Teorema di Pitagora (d^2)
	d = (pow(r1.lat-r2.lat,2)+pow(r1.lon-r2.lon,2));
	return d;
}

