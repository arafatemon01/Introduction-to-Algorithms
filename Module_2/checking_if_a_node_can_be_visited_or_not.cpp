#include <bits/stdc++.h>
using namespace std;
vector<int> adj_list[1003];
bool vis[1003];
void bfs(int src)
{
    queue<int> q;
    q.push(src);
    vis[src] = true;
    while (!q.empty())
    {
        int per = q.front();
        q.pop();
        // cout << per << endl;
        for (int child : adj_list[per])
        {
            if (vis[child] == false)
            {
                q.push(child);
                vis[child] = true;
            }
        }
    }
}

int main()
{
    int n, e;
    cin >> n >> e;
    while (e--)
    {
        int a, b;
        cin >> a >> b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }
    memset(vis, false, sizeof(vis));
    int src,dest;
    cin >> src>>dest;
    bfs(src);
   if (vis [dest])
      cout<<"Yes\n";
   else cout<<"NO\n";   
    return 0;
}