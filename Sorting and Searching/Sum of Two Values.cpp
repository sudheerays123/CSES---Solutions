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

    map<ll,vi> cnt;

    fo(i,0,n-1){
        ll x;
        cin in x;
        cnt[x].pb(i+1);
    }

    for(auto i : cnt){
        auto pos = cnt.find(x-i.first);
        if(pos != cnt.end()){
            if(x-i.first == i.first && i.second.size() >= 2)  {
                cout out i.second[0] space  pos->second[1];
                return 0;
            }
            else if(x-i.first == i.first) break;
            else cout out i.second[0] space  pos->second[0];
            return 0;
        }
    }

    cout out "IMPOSSIBLE";

    return 0;
}
