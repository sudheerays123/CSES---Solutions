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

int main() {

    ll n,m;
    cin in n in m;

    vi indegree(n+5);
    vi adj[n+5];

    fo(i,0,m-1){
        ll a,b;
        cin in a in b;
        adj[a].pb(b);
        indegree[b]++;
    }

    queue<ll> q;

    fo(i,1,n){
        if(indegree[i] == 0){
            q.push(i);
        }
    }

    if(q.size() == 0) {
        cout out "IMPOSSIBLE";
        return 0;
    }

    vi ans(0);
    ll cnt = 0;

    while(!q.empty()){
        ll a = q.front();
        ans.pb(a);
        cnt++;
        q.pop();
        for(auto u : adj[a]){
            indegree[u]--;
            if(indegree[u] == 0) q.push(u);
        }
    }

    if(cnt != n) {
        cout out "IMPOSSIBLE";
        return 0;
    }
    print(ans);

    return 0;
}
