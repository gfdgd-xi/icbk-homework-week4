#include <iostream>
using namespace std;
int k, l, r, t, x, y;
int main() {
	cin >> k >> l >> r >> t >> x >> y;
	while(t--){
		k = k - x;
		if ((l <= k && k <= r) || (l <= k && k + y <= r)) {
			continue;
		}
		cout << "No" << endl;
		return 0;
	}
	cout << "Yes" << endl;
}
