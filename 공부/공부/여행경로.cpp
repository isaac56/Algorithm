#include <string>
#include <vector>
#include <stack>
#include <algorithm>
#include <iostream>

using namespace std;

struct situation {
    int usingTicket = -1;
    vector<string> history;
    vector<bool> consume;
};

bool compare(vector<string> v1, vector<string> v2) {
    return v1[1] > v2[1];
}

vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;
    stack<situation> st;
    sort(tickets.begin(), tickets.end(), compare);

    for (int i = 0; i < tickets.size(); i++) {
        if (tickets[i][0] == "ICN") {
            situation s;
            s.usingTicket = i;
            s.history = vector<string>(1, "ICN");
            s.consume = vector<bool>(tickets.size(), false);
            st.push(s);
        }
    }

    while (!st.empty()) {
        int usingTicket = st.top().usingTicket;
        vector<string> history = st.top().history;
        vector<bool> consume = st.top().consume;
        st.pop();
        history.push_back(tickets[usingTicket][1]);
        consume[usingTicket] = true;

        if(history.size() == tickets.size() + 1) {
            answer = history;
            break;
        }

        for (int i = 0; i < tickets.size(); i++) {
            if (consume[i] == false && tickets[i][0] == tickets[usingTicket][1]) {
                situation next;
                next.usingTicket = i;
                next.history.assign(history.begin(), history.end());
                next.consume.assign(consume.begin(), consume.end());

                st.push(next);
            }
        }
    }

    return answer;
}