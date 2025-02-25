#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

const int MAX = 100001;

int t, n;
int student[MAX];
bool visited[MAX], finished[MAX];
int not_team_count;

void dfs(int node) {
    visited[node] = true;
    int next = student[node];

    if (!visited[next]) {
        dfs(next);
    } else if (!finished[next]) {
        // 사이클 발견
        for (int i = next; i != node; i = student[i]) {
            not_team_count--;
        }
        not_team_count--; // 현재 노드도 포함
    }

    finished[node] = true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> t;
    while (t--) {
        cin >> n;
        not_team_count = n;

        for (int i = 1; i <= n; i++) {
            cin >> student[i];
        }

        memset(visited, false, sizeof(visited));
        memset(finished, false, sizeof(finished));

        for (int i = 1; i <= n; i++) {
            if (!visited[i]) {
                dfs(i);
            }
        }

        cout << not_team_count << '\n';
    }

    return 0;
}
//텀프로젝트 수행, 프로젝트 팀원 수는 제한 없음
//모튼 학생이 한 팀일수도 있음
//모든 학생들은 함께하고 싶은 학생을 선택(단 한명만 선택 가능)
//혼자 하고싶어하면 자기자신 선택 가능
//학생들이 s1,s2...sr이라고 할 때
//s1->3 s2->s1 s3->s3 s4->s4 s5->s3 s6->s4 s7->s6
//이렇게 되면, (3)과 (4, 7, 6)이 팀을 이룰 수 있다. 1, 2, 5는 어느 팀에도 속하지 않는다.

//자기 자신이 자기 자신만 원하거나
//둥글게 연결되어야 팀이 만들어짐
//ex) s1 -> s2, s2 -> s3, 라면 아무런 팀이 만들어지지 않는다