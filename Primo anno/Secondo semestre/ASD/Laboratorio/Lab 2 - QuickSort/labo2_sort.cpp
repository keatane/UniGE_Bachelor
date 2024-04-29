#include "labo2_sort.h"
#include <ctime>
#include <iostream>


void scambia(vector<int>& v, int i, int j)
{ 
  int tmp = v[j];
  v[j] = v[i];
  v[i] = tmp;
}


/**************************************************************************************
				SELECTION SORT
***************************************************************************************/
void selectionSort(vector<int>& v)
{
   int current_min_index;
   unsigned int size = v.size();
   for (unsigned int i=0; i<size; ++i)
   { 
     current_min_index = i;
     for (unsigned int j=i+1;j<size; ++j)
        if (v[current_min_index] > v[j])
            current_min_index = j;
     scambia(v, i, current_min_index);
   }
}



/**************************************************************************************
				INSERTION SORT
***************************************************************************************/
void insertionSort(vector<int>& v)
{
   int current, prev;
   unsigned int size = v.size();
   for (unsigned int i=1; i<size; ++i)
   { current=i; 
     prev=i-1;
     while(prev>=0 && v[current]<v[prev])
        {
         scambia(v, current, prev);
         --current;
         --prev;
        }
   }
}


/**************************************************************************************
				BUBBLESORT
***************************************************************************************/
void bubbleSort(vector<int>& v)
{
   unsigned int size = v.size();
   bool scambiati;
   for (unsigned int i=1; i<size; ++i)
      {
      scambiati = false;
      for (unsigned int j=0; j<size-i; ++j)
          if(v[j]>v[j+1])
            { 
              scambia(v, j, j+1);
              scambiati = true;
            }
      if (!scambiati) return;
      }
}



/**************************************************************************************
				   MERGESORT
***************************************************************************************/
void fondi(vector<int>& v, unsigned int inizio, unsigned int centro, unsigned int fine)
{
   vector<int> vsinistra, vdestra;

   for (unsigned int i=inizio; i<=centro; ++i)
      vsinistra.push_back(v[i]);

   for (unsigned int i=centro+1; i<=fine; ++i)
      vdestra.push_back(v[i]);

   unsigned int indicesinistra = 0;
   unsigned int maxsin = vsinistra.size();
   unsigned int indicedestra = 0;
   unsigned int maxdes = vdestra.size();
   
   for (unsigned int i=inizio; i<=fine; ++i)
   {
      if (indicesinistra < maxsin && indicedestra < maxdes)
         {
         if (vsinistra[indicesinistra]<vdestra[indicedestra])
            {
             v[i] = vsinistra[indicesinistra];
             indicesinistra++; continue;
             }
         else
            { 
            v[i] = vdestra[indicedestra];
            indicedestra++; continue;
            }
         } 
      
      if (indicesinistra == maxsin && indicedestra < maxdes)
         { 
            v[i] = vdestra[indicedestra];
            indicedestra++; continue;
         }

       if (indicedestra == maxdes && indicesinistra < maxsin)
         { 
            v[i] = vsinistra[indicesinistra];
            indicesinistra++; continue;
         }         
   } 
}

void ms(vector<int>& v, unsigned int inizio, unsigned int fine)
{
    if (inizio < fine)
      {
          unsigned int centro = (inizio+fine)/2;
          ms(v, inizio, centro);
          ms(v, centro+1, fine);
          fondi(v, inizio, centro, fine);
      }
}


void mergeSort(vector<int>& v)
{
   if (v.size() != 0)
      ms(v, 0, v.size()-1);
}


/**************************************************************************************
				QUICKSORT - FUNZIONI AUSILIARIE
***************************************************************************************/

int scegliIndexPivot(int inizio, int fine){
	
	// Implementa la scelta di un numero random
  	int seed = static_cast<int>(time(NULL));
   	srand(seed);
   	int number = inizio+rand()%(fine-inizio+1);	
   	return number;
}

/* Funzione ausiliaria per partizionare le sequenze */
int partition(vector<int>& v, int inizio, int fine, bool random){
	
	int pivot;
	if(random){
		// Scegliamo il pivot in modo random
		pivot = scegliIndexPivot(inizio,fine);
		
		// Portiamo convenzionalmente il contenuto di pivot in prima posizione (indice "inizio")
		scambia(v, inizio, pivot);
	}
	else{
		pivot = inizio; // Il pivot è già nella prima posizione ||| posso saltare questo passaggio
	}
	
	// Effettuiamo eventuali scambi fra 'i' (muro dei minori) e 'j' (muro degli analizzati)
	// Nell'indice "inizio" è presente il pivot, sia nel caso triviale che nel caso random
	int i=inizio+1;
	for(int j=inizio+1; j<=fine; ++j){
		if(v[j] <= v[inizio]){
			scambia(v,i,j);
			i++;
		}
	}
		
	// Riporto il contenuto del pivot nella posizione corretta (index pivot)
	pivot = i-1; // modifico indice: perchè i valori PRIMA di i sono minori del pivot;
	scambia(v,inizio,pivot); // modifico contenuto scambiando pivot con un minore
	
	return pivot;
}

/* Funzione ausiliaria al quicksort */
void qs(vector<int>& v, int inizio, int fine, bool random){

	// Il caso base si raggiunge quando la sequenza è vuota o ha dimensione pari a uno. 
	if (inizio >= fine) return;
	if(v.size() > 1){
		int pivot = partition(v, inizio, fine, random);
		qs(v, inizio, pivot-1, random); // sinistra
	  	qs(v, pivot+1, fine, random); // destra
  	}
}

/**************************************************************************************
				QUICKSORT CON SCELTA "BANALE" DEL PIVOT
***************************************************************************************/

/* Implementare quickSort banale con partizione in place */
void quickSortTrivial(vector<int>& v)
{  
	// Per "banale" si intenda la scelta del pivot come primo elemento della sequenza
	qs(v,0,v.size()-1, 0);
}


/**************************************************************************************
				QUICKSORT RANDOMIZZATO
***************************************************************************************/

/* Implementare quickSort randomizzato con partizione in place */
void quickSortRandom(vector<int>& v)
{   
   qs(v,0,v.size()-1, 1);
}
