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

int n;
bool P[nmax];
ll fac[nmax];
vector<int> Prime;

void seive() {
  for (int i = 2; i <= nmax; ++i) P[i]=1;
  for (int i = 2; i <= nmax; ++i) {
    if (P[i]) {
      for (ll j = 1ll*i*i; j <= nmax; j+=i) {
        P[j]=0;
      }
    }
  }
}

ll calc(ll x) {
  return (x+1ll)*x/2ll;
}

void tv1() {
  ll ans=1;
  for (int i = 0; Prime[i] <= n; ++i) {
    int cur = Prime[i], res{};
    while (cur<=n) {
      res+=n/cur;
      cur*=Prime[i];
    }
    cout << Prime[i] << ' ' << res << endl;
    if (res&1) ans*=Prime[i];
  }
  cout << fac[n]/ans << endl;
}

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int q; cin >> q;
  seive();
  for (int i = 1; i <= nmax; ++i) {
    if (P[i]) Prime.pb(i);
  }
  fac[0]=1;
  for (int i = 1; i <= 15; ++i) fac[i]=1ll*i*fac[i-1];
  // ll ans=1;
  // for (int i = 0; Prime[i] <= n; ++i) {
  //   int cur = Prime[i], res{};
  //   while (cur<=n) {
  //     res+=n/cur;
  //     cur*=Prime[i];
  //   }
  //   cout << Prime[i] << ' ' << res << endl;
  //   if (res&1) ans*=Prime[i];
  // }
  // cout << fac[n]/ans << endl;
  while (q--) {
    int state;
    cin >> state >> n;
    if (state==1) {
      ll ans=1;
      for (int i = 0; Prime[i] <= n; ++i) {
        int cur = Prime[i], res{};
        while (cur<=n) {
          res+=n/cur;
          cur*=Prime[i];
        }
        cout << Prime[i] << ' ' << res << endl;
        if (res&1) ans*=Prime[i];
      }
      cout << fac[n]/ans << endl;
    } else {
      vector<ll> list;
      for (int i = 0; Prime[i] <= n; ++i) {
        int cur = Prime[i], res{};
        while (cur<=n) {
          res+=n/cur;
          cur*=Prime[i];
        }
        cout << Prime[i] << ' ' << res << endl;
        if (res&1) list.pb(Prime[i]);
      }
      for (auto i : list) cout << i << endl;
    }
  }
  return 0;
}
