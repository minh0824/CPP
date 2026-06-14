#include <iostream>
#include <math.h>
#include <cstring>
#include <utility>
#include <iomanip>
#include <algorithm>
#include <map>
#include <queue>
#include <vector>

using namespace std;

typedef long long ll;

#define endl '\n'
#define ff first
#define ss second
#define pb push_back
#define sz(a) int(a.size())
#define allin(a) begin(a), end(a)

const int mod = 1e9 + 7;
const int nmax = 1e5 + 7;

int n, a[nmax];

void quickSort(int l, int r) {
  int p = a[(l+r)/2];
  int i = l, j = r;
  while (i < j) {
    while (a[i] < p) i++;
    while (a[j] > p) j--;
    if (i <= j) {
      swap(a[i], a[j]);
      i++;
      j--;
    }
  }
  if (i < r) quickSort(i, r);
  if (l < j) quickSort(l, j);
}

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  quickSort(1, n);
  for (int i = 1; i <= n; ++i) cout << a[i] << ' ';
  cout << endl;

  return 0;
}
