//Julia Fernandez
//Agata Sanchez
//E14

#include "horas.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>
// función que resuelve el problema
void busqueda(std::vector<tiempo> const &v, tiempo &t){
	int ini = 0, fin = v.size()-1;
	tiempo aux;
	int  mitad;
	if (t < v[fin] || t == v[fin]){
		while (ini <= fin){
			mitad = (ini + fin) / 2;
			if (t < v[mitad]){
				aux = v[mitad];
				fin = mitad - 1;
			}
			else if (t == v[mitad]){
				aux = v[mitad];
				ini = fin + 1;
			}
			else
				ini = mitad + 1;
		}
		std::cout << aux;
	}
	else
		std::cout << "NO" << "\n";
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int tren, horas;
	std::cin >> tren>> horas;
	

	if (tren == 0 && horas == 0)
		return false;
	
		std::vector<tiempo> v;
		v.resize(tren);
		tiempo t;
		for (int i = 0; i < tren; i++)
			std::cin >> v[i];
		for (int i = 0; i < horas; i++){
			try{
				std::cin >> t;
				busqueda(v, t);
			}
			catch (std::invalid_argument e){
				std::cout << "ERROR" << "\n";
			}				
	}
		std::cout << "---" << "\n";
	

	return true;

}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto


	while (resuelveCaso())
		;


	// Para restablecer entrada. Comentar para acepta el reto
	system("PAUSE");
	return 0;
}