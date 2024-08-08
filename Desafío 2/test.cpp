#include <iostream>
#include <vector>
using namespace std;

void func(vector<int> &vec) {
  vec[0] = 10;
  cout << vec[0] << endl;
}
int main() {
  vector<int> a = {0};
  cout << a[0] << endl;
  func(a);
  cout << a[0];
}
