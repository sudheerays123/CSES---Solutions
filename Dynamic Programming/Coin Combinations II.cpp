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

    ll n,x;
    cin in n in x;

    vi a(n+5);
    vi dp(x+5,0);

    fo(i,0,n-1) cin in a[i];

    dp[0] = 1;

    fo(coin,1,n){
        fo(i,0,x){
            if(i-a[coin-1] >= 0){
                dp[i] += dp[i-a[coin-1]];
                dp[i] %= MOD;
            }
        }
    }

    cout out dp[x]%MOD;

    return 0;
}
