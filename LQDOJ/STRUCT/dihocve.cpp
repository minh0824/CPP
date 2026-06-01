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

int n;

struct monkey {
  pair<int, int> a[nmax];
  void ss() {
    for (int i = 1; i <= n; ++i) {
      cin >> a[i].ff;
      a[i].ss=i;
    }
    sort(a+1, a+n+1);
    for (int i = 1; i <= n; ++i) cout << a[i].ss << ' ';
  }
};

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cin >> n;
  monkey mk;
  mk.ss();
  return 0;
}
