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
const int nmax = 2e5 + 7;

int n, k, a[nmax];
map<int, int> mp;

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cin >> n >> k;
  int j = 1;
  ll ans{};
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    ++mp[a[i]];
    while (mp.size()>k) {
      if (--mp[a[j]]==0) mp.erase(a[j]);
      ++j;
    }
    ans+=i-j+1;
  }
  cout << ans << endl;
  return 0;
}
