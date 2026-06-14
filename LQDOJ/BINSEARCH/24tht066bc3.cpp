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

int n, k;
double l, v1, v2, tg;

bool check(double t) {
  double total{}, cur{};
  int nn = n/k;
  if (n%k!=0) ++nn;
  for (int i = 1; i < 2*nn; ++i) {
    if (i&1) {
      tg = (l-cur)/v2;
    } else {
      tg = (l-cur)/(v1+v2);
    }
    total+=tg;
    cur+=v1*tg;
  }

}

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cin >> n >> l >> v1 >> v2 >> k;



  return 0;
}
