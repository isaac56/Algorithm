#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    for (vector<int> command : commands) {
        int i = command[0];
        int j = command[1];
        int k = command[2];
        vector<int> sample(array.begin() + (i-1), array.begin() + (j));
        if (sample.size() > 1) {
            cout << *(sample.end() - 1) << endl;
        }
        sort(sample.begin(), sample.end(), less<int>());
        answer.push_back(sample[k - 1]);
    }
    return answer;
}