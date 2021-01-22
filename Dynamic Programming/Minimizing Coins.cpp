#include <bits/stdc++.h>
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
 
    ll n,x;
    cin in n in x;
 
    vi a(n+5);
    vi dp(x+5,INF);
 
    fo(i,0,n-1) {
        cin in a[i];
        if(a[i] > x) continue;
        dp[a[i]] = 1;
    }
 
    fo(i,*min_element(a.begin(),a.begin()+n)+1,x){
        for(auto coin : a){
            if(i-coin >= 0 && dp[i-coin] != INF){
                mmin(dp[i],dp[i-coin]+1);
            }
        }
    }
 
 
    if(dp[x] != INF ) cout out dp[x];
    else cout out "-1";
 
    return 0;
}
