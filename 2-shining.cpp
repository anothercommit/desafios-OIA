#include <iostream>
#include <vector>
#define posicion(i) (mapa[fila[(i)]][col[(i)]])

using namespace std;

int sanar(vector<int>, vector<int>, vector<int>, vector<int>, int,
          vector<vector<char>>);

int main() {
  vector<int> fila = {1, 1};
  vector<int> col = {0, 2};
  // vector<int> vidaInicial = {10, 20};
  // vector<int> vidaActual = {6, 10};
  // int d = 3;
  vector<vector<char>> mapa = {
      {'.', 'X', '.'}, {'.', 'X', '.'}, {'.', '.', '.'}};

  cout << posicion(0) << '\n';
  // sanar(fila, col, vidaInicial, vidaActual, d, mapa);
  return 0;
}

int sanar(vector<int> fila, vector<int> col, vector<int> vidaInicial,
          vector<int> vidaActual, int d, vector<vector<char>> mapa) {

  if (posicion(0) == '.')
    return 1;

  return 0;
}
