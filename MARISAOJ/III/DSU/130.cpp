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

int n;
int parent[nmax], sz[nmax];

void make_set() {
  for (int i = 1; i <= n; ++i) {
    parent[i]=i;
    sz[i]=1;
  }
}

int find(int v) {
  if (v==parent[v]) return v;
  return find(parent[v]);
}

void union_set(int a, int b) {

}

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int q;
  cin >> n >> q;
  return 0;
}
