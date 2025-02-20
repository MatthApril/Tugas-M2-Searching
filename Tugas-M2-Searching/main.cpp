#include <iostream>
#include <cstdlib>
#include <windows.h>
#include <cmath>
#include <fstream>
#include <vector>
#include <ctime>
#include <string>
#include <conio.h>
#include <vector>

using namespace std;

vector<int> insertionSort(vector<int> numbers) {
    for (int i = 0; i < numbers.size() - 1; i++) {
        if (numbers[i] < numbers[i + 1]) {
            for (int j = i + 1; j >= 0; j-- ) {
                if ()
            }
        }
    }
}

void linearSearch(){

}

void binarySearch(){

}

void interpolationSearch(){

}

int main()
{
    srand(time(0));
    int menuInp;
    do{
        system("cls");
        cout << "Tugas Minggu 2 Alpro" << endl;
        cout << "1. Generate Angka\n"
             << "2. Sort\n"
             << "3. Linear\n"
             << "4. Binary\n"
             << "5. Interpolation\n"
             << "6. Exit" << endl;
        cout << ">> ";
        cin >> menuInp;
        if (menuInp == 1) {

        } else if (menuInp == 2) {

        } else if (menuInp == 3) {

        } else if (menuInp == 4) {

        } else if (menuInp == 5) {

        }
    } while (menuInp != 6);
    return 0;
}
