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

    tc {

        ll x1, y1, x2, y2, x3, y3;
        cin in x1 in y1 in x2 in y2 in x3 in y3;

        ll side = (x2-x1)*(y3-y1) - (y2-y1)*(x3-x1);
        if(side == 0 ) cout out "TOUCH\n";
        else if(side > 0) cout out "LEFT\n";
        else cout out "RIGHT\n";

    }

    return 0;
}
