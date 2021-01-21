#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
typedef long long int ll;
#define tc ll test;cin >> test;while(test--)
#define vi vector<ll>
#define pb push_back
#define mp pake_pair
#define INF 0x3f3f3f3f3f
#define MOD 1000000007
#define in >>
#define out <<
#define space << " " <<
#define spacef << " "
#define fo(i,a,b) for(ll i = a; i <= b; i++)
#define nextline out "\n"
 
string s;
 
int main() {
 
    fast;
 
    ll n;
    cin in n;
 
    vector<vi> dp(n+5 , vi(n+5));
    vector<vector<char>> grid(n+5 , vector<char> (n+5) );
 
    fo(i,0,n-1){
        fo(j,0,n-1){
            cin in grid[i][j];
        }
    }
 
    if(grid[0][0] == '*' || grid[n-1][n-1] == '*'){
        cout out "0";
        return 0;
    }
 
    dp[0][0] = 1;
    fo(j,1,n-1){
        if(grid[0][j] == '*') break;
        dp[0][j] = 1;
    }
    fo(i,1,n-1){
        if(grid[i][0] == '*') break;
        dp[i][0] = 1;
    }
    
    fo(i,1,n-1){
        fo(j,1,n-1){
            if(grid[i][j] == '*') dp[i][j] = 0;
            else dp[i][j] = dp[i-1][j] + dp[i][j-1];
            dp[i][j] %= MOD;
        }
    }
 
    cout out dp[n-1][n-1]%MOD;
    
    return 0;
}
