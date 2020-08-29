#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;

struct cmp {
    bool operator()(vector<int> v1, vector<int> v2) {
        return v1[1] > v2[1];
    }
};


int solution(vector<vector<int>> jobs) {
    int answer = 0;
    int currentTime = 0;
    int processingNum = 0;
    vector<bool> visit(jobs.size(), false);
    priority_queue <vector<int>, vector<vector<int>>, cmp> pq;

    while (processingNum < jobs.size()) {
        for (int i = 0; i < jobs.size(); i++) {
            if (visit[i] == false && jobs[i][0] <= currentTime) {
                pq.push(jobs[i]);
                visit[i] = true;
            }
        }
        if (pq.empty()) {
            int min = 1001;
            for (int i = 0; i < jobs.size(); i++) {
                if (visit[i] == false && jobs[i][0] < min) {
                    min = jobs[i][0];
                }
            }
            currentTime = min;
        }
        else {
            currentTime = currentTime + pq.top()[1];
            answer += currentTime - pq.top()[0];
            pq.pop();
            processingNum++;
        }
    }

    answer /= processingNum;
    return answer;
}