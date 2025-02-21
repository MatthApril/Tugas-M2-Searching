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
#include <chrono>
#include <thread>

using namespace std;

int linearTime,
    binaryTime,
    interpolationTime;

void loadFile(vector<int> &numbers, string fileName) {
    numbers.clear();
    ifstream myFile;
    string line;
    myFile.open(fileName, ios::in);
    if (myFile.is_open()) {
        while(getline(myFile, line)) {
            numbers.push_back(stoi(line));
        }
        myFile.close();
    }
}

void saveFile(vector<int> numbers, string fileName) {
    ofstream myFile;
    myFile.open(fileName, ios::out);
    if (myFile.is_open()) {
        for (int i = 0; i < numbers.size(); i++) {
            myFile << numbers[i] << endl;
        }
        myFile.close();
    }
}

void shuffle(vector<int> &numbers, vector <int> sorted) {
    for (int i = 0; i < numbers.size(); i++) {
        int j = (rand() % numbers.size() - i - 1) + i + 1;
        int temp =  numbers[i];
        numbers[i] = numbers[j];
        numbers[j] = temp;
    }
    sorted.clear();
    for (int i = 0; i < 1000000; i++) {
        sorted.push_back(numbers[i]);
    }
    saveFile(sorted, "sorted.txt");
}

//Han Wiguna C | 224117129
void insertSort(vector<int> &numbers){
    cout << "Sorting..." << endl;
    time_t start_time;
    time(&start_time);
    for (int i = 0; i <= numbers.size(); i++) {
        if (numbers[i] > numbers[i + 1]) {
            int temp = numbers[i + 1];
            bool flag = true;
            int j = i + 1;
            while (flag) {
                numbers[j] = numbers[j - 1];
                if (numbers[j] < temp || j == 0) {
                    numbers[j] = temp;
                    flag = false;
                }
                j--;
            }
        }
    }
    time_t end_time;
    time(&end_time);
    saveFile(numbers, "sorted.txt");
    cout << "Sorting done" << endl;
    cout << "Insertion Sort took " << end_time - start_time << " seconds" << endl;
}

//Mathew Aprilian | 224117137
void linearSearch(vector<int> numbers){
    int x;
    cout << "Enter number you searching for: ";
    cin >> x;
    cout << "Searching..." << endl;
    auto start = std::chrono::high_resolution_clock::now();

    int i = 0;
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


    auto ends = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(ends - start);

    cout << endl;
    cout << "Linear Search took " << duration.count() << " microseconds" << endl;
    cout << endl;
}

//Mathew Aprilian | 224117137
void binarySearch(vector<int> numbers){
    int x;
    cout << "Enter number you searching for: ";
    cin >> x;
    cout << "Searching..." << endl;
    auto start = std::chrono::high_resolution_clock::now();

    int high = numbers.size() - 1;
    int flag = false;
    int low = 0;
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

    auto ends = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(ends - start);
    cout << endl;
    cout << "Binary Search took " << duration.count() << " microseconds" << endl;
    cout << endl;
}


//Han Wiguna C | 224117129
void interpolationSearch(vector<int> numbers){
    int x;
    cout << "Enter number you searching for: ";
    cin >> x;
    cout << "Searching..." << endl;
    auto start = std::chrono::high_resolution_clock::now();
    int high = numbers.size() - 1;
    int flag = false;
    int low = 0;
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

    auto ends = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(ends - start);
    cout << endl;
    cout << "Interpolation Search took " << duration.count() << " microseconds" << endl;
    cout << endl;
}

int main() {
    srand(time(0));
    int menuInp, chooseShuffle;
    vector <int> numbers;
    vector <int> sorted;
    ifstream file;
    string line;
    file.open("random.txt", ios::in);
    if (file.is_open()) {
        if (!getline(file, line)) {
            for (int i = 1; i <= 2000000; i++) {
                numbers.push_back(i);
            }
            saveFile(numbers, "random.txt");
            shuffle(numbers, sorted);
            saveFile(numbers, "random.txt");
        }
    }
    loadFile(numbers, "random.txt");
    loadFile(sorted, "sorted.txt");
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
            do {
                cout << "Start shuffling?" << endl;
                cout << "1. Yes\n"
                     << "2. No\n";
                cout << ">> ";
                cin >> chooseShuffle;
                system("cls");
            } while (chooseShuffle < 1 || chooseShuffle > 2);
                if (chooseShuffle == 1){
                    cout << "[ ";
                    for (int i = 0; i < numbers.size(); i++) {
                        cout << numbers[i] << " ";
                    }
                    cout << " ]" << endl;
                    shuffle(numbers, sorted);
                    saveFile(numbers, "random.txt");
                    system("pause");
                }
        } else if (menuInp == 2) {
            loadFile(sorted, "sorted.txt");
            system("cls");
            insertSort(sorted);
            system("pause");
        } else if (menuInp == 3) {
            system("cls");
            linearSearch(sorted);
            system("pause");
        } else if (menuInp == 4) {
            system("cls");
            binarySearch(sorted);
            system("pause");
        } else if (menuInp == 5) {
            system("cls");
            interpolationSearch(sorted);
            system("pause");
        }
    } while (menuInp != 6);
    return 0;
}
