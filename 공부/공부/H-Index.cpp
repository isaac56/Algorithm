#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    sort(citations.begin(), citations.end(), greater<int>());
    int H = citations[0];
    while (H >= 0) {
        int num = 0;
        for (int c : citations) {
            if (c >= H) {
                num++;
            }
            else {
                break;
            }
        }
        if (num >= H) {
            return H;
        }
        H--;
    }

    return 0;
}