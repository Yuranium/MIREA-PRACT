#include <iostream>
#include <ctime>
#include <stdlib.h>
#include <stdio.h>

using namespace std;
int main()
{
    setlocale(0, "");
    srand(time(NULL));
    long a[10000], b, count = 0, cv = 0;
    for (int i = 0; i < 10000; i++)
    {
        a[i] = rand() % 10000;
    }
    clock_t start, end;
    start = clock();
    for (int i = 0; i < 10000; i++)
    {
        for (int j = 0; j < 9999 - i; j++)
        {
            count++;
            if (a[j] > a[j + 1])
            {
                b = a[j];
                a[j] = a[j + 1];
                a[j + 1] = b;
                cv++;
            }
        }
    }
    end = clock();
    cout << "Отсортированный массив:" << endl;
    for (long i = 0; i < 10000; i++)
    {
        cout << a[i] << endl;
    }
    cout << "Количество перестановок элементов: " << cv << endl;
    cout << "Количество сравнений равно: " << count << endl;
    printf("Программа была выполнена за %.4f сек\n", ((double)end - start) / ((double)CLOCKS_PER_SEC)) << '\n';
    return 0;
}