#include <algorithm>
#include <iostream>
using namespace std;

typedef long long ll;

int main() {
  int x, y, u, v;
  cin >> x >> y >> u >> v;

  if (x > u) swap(x, u);
  if (y < v) swap(y, v);

  int firstRow = v + 1;

  ll q = 0;
  for (int col = max(x + 1, firstRow + 1); col <= u; col++) {
    if (col % 3 == 0) q++;
  }

  ll sum = 0;
  for (int row = firstRow; row <= y; row++) {
    if (row % 3 == 0) {
      sum += max(0, min(u, row) - x);
    }

    sum += q;

    int nextRow = row + 1;
    if (nextRow % 3 == 0 && x < nextRow && nextRow <= u) {
      q--;
    }
  }

  cout << sum;
  return 0;
}
