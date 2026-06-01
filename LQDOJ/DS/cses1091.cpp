#include <iostream>
#include <math.h>
#include <cstring>
#include <utility>
#include <iomanip>
#include <algorithm>
#include <map>
#include <set>
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

int n, m;
multiset<int> ms;

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    int val; cin >> val;
    ms.insert(val);
  }
  for (int i = 1; i <= m; ++i) {
    int v; cin >> v;
    auto it = ms.upper_bound(v);
    if (it != ms.begin()) {
      --it;
      cout << *it << endl;
      ms.erase(ms.find(*it));
    } else {
      cout << -1 << endl;
    }
  }
  return 0;
}
