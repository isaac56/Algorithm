#include <string>
#include <vector>
#include <algorithm>
#include<queue>

using namespace std;



int solution(vector<int> priorities, int location) {
    int answer = 0;
    queue<pair<int, int>> locPriority;
    priority_queue< int, vector<int>, less<int> > pq;
    for (int i = 0; i < priorities.size(); i++) {
        locPriority.push(make_pair(i, priorities[i]));
        pq.push(priorities[i]);
    }

    while (!locPriority.empty()) {
        pair<int, int> cur = locPriority.front();
        locPriority.pop();

        if (pq.top() == cur.second) {
            pq.pop();
            if (cur.first == location) {
                answer = priorities.size() - locPriority.size();
                break;
            }
        }
        else {
            locPriority.push(cur);
        }
    }

    return answer;
}
