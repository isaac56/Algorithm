#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(vector<int> numbers, int target) {
    int answer = 0;
    queue<pair<int,int>> dfs;

    dfs.push(make_pair(-1, 0));
    while (!dfs.empty()) {
        int curIdx = dfs.front().first;
        int curTotal = dfs.front().second;
        dfs.pop();

        if (curIdx + 1 >= numbers.size()) {
            if (curTotal == target) {
                answer++;
            }
        }
        else {
            dfs.push(make_pair(curIdx + 1, curTotal + numbers[curIdx + 1]));
            dfs.push(make_pair(curIdx + 1, curTotal - numbers[curIdx + 1]));
        }

    }

    return answer;
}