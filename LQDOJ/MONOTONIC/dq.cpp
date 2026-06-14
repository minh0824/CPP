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
const int nmax = 5e5 + 7;

int a[nmax];

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  deque<int> dq;
  int n, k; cin >> n >> k;
  ll ans{};
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    while (!dq.empty() && a[dq.back()]>=a[i]) dq.pop_back();
    dq.push_back(i);
    if (dq.front() <= i-k) dq.pop_front();
    if (i>=k) cout << a[dq.front()] << endl;
  }
  return 0;
}
