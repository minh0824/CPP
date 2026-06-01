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

int n;
int a[nmax], b[nmax];

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  stack<int> st;
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    while (!st.empty() && a[st.top()]>=a[i]) st.pop();
    b[i]=(st.empty() ? 0 : st.top());
    cout << b[i] << ' ';
    st.push(i);
  }
  return 0;
}
