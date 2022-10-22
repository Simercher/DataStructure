#include<stdio.h>
#include<iostream>
#include<math.h>
using namespace std;
vector<int> tower1, tower2, tower3;
int count = 0, maxnum = 0;

void printStack() {
    count++;
    cout << "Tower1:";
    if (tower1.empty()) {
        cout << endl;
    }else {
        for (auto &i : tower1) {
            if (i != tower1.back())
            {
                cout << i << " ";
            }else {
                cout << i;
            }
        }
        cout << endl;
    }
    cout << "Tower2:";
    if (tower2.empty()) {
        cout << endl;
    }else {
        for (auto &i : tower2) {
            if (i != tower2.back())
            {
                cout << i << " ";
            }else {
                cout << i;
            }
        }
        cout << endl;
    }
    cout << "Tower3:";
    if (tower3.empty()) {
        cout << "\n" <<endl;
    }else {
        for (auto &i : tower3) {
            if (i != tower3.back())
            {
                cout << i << " ";
            }else {
                cout << i;
            }
        }
        if (count <= pow(2, maxnum) - 1){
            cout << "\n" << endl;
        }else {
            // cout << pow(2, maxnum) - 1 << " test " << endl;
            cout << endl;
        }
        
    }
}

void slove(int len, int x, int y, int z) {
    if (len == 1) {
        // cout << "test\n";
        if (x == 1) {
            if (z == 2) {
                tower2.push_back(tower1.at(tower1.size() - 1));
                tower1.pop_back();
            }else {
                // cout << "test\n";
                tower3.push_back(tower1.at(tower1.size() - 1));
                // cout << "test\n";
                tower1.pop_back();
            }
        }else if (x == 2) {
            if (z == 1) {
                tower1.push_back(tower2.at(tower2.size() - 1));
                tower2.pop_back();
            }else {
                tower3.push_back(tower2.at(tower2.size() - 1));
                tower2.pop_back();
            }
        }else if (x == 3) {
            if (z == 2) {
                tower2.push_back(tower3.at(tower3.size() - 1));
                tower3.pop_back();
            }else {
                tower1.push_back(tower3.at(tower3.size() - 1));
                tower3.pop_back();
            }
        }
        printStack();
    }else {
        slove(len - 1, x, z, y);
        if (x == 1) {
            if (z == 2) {
                tower2.push_back(tower1.at(tower1.size() - 1));
                tower1.pop_back();
            }else {
                // cout << "test\n";
                tower3.push_back(tower1.at(tower1.size() - 1));
                // cout << "test\n";
                tower1.pop_back();
            }
        }else if (x == 2) {
            if (z == 1) {
                tower1.push_back(tower2.at(tower2.size() - 1));
                tower2.pop_back();
            }else {
                tower3.push_back(tower2.at(tower2.size() - 1));
                tower2.pop_back();
            }
        }else if (x == 3) {
            if (z == 2) {
                tower2.push_back(tower3.at(tower3.size() - 1));
                tower3.pop_back();
            }else {
                tower1.push_back(tower3.at(tower3.size() - 1));
                tower3.pop_back();
            }
        }
        printStack();
        slove(len - 1, y, x, z);
    }
}

int main() {
    int n = 0;
    cin >> n;
    maxnum = n;
    for (int i = n; i > 0; i--) {
        tower1.push_back(i);
    }
    printStack();
    slove(n, 1, 2, 3);

    return 0;
}