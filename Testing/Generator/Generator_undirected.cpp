#include <fstream>
#include <vector>
#include <random>
#include <ctime>

using namespace std;

int main() {
    ofstream fout;
    mt19937 mersenne(time(nullptr));
    vector<vector<int>> matrix;
    for (int i = 0; i < 30; ++i) {
        unsigned int tops = 900 + mersenne() % 100;
        matrix.assign(tops, vector<int>(tops, 0));
        for (unsigned int x = 1; x < tops; ++x) {
            for (unsigned int y = 0; y < x; ++y) {
                if (mersenne() % 30 == 0) {
                    matrix[y][x] = 1;
                    matrix[x][y] = 1;
                }
            }
        }
        fout.open(R"(C:\Users\sysoy\Logistic-SPC\Testing\Tests\Undirected\AM_test_few)" + to_string(i + 1) + ".txt");
        fout << tops << "\n";
        for (unsigned int x = 0; x < tops; ++x) {
            for (unsigned int y = 0; y < tops; ++y) {
                fout << matrix[x][y] << " ";
            }
            fout << "\n";
        }
        fout.close();
        fout.open(R"(C:\Users\sysoy\Logistic-SPC\Testing\Tests\Undirected\RL_test_few)" + to_string(i + 1) + ".txt");
        int N = 0;
        for (unsigned int x = 0; x < tops; ++x) {
            for (unsigned int y = 0; y < tops; ++y) {
                N += matrix[x][y];
            }
        }
        fout << tops << " " << N << "\n";
        for (unsigned int x = 0; x < tops; ++x) {
            for (unsigned int y = 0; y < tops; ++y) {
                fout << (matrix[x][y] == 1 ? (to_string(x+1) + " " + to_string(y+1)) + "\n" : "");
            }
        }
        fout.close();
    }
    for (int i = 0; i < 30; ++i) {
        unsigned int tops = 900 + mersenne() % 100;
        matrix.assign(tops, vector<int>(tops, 0));
        for (unsigned int x = 1; x < tops; ++x) {
            for (unsigned int y = 0; y < x; ++y) {
                if (mersenne() % 4 != 0) {
                    matrix[y][x] = 1;
                    matrix[x][y] = 1;
                }
            }
        }
        fout.open(R"(C:\Users\sysoy\Logistic-SPC\Testing\Tests\Undirected\AM_test_lot)" + to_string(i + 1) + ".txt");
        fout << tops << "\n";
        for (unsigned int x = 0; x < tops; ++x) {
            for (unsigned int y = 0; y < tops; ++y) {
                fout << matrix[x][y] << " ";
            }
            fout << "\n";
        }
        fout.close();
        fout.open(R"(C:\Users\sysoy\Logistic-SPC\Testing\Tests\Undirected\RL_test_lot)" + to_string(i + 1) + ".txt");
        int N = 0;
        for (unsigned int x = 0; x < tops; ++x) {
            for (unsigned int y = 0; y < tops; ++y) {
                N += matrix[x][y];
            }
        }
        fout << tops << " " << N << "\n";
        for (unsigned int x = 0; x < tops; ++x) {
            for (unsigned int y = 0; y < tops; ++y) {
                fout << (matrix[x][y] == 1 ? (to_string(x+1) + " " + to_string(y+1) + "\n") : "");
            }
        }
        fout.close();
    }
    for (int i = 0; i < 30; ++i) {
        unsigned int tops = 900 + mersenne() % 100;
        matrix.assign(tops, vector<int>(tops, 0));
        for (unsigned int x = 1; x < tops; ++x) {
            for (unsigned int y = 0; y < x; ++y) {
                if (mersenne() % 14 == 0) {
                    matrix[y][x] = 1;
                    matrix[x][y] = 1;
                }
            }
        }
        fout.open(R"(C:\Users\sysoy\Logistic-SPC\Testing\Tests\Undirected\AM_test_medium)" + to_string(i + 1) + ".txt");
        fout << tops << "\n";
        for (unsigned int x = 0; x < tops; ++x) {
            for (unsigned int y = 0; y < tops; ++y) {
                fout << matrix[x][y] << " ";
            }
            fout << "\n";
        }
        fout.close();
        fout.open(R"(C:\Users\sysoy\Logistic-SPC\Testing\Tests\Undirected\RL_test_medium)" + to_string(i + 1) + ".txt");
        int N = 0;
        for (unsigned int x = 0; x < tops; ++x) {
            for (unsigned int y = 0; y < tops; ++y) {
                N += matrix[x][y];
            }
        }
        fout << tops << " " << N << "\n";
        for (unsigned int x = 0; x < tops; ++x) {
            for (unsigned int y = 0; y < tops; ++y) {
                fout << (matrix[x][y] == 1 ? (to_string(x+1) + " " + to_string(y+1)) + "\n" : "");
            }
        }
        fout.close();
    }
}