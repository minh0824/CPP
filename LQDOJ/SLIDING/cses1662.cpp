#include "bits/stdc++.h"

using namespace std;

typedef long long ll;

#define endl '\n'
#define ff first
#define ss second
#define pb push_back
#define sz(a) int(a.size())
#define allin(a) begin(a), end(a)

const int nmax = 2e5+7;

int a[nmax];
ll f[nmax];

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  //freopen("test.inp", "r", stdin);
  //freopen("test.out", "w", stdout);
  int n, d; cin >> n;
  d = n;
  for (int i = 1; i <= n; ++i) {
  	cin >> a[i];
  	f[i]=f[i-1]+a[i];
  }
  for (int i = 1; i <= n; ++i) {
  	f[i]%=d;
  	if (f[i]<0) f[i]+=d;
  }
  map<int, int> m;
  ll ans = 0;
  for (int i = 1; i <= n; ++i) {
  	++m[f[i-1]];
  	ans+=m[f[i]];
  }
  cout << ans << endl;
  return 0;
}
