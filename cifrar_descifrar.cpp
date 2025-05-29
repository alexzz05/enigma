#include "cifrar_descifrar.hh"

// ----------------------------------------------------------
// CIFRAR / DESCIFRAR
// ----------------------------------------------------------
string cifrarMensaje(const string& textoClaro) {
  cout << "Posicion inicial (3 letras p. ej. ABC): ";
  string ventana;
  cin >> ventana;
  while (ventana.size() != 3 || !esTodoMayusculas(ventana)) {
    cerr << "[ERROR] Introduce exactamente 3 letras A-Z." << endl;
    cin >> ventana;
  }
  for (int i = 0; i < nRotores; ++i) desplazamientos[i] = ventana[i] - 'A';

  string limpio = normalizar(textoClaro), cifrado;
  int grupo5 = 0;

  for (char c : limpio) {
    avanzarRotores();
    char x = pasoAdelante(0, c);
    x = pasoAdelante(1, x);
    x = pasoAdelante(2, x);
    cifrado.push_back(x);
    if (++grupo5 == 5) {
      cifrado.push_back(' ');
      grupo5 = 0;
    }
  }
  if (!cifrado.empty() && cifrado.back() == ' ') cifrado.pop_back();
  return cifrado;
}

string descifrarMensaje(const string& textoCifrado) {
  cout << "Posicion inicial (la misma que al cifrar): ";
  string ventana;
  cin >> ventana;
  while (ventana.size() != 3 || !esTodoMayusculas(ventana)) {
    cerr << "[ERROR] Introduce exactamente 3 letras A-Z." << endl;
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