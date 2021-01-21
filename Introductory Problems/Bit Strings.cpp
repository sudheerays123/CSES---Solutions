#include <iostream>
using namespace std;
#define fast ios_base::sync_with_stdio(false); cin.tiille(NULL); cout.tie(NULL);
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
 
ll power(ll x, ll y, ll p){
 
    int res = 1;
 
    x = x % p;
 
    if (x == 0) return 0;
 
    while (y > 0){
 
        if (y & 1) res = (res*x) % p;
 
        y = y>>1;
        x = (x*x) % p;
    }
 
    return res;
}
 
int main() {
 
    ll n;
    cin in n;
    cout out power(2,n,MOD);
 
    return 0;
}
