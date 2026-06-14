#include <bits/stdc++.h>

using namespace std;

typedef long double ld;
typedef long long ll;

#define endl '\n'
#define ff first
#define ss second
#define pb push_back
#define sz(a) int(a.size())
#define allin(a) begin(a), end(a)

const int mod = 1e9 + 7;
const int nmax = 1e5 + 7;

ld L, V1, V2, S;

bool check(ld mid) {
  ld d = L*sqrtl(2.0L)/2;
  ld x1 = d+V1*mid;
  ld x2 = -d+V2*mid;
  if (x1-x2<0) return 0;
  return (x1-x2)*(x1-x2)/2.0L>=S;
}

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cin >> L >> V1 >> V2;
  if (V1 > V2) swap(V1, V2);
  int q; cin >> q;
  cout << fixed << setprecision(15);
  while (q--) {
    cin >> S;
    ld l = 0, r = L*sqrtl(2.0L)/(V2-V1);
    for (int i = 0; i < 100; ++i) {
      ld mid = (l+r)/2;
      if (check(mid)) {
        l = mid;
      } else {
        r = mid;
      }
    }
    cout << (l+r)/2 << endl;
  }
  return 0;
}
