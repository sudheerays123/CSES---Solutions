#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
typedef long long int ll;
#define tc ll test;cin >> test;while(test--)
#define vi vector<ll>
#define pll pair<ll,ll>
#define pb push_back
#define mp make_pair
#define INF 1e18
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
#define N 5005

int main() {

    fast;

    ll a,b;
    cin in a in b;

    vector<vi> dp(a+5,vi(b+5,INF));

    // dp[i][j] = minimum number of cuts needed to cut the rectangle of size i*j into squares

    // base case :

    fo(i,1,min(a,b)) dp[i][i] = 0;

    // recurrence relation :

    fo(i,1,a){
        fo(j,1,b){

            if(dp[i][j] == 0) continue;

            // cut vertically

            fo(k,1,i-1){
                mmin(dp[i][j] , 1 + dp[k][j] + dp[i-k][j]);
            }

            // cut horizontally

            fo(k,1,j-1){
                mmin(dp[i][j] , 1 + dp[i][k] + dp[i][j-k]);
            }

        }
    }

    // answer :

    cout out dp[a][b];

    return 0;
}
