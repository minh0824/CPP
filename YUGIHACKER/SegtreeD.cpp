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
const int nmax = 2e5 + 7;

struct st {
  ll p, s, sum, maxval;
};

int n, q, a[nmax];
st tree[4*nmax];

st merge(st a, st b) {
  st c;
  c.sum=a.sum+b.sum;
  // 2 truong hop
  c.p = max(a.p, a.sum+b.p);
  // 2 truong hop
  c.s = max(b.s, b.sum+a.s);
  // 3 truong hop
  c.maxval = max(a.s+b.p, max(a.maxval, b.maxval));
  return c;
}

void build(int node, int l, int r) {
  if (l==r) {
    tree[node].sum=a[l];
    tree[node].maxval=max(0, a[l]);
    tree[node].p=max(0, a[l]);
    tree[node].s=max(0, a[l]);
    return ;
  }
  int mid = (l+r)/2;
  build(node*2, l, mid);
  build(node*2+1, mid+1, r);
  tree[node]=merge(tree[node*2], tree[node*2+1]);
}

void update(int node, int l, int r, int pos, ll val) {
  if (l==r) {
    tree[node].sum=val;
    tree[node].maxval=max(0ll, val);
    tree[node].p=max(0ll, val);
    tree[node].s=max(0ll, val);
    return ;
  }
  int mid = (l+r)/2;
  if (pos<=mid) {
    update(node*2, l, mid, pos, val);
  } else {
    update(node*2+1, mid+1, r, pos, val);
  }
  tree[node]=merge(tree[node*2], tree[node*2+1]);
}

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cin >> n >> q;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  build(1, 1, n);
  while (q--) {
    int pos, val; cin >> pos >> val;
    update(1, 1, n, pos, val);
    cout << tree[1].maxval << endl;
  }
  return 0;
}
