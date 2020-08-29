#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int currentWeight = 0, currentTime = 0;
    queue<pair<int, int>> timeWeights;

    for (int truckWeight : truck_weights) {
        currentTime++;

        while (!timeWeights.empty() && (currentTime >= timeWeights.front().first || currentWeight + truckWeight > weight)) 
        {
            currentTime = timeWeights.front().first;
            currentWeight -= timeWeights.front().second;
            timeWeights.pop();
        }

        currentWeight += truckWeight;
        timeWeights.push(make_pair(currentTime + bridge_length, truckWeight));
    }

    return timeWeights.back().first;
}