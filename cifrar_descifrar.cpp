#include "cifrar_descifrar.hh"

// ----------------------------------------------------------
// CIFRAR / DESCIFRAR
// ----------------------------------------------------------
string cifrarMensaje(const string& textoClaro) {
    cout << "Posicion inicial (3 letras p. ej. ABC): ";
    string ventana;
    cin >> ventana;
    while (ventana.size() != 3 || !esTodoMayusculas(ventana)) {
        cerr << "[ERROR] Introduce exactamente 3 letras A-Z." << endl;      // te pide una ventana y si la introduces mal da ERROR
        cin >> ventana;
    }
    for (int i = 0; i < nRotores; ++i) desplazamientos[i] = ventana[i] - 'A';       // guarda como de movido esta el Rotor respecto de la posicion inicial

    string limpio = normalizar(textoClaro), cifrado; // normalizar lo convierte a mayusculas y elimina chars que no son letras
    int grupo5 = 0;

    for (char c : limpio) {     // char c : limpio --> el 'for' itera 'char c' por cada elemento de 'limpio' 
        avanzarRotores();                       // 'limpio' es el texto por cifrar
        char x = pasoAdelante(0, c); // char x = char cifrado por el Rotor
        x = pasoAdelante(1, x);
        x = pasoAdelante(2, x);
        cifrado.push_back(x);
        if (++grupo5 == 5) {
            cifrado.push_back(' ');     // ---> cada 5 letras ponen un espacio (cifrado militar)
            grupo5 = 0;
        }
    }
    if (!cifrado.empty() && cifrado.back() == ' ') cifrado.pop_back();   // si cifrado no esta vacio y el ultimo elemento es un espacio, elimina el ultimo elemento
    return cifrado;
}

string descifrarMensaje(const string& textoCifrado) {
    cout << "Posicion inicial (la misma que al cifrar): ";
    string ventana;
    cin >> ventana;
    while (ventana.size() != 3 || !esTodoMayusculas(ventana)) {
        cerr << "[ERROR] Introduce exactamente 3 letras A-Z." << endl;          // hace el proceso inverso de 'cifrarMensaje()'
        cin >> ventana;
    }
    for (int i = 0; i < nRotores; ++i) desplazamientos[i] = ventana[i] - 'A';

    string limpio = normalizar(textoCifrado), claro;
    for (char c : limpio) {
        avanzarRotores();
        char x = pasoAtras(2, c);
        x = pasoAtras(1, x);
        x = pasoAtras(0, x);
        claro.push_back(x);
    }
    return claro;
}