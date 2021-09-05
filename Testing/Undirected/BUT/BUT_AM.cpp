#include <fstream>
#include <vector>
#include <algorithm>
#include <windows.h>

using namespace std;

struct Rib {
    int start, finish;
};


int M, N, order = 1;
vector<vector<int>> matrix;
vector<int> Num;
vector<int> Low;
Rib input;

void dfs(int top, int parent) {
    Num[top] = order;
    Low[top] = Num[top];
    order++;
    for (int ending = 0; ending < N; ending++) {
        if (matrix[top][ending] == 1) {
            if (ending == parent) continue;
            if (Num[ending] == 0) {
                dfs(ending, top);
                Low[top] = min(Low[top], Low[ending]);
                if (Low[ending] > Num[top]) {
                    //Bridge
                }
            } else {
                Low[top] = min(Low[top], Num[ending]);
            }
        }
    }
}

int main(int argc, char **argv) {
    LARGE_INTEGER frequency, t1, t2;
    double elapsedTime;
    QueryPerformanceFrequency(&frequency);
    ifstream fin(argv[1]);
    ofstream fout(argv[2], ios::app);
    fin >> N;
    matrix.resize(N, vector<int>(N));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            fin >> matrix[i][j];
            if (matrix[i][j] == 1) {
                M++;
            }
        }
    }
    M /= 2;
    Num.resize(M, 0);
    Low.resize(M, INT32_MAX);
    QueryPerformanceCounter(&t1);
    for (int i = 0; i < N; ++i) {
        if (Num[i] == 0) {
            dfs(i, -1);
        }
    }
    QueryPerformanceCounter(&t2);
    elapsedTime = (double) (t2.QuadPart - t1.QuadPart) * 1000.0 / (double) frequency.QuadPart;
    fout << elapsedTime << endl;
    return 0;
}