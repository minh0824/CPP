#include <bits/stdc++.h>
#include <pthread.h>

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

int n, w, a[nmax];

bool check(int h) {
  ll cur{};
  for (int i = 1; i <= n; ++i) {
    if (h>a[i]) cur+=h-a[i];
    if (cur>w) return 0;
  }
  return cur<=w;
}

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cin >> n >> w;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  int l = 0, r = 1e9+7;
  while (r-l>0) {
    int mid = (r+l+1)/2;
    if (check(mid)) {
      l = mid;
    } else r = mid-1;
  }
  cout << l << endl;
  return 0;
}
