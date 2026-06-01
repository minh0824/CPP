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

int n, l;
ll ans;

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cin >> n >> l;
  for (int i = 1; i <= n; ++i) {
    int x; cin >> x;
    ans+=x;
  }
  cout << ans/(2*l+1);

  return 0;
}
