#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
typedef long long int ll;
#define tc ll test;cin >> test;while(test--)
#define vi vector<ll>
#define pb push_back
#define mp make_pair
#define INF 1e18
#define MOD 7
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
#define N 100005

vi adj[N];
vector<bool> visited(N);

void dfs(ll s){

    if(visited[s]) return;
    visited[s] = true;

    for(auto u : adj[s]) dfs(u);
}

int main() {

    fast;

    ll n,m;
    cin in n in m;

    vi indegree(n+5);
    vi incoming[n+5];

    fo(i,0,m-1){
        ll a,b;
        cin in a in b;

        indegree[b]++;
        incoming[b].pb(a);
        adj[a].pb(b);
    }

    if(indegree[1] != 0){
        cout out "IMPOSSIBLE";
        return 0;
    }

    dfs(1);

    fo(i,1,n){
        for(auto u : incoming[i]){
            if(visited[u] == false) {
                indegree[i]--;
            }
        }
    }

    queue<ll> q;
    q.push(1);

    vi dp(n+5,-INF);

    // dp[i] = maximum number of cities we have to use to come to the ith city from the first city

    // base case :

    dp[1] = 1;

    // recurrence relation :

    while(!q.empty()){

        ll a = q.front();
        q.pop();

        for(auto u : adj[a]){
            mmax(dp[u],dp[a]+1);

            indegree[u]--;
            if(indegree[u] == 0) q.push(u);
        }
    }

    // answer :

    if(dp[n] == -INF ){
        cout out "IMPOSSIBLE";
        return 0;
    }

    cout out dp[n] nextline;

    vi path(0);

    ll last = n;

    while(last != 1){
        path.pb(last);

        for(auto u : incoming[last]){
            if(dp[u] + 1 == dp[last]){
                last = u;
                break;
            }
        }
    }

    path.pb(1);
    reverse(path.begin(),path.end());
    print(path);

    return 0;
}
