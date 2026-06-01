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

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  string s; cin >> s;
  stack<ll> st;
  s += "+";
  ll num = 0;
  char op = '+';
  for (int i = 0; i < sz(s); ++i) {
    if (isdigit(s[i])) {
      num = num*10+(s[i]-'0');
    } else {
      if (op == '+') st.push(num);
      else if (op == '-') st.push(-num);
      else if (op == '*') {
        ll x = st.top(); st.pop();
        st.push(x*num);
      } else if (op == '/') {
        ll x = st.top(); st.pop();
        st.push(x/num);
      }
      op = s[i];
      num = 0;
    }
  }
  ll ans{};
  while (!st.empty()) {
    ans+=st.top(); st.pop();
  }
  cout << ans << endl;
  return 0;
}
