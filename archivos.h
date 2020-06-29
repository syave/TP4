#ifndef ARCHIVOS_H_
#define ARCHIVOS_H_

#include <fstream>
#include <string>

#include "Pelicula.h"
#include "Lista.h"
using namespace std;

void cargarDesdeArchivo(std::string nombreArchivo, Lista<Pelicula> &lista);

#endif /* ARCHIVOS_H_ */
