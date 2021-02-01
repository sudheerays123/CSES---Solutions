#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <unordered_map>
using namespace std;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
typedef long long int ll;
#define tc ll test;cin >> test;while(test--)
#define vi vector<ll>
#define pb push_back
#define mp make_pair
#define INF 0x3f3f3f3f3f
#define MOD 7
#define ff first
#define ss second
#define in >>
#define out <<
#define space << " " <<
#define spacef << " "
#define fo(i,a,b) for(ll i = a; i <= b; i++)
#define nextline out "\n"
#define print(x) for(auto i : x ) cout out i spacef;
#define mmax(x,i) x = max(x,i)
#define mmin(x,i) x = min(x,i)

vi alldigits(ll n){
    vi ans(0);
    while(n != 0){
        if(n%10 != 0 )ans.pb(n%10);
        n /= 10;
    }
    return ans;
}

int main() {

    ll n;
    cin in n;

    vi dp(n+10);

    // base case :

    fo(i,1,9) dp[i] = 1;

    fo(i,10,n){
        dp[i] = 1;

        vi onedigit = alldigits(i);
        ll x = INF;
        for(auto j : onedigit) mmin(x,dp[i-j]);

        dp[i] += x;
    }

    cout out dp[n];

    return 0;
}
