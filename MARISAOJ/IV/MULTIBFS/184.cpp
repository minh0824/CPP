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
const int nmax = 5e3 + 7;

int dx[4]={1, -1, 0, 0};
int dy[4]={0, 0, 1, -1};

int n, r;
char a[nmax][nmax];
vector<pair<int,int>> v;
int cnt;
queue<pair<int,int>> q;

void bfs() {
  for (pair<int, int> i : v) {
    q.push({i.ff, i.ss});
  }
  while (r-- && !q.empty()) {
    int layer = q.size();

    while (layer--) {
      pair<int,int> u = q.front(); q.pop();
      int i = u.ff, j = u.ss;
      for (int k = 0; k < 4; ++k) {
        int ii = i+dx[k], jj = j+dy[k];
        if (ii>=1&&ii<=n&&jj>=1&&jj<=n&&a[ii][jj]=='.') {
          a[ii][jj]='X';
          // cout << ii << ' ' << jj << endl;
          q.push({ii, jj});
        }
      }
    }
  }
}

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cin >> n >> r;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      cin >> a[i][j];
      if (a[i][j]=='X') q.push({i, j});
    }
  }
  bfs();
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) if (a[i][j]=='.') ++cnt;
  }
  cout << cnt;
  return 0;
}
