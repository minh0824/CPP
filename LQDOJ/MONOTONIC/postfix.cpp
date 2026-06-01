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
  string S;
  while (getline(cin, S)) {
    if (S.empty()) continue;
    stringstream ss(S);
    string s;
    stack<ll> st;

    while(ss >> s) {

    if (s=="+"||s=="-"||s=="*") {
      int a = st.top(); st.pop();
      int b = st.top(); st.pop();
      if (s=="+") st.push(a+b);
      else if (s=="-") st.push(b-a);
      else st.push(a*b);
    } else st.push(stoi(s));
    }
  cout << st.top() << endl;
  }
  return 0;
}
