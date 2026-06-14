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

int n, q;

vector<int> merge(vector<int> a, vector<int> b) {
  for (int i : b) a.pb(i);
  return a;
}

struct segtree {
  int a[nmax];
  vector<int> tree[4*nmax];
  void build(int node, int l, int r) {
    if (l==r) {
      tree[node].pb(a[l]);
      return ;
    }
    int mid = (l+r)/2;
    build(node*2, l, mid);
    build(node*2+1, mid+1, r);
    tree[node]=merge(tree[node*2], tree[node*2+1]);
  }
  vector<int> fin(int node, int l, int r, int L, int R) {
    if (r<L || R<l) return {};
    if (L<=l && r<=R) {
      return tree[node];
    }
    int mid = (l+r)/2;
    return merge(fin(node*2, l, mid, L, R), fin(node*2+1, mid+1, r, L, R));
  }
};

segtree A, B;

void update(int node, int l, int r, int L, int R) {
  if (r<L || R<l) return ;
  if (L<=l && r<=R) {
    A.tree[node]=B.tree[node];
  }
  int mid = (l+r)/2;
  update(node*2, l, mid, L, R);
  update(node*2+1, mid+1, r, L, R);
}

int query(int node, int l, int r, int pos) {
  if (l==r) return A.tree[node][0];
  int mid = (l+r)/2;
  if (pos<=mid) {
    return query(node*2, l, mid, pos);
  } else {
    return query(node*2+1, mid+1, r, pos);
  }
}

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cin >> n >> q;
  for (int i = 1; i <= n; ++i) cin >> A.a[i];
  for (int i = 1; i <= n; ++i) cin >> B.a[i];
  A.build(1, 1, n), B.build(1, 1, n);
  return 0;
}
