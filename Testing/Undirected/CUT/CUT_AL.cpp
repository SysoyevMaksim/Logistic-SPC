#include <fstream>
#include <vector>
#include <algorithm>
#include <stack>
#include <windows.h>

using namespace std;

struct Rib {
    int start, finish;
};

int M, N, order = 1;
vector<vector<int>> tops;
vector<int> Num;
vector<int> Low;
stack<Rib> output;
Rib input;

void print_stack(int top) {
    while (!output.empty()) {
        Rib data = output.top();
        output.pop();
        if (data.start == top) return;
    }
}

void dfs(int top, int parent) {
    Num[top] = order;
    Low[top] = Num[top];
    order++;
    for (auto ending: tops[top]) {
        if (Num[ending] == 0) {
            output.push({top, ending});
            dfs(ending, top);
            Low[top] = min(Low[top], Low[ending]);
            if (Low[ending] == Num[top]) {
                print_stack(top);
            }
        } else {
            if (Num[top] > Num[ending] && ending != parent) {
                output.push({top, ending});
            }
            Low[top] = min(Low[top], Num[ending]);
        }
    }
}

int main(int argc, char **argv) {
    LARGE_INTEGER frequency, t1, t2;
    double elapsedTime;
    QueryPerformanceFrequency(&frequency);
    ifstream fin(argv[1]);
    ofstream fout(argv[2], ios::app);
    fin >> M >> N;
    tops.resize(M);
    Num.resize(M, 0);
    Low.resize(M, INT32_MAX);
    for (int i = 0; i < N; ++i) {
        fin >> input.start >> input.finish;
        input.start--;
        input.finish--;
        tops[input.start].push_back(input.finish);
        tops[input.finish].push_back(input.start);
    }
    QueryPerformanceCounter(&t1);
//    for (int i = 0; i < M; ++i) {
//        sort(tops[i].begin(), tops[i].end());
//    }
    for (int i = 0; i < M; ++i) {
        if (Num[i] == 0) {
            dfs(i, -1);
        }
    }
    QueryPerformanceCounter(&t2);
    elapsedTime = (double) (t2.QuadPart - t1.QuadPart) * 1000.0 / (double) frequency.QuadPart;
    fout << elapsedTime << endl;
    return 0;
}