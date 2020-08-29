#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    for (int yellowY = 1; yellowY <= yellow; yellowY++) {
        if (yellow % yellowY == 0) {
            int yellowX = yellow / yellowY;
            if (brown == 2 * yellowX + 2 * yellowY + 4) {
                answer.push_back(yellowX + 2);
                answer.push_back(yellowY + 2);
                break;
            }
        }
    }
    return answer;
}