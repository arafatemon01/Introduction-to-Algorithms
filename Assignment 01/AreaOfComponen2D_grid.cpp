#include <bits/stdc++.h>
using namespace std;
int n,m;
char grid[1002][1002];
bool vis[1002][1002];
vector <pair<int, int>>d = {{1,0},{-1,0},{0,1},{0,-1}};
bool valid (int i, int j)
{
    if (i<0 || i>=n || j<0 || j>=m)
    {
        return false;
    }
    return true;
}
int dfs (int si , int sj)
{
    vis[si][sj] = true;
    int cnt = 1;
    for (int i = 0;i<4 ;i++)
    {
        int ci = d[i].first + si;
        int cj = d[i].second + sj;
        if (valid (ci,cj) && grid[ci][cj] == '.'&& vis[ci][cj]== false)
        {
            cnt = cnt + dfs (ci,cj);
        }
    }
    return cnt;
}
int main(){
    cin>>n>>m;
    for (int i = 0;i<n;i++)
    {
        for (int j = 0 ;j<m;j++)
        {
            cin>>grid[i][j];
        }
    }
    int mn = INT_MAX;
    bool found = false;
    for (int i = 0;i<n;i++)
    {
        for (int j = 0;j<m;j++){
            if (grid[i][j] == '.' && vis[i][j]== false)
            {
                int area = dfs(i,j);
                mn = min(mn,area);
                found = true;
            }
        }
    }
    if (found == false ) cout<<"-1";
    else cout<<mn;
    return 0;
}