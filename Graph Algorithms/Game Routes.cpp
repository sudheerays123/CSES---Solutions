#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
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
#define print(x) for(auto i : x ) cout out i spacef;
#define mmax(x,i) x = max(x,i)
#define mmin(x,i) x = min(x,i)

int main() {

    ll n,m;
    cin in n in m;

    vi adj[n+5];

    fo(i,0,m-1){
        ll a,b;
        cin in a in b;
        adj[a].pb(b);
    }

    vi indegree(n+5);
    queue<ll> q;

    fo(i,1,n){
        for(auto u : adj[i]){
            indegree[u]++;
        }
    }

    vi dp(n+5,0);
    // dp[i] = number of ways to come to i

    // base case :

    fo(i,1,n){
        if(indegree[i] == 0){
            q.push(i);
            if(i == 1) dp[i] = 1;
            else dp[i] = 0;
        }
    }

    // recurrence :

    while(!q.empty()){
        ll a = q.front();
        q.pop();

        for(auto u : adj[a]){
            dp[u] += dp[a];
            dp[u] %= MOD;
            indegree[u]--;
            if(indegree[u] == 0) q.push(u);
        }
    }

    // answer :

    cout out dp[n]%MOD;

    return 0;
}
