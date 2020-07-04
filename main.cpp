#include "CargadorDeArchivos.h"
#include "Menu.h"
using namespace std;

int main() {

	CargadorDeArchivos cargador;
	Menu menu;

	cargador.cargarPeliculasVistas("peliculas_vistas.txt");
	cargador.cargarPeliculasNoVistas("peliculas_no_vistas.txt");

	menu.agregarPeliculasNoVistas(cargador.obtenerPeliculasNoVistas());
	menu.agregarPeliculasVistas(cargador.obtenerPeliculasVistas());

	menu.calcularRecomendadas();
	
	menu.mostrarMenu();

	cout << "** fin **" << endl;

	return 0;
}
