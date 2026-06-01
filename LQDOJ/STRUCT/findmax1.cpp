#include <iostream>
#include <math.h>
#include <cstring>
#include <utility>
#include <iomanip>
#include <algorithm>
#include <map>
#include <queue>
#include <vector>

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

int q;

struct Segtree {
  int n;
  ll tree[4*nmax];
  void update(int node, int l, int r, int pos, int val) {
    if (l==r) {
      tree[node]=val;
      return ;
    }
    int mid = (l+r)/2;
    if (pos<=mid) update(node*2, l, mid, pos, val);
    else update(node*2+1, mid+1, r, pos, val);
    tree[node]=max(tree[node*2], tree[node*2+1]);
  }
  ll query(int node, int l, int r, int L, int R) {
    if (r<L || R<l) return 0;
    if (L<=l && r<=R) return tree[node];
    int mid = (l+r)/2;
    return max(query(node*2, l, mid, L, R), query(node*2+1, mid+1, r, L, R));
  }
};

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  Segtree st;
  cin >> st.n >> q;
  for (int i = 1; i <= st.n; ++i) {
    int x; cin >> x;
    st.update(1, 1, st.n, i, x);
  }
  while (q--) {
    int t, a, b; cin >> t >> a >> b;
    if (t==1) st.update(1, 1, st.n, a, b);
    else cout << st.query(1, 1, st.n, a, b) << endl;
  }
  return 0;
}
