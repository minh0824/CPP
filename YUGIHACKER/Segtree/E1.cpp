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

struct Segtree {
  int a[nmax], tree[4*nmax];
  void update(int node, int l, int r, int pos, int val) {
    if (l==r) {
      tree[node]+=val;
      return ;
    }
    int mid = (l+r)/2;
    if (pos<=mid) update(node*2, l, mid, pos, val);
    else update(node*2+1, mid+1, r, pos, val);
    tree[node]=tree[node*2]+tree[node*2+1];
  }
  int query(int node, int l, int r, int L, int R) {
    if (r<L || R<l) return 0;
    if (L<=l && r<=R) return tree[node];
    int mid = (l+r)/2;
    return query(node*2, l, mid, L, R)+query(node*2+1, mid+1, r, L, R);
  }
};

int n, q;
string s;
char pos[nmax];
Segtree st[26];

int sum(int l, int r) {
  int cnt{};
  for (int i = 0; i < 26; ++i) {
    if (st[i].query(1, 1, n, l, r)>0) ++cnt;
  }
  return cnt;
}

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cin >> n >> s >> q;
  s=" "+s;
  for (int i = 1; i <= n; ++i) {
    pos[i]=s[i];
    st[s[i]-'a'].update(1, 1, n, i, +1);
  }
  while (q--) {
    int state;
    cin >> state;
    if (state==1) {
      int id; char c;
      cin >> id >> c;
      st[pos[id]-'a'].update(1, 1, n, id, -1);
      pos[id]=c;
      st[pos[id]-'a'].update(1, 1, n, id, +1);
    } else if (state==2) {
      int l, r; cin >> l >> r;
      cout << sum(l, r) << endl;
    }
  }
  return 0;
}
