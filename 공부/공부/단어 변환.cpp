#include <string>
#include <vector>
#include <queue>

using namespace std;

bool diffOne(string s1, string s2) {
    int n = 0;
    for (int i = 0; i < s1.size(); i++) {
        if (s1[i] != s2[i]) {
            n++;
        }
    }

    return n == 1;
}

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    vector<bool> visit(words.size(), false);

    bool existTarget = false;
    for (string word : words) {
        if (word == target) {
            existTarget = true;
            break;
        }
    }

    if (existTarget == false) {
        answer = 0;
    }
    else {
        queue<pair<int, int>> idxNumQueue;
        for (int i = 0; i < words.size(); i++) {
            if (visit[i] == false && diffOne(begin, words[i])) {
                idxNumQueue.push(make_pair(i, 1));
            }
        }

        while (!idxNumQueue.empty()) {
            int curIdx = idxNumQueue.front().first;
            int num = idxNumQueue.front().second;
            string cur = words[curIdx];
            visit[idxNumQueue.front().first] = true;
            idxNumQueue.pop();

            if (cur == target) {
                answer = num;
                break;
            }

            for (int i = 0; i < words.size(); i++) {
                if (visit[i] == false && diffOne(cur, words[i])) 
                {
                    idxNumQueue.push(make_pair(i, num + 1));
                }
            }

        }
    }

    return answer;
}