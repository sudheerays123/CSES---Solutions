#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
typedef long long int ll;
#define tc ll test;cin >> test;while(test--)
#define vi vector<ll>
#define pb push_back
#define mp make_pair
#define INF 0x3f3f3f3f3f
#define MOD 1000000007
#define ff first
#define ss second
#define in >>
#define out <<
#define space << " " <<
#define spacef << " "
#define fo(i,a,b) for(ll i = a; i <= b; i++)
#define nextline out "\n"
#define print(x) for(auto i : x ) cout out i spacef
#define mmax(x,i) x = max(x,i)
#define mmin(x,i) x = min(x,i)
 
int main() {
 
    ll n,m;
    cin in n in m;
 
    vi a(n+5);
    fo(i,1,n) cin in a[i];
 
    vector<vi> dp(n+5,vi(m+5,0));
 
    // dp[i][j] = number of ways to create array with first i elements and upper bound = j
 
    // base case :
 
    fo(j,0,m){
        if(a[1] == 0){
            dp[1][j] = 1;
        }
        else if(a[1] != 0 && a[1] == j) dp[1][j] = 1;
    }
 
    // recurrence relation :
 
    fo(i,2,n){
        fo(j,1,m){
            if(a[i] == 0){
                if(j == 1) dp[i][j] = dp[i-1][j] + dp[i-1][j+1];
                else if(j == m) dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
                else dp[i][j] = dp[i-1][j-1] + dp[i-1][j] + dp[i-1][j+1];
 
                dp[i][j] %= MOD;
            }
            else if(a[i] != 0 && a[i] == j){
                if(j == 1) dp[i][j] = dp[i-1][j+1] + dp[i-1][j];
                else if(j == m) dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
                else dp[i][j] = dp[i-1][j-1] + dp[i-1][j] + dp[i-1][j+1];
 
                dp[i][j] %= MOD;
            }
        }
    }
 
    // answer :
 
    ll sum = 0;
 
    fo(j,1,m){
        sum += dp[n][j];
        sum %= MOD;
    }
 
    cout out sum%MOD;
 
    return 0;
 
}
