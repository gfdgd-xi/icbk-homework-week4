#include <iostream>
#include <string>
using namespace std;
int main() {
	string s;
	cin >> s;
	int a = s.size();
	for(int i=a-1;i>=1;i--){
		for(int j=0;j<a - i;j++){
			string d = s.substr(j, i);
			if (s.find(d, j + 1) != s.npos) {
				cout << i << endl;
				return 0;
			}
		}
	}
	cout << 0;
}
