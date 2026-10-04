#include <bits/stdc++.h>
using namespace std;
vector<pair<int,int>>d = {{2,1},{2,-1},{-2,1},{-2,-1},{1,2},{-1,2},{1,-2},{-1,-2}};
int n,m;
bool vis[102][102];
int dis[102][102];
bool valid (int i, int j)
{
    if (i<0 || i>=n || j<0 || j>=m)
    {
        return false;
    }
    return true;
}
int bfs (int ki ,int kj , int qi, int qj){
   queue <pair<int,int>>q;
   q.push ({ki,kj});
   vis[ki][kj] = true;
   dis[ki][kj] = 0;
   while (!q.empty())
   {
    pair <int,int> par = q.front ();
    q.pop ();
    int i = par.first;
    int j = par.second ;
    if (i == qi && j == qj)
    {
        return dis[i][j];
    }
    for (auto dir : d)
    {
        int ni = i + dir.first;
        int nj = j + dir.second;
        if (valid (ni,nj) && vis[ni][nj] == false)
        {
            vis[ni][nj] = true;
            dis[ni][nj] = dis[i][j] + 1;
            q.push ({ni,nj});
        }
    }
   }
   return -1;
}
int main(){
    int t;
    cin>>t;
    while (t--)
    {
        memset(vis, false, sizeof(vis));
        memset(dis, 0, sizeof(dis));
        cin>>n>>m;
        int ki,kj;
        cin>>ki>>kj;
        int qi,qj;
        cin>>qi>>qj;
        cout<<bfs (ki,kj,qi,qj)<<endl;
    }
    
    return 0;
}