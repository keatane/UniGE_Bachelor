#include <iomanip>
#include <iostream>
#include <sstream>
#include <limits>
#include "contact.h"

// salta un campo in uno stringstream
void skip(std::stringstream & ss)
{
  ss.ignore(std::numeric_limits<std::streamsize>::max(), ' ');
}


// legge un record GPS in formato NMEA "gprmc" da un file aperto
bool readGpsRecord(std::ifstream & f, Gprmc & r)
{
  std::string line;
  std::string tmps;

  if (!getline(f,line)) return false;
  // il record è separato da virgole; sostituisco con spazi
  for (int i=0; i<line.size(); i++) if(line[i]==',') line[i]=' ';

  // leggo i record che mi servono attraverso uno stringstream ausiliario
  std::stringstream ss(line);

  // scarto campo "tipo record"
  skip(ss);
  // scarto campo "active/void"
  skip(ss);
  // leggo campo "ora"
  ss >> r.time;
  // leggo campo "latitudine"
  ss >> r.lat;
  // leggo e interpreto il campo "direzione"
  ss >> tmps;
  if (tmps=="W" || tmps=="w") r.lat = -r.lat;  // ovest = negativo
  // leggo campo "longitudine"
  ss >> r.lon;
  // leggo e interpreto il campo "direzione"
  ss >> tmps;
  if (tmps=="S" || tmps=="tmps") r.lon = -r.lon;  // sud = negativo
  // scarto campi "speed" e "track angle"
  skip(ss);
  skip(ss);
  skip(ss);
  // leggo campo "data"
  ss >> r.date;

  return f.good();
}


void writeGpsRecord(Gprmc r)
{
  convDateTime(r);
  std::cout << std::fixed << std::setprecision(2) << std::setfill('0');
  std::cout << std::setw(2)<<r.gg<<"/";
  std::cout << std::setw(2)<<r.mm<<"/";
  std::cout << std::setw(4)<<r.aaaa<<" - ";
  std::cout << std::setw(2)<<r.h<<":";
  std::cout << std::setw(2)<<r.m<<",";
  std::cout << std::setw(2)<<r.s<<"  ";
  std::cout << std::setprecision(6);
  std::cout<<r.lat<<", "<<r.lon<<"\n";
}


int main()
{
  ContactList c;
  std::cout<<"Lettura\n";
  try {
    leggiGps(std::string("gpsdata.txt"), c);
  }
  catch (std::string s) {
    std::cerr << "Exception opening file: "<< s<<"\n";
  }
  std::cout<<"\nScrittura\n";
  scriviGps(c);
  std::cout<<"\nOrdinamento\n";
  sort(c);
  std::cout<<"\nScrittura dopo ordinamento\n";
  scriviGps(c);
  std::cout<<"\nBaricentro\n";

  float latB=0.0, lonB=0.0;
  baricentro(c, latB, lonB);
  std::cout<<"\nPosizione centrale: lat = "<<latB<<"   lon = "<<lonB<<"\n";
}
