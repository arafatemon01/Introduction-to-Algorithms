#include <bits/stdc++.h>
using namespace std;
int main(){
    int node , edge;
    cin>>node>>edge;
    vector <int> adj_list[node]; // array of vector.
    while (edge--)
{
    int a,b;
    cin>>a>>b;
    adj_list[a].push_back(b);
    adj_list[b].push_back(a);  // because undirected graph
}
for (int i = 0;i<node;i++)
{
   cout<< i << " -> ";
   for (int x: adj_list[i])
   {
     cout<< x << " ";
   }
   cout<<endl;
}
    return 0;
}