#include <fstream>

using namespace std;

int main() {

    ofstream fout1;
    ofstream fout2;
    ofstream fout3;
    string AL, AM, RL, test_AM, test_RL,
            result_AL_F, result_AM_F, result_RL_F,
            result_AL_M, result_AM_M, result_RL_M,
            result_AL_L, result_AM_L, result_RL_L,
            start;

/** AUT*/

    AL = R"(C:\SPC\1\AUT_AL.exe )";
    AM = R"(C:\SPC\1\AUT_AM.exe )";
    RL = R"(C:\SPC\1\AUT_RL.exe )";

/** Few*/
    result_AL_F = R"(C:\SPC\3\AUT_AL_few.txt)";
    result_AM_F = R"(C:\SPC\3\AUT_AM_few.txt)";
    result_RL_F = R"(C:\SPC\3\AUT_RL_few.txt)";

    fout1.open(result_AL_F);
    fout2.open(result_AM_F);
    fout3.open(result_RL_F);
    for (int i = 0; i < 30; i++) {
        test_AM = R"(C:\SPC\2\AM_test_few)"
                  + to_string(i + 1) + ".txt ";
        test_RL = R"(C:\SPC\2\RL_test_few)"
                  + to_string(i + 1) + ".txt ";

        start = "start ";
        system((start.append(AL).append(test_RL).append(result_AL_F)).c_str());
        start = "start ";
        system((start.append(AM).append(test_AM).append(result_AM_F)).c_str());
        start = "start ";
        system((start.append(RL).append(test_RL).append(result_RL_F)).c_str());
    }
    fout1.close();
    fout2.close();
    fout3.close();

/** Medium*/
    result_AL_M = R"(C:\SPC\3\AUT_AL_medium.txt)";
    result_AM_M = R"(C:\SPC\3\AUT_AM_medium.txt)";
    result_RL_M = R"(C:\SPC\3\AUT_RL_medium.txt)";

    fout1.open(result_AL_M);
    fout2.open(result_AM_M);
    fout3.open(result_RL_M);
    for (int i = 0; i < 30; i++) {
        test_AM = R"(C:\SPC\2\AM_test_medium)"
                  + to_string(i + 1) + ".txt ";
        test_RL = R"(C:\SPC\2\RL_test_medium)"
                  + to_string(i + 1) + ".txt ";

        start = "start ";
        system((start.append(AL).append(test_RL).append(result_AL_M)).c_str());
        start = "start ";
        system((start.append(AM).append(test_AM).append(result_AM_M)).c_str());
        start = "start ";
        system((start.append(RL).append(test_RL).append(result_RL_M)).c_str());
    }
    fout1.close();
    fout2.close();
    fout3.close();

/** Lot*/
    result_AL_L = R"(C:\SPC\3\AUT_AL_lot.txt)";
    result_AM_L = R"(C:\SPC\3\AUT_AM_lot.txt)";
    result_RL_L = R"(C:\SPC\3\AUT_RL_lot.txt)";

    fout1.open(result_AL_L);
    fout2.open(result_AM_L);
    fout3.open(result_RL_L);
    for (int i = 0; i < 30; i++) {
        test_AM = R"(C:\SPC\2\AM_test_lot)"
                  + to_string(i + 1) + ".txt ";
        test_RL = R"(C:\SPC\2\RL_test_lot)"
                  + to_string(i + 1) + ".txt ";

        start = "start ";
        system((start.append(AL).append(test_RL).append(result_AL_L)).c_str());
        start = "start ";
        system((start.append(AM).append(test_AM).append(result_AM_L)).c_str());
        start = "start ";
        system((start.append(RL).append(test_RL).append(result_RL_L)).c_str());
    }
    fout1.close();
    fout2.close();
    fout3.close();

/** BUT*/

    AL = R"(C:\SPC\1\BUT_AL.exe )";
    AM = R"(C:\SPC\1\BUT_AM.exe )";
    RL = R"(C:\SPC\1\BUT_RL.exe )";

/** Few*/
    result_AL_F = R"(C:\SPC\3\BUT_AL_few.txt)";
    result_AM_F = R"(C:\SPC\3\BUT_AM_few.txt)";
    result_RL_F = R"(C:\SPC\3\BUT_RL_few.txt)";

    fout1.open(result_AL_F);
    fout2.open(result_AM_F);
    fout3.open(result_RL_F);
    for (int i = 0; i < 30; i++) {
        test_AM = R"(C:\SPC\2\AM_test_few)"
                  + to_string(i + 1) + ".txt ";
        test_RL = R"(C:\SPC\2\RL_test_few)"
                  + to_string(i + 1) + ".txt ";

        start = "start ";
        system((start.append(AL).append(test_RL).append(result_AL_F)).c_str());
        start = "start ";
        system((start.append(AM).append(test_AM).append(result_AM_F)).c_str());
        start = "start ";
        system((start.append(RL).append(test_RL).append(result_RL_F)).c_str());
    }
    fout1.close();
    fout2.close();
    fout3.close();

/** Medium*/
    result_AL_M = R"(C:\SPC\3\BUT_AL_medium.txt)";
    result_AM_M = R"(C:\SPC\3\BUT_AM_medium.txt)";
    result_RL_M = R"(C:\SPC\3\BUT_RL_medium.txt)";

    fout1.open(result_AL_M);
    fout2.open(result_AM_M);
    fout3.open(result_RL_M);
    for (int i = 0; i < 30; i++) {
        test_AM = R"(C:\SPC\2\AM_test_medium)"
                  + to_string(i + 1) + ".txt ";
        test_RL = R"(C:\SPC\2\RL_test_medium)"
                  + to_string(i + 1) + ".txt ";

        start = "start ";
        system((start.append(AL).append(test_RL).append(result_AL_M)).c_str());
        start = "start ";
        system((start.append(AM).append(test_AM).append(result_AM_M)).c_str());
        start = "start ";
        system((start.append(RL).append(test_RL).append(result_RL_M)).c_str());
    }
    fout1.close();
    fout2.close();
    fout3.close();

/** Lot*/
    result_AL_L = R"(C:\SPC\3\BUT_AL_lot.txt)";
    result_AM_L = R"(C:\SPC\3\BUT_AM_lot.txt)";
    result_RL_L = R"(C:\SPC\3\BUT_RL_lot.txt)";

    fout1.open(result_AL_L);
    fout2.open(result_AM_L);
    fout3.open(result_RL_L);
    for (int i = 0; i < 30; i++) {
        test_AM = R"(C:\SPC\2\AM_test_lot)"
                  + to_string(i + 1) + ".txt ";
        test_RL = R"(C:\SPC\2\RL_test_lot)"
                  + to_string(i + 1) + ".txt ";

        start = "start ";
        system((start.append(AL).append(test_RL).append(result_AL_L)).c_str());
        start = "start ";
        system((start.append(AM).append(test_AM).append(result_AM_L)).c_str());
        start = "start ";
        system((start.append(RL).append(test_RL).append(result_RL_L)).c_str());
    }
    fout1.close();
    fout2.close();
    fout3.close();

/** CUT*/

    AL = R"(C:\SPC\1\CUT_AL.exe )";
    AM = R"(C:\SPC\1\CUT_AM.exe )";
    RL = R"(C:\SPC\1\CUT_RL.exe )";

/** Few*/
    result_AL_F = R"(C:\SPC\3\CUT_AL_few.txt)";
    result_AM_F = R"(C:\SPC\3\CUT_AM_few.txt)";
    result_RL_F = R"(C:\SPC\3\CUT_RL_few.txt)";

    fout1.open(result_AL_F);
    fout2.open(result_AM_F);
    fout3.open(result_RL_F);
    for (int i = 0; i < 30; i++) {
        test_AM = R"(C:\SPC\2\AM_test_few)"
                  + to_string(i + 1) + ".txt ";
        test_RL = R"(C:\SPC\2\RL_test_few)"
                  + to_string(i + 1) + ".txt ";

        start = "start ";
        system((start.append(AL).append(test_RL).append(result_AL_F)).c_str());
        start = "start ";
        system((start.append(AM).append(test_AM).append(result_AM_F)).c_str());
        start = "start ";
        system((start.append(RL).append(test_RL).append(result_RL_F)).c_str());
    }
    fout1.close();
    fout2.close();
    fout3.close();

/** Medium*/
    result_AL_M = R"(C:\SPC\3\CUT_AL_medium.txt)";
    result_AM_M = R"(C:\SPC\3\CUT_AM_medium.txt)";
    result_RL_M = R"(C:\SPC\3\CUT_RL_medium.txt)";

    fout1.open(result_AL_M);
    fout2.open(result_AM_M);
    fout3.open(result_RL_M);
    for (int i = 0; i < 30; i++) {
        test_AM = R"(C:\SPC\2\AM_test_medium)"
                  + to_string(i + 1) + ".txt ";
        test_RL = R"(C:\SPC\2\RL_test_medium)"
                  + to_string(i + 1) + ".txt ";

        start = "start ";
        system((start.append(AL).append(test_RL).append(result_AL_M)).c_str());
        start = "start ";
        system((start.append(AM).append(test_AM).append(result_AM_M)).c_str());
        start = "start ";
        system((start.append(RL).append(test_RL).append(result_RL_M)).c_str());
    }
    fout1.close();
    fout2.close();
    fout3.close();

/** Lot*/
    result_AL_L = R"(C:\SPC\3\CUT_AL_lot.txt)";
    result_AM_L = R"(C:\SPC\3\CUT_AM_lot.txt)";
    result_RL_L = R"(C:\SPC\3\CUT_RL_lot.txt)";

    fout1.open(result_AL_L);
    fout2.open(result_AM_L);
    fout3.open(result_RL_L);
    for (int i = 0; i < 30; i++) {
        test_AM = R"(C:\SPC\2\AM_test_lot)"
                  + to_string(i + 1) + ".txt ";
        test_RL = R"(C:\SPC\2\RL_test_lot)"
                  + to_string(i + 1) + ".txt ";

        start = "start ";
        system((start.append(AL).append(test_RL).append(result_AL_L)).c_str());
        start = "start ";
        system((start.append(AM).append(test_AM).append(result_AM_L)).c_str());
        start = "start ";
        system((start.append(RL).append(test_RL).append(result_RL_L)).c_str());
    }
    fout1.close();
    fout2.close();
    fout3.close();
}