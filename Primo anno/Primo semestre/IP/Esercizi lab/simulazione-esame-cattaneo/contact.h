#ifndef _CONTACT_H_
#define _CONTACT_H_


#include <fstream>
#include <string>

struct Gprmc {
  // dati grezzi letti da file
  float lat;
  float lon;

  int time;
  int date;
  
  // dati formattati
  int h;
  int m;
  int s;

  int gg;
  int mm;
  int aaaa;
};

#include "def"

bool readGpsRecord(std::ifstream &, Gprmc &);
void writeGpsRecord(Gprmc);

void leggiGps(std::string, ContactList &);
void scriviGps(ContactList &);
void convDateTime(Gprmc &);
float dist(Gprmc, Gprmc);
void sort(ContactList &);
void baricentro(ContactList c, float &latB, float & lonB);

#endif

