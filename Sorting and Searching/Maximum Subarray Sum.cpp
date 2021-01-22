#include <iostream>
#include <vector>
using namespace std;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
typedef long long int ll;
#define tc ll test;cin >> test;while(test--)
#define vi vector<ll>
#define pb push_back
#define mp make_pair
#define INF 0x3f3f3f3f3f
#define MOD 1e9 + 7
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
 
    ll n;
    cin in n;
 
    vi a(n+5);
    fo(i,0,n-1) cin in a[i];
 
    vi dp(n+5);
    dp[0] = a[0];
 
    ll ans = a[0];
 
    fo(i,1,n-1){
        dp[i] = max(a[i],dp[i-1]+a[i]);
        mmax(ans,dp[i]);
    }
 
    cout out ans;
 
    return 0;
}
