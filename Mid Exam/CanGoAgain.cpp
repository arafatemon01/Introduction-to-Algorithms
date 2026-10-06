#include <bits/stdc++.h>
using namespace std;
class Edge {
    public:
    int a,b,c;
    Edge (int a , int b, int c ){
        this->a = a;
        this->b = b;
        this->c = c;
    }
};
 int n,e;
vector <Edge> edge_list;
long long dis[1002];
bool bellman_ford (){
    for (int i = 0;i<n-1;i++){
        for (auto ed : edge_list)
        {
            int a, b, c;
            a = ed.a;
            b= ed.b;
            c = ed.c;
        if (dis[a] != LLONG_MAX && dis[a] + c < dis[b])
        {
            dis[b] = dis[a] + c;
        }
        }
    }
   bool cycle = false;
  
      for (auto ed : edge_list)
      {
        int a, b, c;
         a = ed.a;
         b = ed.b;
         c = ed.c;
       if (dis[a] != LLONG_MAX && dis[a] + c < dis[b])
       {
         cycle = true;
         break;
       }
      }
     return cycle;
   }

int main(){
   
    cin>>n>>e;
    while (e--)
    {
        int a, b, c;
        cin>>a>>b>>c;
        edge_list.push_back (Edge(a,b,c));
    }
    int source;
    cin>>source;
    for (int i = 1;i<=n;i++)
       dis[i] = LLONG_MAX;
       dis [source] = 0;
    
    bool cycle =  bellman_ford ();
    if (cycle)
    {
        cout << "Negative Cycle Detected" << endl;
        return 0;
    }
    int t;
    cin>>t;
    while (t--)
    {
        int dst;
        cin>>dst;
    if (dis[dst] == LLONG_MAX)
       cout<<"Not Possible"<<endl;
    else
       cout<<dis[dst]<<endl;
    }
    return 0;
}