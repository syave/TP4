#include "Pelicula.h"

Pelicula::Pelicula(){
	nombre = "";
	genero = "";
	puntaje = "";
	director = "";
	actores = 0;
}

Pelicula::~Pelicula(){}

void Pelicula::setNombre(std::string nombre){
	this->nombre = nombre;
}

string Pelicula::getNombre(){
	return nombre;
}

void Pelicula::setGenero(std::string genero){
	this->genero = genero;
}

std::string Pelicula::getGenero(){
	return genero;
}

void Pelicula::setPuntaje(string puntaje){
	this->puntaje = puntaje;
}

std::string Pelicula::getPuntaje(){
	return puntaje;
}

void Pelicula::setDirector(std::string director){
	this->director = director;
}

std::string Pelicula::getDirector(){
	return director;
}

void Pelicula::setActores(Lista<string> *listaActores){
	actores = listaActores;
}

Lista<string> *Pelicula::getActores(){
	return actores;
}

void Pelicula::agregarActor(string nombre){
	actores->agregar(nombre);
}
