#include <bits/stdc++.h>
#include<vector>
using namespace std;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
typedef long long int ll;
#define tc ll test;cin >> test;while(test--)
#define vi vector<ll>
#define pb push_back
#define mp pake_pair
#define INF 0x3f3f3f3f3f
#define in >>
#define out <<
#define space << " " <<
#define spacef << " "
#define fo(i,a,b) for(ll i = a; i <= b; i++)
#define MOD 1000000007
#define endl "\n"
 
int main() {
 
    fast;
 
    ll n;
    cin in n;
 
    vi dp(n+5);
 
    dp[1] = 1;
    dp[2] = 1 + dp[1];
    dp[3] = 1+dp[1]+dp[2];
    dp[4] = 1+dp[1]+dp[2]+dp[3];
    dp[5] = 1+dp[1]+dp[2]+dp[3]+dp[4];
    dp[6] = 1+dp[1]+dp[2]+dp[3]+dp[4]+dp[5];
 
    fo(i,7,n) {
        dp[i] = dp[i-1] + dp[i-2] + dp[i-3] + dp[i-4] + dp[i-5] + dp[i-6];
        dp[i] %= MOD;
    }
 
    cout out dp[n];
 
    return 0;
}
