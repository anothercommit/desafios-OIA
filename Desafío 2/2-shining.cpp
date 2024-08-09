#include <iostream>
#include <string>
#include <vector>

#define POSICION(i) mapa[fila[i]][col[i]]

using namespace std;

int sanar(vector<int> &, vector<int> &, vector<int> &, vector<int> &, int,
          vector<vector<string>> &);
string printMapa(const vector<vector<string>> &);

int main() {
  vector<int> fila;
  vector<int> col;
  vector<int> vidaInicial;
  vector<int> vidaActual;
  vector<vector<string>> mapa;

  int n, r, c, d, num;
  cin >> n >> r >> c;

  for (--n; n >= 0; --n) {
    fila.push_back((cin >> num, num));
    col.push_back((cin >> num, num));
    vidaInicial.push_back((cin >> num, num));
    vidaActual.push_back((cin >> num, num));
  }

  cin >> d;

  for (int y = 0; y < r; ++y) {
    mapa.push_back({});
    for (int x = 0; x < c; ++x) {
      char c = (cin >> c, c);
      mapa[y].push_back(c != 'X' ? "-1" : string(1, c));
    }
  }

  for (int i = 1; i < col.size(); ++i)
    POSICION(i) = "L";

  // cout << printMapa(mapa);

  cout << sanar(fila, col, vidaInicial, vidaActual, d, mapa) << '\n';

  return 0;
}

int sanar(vector<int> &fila, vector<int> &col, vector<int> &vidaInicial,
          vector<int> &vidaActual, int d, vector<vector<string>> &mapa) {
  if (0 > fila[0] || fila[0] >= mapa.size() || 0 > col[0] ||
      col[0] >= mapa[fila[0]].size())
    return 0;
  else if (POSICION(0) == "X" || (d == 0 && POSICION(0) == "L"))
    return 0;
  else if (POSICION(0) != "L" && stoi(POSICION(0)) >= d)
    return 0;

  POSICION(0) = "+";
  cout << printMapa(mapa) << endl;
  POSICION(0) = to_string(d);
  // int maxHeal = 0;

  // if (POSICION(0) != 'L')
  //   for (int i = 0, size = col.size(); i < size; ++i)
  //     if ((abs(fila[0] - fila[i]) + abs(col[0] - col[i])) <= 2) {
  //       int posibleCuracion = vidaInicial[i] - vidaActual[i];

  //       posibleCuracion = posibleCuracion > 10 ? 10 : posibleCuracion;
  //       maxHeal = posibleCuracion > maxHeal ? posibleCuracion : maxHeal;
  //     }

  if (d <= 0)
    return 0;

  fila[0] -= 1;
  int arriba = sanar(fila, col, vidaInicial, vidaActual, d - 1, mapa);
  // if (maxHeal < arriba)
  //   maxHeal = arriba;

  fila[0] += 1;
  col[0] += 1;
  int derecha = sanar(fila, col, vidaInicial, vidaActual, d - 1, mapa);
  // if (derecha > maxHeal)
  //   maxHeal = derecha;

  col[0] -= 1;
  fila[0] += 1;
  int abajo = sanar(fila, col, vidaInicial, vidaActual, d - 1, mapa);
  // if (abajo > maxHeal)
  //   maxHeal = abajo;

  fila[0] -= 1;
  col[0] -= 1;
  int izquierda = sanar(fila, col, vidaInicial, vidaActual, d - 1, mapa);
  // if (maxHeal < izquierda)
  //   maxHeal = izquierda;

  // return maxHeal;
  return 0;
}

string printMapa(const vector<vector<string>> &mapa) {
  string m;

  for (int f = 0, size = mapa.size(); f < size; ++f) {
    for (int c = 0, size = mapa[f].size(); c < size; ++c)
      m += mapa[f][c] + "  ";
    m += '\n';
  }
  return m;
}
