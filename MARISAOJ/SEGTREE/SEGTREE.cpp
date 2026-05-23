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

int n, q, a[nmax];
// tao segtree voi y nghia la tong cua doan tu l_r
ll tree[4*nmax];

void build(int node, int l, int r) {
  // node la [l, r];
  // neu node chi gom 1 phan tu -> tra ve gtri goc
  if (l==r) {
    tree[node]=a[l];
    return;
  }

  int mid = l+(r-l)/2;

  build(node*2, l, mid);
  build (node*2+1, mid+1, r);

  // segtree tinh tong
  tree[node] = tree[node*2] + tree[node*2+1];
}

ll query(int node, int l, int r, int L, int R) {
  // neu l, r nam ngoai khoang yeu cau:
  if (r<L || l>R) return 0;

  if (L<=l && r<=R) return tree[node];

  int mid = l + (r-l)/2;
  ll lo = query(node*2, l, mid, L, R);
  ll hi = query(node*2+1, mid+1, r, L, R);

  return lo+hi;
}

void update(int node, int l, int r, int pos, int val) {
  if (l==r) {
    tree[node]=val;
    return ;
  }

  int mid = l + (r-l)/2;

  if (pos<=mid) {
    update(node*2, l, mid, pos, val);
  } else {
    update(node*2+1, mid+1, r, pos, val);
  }

  tree[node] = tree[node*2] + tree[node*2+1];
}

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cin >> n >> q;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  build(1, 1, n);
  while (q--) {
    int state; cin >> state;
    if (state==1) {
      int i, x; cin >> i >> x;
      update(1, 1, n, i, x);
    }
    else {
      int l, r; cin >> l >> r;
      cout << query(1, 1, n, l, r) << endl;
    }
  }
  return 0;
}
