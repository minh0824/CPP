#include <iostream>
#include <map>
#include <vector>
#include <numeric>
#include <set>
#include<algorithm>
using namespace std;
long long pre[3001][3001];
int main(){
int n, m, s;
cin >> n >> m >> s;
int a[n+1][m+1];
for(int i = 1; i <= n; i++)
    for(int j = 1; j <= m; j++){
        cin >> a[i][j];
    pre[i][j]=a[i][j]+pre[i-1][j]+pre[i][j-1]-pre[i-1][j-1];
    }
int l=1,hi=min(n,m),ans=0;
while(l<=hi){
    int mid=l+ (hi-l)/2;
    int x=1;
    for(int i=mid;i<=n;i++){
    for(int j=mid;j<=m;j++){
        long long sum= pre[i][j]-pre[i-mid][j]-pre[i][j-mid]+pre[i-mid][j-mid];
        if(sum<=s)x=0;
    }
    }
    if(x==0){
        ans=mid;l=mid+1;}
    else{hi=mid-1;}
}
cout<<(ans)*(ans);
return 0;
}
