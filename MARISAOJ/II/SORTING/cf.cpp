#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define endl '\n'
#define ff first
#define ss second
#define pb push_back
#define sz(a) int(a.size())
#define allin(a) begin(a), end(a)

const int nmax = 2e5+7;

int n;
double a[nmax], pref[nmax];

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    pref[i]=pref[i-1]+a[i];
  }
  int cnt{};
  for (int i = 1; i <= n; ++i) {
    if (pref[i-1]/(double)(i-1)+(pref[n]-pref[i])/(double)(n-i)==a[i]) ++cnt;
  }
  cout << cnt;
  return 0;
}
