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

int n, q, a[nmax], b[nmax];
int tree[4*nmax];

void update(int node, int l, int r, int L, int R) {
  if (r<L || R<l) return ;
  if (L<=l && r<=R) {
    tree[node]=1;
    return ;
  }
  int mid = (l+r)/2;
  update(node*2, l, mid, L, R);
  update(node*2+1, mid+1, r, L, R);
}

bool query(int node, int l, int r, int pos) {
  if (l==r) return tree[node];
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
  for (int i = 1; i <= n; ++i) { cin >> a[i]; }
  for (int i = 1; i <= n; ++i) { cin >> b[i]; }
  while (q--) {
    int state; cin >> state;
    if (state==1) {
      int x, y, k;
      update(1, 1, n, x, x)
    }
  }


  return 0;
}
