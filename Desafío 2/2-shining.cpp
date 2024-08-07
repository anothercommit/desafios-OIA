#include <iostream>
#include <vector>

#define POSICION(i) mapa[fila[i]][col[i]]

using namespace std;

int sanar(vector<int>, vector<int>, vector<int>, vector<int>, int,
          vector<vector<char>>);

void printMapa(vector<vector<char>>);

int main() {
  vector<int> fila = {1, 1};
  vector<int> col = {0, 2};
  // vector<int> vidaInicial = {10, 20};
  // vector<int> vidaActual = {6, 10};
  // int d = 3;
  vector<vector<char>> mapa = {
      {'.', 'X', '.'}, {'.', 'X', '.'}, {'.', '.', '.'}};

  for (int i = 1; i < col.size(); ++i)
    POSICION(i) = 'L';

  return 0;
}

int sanar(vector<int> fila, vector<int> col, vector<int> vidaInicial,
          vector<int> vidaActual, int d, vector<vector<char>> mapa) {

  if (0 > fila[0] > mapa.size() || 0 > col[0] > mapa.size() ||
      POSICION(0) == 'X')
    return 0;

  POSICION(0) = 'x';
  int maximaCuracion = 0;

  if (POSICION(0) != 'L') {
    for (int i = 1, size = col.size(); i < size; ++i) {
      // if está a distancia < 2
      // a_curar = (vidaInicial[i] - vidaActual[i]) > 10 ? 10 : (vidaInicial[i]
      // - vidaActual[i])
      // if a_curar > maximaCuracion, maximaCuracion = a_curar
    }
  }

  fila[0] -= 1;
  int arriba = sanar(fila, col, vidaInicial, vidaActual, d - 1, mapa);
  if (maximaCuracion < arriba)
    maximaCuracion = arriba;

  col[0] += 1;
  int derecha = sanar(fila, col, vidaInicial, vidaActual, d - 1, mapa);
  if (derecha > maximaCuracion)
    maximaCuracion = derecha;

  fila[0] += 1;
  int abajo = sanar(fila, col, vidaInicial, vidaActual, d - 1, mapa);
  if (abajo > maximaCuracion)
    maximaCuracion = abajo;

  col[0] -= 1;
  int izquierda = sanar(fila, col, vidaInicial, vidaActual, d - 1, mapa);
  if (maximaCuracion < izquierda)
    maximaCuracion = izquierda;

  return maximaCuracion;
}

void printMapa(vector<vector<char>> mapa) {
  for (int f = 0, size = mapa.size(); f < size; ++f) {
    for (int c = 0, size = mapa[f].size(); c < size; ++c)
      cout << mapa[f][c] << ' ';
    cout << '\n';
  }
}
