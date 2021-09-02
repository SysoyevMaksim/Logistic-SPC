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
vector<Rib> ribs;
vector<int> Num;
vector<int> Low;
stack<Rib> output;
Rib input;

bool by_start_by_finish(Rib a, Rib b) {
    if (a.start == b.start) {
        return a.finish < b.finish;
    }
    return a.start < b.start;
}

bool by_start(Rib a, Rib b) {
    return a.start < b.start;
}

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
    auto begin = lower_bound(ribs.begin(), ribs.end(), Rib{top, 0}, by_start),
            end = upper_bound(ribs.begin(), ribs.end(), Rib{top, 0}, by_start);
    for (auto way = begin; way != end; way++) {
        int ending = (*way).finish;
        if (Num[ending] == 0) {
            output.push(*way);
            dfs(ending, top);
            Low[top] = min(Low[top], Low[ending]);
            if (Low[ending] == Num[top]) {
                print_stack(top);
            }
        } else {
            if (Num[top] > Num[ending] && ending != parent) {
                output.push(*way);
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
    ribs.resize(2 * N);
    Num.resize(M, 0);
    Low.resize(M, INT32_MAX);
    for (int i = 0; i < 2 * N; i += 2) {
        fin >> input.start >> input.finish;
        input.start--;
        input.finish--;
        ribs[i] = {input.start, input.finish};
        ribs[i + 1] = {input.finish, input.start};
    }
    QueryPerformanceCounter(&t1);
    sort(ribs.begin(), ribs.end(), by_start_by_finish);
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