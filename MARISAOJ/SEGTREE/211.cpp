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
ll lazy[4*nmax], tree[3][4*nmax];

// swap[0][1], swap[0][2]
// khi cong 1 tu l->r
// tat ca cac tap du se doi cho cho nhau

void rotate(int node) {
  swap(tree[0][node], tree[1][node]);
  swap(tree[0][node], tree[2][node]);
}

void build(int node, int l, int r) {
  if (l==r) {
    ++tree[a[l]%3][node];
    return ;
  }

  int mid = (l+r)/2;
  build(node*2, l, mid);
  build(node*2+1, mid+1, r);

  for (int i = 0; i < 3; ++i) {
    tree[i][node]=tree[i][node*2]+tree[i][node*2+1];
  }
}

void push(int node, int l, int r) {
  if (lazy[node]==0) return ;
  lazy[node]%=3;

  if (l!=r) {
    int mid = (l+r)/2;
      for (int i = 1; i <= lazy[node]; ++i) {
        rotate(node*2), rotate(node*2+1);
      }
      lazy[node*2] += lazy[node];
      lazy[node*2+1] += lazy[node];
  }

  lazy[node]=0;
}

void update(int node, int l, int r, int L, int R) {
  if (r<L || R<l) return ;

  if (L<=l && r<=R) {
    rotate(node);
    ++lazy[node]%=3;
    return ;
  }

  push(node, l, r);

  int mid = (l+r)/2;
  update(node*2, l, mid, L, R);
  update(node*2+1, mid+1, r, L, R);

  for (int i = 0; i < 3; ++i) {
    tree[i][node]=tree[i][node*2]+tree[i][node*2+1];
  }
}

ll query(int node, int l, int r, int L, int R) {
  if (r<L || R<l) return 0;

  if (L<=l && r<=R) return tree[0][node];

  push(node, l, r);
  int mid = (l+r)/2;
  return query(node*2, l, mid, L, R)+query(node*2+1, mid+1, r, L, R);
}

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cin >> n >> q;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  build(1, 1, n);
  while(q--) {
    int state; cin >> state;
    int l, r; cin >> l >> r;
    if (state==1) {
      update(1, 1, n, l, r);
    } else {
      cout << query(1, 1, n, l, r) << endl;
    }
  }
  return 0;
}
