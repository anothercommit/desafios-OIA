#include <algorithm>
#include <iostream>
#include <vector>

#define POSICION(i) mapa[fila[i]][col[i]]

using namespace std;

int sanar(vector<int>, vector<int>, vector<int>, vector<int>, int,
          vector<vector<char>>);

void printMapa(vector<vector<char>>);

int main() {
  vector<int> fila;
  vector<int> col;
  vector<int> vidaInicial;
  vector<int> vidaActual;
  vector<vector<char>> mapa;

  int n, r, c, d, num;
  cin >> n >> r >> c;

  for (--n; n >= 0; --n) {
    fila.push_back((cin >> num, num));
    col.push_back((cin >> num, num));
    vidaInicial.push_back((cin >> num, num));
    vidaActual.push_back((cin >> num, num));
  }

  cin >> d;

  char ch;
  for (int y = 0; y < r; ++y) {
    mapa.push_back({});
    for (int x = 0; x < c; ++x)
      mapa[y].push_back((cin >> ch, ch));
  }

  for (int i = 1; i < col.size(); ++i)
    POSICION(i) = 'L';

  printMapa(mapa);

  cout << sanar(fila, col, vidaInicial, vidaActual, d, mapa) << '\n';

  return 0;
}

int sanar(vector<int> fila, vector<int> col, vector<int> vidaInicial,
          vector<int> vidaActual, int d, vector<vector<char>> mapa) {
  if (0 > fila[0] || fila[0] >= mapa.size() || 0 > col[0] ||
      col[0] >= mapa.size())
    return 0;
  else if (POSICION(0) == 'X' || d == 0)
    return 0;

  POSICION(0) = 'X';
  int maxHeal = 0;

  if (POSICION(0) != 'L')
    for (int i = 1, size = col.size(); i < size; ++i)
      if ((abs(fila[0] - fila[i]) + abs(col[0] - col[i])) <= 2) {
        int posibleCuracion = vidaInicial[i] - vidaActual[i];

        posibleCuracion = posibleCuracion > 10 ? 10 : posibleCuracion;
        maxHeal = posibleCuracion > maxHeal ? posibleCuracion : maxHeal;
        cout << "posibleCuracion = " << posibleCuracion << ' ';
        cout << "maxHeal = " << maxHeal << endl;
      }

  fila[0] -= 1;
  int arriba = sanar(fila, col, vidaInicial, vidaActual, d - 1, mapa);
  if (maxHeal < arriba)
    maxHeal = arriba;

  fila[0] += 1;
  col[0] += 1;
  int derecha = sanar(fila, col, vidaInicial, vidaActual, d - 1, mapa);
  if (derecha > maxHeal)
    maxHeal = derecha;

  col[0] -= 1;
  fila[0] += 1;
  int abajo = sanar(fila, col, vidaInicial, vidaActual, d - 1, mapa);
  if (abajo > maxHeal)
    maxHeal = abajo;

  fila[0] -= 1;
  col[0] -= 1;
  int izquierda = sanar(fila, col, vidaInicial, vidaActual, d - 1, mapa);
  if (maxHeal < izquierda)
    maxHeal = izquierda;

  return maxHeal;
}

void printMapa(vector<vector<char>> mapa) {
  for (int f = 0, size = mapa.size(); f < size; ++f) {
    for (int c = 0, size = mapa[f].size(); c < size; ++c)
      cout << mapa[f][c] << ' ';
    cout << '\n';
  }
}
