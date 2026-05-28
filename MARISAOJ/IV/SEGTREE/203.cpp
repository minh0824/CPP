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
ll tree[4*nmax], lazy[4*nmax];

void build(int node, int l, int r) {
  if (l==r) {
    tree[node]=a[l];
    return ;
  }

  int mid = l + (r-l)/2;
  build(node*2, l, mid);
  build(node*2+1, mid+1, r);

  tree[node]=tree[node*2]+tree[node*2+1];
}

void push(int node, int l, int r) {
  if (lazy[node]==0) return ;

  // cap nhat lazy den 2 node duoi
  if (l!=r) {
    int mid = l + (r-l)/2;

    tree[node*2] += lazy[node] * (mid-l+1);
    lazy[node*2] += lazy[node];

    tree[node*2+1] += lazy[node] * (r-mid);
    lazy[node*2+1] += lazy[node];
  }

  //reset lazy sau khi cap nhat xong;
  lazy[node]=0;
}

void update(int node, int l, int r, int L, int R, ll val) {
  if (r<L || R<l) return ;

  // neu node nam hoan toan trong l r
  if (L<=l && r<=R) {
    tree[node] += val * (r-l+1);
    lazy[node] += val;
    return ;
  }

  // nam mot phan thi phai update node duoi de con tinh tiep
  push(node, l, r);

  int mid = l + (r-l)/2;

  update(node*2, l, mid, L, R, val);
  update(node*2+1, mid+1, r, L, R, val);

  tree[node]=tree[node*2]+tree[node*2+1];
}


ll query(int node, int l, int r, int L, int R) {
  if (r<L || R<l) return 0;

  // neu nam trong doan nay thi return luon
  if (L<=l && r<=R) {
    return tree[node];
  }

  // day lazy xuong duoi de tinh tiep
  push(node, l, r);

  int mid = l + (r-l)/2;
  return query(node*2, l, mid, L, R)+query(node*2+1, mid+1, r, L, R);
}

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cin >> n >> q;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  build(1, 1, n);
  while (q--) {
    int state; cin >> state;
    if (state==1) {
      int l, r;
      ll val;
      cin >> l >> r >> val;
      update(1, 1, n, l, r, val);
    } else {
      int l, r;
      cin >> l >> r;
      cout << query(1, 1, n, l, r) << endl;
    }
  }
  return 0;
}
