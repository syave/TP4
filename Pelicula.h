#ifndef PELICULA_H_
#define PELICULA_H_

#include "Lista.h"

class Pelicula {
private:
	std::string nombre;
	std::string genero;
	string puntaje;
	std::string director;
	Lista<string> *actores;
public:

	Pelicula();

	~Pelicula();

	void setNombre(string nombre);
	string getNombre();
	void setGenero(string genero);
	string getGenero();
	void setPuntaje(string puntaje);
	string getPuntaje();
	void setDirector(string director);
	string getDirector();
	void setActores(Lista<string> *listaActores);

	Lista<string> *getActores();

	void agregarActor(string nombre);

};

#endif /* PELICULA_H_ */
