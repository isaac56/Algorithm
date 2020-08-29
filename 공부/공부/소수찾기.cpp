#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <set>

using namespace std;

bool isPrime(int a) {
    if (a <= 1) { 
        return false;
    }

    for (int i = 2; i <= sqrt(a); i++) {
        if (a % i == 0) {
            return false;
        }
    }
    return true;
}

int solution(string numbers) {
    int answer = 0;
    set<int> candi;

    sort(numbers.begin(), numbers.end(), less<char>());
    do {
        for (int i = 1; i <= numbers.length(); i++) {
            candi.insert(stoi(numbers.substr(0, i)));
        }
    } while (next_permutation(numbers.begin(), numbers.end()));

    for (set<int>::iterator iter = candi.begin(); iter != candi.end(); iter++) {
        if (isPrime(*iter)) {
            answer++;
        } 
    }

    return answer;
}