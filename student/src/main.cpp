#include <iostream>
#include <string>
using namespace std;
class Student {
public:
    Student(string name, int id, int numScores)
        : name(name)
        , id(id)
        , numScores(numScores)
    {
        this->scores = new int[numScores];
    }

    Student(const Student &other)
        : name(other.name)
        , id(other.id)
        , numScores(other.numScores)
    {
        this->scores = new int[numScores];
        for (int i = 0; i < this->numScores; ++i) {
            this->scores[i] = other.scores[i];
        }
    }

    ~Student() {
        delete[] this->scores;
    }

    void insertScores(int index, int data) {
        if (index < 0 || index > numScores - 1) {
            return;
        }
        scores[index] = data;
    }

    void print() {
        cout << name << " " << id << " ";
        for (int i = 0; i < this->numScores; ++i) {
            cout << this->scores[i] << " ";
        }
        cout << endl;
    }

private:
    string name;
    int id;
    int *scores;
    int numScores;
};

int main() {
    Student stu1("张三", 2025001, 3);
    stu1.insertScores(0, 85);
    stu1.insertScores(1, 90);
    stu1.insertScores(2, 78);
    cout << "stu1: ";
    stu1.print();
    Student stu2 = stu1;
    cout << "stu2: ";
    stu2.print();
    cout << endl;
    stu1.insertScores(0, 60);
    cout << "修改 stu1 第一门成绩为 60 后：" << endl;
    cout << "stu1: ";
    stu1.print();
    cout << "stu2: ";
    stu2.print();
    return 0;
}