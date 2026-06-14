#include <bits/stdc++.h>

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
map<int,int> mp;

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  sort(a+1, a+n+1);
  vector<int> b = {0};
  for (int i = 1; i <= n; ++i) {
    if (a[i]!=b.back()) b.pb(a[i]);
  }
  int ans = mod;
  for (int i = 1; i <= n; ++i) {
    int l = lower_bound(b.begin(), b.end(), a[i])-b.begin();
    int r = upper_bound(b.begin(), b.end(), a[i]+n-1)-b.begin();
    ans=min(ans, n-(r-l));
  }
  cout << ans << endl;
  return 0;
}
