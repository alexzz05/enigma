#include "main.hh"

// ----------------------------------------------------------
// MAIN
// ----------------------------------------------------------
int main() {
    int opcion = 0;
    while (opcion != 4) {
        cout << "ENIGMA:\n-------------------------------\n";
        cout << "1. Cifrar mensaje\n2. Descifrar mensaje\n3. Editar rotores\n4. Salir\n";
        cin >> opcion;

        switch (opcion) {
        case 1: {  // Cifrar
            if (permutacionRotor[0].empty()) comprobarRotores();

            cout << "¿Como quieres introducir el mensaje?\n1. Teclado\n2. Leer \"desxifrat.txt\"\n";
            int modoEntrada;
            cin >> modoEntrada;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            string texto;
            if (modoEntrada == 1) {
                cout << "> ";
                getline(cin, texto);
            }
            else if (modoEntrada == 2) {
                ifstream in("desxifrat.txt");
                if (!in) { cerr << "[ERROR] Falta \"desxifrat.txt\".\n"; break; }
                texto.assign((istreambuf_iterator<char>(in)), istreambuf_iterator<char>());
            }
            else { cerr << "[ERROR] Opción no válida.\n"; break; }

            string res = cifrarMensaje(texto);
            ofstream("xifrat.txt") << res;

            int letras = count_if(res.begin(), res.end(), [](char c) {return c != ' '; });
            int grupos = (letras + 4) / 5;
            cout << "[OK] Mensaje cifrado a \"xifrat.txt\" (" << letras
                << " letras, " << grupos << " grupos de 5)\n\n";
            break;
        }
        case 2: {  // Descifrar
            if (permutacionRotor[0].empty()) comprobarRotores();

            cout << "¿Como quieres introducir el cifrado?\n1. Teclado\n2. Leer \"xifrat.txt\"\n";
            int modoEntrada;
            cin >> modoEntrada;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            string cifrado;
            if (modoEntrada == 1) {
                cout << "> ";
                getline(cin, cifrado);
            }
            else if (modoEntrada == 2) {
                ifstream in("xifrat.txt");
                if (!in) { cerr << "[ERROR] Falta \"xifrat.txt\".\n"; break; }
                cifrado.assign((istreambuf_iterator<char>(in)), istreambuf_iterator<char>());
            }
            else { cerr << "[ERROR] Opción no valida.\n"; break; }

            string claro = descifrarMensaje(cifrado);
            ofstream("desxifrat.txt") << claro;

            cout << "[OK] Mensaje descifrado a \"desxifrat.txt\" (" << claro.size()
                << " letras)\n\n";
            break;
        }
        case 3:
            comprobarRotores();
            modificarRotores();
            break;
        }
    }
}