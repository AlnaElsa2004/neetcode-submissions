class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,int>> cars;
        int n=position.size();
for (int i = 0; i < n; i++) {
    cars.push_back({position[i], speed[i]});
}

sort(cars.begin(), cars.end(), greater<>());

vector<double> time;

for (int i = 0; i < n; i++) {
    time.push_back((double)(target - cars[i].first) / cars[i].second);
}

int fleets = 0;
double currMax = 0;

for (int i = 0; i < n; i++) {
    if (time[i] > currMax) {
        fleets++;
        currMax = time[i];
    }
}

return fleets;
    }
};
