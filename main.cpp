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

int linearTime,
    binaryTime,
    interpolationTime;

//Han Wiguna C | 224117129
void insertSort(vector<int> numbers){
    int arr[] = {10, 5, 7, 1, 3, 4, 8, 16, 15, 2};
    for (int i = 0; i < 10; i++) {
        if (arr[i] > arr[i + 1]) {
            int temp = arr[i + 1];
            bool flag = true;
            int j = i + 1;
            while (flag) {
                arr[j] = arr[j - 1];
                if (arr[j] < temp || j == 0) {
                    arr[j] = temp;
                    flag = false;
                }
                j--;
            }
        }
        for (int i = 0; i < 10; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
}

//Mathew Aprilian | 224117137
void linearSearch(vector<int> numbers){
    cout << "Searching..." << endl;
    time_t start_time;
    time(&start_time);

    int i = 0;
    int x = 7;
    bool flag = false;
    while (!flag && i != numbers.size()){
        if (numbers[i] == x){
            cout << "Found" << endl;
            flag = true;
        }
        i++;
    }
    if (!flag)
        cout << "Not found" << endl;


    time_t end_time;
    time(&end_time);

    cout << endl;
    linearTime = end_time - start_time;
    cout << "Linear Search took " << linearTime << " seconds" << endl;
    cout << endl;
}

//Mathew Aprilian | 224117137
void binarySearch(vector<int> numbers){
    cout << "Searching..." << endl;
    time_t start_time;
    time(&start_time);

    int high = numbers.size() - 1;
    int flag = false;
    int low = 0;
    int x = 7;
    while (high >= low && numbers[low] <= x && numbers[high] >= x && !flag) {
        int mid = low + (high-low)/2;
        if (numbers[mid] < x) {
            low = mid + 1;
        } else if (numbers[mid] > x) {
            high = mid - 1;
        } else if (numbers[mid] == x) {
            cout << "Found" << endl;
            flag = true;
        }
    }
    if (!flag)
        cout << "Not found" << endl;



    time_t end_time;
    time(&end_time);

    cout << endl;
    binaryTime = end_time - start_time;
    cout << "Binary Search took " << binaryTime << " seconds" << endl;
    cout << endl;
}


//Han Wiguna C | 224117129
void interpolationSearch(vector<int> numbers){
    cout << "Searching..." << endl;
    time_t start_time;
    time(&start_time);

    int high = numbers.size() - 1;
    int flag = false;
    int low = 0;
    int x = 7;
    while (high >= low && numbers[low] <= x && numbers[high] >= x && !flag) {
        int mid = ((x-numbers[low])/(numbers[high]-numbers[low])*(high - low)) + low;
        if (numbers[mid] < x) {
            low = mid + 1;
        } else if (numbers[mid] > x) {
            high = mid - 1;
        } else if (numbers[mid] == x) {
            cout << "Found" << endl;
            flag = true;
        }
    }
    if (!flag)
        cout << "Not found" << endl;



    time_t end_time;
    time(&end_time);

    cout << endl;
    interpolationTime = end_time - start_time;
    cout << "Interpolation Search took " << interpolationTime << " seconds" << endl;
    cout << endl;
}

int main() {
    srand(time(0));
    int menuInp;
    vector <int> numbers;
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
            system("cls");

            system("pause");
        } else if (menuInp == 2) {
            system("cls");

            system("pause");
        } else if (menuInp == 3) {
            system("cls");
            linearSearch(numbers);
            system("pause");
        } else if (menuInp == 4) {
            system("cls");
            binarySearch(numbers);
            system("pause");
        } else if (menuInp == 5) {
            system("cls");
            interpolationSearch(numbers);
            system("pause");
        }
    } while (menuInp != 6);
    return 0;
}