#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

#define letrasAbecedario 26

const int nRotores = 3;
vector<int> notch(nRotores);
vector<vector<char>> permutacionRotor(nRotores, vector<char>(letrasAbecedario));

int main() {
    int opcion = 0;
    while (opcion != 4) {
        cout << "ENIGMA:" << endl << "-------------------------------" << endl;
        cout << "1. Xifrar missatge" << endl;
        cout << "2. Desxifrar missatge" << endl;
        cout << "3. Editar rotors" << endl;
        cout << "4. Sortir" << endl;
        switch (opcion)
        {
        case 1:
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
