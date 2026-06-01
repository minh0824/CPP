#include <iostream>
#include <math.h>
#include <cstring>
#include <utility>
#include <iomanip>
#include <algorithm>
#include <map>
#include <queue>
#include <set>
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

int x, n;

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cin >> x >> n;
  multiset<int> p, g;
  p.insert(0), p.insert(x);
  g.insert(x);
  for (int i = 1; i <= n; ++i) {
    int j; cin >> j;
    auto it = p.lower_bound(j);
    int sj=*it;
    --it;
    int pj=*it;
    p.insert(j);
    g.erase(g.find(sj-pj));
    g.insert(sj-j), g.insert(j-pj);
    cout << *g.rbegin() << ' ';
  }
  return 0;
}
