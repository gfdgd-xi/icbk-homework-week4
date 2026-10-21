#include <iostream>
#include <vector>
using namespace std;
int main() {
    vector<int> data = {};
    // 输入
    int n;
    cout << "输入几个数？" << endl;
    cin >> n;
    cout << "输入：";
    for (int i = 0; i < n; ++i) {
        int j;
        cin >> j;
        data.push_back(j);
    }
    vector<int> newData;
    // 排序
    for (int i: data) {
        if (!newData.size()) {
            newData.push_back(i);
            continue;
        }
        for (int j = 0; j < newData.size(); ++j) {
            if (newData[j] > i) {
                newData.insert(newData.begin() + j, i);
                goto outer_whileEnd;
            }
        }
        newData.push_back(i);
outer_whileEnd:
        continue;
    }
    cout << "排序输出：";
    for (int i: newData) {
        cout << i << " ";
    }
    cout << endl;
    // 去重
    vector<int> quChongData;
    int maxVal = 0;
    for (int i: newData) {
        if (maxVal < i) {
            quChongData.push_back(i);
            maxVal = i;
        }
    }
    cout << "去重输出：";
    for (int i: quChongData) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}