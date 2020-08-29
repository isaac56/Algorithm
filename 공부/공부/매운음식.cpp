#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> pq;

    for (int i : scoville) {
        pq.push(i);
    }

    while (pq.size() >= 2 && pq.top() < K) {
        int first = pq.top();
        pq.pop();
        int second = pq.top();
        pq.pop();
        pq.push(first + (second * 2));
        answer++;
    }

    if (pq.top() >= K) {
        return answer;
    }
    else {
        return -1;
    }
}