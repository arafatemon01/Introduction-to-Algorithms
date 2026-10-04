#include <bits/stdc++.h>
using namespace std;
vector<pair<int,int>>d = {{1,0},{-1,0},{0,1},{0,-1}};
bool vis[100][100];
int dis_arr[100][100];
char arr[102][102];
int n,m;
bool valid (int i ,int j)
{
    if (i<0 || i>=n || j<0 ||j>=m)
    {
        return false;
    }
    return true;
}
void bfs(int src1,int src2)
{
   queue <pair<int,int>>q;
   q.push ({src1,src2});
   vis[src1][src2] = true;
   dis_arr[src1][src2] = 0;
   while (!q.empty())
   {
      pair<int,int>par  = q.front ();
      int a = par.first;
      int b = par.second;
      q.pop();
      for (int i =0;i<4;i++)
      {
        int ci = a + d[i].first;
        int cj = b + d[i].second;
        if (valid(ci,cj) && vis[ci][cj] == false)
        {
            q.push ({ci,cj});
            vis[ci][cj] = true;
            dis_arr[ci][cj] = dis_arr[a][b]+1;
        }
      }
   }
}
int main(){
    cin>>n>>m;
    for (int i = 0 ;i<n;i++)
    {
        for (int j =0;j<m;j++){
            cin>>arr[i][j];
        }
    }
    int si,sj;
    cin>>si>>sj;
    memset (vis,false,sizeof (vis));
    memset (dis_arr,-1,sizeof(dis_arr));
    bfs(si,sj);
    
for(int i = 0; i < n; i++)
{
    for(int j = 0; j < m; j++)
    {
        cout << dis_arr[i][j] << " ";
    }
    cout << endl;
}
    return 0;
}