#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct jewel {
    int weight;
    int price;
};

bool compare(jewel a, jewel b) {
    return a.weight < b.weight;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, K;
    cin >> N >> K;

    vector<jewel> jewels(N);
    vector<int> bags(K);

    for (int i = 0; i < N; i++) {
        cin >> jewels[i].weight >> jewels[i].price;
    }

    for (int i = 0; i < K; i++) {
        cin >> bags[i];
    }

    sort(jewels.begin(), jewels.end(), compare);
    sort(bags.begin(), bags.end());

    priority_queue<int> pq;
    long long max_value = 0;
    int index = 0;

    for (int i = 0; i < K; i++) {
        while (index < N && jewels[index].weight <= bags[i]) {
            pq.push(jewels[index].price);
            index++;
        }

        if (!pq.empty()) {
            max_value += pq.top();
            pq.pop();
        }
    }

    cout << max_value << endl;
    return 0;
}