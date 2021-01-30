#include <bits/stdc++.h>
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
#define print(x) for(auto i : x ) cout out i;
#define mmax(x,i) x = max(x,i)
#define mmin(x,i) x = min(x,i)

int main() {

    ll n,q;
    cin in n in q;

    vi a(n+5);
    vi presum(n+5);
    fo(i,1,n) {
        cin in a[i];
        presum[i] = presum[i-1] + a[i];
    }
    while(q--){
        ll a,b;
        cin in a in b;
        cout out presum[b]-presum[a-1] nextline;
    }

    return 0;
}
