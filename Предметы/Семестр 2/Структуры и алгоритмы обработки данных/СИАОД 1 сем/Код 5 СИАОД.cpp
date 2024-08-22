#include <iostream>
#include <algorithm>
#include <ctime>
#include <iomanip>
using namespace std;
int main() 
{
    setlocale(LC_ALL, "rus");
    srand(time(NULL));
    int arr[1000];
    int key, count = 0;
    cout << "Массив: " << endl;
    for (int i = 0; i < 1000; i++) 
    {
        arr[i] = rand() % 500;
    }
    sort(arr, arr + 1000); // сортируем с помощью функции sort (быстрая сортировка)
    for (int i = 0; i < 1000; i++)
    {
        cout << arr[i] << setw(5);
    }
    cout << endl << "Введите ключ: ";
    cin >> key;
    bool flag = false;
    int l = 0; // левая граница
    int r = 999; // правая граница
    int mid;
    while ((l <= r) && (flag != true)) 
    {
        count++;
        mid = (l + r) / 2; // считываем срединный индекс отрезка [l,r]
        if (arr[mid] == key) 
        {
            flag = true; //проверяем ключ со серединным элементом
        }
        if (arr[mid] > key) 
        {
            r = mid - 1; // проверяем, какую часть нужно отбросить
        }
        else l = mid + 1;
    }
    if (flag) cout << "Индекс элемента " << key << " в массиве равен: " << mid << endl;
    else cout << "Такого элемента в массиве нет" << endl;
    cout << "Количество сравнений равно: " << count << endl;
    system("pause");
    return 0;
}