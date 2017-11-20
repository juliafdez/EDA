//Julia Fernandez Reyes	
//E14


#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;
// función que resuelve el problema
// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	int num = 0;
	int max;
	int veces = 1;
	int numMax;
	int i = 0;
	// leer los datos de la entrada
	cin >> num;
	cin >> numMax;
	while (i < num-1){
		//for (int i = 0; i < num; i++){
		cin >> max;
		if (numMax < max){
			numMax = max;
			veces=1;
		}
		else if (numMax == max){
			veces++;
		}

		i++;
	}
	//}
	// escribir sol
	cout << numMax << " " << veces << endl;
}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("prueba.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


	int numCasos;
	std::cin >> numCasos;
	for (int i = 0; i < numCasos; ++i)
		resuelveCaso();


	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}