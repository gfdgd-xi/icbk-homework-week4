#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;
int main() {
    // 用 sstream 会比双指针好实现，因为不需要再自己处理单词之间多个空格的奇怪情况
    string data;
    cout << "输入：";
    getline(cin, data);
    istringstream ss(data);
    string str;
    int num = 0;
    while (ss>>str)
    {
        ++num;
    }
    cout << "单词个数：" << num << endl;
    ss.clear();
    ss.seekg(0);
    vector<string> niStr;
    while (ss>>str)
    {
        niStr.push_back(str);
    }
    cout << "逆序输出：";
    for (int i = niStr.size() - 1; i >= 0; --i) {
        cout << niStr[i] << " ";
    }
    cout << endl;
}