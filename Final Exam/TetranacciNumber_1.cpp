#include <bits/stdc++.h>
using namespace std;
int dp[35];
int tetranacciNumber (int n)
{
    if (n == 0) return 0;
    if (n == 1) return 1;
    if (n == 2) return 1;
    if (n == 3) return 2;
    if (dp[n] != -1) 
       return dp[n];
    dp[n] = tetranacciNumber (n-1) + tetranacciNumber (n-2) + tetranacciNumber (n-3) + tetranacciNumber (n-4);
        return dp[n];
}
int main(){
    memset (dp, -1 , sizeof (dp));
    int n;
    cin>>n;
    cout<<tetranacciNumber (n)<<endl;
    return 0;
}