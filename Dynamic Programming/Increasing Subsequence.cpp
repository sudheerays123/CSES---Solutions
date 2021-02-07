#include <iostream>
#include <vector>
#include <algorithm>
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
#define print(x) for(auto i : x ) cout out i spacef
#define mmax(x,i) x = max(x,i)
#define mmin(x,i) x = min(x,i)

int main() {

    ll n;
    cin in n;

    vi a(n+5);
    fo(i,0,n-1) cin in a[i];

    vi lis(0);

    fo(i,0,n-1){
        if(i == 0 || lis.back() < a[i]){
            lis.pb(a[i]);
        }
        else{
            vi :: iterator low = lower_bound(lis.begin(),lis.end(),a[i]);
            ll l = low - a.begin();
            lis[(low-lis.begin())] = a[i];
        }
    }

    cout out lis.size();

    return 0;

}
