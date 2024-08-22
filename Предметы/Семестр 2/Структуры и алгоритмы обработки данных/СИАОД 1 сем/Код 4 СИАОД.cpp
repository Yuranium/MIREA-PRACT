Код с рандомными числами:
#include <iostream>
#include <ctime>
using namespace std;
int main()
{
  setlocale(0, "");
  srand(time(NULL));
  int a[75], b, count = 0;
  cout << "Введите число, которое хотите найти в массиве: " << endl;
  cin >> b;
  clock_t start, end;
  start = clock();
  for (int i = 0; i < 75; i++)
  {
    count++;
    a[i] = rand() % 75 + 1;
    if (a[i] == b)
    {
      cout << "Число в массиве: " << a[i] << endl;
      break;
    }
    else if (!(75 - i - 1))
      cout << "Числа нет в массиве." << endl;
  }
  end = clock();
  cout << "Количество сравнений равно: " << count << endl;
  printf("Программа была выполнена за %.4f сек\n", ((double)end - start) / ((double)CLOCKS_PER_SEC)) << '\n';
  return 0;
}


Код с возрастающими числами:
#include <iostream>
#include <ctime>
using namespace std;
int main()
{
	setlocale(0, "");
	srand(time(NULL));
	int a[10], b, count = 0;
	cout << "Введите число, которое хотите найти в массиве: " << endl;
	cin >> b;
	clock_t start, end;
	start = clock();
	for (int i = 0; i < 10; i++)
	{
		count++;
		if (i == b)
		{
			cout << "Число есть в массиве" << endl;
			break;
		}
		else if (!(10 - i - 1))
			cout << "Числа нет в массиве" << endl;
	}
	end = clock();
	cout << "Количество сравнений равно: " << count << endl;
	printf("Программа была выполнена за %.4f сек\n", ((double)end - start) / ((double)CLOCKS_PER_SEC)) << '\n';
	return 0;
}

Код с убывающими числами:
#include <iostream>
#include <ctime>
using namespace std;
int main()
{
	setlocale(0, "");
	srand(time(NULL));
	int a[10], b, count = 0;
	cout << "Введите число, которое хотите найти в массиве: " << endl;
	cin >> b;
	clock_t start, end;
	start = clock();
	for (int i = 10; i > 0; --i)
	{
		count++;
		cout << i;
		if (i == b)
		{
			cout << "Число есть в массиве" << endl;
			break;
		}
		else if (!(i - 1))
			cout << "Числа нет в массиве" << endl;
	}
	end = clock();
	cout << "Количество сравнений равно: " << count << endl;
	printf("Программа была выполнена за %.4f сек\n", ((double)end - start) / ((double)CLOCKS_PER_SEC)) << '\n';
	return 0;
}