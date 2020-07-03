#ifndef ARCHIVOS_H_
#define ARCHIVOS_H_

#include <fstream>
#include <string>

#include "Pelicula.h"
#include "Lista.h"
using namespace std;

void cargarDesdeArchivo(std::string nombreArchivo, Lista<Pelicula> &lista);
//Falta arreglar
/*
void cargarRecomendadas(Lista<Pelicula> &lista1, Lista<Pelicula> &lista2,Lista<Pelicula> &lista3);
void escribirArchivo(ofstream* archivo, string nombre);
*/

#endif /* ARCHIVOS_H_ */
