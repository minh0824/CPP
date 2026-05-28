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

const int nmax = 2e3 + 7;

int dx[4]={-1, 1, 0, 0};
int dy[4]={0, 0, -1, 1};

int n, a[nmax][nmax], d[nmax][nmax];
vector<pair<int,int>> adj[nmax];
bool visited[nmax][nmax], visitedval[nmax];

void bfs() {
  queue<pair<int,int>> q; q.push({1, 1});
  visited[1][1]=1;
  while (!q.empty()) {
    int i = q.front().ff, j = q.front().ss;
    q.pop();
    for (int k=0; k<4; ++k) {
      int ii = i+dx[k], jj = j+dy[k];
      if (ii>0&&ii<=n&&jj>0&&jj<=n&&!visited[ii][jj]) {
        visited[ii][jj]=1;
        d[ii][jj]=d[i][j]+1;
        q.push({ii, jj});
      }
    }
    if (!visitedval[a[i][j]]) {
      for (pair<int,int> x : adj[a[i][j]]) {
        int ii = x.ff, jj = x.ss;
        if (!visited[ii][jj]) {
          visited[ii][jj]=1;
          d[ii][jj]=d[i][j]+1;
          q.push({ii, jj});
        }
      }
      visitedval[a[i][j]]=1;
    }
    if (visited[n][n]) {
      cout << d[n][n];
      return ;
    }
  }
}

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cin >> n;
  for (int i=1; i<=n; ++i) {
    for (int j=1; j<=n; ++j) {
      cin >> a[i][j];
      adj[a[i][j]].pb({i, j});
    }
  }
  bfs();
  return 0;
}
