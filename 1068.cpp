#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> tree[51];
bool visited[51];
int root, delete_node;

void deleteNode(int node) {
    visited[node] = true;
    for (int next : tree[node]) {
        deleteNode(next);
    }
}

int leaf_count(int node) {
    if (visited[node]) return 0;
    if (tree[node].empty()) return 1;

    int leaf_count = 0;
    bool isLeaf = true;
    for (int next : tree[node]) {
        if (!visited[next]) {
            isLeaf = false;
            leaf_count += leaf_count(next);
        }
    }
    if (isLeaf) return 1; // 삭제된 자식만 남아있으면 리프
    return leaf_count;
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int parent;
        cin >> parent;
        if (parent == -1) {
            root = i;
        } else {
            tree[parent].push_back(i);
        }
    }

    cin >> delete_node;
    deleteNode(delete_node);

    if (visited[root]) {
        cout << 0 << endl;
    } else {
        cout << leaf_count(root) << endl;
    }
    return 0;
}

//

/* 트리에서 리프 노드란, 자식의 개수가 0인 노드를 말한다.

트리가 주어졌을 때, 노드 하나를 지울 것이다. 그 때, 남은 트리에서 리프 노드의 개수를 구하는 프로그램을 작성하시오. 노드를 지우면 그 노드와 노드의 모든 자손이 트리에서 제거된다.

예를 들어, 다음과 같은 트리가 있다고 하자.

현재 리프 노드의 개수는 3개이다. (초록색 색칠된 노드) 이때, 1번을 지우면, 다음과 같이 변한다. 검정색으로 색칠된 노드가 트리에서 제거된 노드이다.
 */