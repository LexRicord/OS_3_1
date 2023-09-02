#include <iostream>
#include <Windows.h>

#define KB (1024)
#define PG (4 * KB)

using namespace std;

//Г c3
//е e5
//р f0 
//страница C3 = 195
//смещение E5F = 3679
//адрес = 195 * PG + 3679 = 0x000CAEEE
//00007FF7444A0000 - 00007FF7444C7000[16156]

int main() {
    int pages = 256;
    int countItems = pages * PG / sizeof(int);

    LPVOID xmemaddr = VirtualAlloc(NULL, pages * PG, MEM_COMMIT, PAGE_READWRITE);
    int* arr = (int*)xmemaddr;
    for (int i = 0; i < countItems; i++) {
        arr[i] = i;
    }
    cout << endl;

    getchar();

    VirtualFree(xmemaddr, NULL, MEM_RELEASE) ?
        cout << "VirtualFree true\n" : cout << "VirtualFree false\n";

    system("pause");
}

