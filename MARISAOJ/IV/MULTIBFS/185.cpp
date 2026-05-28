#include <iostream>
#include <utility>
#include <algorithm>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;


#define endl '\n'
#define ff first
#define ss second
#define pb push_back
#define sz(a) int(a.size())
#define allin(a) begin(a), end(a)

const int INF = 1e9+7;
const int nmax = 1e5 + 7;

int n, m, k, p;
int doll[nmax], st[nmax], distM[nmax], distD[nmax];
vector<int> adj[nmax];
bool visited[nmax];

void bfs() {
  //BFS Marisa
  queue<int> q;
  q.push(1);
  distM[1]=0;
  while(!q.empty()) {
    int u = q.front(); q.pop();
    for (int v : adj[u]) {
      if (!visited[v]) {
        visited[v]=1;
        distM[v]=distM[u]+1;
        q.push(v);
      }
    }
  }
  //BFS Doll
  memset(visited, 0, sizeof(visited));
  for (int i = 1; i <= k; ++i) {
    distD[doll[i]]=0;
    q.push(doll[i]);
  }
  while (!q.empty()) {
    int u = q.front(); q.pop();
    for (int v : adj[u]) {
      if (!visited[v]) {
        visited[v]=1;
        distD[v]=distD[u]+1;
        q.push(v);
      }
    }
  }
}

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cin >> n >> m >> k >> p;
  for (int i = 1; i <= k; ++i) { cin >> doll[i]; }
  for (int i = 1; i <= p; ++i) { cin >> st[i]; }
  for (int i = 1; i <= m; ++i) {
    int x, y; cin >> x >> y;
    adj[x].pb(y), adj[y].pb(x);
  }
  for (int i = 1; i <= n; ++i) {
    distM[i]=INF, distD[i]=INF;
  }
  bfs();
  for (int i = 1; i <= p; ++i) {
    if (distM[st[i]]<distD[st[i]]) {
      cout << "YES";
      return 0;
    }
  }
  cout << "NO" << endl;
  return 0;
}
