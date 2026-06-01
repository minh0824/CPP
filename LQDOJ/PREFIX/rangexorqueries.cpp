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
const int nmax = 2e5 + 7;

int n, q, a[nmax];
int p[nmax];

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cin >> n >> q;;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    p[i]=p[i-1]^a[i];
  }
  while (q--) {
    int l, r; cin >> l >> r;
    cout << (p[r] xor p[l-1]) << endl;
  }
  return 0;
}
