#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    vector<int> queue;
    for (int i = 0; i < progresses.size(); i++) 
    {
        int completeDay = (100 - progresses[i]) % speeds[i] == 0 ? (100 - progresses[i]) / speeds[i] : (100 - progresses[i]) / speeds[i] + 1;
        if (!queue.empty() && queue.front() < completeDay) {
            answer.push_back(queue.size());
            queue.clear();
        }
        queue.push_back(completeDay);
    }

    if (!queue.empty()) {
        answer.push_back(queue.size());
    }

    return answer;
}