#include <bits/stdc++.h>
#include <deque>

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

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  stack<char> st;
  string s; cin >> s;
  for (int i = 0; i < sz(s); ++i) {
    if (st.empty()) st.push(s[i]);
    else {
      if (st.top()!=s[i]) st.push(s[i]);
      else st.pop();
    }
  }
  cout << (st.empty() ? 1 : 0);
  return 0;
}
