#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

struct Rib {
    int start, finish;
};


int M, N, order = 1, ways;
vector<vector<int>> tops;
vector<int> Num;
vector<int> Low;
Rib input;
auto comp = [](Rib a, Rib b) {
    if (a.start == b.start) return a.finish < b.finish;
    return a.start < b.start;
};
set<Rib, decltype(comp)> output(comp);

void dfs(int top, int parent) {
    Num[top] = order;
    Low[top] = Num[top];
    order++;
    for (auto ending : tops[top]) {
        if (ending == parent) continue;
        if (Num[ending] == 0) {
            dfs(ending, top);
            Low[top] = min(Low[top], Low[ending]);
            if (Low[ending] > Num[top]) {
                output.insert(Rib{top + 1, ending + 1});
            }
        } else {
            Low[top] = min(Low[top], Num[ending]);
        }
    }
}

int main() {
    cin >> M >> N;
    tops.resize(M);
    Num.resize(M, 0);
    Low.resize(M, INT32_MAX);
    for (int i = 0; i < N; ++i) {
        cin >> input.start >> input.finish >> ways;
        input.start--;
        input.finish--;
        if(ways == 2) {
            tops[input.start].push_back(input.finish);
            tops[input.finish].push_back(input.start);
        } else if (ways == 1) {
            tops[input.start].push_back(input.finish);
        }
    }
    for (int i = 0; i < M; ++i) {
        sort(tops[i].begin(), tops[i].end());
    }
    for (int i = 0; i < M; ++i) {
        if (Num[i] == 0) {
            dfs(i, -1);
        }
    }
    return 0;
}