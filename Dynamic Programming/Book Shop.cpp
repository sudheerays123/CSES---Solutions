#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
typedef int ll;
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
#define print(x) for(auto i : x ) cout out i spacef;
#define mmax(x,i) x = max(x,i)
#define mmin(x,i) x = min(x,i)

ll dp[1001][100002];

int main() {

    ll n,x;
    cin in n in x;

    vi price(n+5);
    vi page(n+5);

    fo(i,1,n) cin in price[i];
    fo(i,1,n) cin in page[i];

    // dp[i][j] = maximum number of pages we can buy in the first i pages and maximum limit of money as j

    // recurrence relation :

    fo(i,1,n){
        fo(j,1,x){
            dp[i][j] = dp[i-1][j];
            if(j - price[i] >= 0 ) mmax(dp[i][j] , dp[i-1][j-price[i]]+page[i]);
        }
    }

    // answer :

    cout out dp[n][x];

    return 0;
}
