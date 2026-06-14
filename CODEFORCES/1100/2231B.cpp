#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define endl '\n'
#define ff first
#define ss second
#define pb push_back
#define sz(a) int(a.size())
#define allin(a) begin(a), end(a)
#define pii pair<int,int>

const int mod = 1e9 + 7;
const int nmax = 2e5 + 7;

int n, a[nmax], mp[nmax], ms[nmax];
bool mark[nmax];

bool check() {
  for (int i = 1; i <= n; ++i) {
    if (a[i-1]>a[i]) return 0;
  }
  return 1;
}

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int tt; cin >> tt;
  while(tt--) {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
      cin >> a[i];
    }
    int k{};
    for (int i = 1; i <= n; ++i) {
      if (a[i-1]>a[i]) {
        k = max(k, a[i-1]-a[i]);
      }
    }
    for (int i = 1; i <= n; ++i) {
      if (a[i-1]>a[i]) a[i]+=k;
    }
    if (check()) cout << "YES" << endl;
    else cout << "NO" << endl;
  }
  return 0;
}
