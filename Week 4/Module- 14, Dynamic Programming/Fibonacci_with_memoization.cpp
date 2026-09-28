#include<bits/stdc++.h>
using namespace std;
int dp[1005];
int fib(int n)
{
    if(n == 0 || n== 1) return n;
    if(dp[n] != -1) return dp[n];
    dp[n] = fib(n-1) + fib(n-2);
    return dp[n];

}
int main (){
    memset(dp, -1, sizeof(dp));
   cout <<   fib(7) << endl;
    return 0;
}