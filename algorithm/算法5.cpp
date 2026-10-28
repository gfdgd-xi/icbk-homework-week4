#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector<int> students = {1, 1, 1, 0, 0, 1};
	vector<int> sandwiches = {1, 0, 0, 0, 1, 1};
	int sa = sandwiches.size();
	int st = students.size();
	for(int i = 0; i < sa; ++i) {
		for(int j=0;j<st;j++){
			if (students[0] == sandwiches[0]) {
				students.erase(students.begin());
				sandwiches.erase(sandwiches.begin());
				break;
			}
			int student = students[0];
			students.erase(students.begin());
			students.push_back(student);
		}
	}
	 
	
	cout << students.size() << endl;
}
