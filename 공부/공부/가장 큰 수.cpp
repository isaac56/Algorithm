#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(string s1, string s2) {
    return s1 + s2 > s2 + s1;
}

string solution(vector<int> numbers) {
    string answer = "";
    vector<string> s_numbers;
    for (int i : numbers) {
        s_numbers.push_back(to_string(i));
    }

    sort(s_numbers.begin(), s_numbers.end(), compare);



    for (string n : s_numbers) {
        answer += n;
    }

    if (stoi(s_numbers[0]) == 0) {
        answer = "0";
    }

    return answer;
}