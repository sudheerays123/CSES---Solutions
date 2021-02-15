#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long int
#define tc ll test;cin >> test;while(test--)
#define vi vector<ll>
#define pb push_back
#define mp make_pair
#define INF 0x3f3f3f3f3f
#define MOD 13371337
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
#define N 200005

ll n;
vi adj[100005];
vi parent(100005);

ll bfs(ll s){

    vi dist(n+5,INF);
    vector<bool> visited(n+5,false);
    queue<ll> q;

    dist[s] = 1;
    visited[s] = true;
    q.push(s);

    while(!q.empty()){

        ll a = q.front();
        q.pop();

        for(auto u : adj[a]){

            if(dist[u] > dist[a] + 1){
                dist[u] = dist[a] + 1;
                q.push(u);
                parent[u] = a;
            }
        }
    }

    return dist[n];
}

int main() {

    ll m;
    cin in n in m;


    fo(i,0,m-1){

        ll a,b;
        cin in a in b;

        adj[a].pb(b);
        adj[b].pb(a);

    }

    ll d = bfs(1);

    if(d == INF) {
        cout out "IMPOSSIBLE\n";
        return 0;
    }

    cout out bfs(1) nextline;

    ll last = n;
    vi path(0);

    while(last != 1){

        path.pb(last);
        last = parent[last];
    }

    path.pb(1);
    reverse(path.begin(),path.end());

    print(path);

    return 0;
}
