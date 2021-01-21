#include <iostream>
#include <vector>
using namespace std;
#define fast ios_base::sync_with_stdio(false); cin.tiille(NULL); cout.tie(NULL);
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
 
    ll n;
    cin in n;
 
    if(n <= 3 && n >= 2){
        cout out  "NO SOLUTION";
        return 0;
    }
    if(n == 1){
        cout out "1";
        return 0;
    }
    if(n == 4){
        cout out "2 4 1 3 ";
        return 0;
    }
 
    ll odd = 1;
    while(odd <= n){
        cout out odd spacef;
        odd += 2;
    }
 
    ll even = 2;
    while(even <= n){
        cout out even spacef;
        even += 2;
    }
 
    return 0;
}
