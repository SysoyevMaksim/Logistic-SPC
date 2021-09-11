#include <iostream>
#include <fstream>

using namespace std;

string task[] = {"AUT", "BUT", "CUT"};
string type[] = {"AL", "AM", "RL"};
string density[] = {"few", "medium", "lot"};

int main(){
    string input_package = R"(C:\Users\sysoy\Logistic-SPC\Testing\Results\Undirected\)";
    string output_package = R"(C:\Users\sysoy\Logistic-SPC\Testing\Counted_results\Undirected\)";
    for (const string& cur_task: task) {
        for (const string& cur_type: type) {
            for (const string& cur_density: density) {
                string input_file, output_file, file_name;
                file_name.append(cur_task).append("_").append(cur_type).append("_").append(cur_density).append(".txt");
                input_file.append(input_package).append(file_name);
                output_file.append(output_package).append(file_name);
                ifstream input(input_file);
                ofstream output(output_file);
                double global_sum = 0;
                for (int i = 0; i < 3; ++i) {
                    double sum = 0, maximum = 0, minimum, data;
                    input >> minimum;
                    sum += minimum;
                    maximum = max(minimum, maximum);
                    for (int line = 0; line < 9; ++line) {
                        input >> data;
                        minimum = min(minimum, data);
                        maximum = max(maximum, data);
                        sum += data;
                    }
                    global_sum += (sum - minimum - maximum) / 8;
                }
                output << global_sum / 3 << "\n";
            }
        }
    }
}