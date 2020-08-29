#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    stack<pair<int, int>> timePrice;

    for (int time = 0; time < prices.size(); time++) {
        int price = prices[time];
        while (!timePrice.empty() && timePrice.top().second > price) {
            pair<int, int> toWrite = timePrice.top();
            timePrice.pop();
            answer[toWrite.first] = time - toWrite.first;
        }
        timePrice.push(make_pair(time, price));
    }

    while (!timePrice.empty()) {
        pair<int, int> toWrite = timePrice.top();
        timePrice.pop();
        answer[toWrite.first] = (prices.size() - 1) - toWrite.first;
    }

    return answer;
}