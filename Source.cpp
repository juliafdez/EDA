// Julia Fernandez Reyes
// E14

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resolver(vector <int> v, int n) {
	int max = v[0];
	bool cierto = false;

	if (n + 1 > v.size() - 1) return true;
	else{
		for (int i = 0; i <= n; i++){
			if (v[i] > max){
				max = v[i];
			}
		}
		int min = v[n + 1];
		for (int j = n + 1; j < v.size(); j++){
			if (v[j] < min){
				min = v[j];
			}
		}

		if (max < min) return true;
		else return false;
	}
}

void resuelveCaso(){
	int num, n;
	int x;

	cin >> num;
	cin >> n;
	vector <int> v(num);
	for (int i = 0; i < num; i++){
		cin >> x;
		v[i] = x;
	}

	if (resolver(v, n)) cout << "SI" << endl;
	else cout << "NO" << endl;
}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
	//#ifndef DOMJUDGE
	//	std::ifstream in("datos.txt");
	//	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
	//#endif 
	//

	int numCasos;
	std::cin >> numCasos;
	for (int i = 0; i < numCasos; ++i)
		resuelveCaso();


	//	// Para restablecer entrada. Comentar para acepta el reto
	//#ifndef DOMJUDGE // para dejar todo como estaba al principio
	//	std::cin.rdbuf(cinbuf);
	//	system("PAUSE");
	//#endif

	return 0;
}