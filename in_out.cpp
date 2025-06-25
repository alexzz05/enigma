#include "in_out.hh"

// ----------------------------------------------------------
// CREAR ROTOR (cuando no existe o tras corrupcion)
// ----------------------------------------------------------
bool crearArchivoRotor(const string& path, ifstream& entrada) { // crea el archivo del Rotor y te avisa si falla
    ofstream nuevoArchivo(path);
    if (!nuevoArchivo) {
        cerr << "[ERROR] No se ha podido crear el archivo \"" << path << "\"."
            << endl;
        return false;
    }

    string permutacion;
    do {
        cout << "Estas creando " << path << endl;
        cout << "Introducir la permutacion (26 chars A-Z, sin espacios): ";
        cin >> permutacion;
        transform(permutacion.begin(), permutacion.end(), permutacion.begin(),
            ::toupper);
        string motivo;
        if (!esPermutacionValida(permutacion, motivo))
            cerr << "[ERROR] " << motivo << "." << endl;
        else
            break;
    } while (true);

    nuevoArchivo << permutacion << '\n';

    cout << "Notch (Enter = Z): ";
    string notchStr;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');   // declara el Notch y si es ENTER le mete una Z
    getline(cin, notchStr);
    char notchChar =
        (notchStr.empty() || !esTodoMayusculas(notchStr)) ? 'Z' : notchStr[0];
    nuevoArchivo << notchChar << '\n';
    nuevoArchivo.close();

    entrada.open(path);                 // lo reabrimos para seguir leyendo
    return entrada.is_open();
}

// ----------------------------------------------------------
// LECTURA / VALIDACION DEL ROTOR DESDE DISCO
// ----------------------------------------------------------
void leerRotor(const string& path) {
    ifstream entrada(path);
    if (!entrada && !crearArchivoRotor(path, entrada)) return;  // comprueba si el Rotor existe o se ha podido crear

    int idx = path[5] - '0' - 1;  // Rotor1.txt --> 0, idx --> se refiere al numero del Rotor que va cambiando

    getline(entrada, permutacionRotor[idx]);   // guarda la linea de 'entrada' en 'permutacionRotor'
    string notchLine;
    getline(entrada, notchLine);               // guarda el char del Notch

    // notch por defecto
    notch[idx] =
        (!notchLine.empty() && esTodoMayusculas(notchLine)) ? notchLine[0] : 'Z';

    string motivo;
    if (!esPermutacionValida(permutacionRotor[idx], motivo)) {
        cerr << "[ERROR] " << path << ": permutacion incorrecta — " << motivo << '.'
            << endl;
        cout << "Crear de nuevo (s/n)? ";                                                   // si la permutacion no es valida, te informa del motivo y te la hace crear
        char resp;
        cin >> resp;
        if (tolower(resp) == 's') crearArchivoRotor(path, entrada);
    }
    entrada.close();
}

void comprobarRotores() {
    string path = "RotorX.txt";
    for (int i = 1; i <= nRotores; ++i) {    // comprueba los Rotores
        path[5] = char('0' + i);
        leerRotor(path);
    }
}

// ----------------------------------------------------------
// MODIFICAR UN ROTOR EXISTENTE
// ----------------------------------------------------------
void modificarRotores() {
    int rotor;
    cout << "Que rotor quieres modificar (1-3): ";   // te pide que Rotor quieres modificar
    cin >> rotor;
    if (rotor < 1 || rotor > 3) return;

    string path = "RotorX.txt";
    path[5] = char('0' + rotor);

    string permutacion, motivo;
    do {
        cout << "Introducir la permutacion (26 chars A-Z): ";
        cin >> permutacion;
        transform(permutacion.begin(), permutacion.end(), permutacion.begin(),   // te pide la Permutacion y la convierte a mayusculas
            ::toupper);
        if (!esPermutacionValida(permutacion, motivo))
            cerr << "[ERROR] " << motivo << '.' << endl;  // si no es valida te da ERROR y te indica el motivo
        else
            break;
    } while (true);

    cout << "Notch (Enter = Z): ";
    string notchStr;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');      // lee el Notch introducido por el usuario
    getline(cin, notchStr);
    char notchChar =
        (notchStr.empty() || !esTodoMayusculas(notchStr)) ? 'Z' : notchStr[0];

    ofstream archivoRotor(path);
    archivoRotor << permutacion << '\n' << notchChar << '\n';  // escribe en el nuevo archivo la Permutacion y el Notch
    archivoRotor.close();

    permutacionRotor[rotor - 1] = permutacion;
    notch[rotor - 1] = notchChar;                               // asigna a ls variables globales la Permutacion y el Notch
    cout << "[OK] Rotor modificado con exito" << endl;
}
