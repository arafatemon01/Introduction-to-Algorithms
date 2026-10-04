#include <bits/stdc++.h>
using namespace std;
char arr[100][100];
bool vis[100][100];
int n,m;
vector<pair<int,int>> edge_list = {{0,1},{0,-1},{1,0},{-1,0}};
bool valid (int i,int j)
{
    if(i<0||i>n||j<0||j>m) {
        return false;
    }
    return true;
}
void dfs (int src1,int src2)
{
      cout<<src1<<" "<<src2<<endl;
      vis[src1][src2] = true;
      for (int i = 0;i<4;i++)
      {
        int ci = src1 + edge_list[i].first;
        int cj = src2 + edge_list[i].second;
        if (valid (ci,cj) && vis[ci][cj] == false)
        {
            dfs(ci,cj);
        }
      }
}
int main(){
    
    cin>>n>>m;
    for (int i = 0;i<n;i++)
    {
        for (int j= 0;j<m;j++){
            cin>>arr[i][j];
        }
    }
    int s1,s2;
    cin>>s1>>s2;
   memset(vis,false,sizeof (vis));
   dfs(s1,s2);
    return 0;
}