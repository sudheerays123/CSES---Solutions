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

    ll n,x;
    cin in n in x;

    vector<vi> a(n+5,vi(2));
    fo(i,0,n-1) {
        cin in a[i][0];
        a[i][1] = i+1;
    }

    sort(a.begin(),a.begin()+n);

    ll low = 0 , high = n-1;

    while(low < high){
        ll sum = a[low][0] + a[high][0];

        if(sum == x){
            cout out a[low][1] space a[high][1];
            return 0;
        }
        else if(sum < x) low++;
        else if(sum > x) high--;
    }

    cout out "IMPOSSIBLE";

    return 0;
}
