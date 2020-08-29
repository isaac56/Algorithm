#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int getScore(vector<int> my, vector<int> answers) {
    int score = 0;
    for (int i = 0; i < answers.size(); i++) {
        int index = i % my.size();
        if (answers[i] == my[index]) {
            score++;
        }
    }

    return score;
}

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    vector<int> a1{ 1,2,3,4,5 };
    vector<int> a2{ 2,1,2,3,2,4,2,5 };
    vector<int> a3{ 3,3,1,1,2,2,4,4,5,5 };
    vector<int> scores;

    scores.push_back(getScore(a1, answers));
    scores.push_back(getScore(a2, answers));
    scores.push_back(getScore(a3, answers));

    int max = -1;
    for (int i = 0; i < scores.size(); i++) {
        if (max < scores[i]) {
            max = scores[i];
        }
    }

    for (int i = 0; i < scores.size(); i++) {
        if (max == scores[i]) {
            answer.push_back(i + 1);
        }
    }
    return answer;
}