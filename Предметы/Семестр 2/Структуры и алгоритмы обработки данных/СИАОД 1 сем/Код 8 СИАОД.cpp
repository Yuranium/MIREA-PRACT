Реализация без стека:
#include <iostream>
#include <iomanip>
#include <ctime>
using namespace std;
int main()
{
    srand(time(NULL));
    setlocale(0, "");
    int size_m, start, count = 0;
    cout << "Размер массива: " << endl;
    cin >> size_m;
    int* size = new int[size_m];
    for (int i = 0; i < size_m; i++)
    {
        size[i] = rand() % 50;
    }
    cout << "Высоты зданий:   ";
    for (int i = 0; i < size_m; i++)
    {
        cout << size[i] << setw(4);
    }
    int max = size[0];
    for (int i = 0; i < size_m; i++)
    {
        if (size[i] > max)
            max = size[i];
    }
    cout << endl << "Введите стартовую позицию: ";
    cin >> start;
    if (start > max)
        count += size_m;
    else
    {
        for (int j = 0; j < size_m; j++)
        {
            if (size[j] >= start)
            {
                count++;
                start = size[j];
            }
        }
    }
    cout << "Зданий видно со стартовой точки: " << count << endl;
    delete[] size;
    return 0;
}



Стековая реализация:
#include <iostream>
#include <ctime>
#include <stack>
using namespace std;
int main()
{
    srand(time(NULL));
    setlocale(0, "");
    int size, x;
    stack<int> mas;
    cout << "Введите размер стека: ";
    cin >> size;
    cout << "Введите элементы стека(Высоты зданий):" << endl;
    for (int i = 0; i < size; i++) 
    {
        cin >> x;
        if (i == 0) 
        {
            mas.push(x);
        }
        if (i > 0) 
        {
            if (x > mas.top()) 
            {
                mas.push(x);
            }
        }
    }
    cout << "Зданий видно со стартовой точки: " << mas.size() << "\n";
    return 0;
}





№8.1:
#include <iostream>
#include <string>

using namespace std;

string addStrings(string num1, string num2) {
    string result = "";
    int carry = 0;
    int i = num1.size() - 1;
    int j = num2.size() - 1;

    while (i >= 0 || j >= 0) {
        int sum = carry;
        if (i >= 0) {
            sum += num1[i] - '0';
            i--;
        }
        if (j >= 0) {
            sum += num2[j] - '0';
            j--;
        }
        result = to_string(sum % 10) + result;
        carry = sum / 10;
    }

    if (carry > 0) {
        result = to_string(carry) + result;
    }

    return result;
}

int main() {
    string num1, num2;
    cout << "Enter the first large integer: ";
    cin >> num1;
    cout << "Enter the second large integer: ";
    cin >> num2;
    string sum = addStrings(num1, num2);
    cout << "Sum = " << sum << endl;
    return 0;
}
Объяснение: 

The addStrings()функция принимает две строки ` num1и num2в качестве входных данных и возвращает их сумму в виде строки.  Он использует два указателя iи jдля перебора строк справа налево и добавления соответствующих цифр num1и num2вместе с любым переносом из предыдущего дополнения.  Полученная сумма присоединяется к resultстрока, и перенос обновляется для следующей итерации.  Наконец, если остался перенос, он добавляется к результату. 

в main()мы читаем с клавиатуры два больших целых числа в виде строк, а затем вызываем addStrings()функция их добавления.  Результат распечатывается 

