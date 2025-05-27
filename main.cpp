#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

#define letrasAbecedario 26

const int nRotores = 3;
vector<char> notch(nRotores);
vector<string> permutacionRotor(nRotores);

void gestionarArchivoRotor(const string& path) {
    ifstream entrada;
    entrada.open(path);
    if (!entrada.is_open()) {
        cout << "[AVISO] El archivo \"" << path << "\" no existe" << endl;
        cout << "1. Crear archivo" << endl;
        cout << "2. Error y salir" << endl;
        
        int opt; cin >> opt;
        if (opt == 1) {
            ofstream nuevoArchivo(path);
            if (!nuevoArchivo.is_open()) {
                cerr << "[ERROR] No se ha podido crear el archivo \"" << path << "\".\n";
                return;
            }
            cout << "Introducir la permutaciÃ³n(26 chars): ";
            string permutacion; cin >> permutacion;
            // Contenido predeterminado para un rotor (ejemplo)
            nuevoArchivo << permutacion << endl;
            cout << "Notch: ";
            char notch; cin >> notch;
            nuevoArchivo << notch << endl;
            nuevoArchivo.close();
            entrada.open(path);
            if (!entrada.is_open()) {
                cerr << "[ERROR] No se ha podido abrir el archivo \"" << path << "\".\n";
                return;
            }
        }
        else {
            exit(1);
        }
    }
    
    getline(entrada, permutacionRotor[(path[5]-'0'-1)]);
    entrada >> notch[(path[5]-'0'-1)];
}

void leerRotores() {
    string path = "Rotor1.txt";
    for(int i = 1; i <= nRotores; ++i) {
        path[5] = i +'0';
        gestionarArchivoRotor(path);
    }
}

int main() {
    int opcion = 0;
    while (opcion != 4) {
        cout << "ENIGMA:" << endl << "-------------------------------" << endl;
        cout << "1. Cifrar mensaje" << endl;
        cout << "2. Descifrar mensaje" << endl;
        cout << "3. Editar rotores" << endl;
        cout << "4. Salir" << endl;
        cin >> opcion;
        switch (opcion)
        {
        case 1:
            leerRotores();
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        default:
            break;
        }
    }
}
