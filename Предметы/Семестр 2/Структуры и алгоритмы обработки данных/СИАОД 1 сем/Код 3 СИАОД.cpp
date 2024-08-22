#include <iostream>
#include <iomanip>
#include <ctime>
#include <time.h>
using namespace std;
//функция, сливающая массивы
void Merge(int* A, int first, int last) {
    int middle, start, final, j;
    int* mas = new int[10005];
    middle = (first + last) / 2;  //вычисление среднего элемента
    start = first;                //начало левой части
    final = middle + 1;           //начало правой части
    for (j = first; j <= last; j++) { //выполнять от начала до конца
        if ((start <= middle) && ((final > last) || (A[start] < A[final]))) {
            mas[j] = A[start];
            start++;
        }
        else {
            mas[j] = A[final];
            final++;
        }
    }
    //возвращение результата в список
    for (j = first; j <= last; j++)
        A[j] = mas[j];
    delete[] mas;
};
//рекурсивная процедура сортировки
void MergeSort(int* A, int first, int last) {
    if (first < last) {
        MergeSort(A, first, (first + last) / 2);  //сортировка левой части
        MergeSort(A, (first + last) / 2 + 1, last);  //сортировка правой части
        Merge(A, first, last);  //слияние двух частей
    }
}
//главная функция
int main() {
    setlocale(LC_ALL, "Rus");
    int i, n;
    int* A = new int[10005];
    cout << "Введите размер массива: ";
    cin >> n;
    srand(time(NULL));
    for (i = 0; i <= n; i++)
    {
        A[i] = 0 + rand() % 100;
    }
    clock_t start, end;
    start = clock();
    MergeSort(A, 0, n);  //вызов сортирующей процедуры
    end = clock();
    cout << endl << endl;
    cout << "Отсортированный массив:" << endl;  //вывод упорядоченного массива
    for (i = 0; i < n; i++)
        cout << A[i] << setw(3);
    printf("\n\nПрограмма была выполнена за %.4f сек\n", ((double)end - start) / ((double)CLOCKS_PER_SEC)) << '\n';
    delete[] A;
    system("pause>>void");
}