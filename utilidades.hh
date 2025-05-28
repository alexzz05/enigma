#include <string>
#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
using namespace std;

extern const int letrasAbecedario;
extern const int nRotores;
extern vector<string> permutacionRotor;
extern vector<char> notch;
extern vector<int> desplazamientos;

bool esTodoMayusculas(const string& s);
bool esPermutacionValida(const string& p, string& motivo);
string normalizar(const string& in);
void avanzarRotores();
char pasoAdelante(int r, char c);
char pasoAtras(int r, char c);