#include <string>
#include <vector>
#include <set>
#include <iostream>

using namespace std;

struct cmp {
    bool operator()(int a, int b) {
        return a < b;
    }
};

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    multiset<int, cmp> ms;
    for (string s : operations) {
        char cmd = s[0];
        int num = stoi(s.substr(2, s.length() - 2));
        if (cmd == 'I')
        {
            ms.insert(num);
        }
        else {
            if (ms.size() > 0) {
                if (num == 1) {
                    ms.erase(--ms.end());
                }
                else {
                    ms.erase(ms.begin());
                }
            }
        }
    }

    //if (!ms.empty()) {
    //    multiset<int>::iterator iter;
    //    for (iter = ms.begin(); iter != ms.end(); iter++) {
    //        cout << *iter << endl;
    //    }
    //}
    multiset<int>::iterator iter;
    if (ms.size() == 0) {
        answer.push_back(0);
        answer.push_back(0);
    }
    else {
        answer.push_back(*(--ms.end()));
        answer.push_back(*ms.begin());
    }

    return answer;
}