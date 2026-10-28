#include <iostream>
using namespace std;
int main() {
	int n, m;
	cin >> n >> m;
	int N[n];
	int M[m];
	for(int i=0;i<n;i++){
		cin >> N[i];
	}
	for(int i=0;i<m;i++){
		cin >> M[i];
	}
	for(int i=0;i<m;i++){
		int m = M[i];
		for(int j=0;j<n;j++){
			if (N[j] == m) {
				cout << j + 1 << " ";
				goto next;
			}
		}
		cout << "-1 ";
next:
		continue;
	}
}
