#include "archivos.h"
#include "Pelicula.h"

//Faltan arreglos
/*
void escribirArchivo(ofstream* archivo, std::string nombre) {
	*archivo << nombre << endl;
}

void cargarRecomendadas(Lista<Pelicula> &lista1, Lista<Pelicula> &lista2,Lista<Pelicula> &lista3) {
	ofstream recomendado("recomendado.txt");
	int puntos;

	if (!recomendado.fail()) {
		for (unsigned int j = 1; j <= lista1.getTamanio(); j++) {
			for (unsigned int i = 1; i <= lista2.getTamanio(); i++) {
				if((lista1.obtener(j).getGenero() == lista2.obtener(i).getGenero()) && (lista1.obtener(j).getDirector() == lista2.obtener(i).getDirector())) {
					lista3.agregar(lista1.obtener(j));
					escribirArchivo(&recomendado,lista1.obtener(j).getNombre());
				}
				puntos = atoi(lista2.obtener(i).getPuntaje().c_str());
				if(puntos >= 7) {
					lista3.agregar(lista2.obtener(i));
					escribirArchivo(&recomendado,lista2.obtener(i).getNombre());
				}

			}
		}
	}
}
*/
void cargarDesdeArchivo(std::string nombreArchivo, Lista<Pelicula> &lista) {
	ifstream archivo(nombreArchivo);
	string linea;

	if (!archivo.fail()) {

		while (archivo >> linea) {
			Pelicula p;
			Lista<string> *actoresAuxiliares = new Lista<string>;
			p.setNombre(linea);

			archivo >> linea;
			p.setGenero(linea);

			archivo >> linea;
			p.setPuntaje(linea);

			archivo >> linea;
			p.setDirector(linea);

			archivo >> linea;
			actoresAuxiliares->agregar(linea);

			while(archivo.peek()!='\n'){
				archivo >> linea;
				actoresAuxiliares->agregar(linea);
			}

			p.setActores(actoresAuxiliares);
			lista.agregar(p);
		}

		archivo.close();
	}
}
