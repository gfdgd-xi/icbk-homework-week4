#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	int n, L;
	cin >> n >> L;
	int da[n];
	for(int i=0;i<n;i++){
		int d;
		cin >> d;
		da[i] = d;
	}
	sort(da, da + n);
	double maxr = da[0];
	if (L - da[n-1] > maxr) {
		maxr = L - da[n-1];
	}
	for(int i=0;i<n-1;i++){
		double d = (da[i + 1] - da[i]) / 2.0;
		if (d > maxr) {
			maxr = d;
		}
	}
	//cout << maxr << endl;
	printf("%.2f", maxr);
	
}
