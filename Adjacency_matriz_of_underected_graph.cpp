#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,e;
    cin>>n>>e;
    int matrix [n][n];
        // for (int i=0;i<n;i++)
        // {
        //     for (int j = 0;j<n;j++){
        //         matrix [i][j] = 0;
        //     }
        // }
    memset (matrix,0,sizeof (matrix));
    for (int i = 0;i<n;i++)
       for (int j = 0 ;j<n;j++)
          if (i == j) 
            matrix[i][j] = 1;

    for (int i= 0;i<e;i++)
    {
        int a,b;
        cin>>a>>b;
        matrix [a][b] = 1;
        matrix [b][a] = 1;
    }

   for (int i=0;i<n;i++)
    {
        for (int j = 0;j<n;j++){
          cout<<  matrix [i][j] <<" ";
        }
        cout<<endl;
    }
    return 0;
}