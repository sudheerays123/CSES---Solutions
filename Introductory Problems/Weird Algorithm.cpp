#include <iostream>
using namespace std;
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long int
 
int main() {
 
    ll n;
    cin >> n;
 
    cout << n << " ";
    while (n != 1) {
        if (n % 2 == 0) n /= 2;
        else n = n * 3 + 1;
 
        cout << n << " ";
    }
 
    return 0;
}
