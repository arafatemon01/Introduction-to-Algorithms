#include <bits/stdc++.h>
using namespace std;
 int n,m;
 int di,dj;
char grid [1005][1005];
bool vis[1005][1005];
bool found = false;
vector<pair<int,int>>d = {{1,0},{-1,0},{0,1},{0,-1}};
bool valid (int i, int j ){
    if (i<0||i>=n||j<0||j>=m)
    {
        return false;
    }
    return true;
}
void dfs (int si , int sj)
{
    if (si == di && sj == dj) 
    {
        found = true;
        return;
    }
    vis[si][sj] = true;
    for ( int i = 0;i<4;i++)
    {
        int ci = si + d[i].first;
        int cj = sj + d[i].second;
        if (valid (ci,cj) && vis[ci][cj] == false && grid[ci][cj] == '.')
       {
          dfs (ci,cj);
          if (found) return;
       }
    }
}
int main(){
    cin>>n>>m;
    for (int i = 0;i<n;i++){
        for (int j = 0;j<m;j++){
            cin>> grid[i][j];
        }
    }
    int si,sj;
    cin>>si>>sj;
    cin>>di>>dj;
    memset(vis,false,sizeof (vis));
    if (grid[si][sj] == '-'|| grid[di][dj] == '-'){
        cout<<"NO";
    }
    else {
        dfs(si,sj);
            if (found) cout<<"YES";
            else cout <<"NO";
    }

    return 0;
}