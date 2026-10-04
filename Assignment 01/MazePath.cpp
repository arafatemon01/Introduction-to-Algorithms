#include <bits/stdc++.h>
using namespace std;
int n,m;
char grid [1003][1003];
bool vis[1003][1003];
vector <pair <int,int>>d = {{0,1},{0,-1},{-1,0},{1,0}};
pair <int,int> parent [1003][1003];
bool valid (int i , int j)
{
    if (i<0 || i>= n || j<0 || j>= m)
        return false;
    if (vis[i][j])
        return false;
    if (grid[i][j] == '#')
        return false;
return true;
}
void bfs (int si, int sj, int di, int dj)
{
   queue <pair<int,int>>q;
   q.push({si,sj});
   vis[si][sj] = true;
   parent [si][sj] = {-1,-1};
   while (!q.empty ())
   {
    auto current = q.front();
    q.pop();
    int ci = current.first;
    int cj = current.second;
    if (ci == di && cj == dj)
        break;
    for (int i = 0; i<4 ;i++){
        int ni = ci + d[i].first;
        int nj = cj + d[i].second;

        if (valid(ni,nj))
          {
            vis[ni][nj] = true;
            parent[ni][nj] = {ci,cj};
            q.push({ni,nj});
          }
    }    
   }
   if (!vis[di][dj])
      return;
   int i = di;
   int j = dj;
   while (!(i==si && j ==sj))
   {
      if (grid[i][j] != 'D')
      {
        grid[i][j] = 'X';
      }
    int pi = parent[i][j].first;
    int pj = parent[i][j].second;
    i = pi;
    j = pj;
   }   
}
int main(){
 cin>>n>>m;
int si = -1,sj=-1, di = -1, dj = -1 ;
for (int i = 0;i<n;i++)
{
    for (int j = 0; j<m; j++)
    {
        cin>>grid[i][j];
        if (grid[i][j] == 'R')
            {
                si = i;
                sj = j;
            }
        if (grid [i][j] == 'D')
           {
              di = i;
              dj = j;
           }    
    }
}
bfs (si, sj, di, dj);
for (int i = 0;i<n;i++)
{
    for (int j = 0;j<m;j++)
    {
        cout<<grid[i][j];
    }
    cout<<endl;
}
    return 0;
}