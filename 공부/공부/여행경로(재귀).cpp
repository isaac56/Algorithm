#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(vector<string> v1, vector<string> v2) {
    return v1[1] < v2[1];
}

bool dfs(int toUse, vector<bool>& consume, vector<string>& answer, vector<vector<string>> &tickets) {
    consume[toUse] = true;
    answer.push_back(tickets[toUse][1]);

    if (answer.size() == tickets.size() + 1) {
        return true;
    }

    for (int i = 0; i < tickets.size(); i++) {
        if (consume[i] == false && tickets[toUse][1] == tickets[i][0]) {
            if (dfs(i, consume, answer, tickets)) {
                return true;
            }
        }
    }


    consume[toUse] = false;
    answer.pop_back();
    return false;
}

vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;
    answer.push_back("ICN");
    vector<bool> consume(tickets.size(), false);
    sort(tickets.begin(), tickets.end(), compare);

    for (int i = 0; i < tickets.size(); i++) {
        if (tickets[i][0] == "ICN") {
            if (dfs(i, consume, answer, tickets)) {
                break;
            }
        }
    }

    return answer;
}