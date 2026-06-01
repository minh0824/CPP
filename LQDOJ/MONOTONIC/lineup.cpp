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

int a[nmax];

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  freopen("LINEUP.INP", "r", stdin);
  freopen("LINEUP.OUT", "w", stdout);
  stack<int> st;
  int n; cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    while (!st.empty() && a[st.top()]<=a[i]) st.pop();
    cout << (st.empty() ? 0 : st.top()) << ' ';
    st.push(i);
  }
  return 0;
}
