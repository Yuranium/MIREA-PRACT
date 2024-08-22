#include <iostream>
#include <ctime>
#include <iomanip>
using namespace std;
long main()
{
    setlocale(0, "");
    srand(time(NULL));
    long a[100], min, buf, cv = 0, count = 0;
    for (long i = 0; i < 100; i++)
    {
        a[i] = 0 + rand() % 100;
    }
    clock_t start, end;
    start = clock();
    for (long i = 0; i < 100; i++)
    {
        min = i;
        for (long j = i + 1; j < 100; j++)
        {
            count++;
            min = (a[j] < a[min]) ? j : min;
        }
        if (i != min)
        {
            buf = a[i];
            a[i] = a[min];
            a[min] = buf;
            cv++;
        }
    }
    end = clock();
    cout << "Отсортированный массив:" << endl;
    for (long i = 0; i < 100; i++)
    {
        cout << a[i] << setw(4);
    }
    cout << endl << endl;
    cout << "Количество перестановок элементов: " << cv << endl;
    cout << "Количество сравнений равно: " << count << endl;
    printf("Программа была выполнена за %.4f сек\n", ((double)end - start) / ((double)CLOCKS_PER_SEC)) << '\n';
    return 0;
}