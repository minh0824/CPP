#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define endl '\n'
#define pb push_back
#define allin(a) begin(a), end(a)

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  int n;
  cin >> n;

  ll sum = 0;
  vector<ll> d[3];

  for (int i = 1; i <= n; ++i) {
    ll x;
    cin >> x;
    sum += x;
    d[x % 3].pb(x);
  }

  sort(allin(d[1]));
  sort(allin(d[2]));

  ll remove = 0;
  const ll INF = 4e18;

  if (sum % 3 == 1) {
    ll op1 = d[1].size() >= 1 ? d[1][0] : INF;
    ll op2 = d[2].size() >= 2 ? d[2][0] + d[2][1] : INF;
    remove = min(op1, op2);
  } else if (sum % 3 == 2) {
    ll op1 = d[2].size() >= 1 ? d[2][0] : INF;
    ll op2 = d[1].size() >= 2 ? d[1][0] + d[1][1] : INF;
    remove = min(op1, op2);
  }

  cout << (sum - remove) / 3 << endl;
  return 0;
}
