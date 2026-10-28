#include <iostream>
#include<algorithm>
using namespace std;
int main() {
	int n;
	cin >> n;
	int T[n];
	for (int i = 0; i < n; ++i) {
		cin >> T[i];
	}
	sort(T, T + n);
	double all = 0;
	for(int i=0;i<n-1;i++){
		int p = n - i-1;
		int b = T[i];
		all = all + p * b;
	}
	cout << all / n / 1.0;
}
