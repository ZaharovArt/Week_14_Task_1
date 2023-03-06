// Week_14_Task_1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;
int** initArray(int rows, int cols);
void printArray(int** Arr, int rows, int cols);
int** newArray(int** Arr, int rows, int cols);
int** newArrayadd(int** Arr, int rows, int cols, int* Arr2, int size);
int** newArrayadd2(int** Arr, int rows, int cols, int* Arr2, int size);



int main()
{
    
    int rows, cols;

    rows = 5;
    cols = 5;

    int** Array1 =  initArray(rows,cols);
    printArray(Array1, rows, cols);

    int** Array2 = newArray(Array1, rows, cols);
    cout << endl;

    printArray(Array2, rows + 1, cols);

    int Array3[5] = { 1,2,3,4,5};

    int** Array4 = newArrayadd(Array1, rows, cols, Array3, 5);
    cout << endl;
    printArray(Array4, rows + 1, cols);

    int** Array5 = newArrayadd2(Array1, rows, cols, Array3, 5);
    cout << endl;
    printArray(Array5, rows + 1, cols);

}

int** initArray(int rows, int cols) {

    int** pArr = new int* [rows];

    for (int i = 0; i < rows; i++) {
        pArr[i] = new int  [cols] ;
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            pArr[i][j] = rand() % 10;
        }
    }
    return pArr;
}


void printArray(int ** Arr, int rows, int cols) {

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
           cout << Arr[i][j]<<" ";
        }
        cout << endl;
    }
    
}

int** newArray(int** Arr, int rows, int cols) {

    int** pArr = new int* [rows + 1];
    for (int i = 0; i < rows+1; i++) {
        pArr[i] = new int[cols];
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            pArr[i][j] = Arr[i][j];
        }
    }

    for (int i = 0; i < cols; i++) {
        pArr[rows][i] = rand() % 10;
    }
    return pArr;
}

int** newArrayadd(int** Arr, int rows, int cols, int* Arr2, int size) {

    int** pArr = new int* [rows + 1];
    for (int i = 0; i < rows; i++) {
        pArr[i] = new int[cols];
    }

    pArr[rows] = new int[size];

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            pArr[i][j] = Arr[i][j];
        }
    }

    for (int i = 0; i < size; i++) {
        pArr[rows][i] = Arr2[i];
    }
    return pArr;
}

int** newArrayadd2(int** Arr, int rows, int cols, int* Arr2, int size) {

    int** pArr = new int* [rows + 1];
    for (int i = 0; i < rows; i++) {
        pArr[i] = new int[cols];
    }

    pArr[0] = new int[size];

    for (int i = 1; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            pArr[i][j] = Arr[i][j];
        }
    }

    for (int i = 0; i < size; i++) {
        pArr[0][i] = Arr2[i];
    }
    return pArr;
}