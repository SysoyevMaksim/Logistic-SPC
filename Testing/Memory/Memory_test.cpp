#include "windows.h"
#include "psapi.h"
#include <iostream>
#include <vector>

using namespace std;

//int test1[100000];
//vector<int> test2(100000);

int main() {
//    int test3[100000];
    MEMORYSTATUSEX memInfo;
    memInfo.dwLength = sizeof(MEMORYSTATUSEX);
    GlobalMemoryStatusEx(&memInfo);
    DWORDLONG totalVirtualMem = memInfo.ullTotalVirtual;
    DWORDLONG totalPhysMem = memInfo.ullTotalPhys;
    cout << totalVirtualMem << (totalVirtualMem > totalPhysMem ? " > " : " < ") << totalPhysMem << "\n";

    DWORDLONG virtualMemUsed = memInfo.ullTotalVirtual - memInfo.ullAvailVirtual;
    DWORDLONG physMemUsed = memInfo.ullTotalPhys - memInfo.ullAvailPhys;

    cout << virtualMemUsed << (virtualMemUsed > physMemUsed ? " > " : " < ") << physMemUsed << "\n";

    PROCESS_MEMORY_COUNTERS_EX pmc;
    GetProcessMemoryInfo(GetCurrentProcess(), (PROCESS_MEMORY_COUNTERS *) &pmc, sizeof(pmc));
    SIZE_T physMemUsedByMe = pmc.WorkingSetSize;
    SIZE_T virtualMemUsedByMe = pmc.PrivateUsage;
    cout << virtualMemUsedByMe << (virtualMemUsedByMe > physMemUsedByMe ? " > " : " < ") << physMemUsedByMe << "\n";
}