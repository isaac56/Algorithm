#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

int n = 0;

void dfs(int computer, vector<vector<int>> &computers, vector<bool> &visit) {
    stack<int> st;

    st.push(computer);
    while (!st.empty()) {
        int cur = st.top();
        visit[cur] = true; 
        st.pop();

        vector<int> path = computers[cur];
        for (int i = 0; i < path.size(); i++) {
            if (path[i] == 1 && visit[i] == false) {
                st.push(i);
            }
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    vector<bool> visit(n, false);

    for (int i = 0; i < computers.size(); i++) {
        if (visit[i] == false) {
            answer++;

            dfs(i, computers, visit);
        }
    }

    return answer;
}