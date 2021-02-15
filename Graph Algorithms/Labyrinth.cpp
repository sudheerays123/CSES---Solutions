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
#define print(x) for(auto i : x ) cout out i
#define mmax(x,i) x = max(x,i)
#define mmin(x,i) x = min(x,i)
#define N 1005

ll n,m;
vector<vector<char>> parent(N,vector<char>(N));
vector<vector<char>> grid(N,vector<char>(N));

vi dx = {0,-1,0,+1};
vi dy = {-1,0,+1,0};

ll bfs(ll startx , ll starty , ll endx , ll endy){

    vector<vi> dist(N,vi(N,INF));
    queue<pair<ll,ll>> q;

    dist[startx][starty] = 0;
    q.push({startx,starty});
    parent[startx][starty] = 'S';

    while(!q.empty()){

        ll a = q.front().first;
        ll b = q.front().second;

        q.pop();

        fo(i,0,3){

            ll x = a + dx[i];
            ll y = b + dy[i];

            if(x >= 1 && x <= n && y >= 1 && y <= m && grid[x][y] != '#' && dist[x][y] > dist[a][b] + 1){
                dist[x][y] = dist[a][b] + 1;
                q.push({x,y});

                if(x == a && y == b-1) parent[x][y] = 'L';
                if(x == a && y == b+1) parent[x][y] = 'R';
                if(x == a-1 && y == b) parent[x][y] = 'U';
                if(x == a+1 && y == b) parent[x][y] = 'D';

            }
        }
        
    }

    return dist[endx][endy];

}

int main() {

    fast;

    cin in n in m;

    ll startx , starty , endx , endy;

    fo(i,1,n){
        fo(j,1,m){
            cin in grid[i][j];

            if(grid[i][j] == 'A'){
                startx = i;
                starty = j;
            }
            if(grid[i][j] == 'B'){
                endx = i;
                endy = j;
            }
        }
    }

    ll d = bfs(startx , starty , endx , endy);

    if(d == INF){
        cout out "NO";
        return 0;
    }

    cout out "YES\n";
    cout out d nextline;

    vector<char> path(0);

    ll lastx = endx , lasty = endy;
    char lastc = 'A';

    while(lastc != 'S'){

        lastc = parent[lastx][lasty];

        if(lastc != 'S') path.pb(parent[lastx][lasty]);

        if(lastc == 'U') lastx++;
        if(lastc == 'D') lastx--;
        if(lastc == 'L') lasty++;
        if(lastc == 'R') lasty--;
       
    }

    reverse(path.begin(),path.end());
    print(path);

    return 0;
}
