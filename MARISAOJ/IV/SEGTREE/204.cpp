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

const ll INF = 1e18+7;
const int mod = 1e9 + 7;
const int nmax = 1e5 + 7;

int n, q, a[nmax];
ll lazy[4*nmax], tree[4*nmax];

void build(int node, int l, int r) {
  if (l==r) {
    tree[node]=a[l];
    return ;
  }

  int mid = l + (r-l)/2;
  build(node*2, l, mid);
  build(node*2+1, mid+1, r);

  tree[node]=min(tree[node*2], tree[node*2+1]);
}

// day lazy xuong duoi
void push(int node, int l, int r) {
  // neu lazy[node]==0 thi return ;
  if (lazy[node]==0) return ;

  if (l!=r) {
    tree[node*2] += lazy[node];
    lazy[node*2] += lazy[node];

    tree[node*2+1] += lazy[node];
    lazy[node*2+1] += lazy[node];
  }

  // push xong thi reset lazy[node];
  lazy[node]=0;
}

void update(int node, int l, int r, int L, int R, ll val) {
  if (r<L || R<l) return ;

  if (L<=l && r<=R) {
    tree[node] += val;
    // update cho lazy;
    lazy[node] += val;
    return ;
  }

  // neu nam ngoai thi ta phai push lazy de tinh;
  push(node, l, r);

  int mid = l + (r-l)/2;
  update(node*2, l, mid, L, R, val);
  update(node*2+1, mid+1, r, L, R, val);

  tree[node]=min(tree[node*2], tree[node*2+1]);
}

ll query(int node, int l, int r, int L, int R) {
  if (r<L || R<l) return INF;

  if (L<=l && r<=R) return tree[node];

  push(node, l, r);

  int mid = l + (r-l)/2;
  return min(query(node*2, l, mid, L, R), query(node*2+1, mid+1, r, L, R));
}

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cin >> n >> q;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  build(1, 1, n);
  while (q--) {
    int state; cin >> state;
    if (state==1) {
      int l, r; ll x;
      cin >> l >> r >> x;
      update(1, 1, n, l, r, x);
    }
    else {
      int l, r; cin >> l >> r;
      cout << query(1, 1, n, l, r) << endl;
    }
  }

  return 0;
}
