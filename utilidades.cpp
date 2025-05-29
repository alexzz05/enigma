#include "utilidades.hh"

const int letrasAbecedario = 26;
const int nRotores = 3;
vector<string> permutacionRotor(nRotores);
vector<char> notch(nRotores);
vector<int> desplazamientos(nRotores, 0);

// ----------------------------------------------------------
// VALIDACIONES
// ----------------------------------------------------------
bool esTodoMayusculas(const string& s) {
  return all_of(s.begin(), s.end(),
                [](char c) { return c >= 'A' && c <= 'Z'; });
}

/*  Detecta: longitud≠26, char invalido o duplicados.
    Devuelve false y deja un mensaje en 'motivo'.              */
bool esPermutacionValida(const string& p, string& motivo) {
  if (p.size() != letrasAbecedario) {
    motivo = "hacen falta 26 letras";
    return false;
  }
  if (!esTodoMayusculas(p)) {
    motivo = "solo letras mayusculas A–Z";
    return false;
  }
  set<char> unicas(p.begin(), p.end());
  if (unicas.size() != letrasAbecedario) {
    motivo = "letras repetidas";
    return false;
  }
  return true;
}


// ----------------------------------------------------------
// UTILIDADES DE CIFRADO
// ----------------------------------------------------------
string normalizar(const string& in) {
  string out;
  for (char c : in) {
    if (c >= 'a' && c <= 'z') c -= 32;
    if (c >= 'A' && c <= 'Z') out.push_back(c);
  }
  return out;
}

void avanzarRotores() {
  desplazamientos[0] = (desplazamientos[0] + 1) % 26;
  if (desplazamientos[0] == (notch[0] - 'A'))
    desplazamientos[1] = (desplazamientos[1] + 1) % 26;
  if (desplazamientos[1] == (notch[1] - 'A'))
    desplazamientos[2] = (desplazamientos[2] + 1) % 26;
}

char pasoAdelante(int r, char c) {
  int idxE = (c - 'A' + desplazamientos[r]) % 26;
  char m = permutacionRotor[r][idxE];
  int idxS = (m - 'A' - desplazamientos[r] + 26) % 26;
  return char('A' + idxS);
}
char pasoAtras(int r, char c) {
  int idxE = (c - 'A' + desplazamientos[r]) % 26;
  int pos = permutacionRotor[r].find(char('A' + idxE));
  int idxS = (pos - desplazamientos[r] + 26) % 26;
  return char('A' + idxS);
}
