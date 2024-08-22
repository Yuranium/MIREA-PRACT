1 часть:
#include <iostream>
using namespace std;
struct List 
{
    char data;                                  //тип данных элементов
    List* next;
};
void print(List* L, int num)                     //выводит список
{
    List* p = L;                                //присваиваем p первый элемент (L указывает на первый элемент)
    cout << "Список L" << num << ":" << endl;

    while (p) 
    {                                 //пока не закончатся элементы (p != nullptr)
        cout << p->data << endl;                //выводим то, что записали
        p = p->next;                            //переходим к следующему
    }
}
void create_list(List*& L, int size) 
{         //создает список
    List* t;
    cout << "Введите элементы списка: " << endl;
    for (int i = 0; i < size; i++)              //size - размер списка
    {
        t = new List;
        cin >> t->data;                         //вводим элемент
        t->next = L;                            //указываем на начало
        L = t;                                  //добавляем в начало
    }
}
int main(int argc, const char* argv[])
{
    setlocale(0, "");
    List* L1 = NULL, * L2 = NULL;               //объявляем указатели на первые элементы
    int size;
    cout << "Введите размер 1-ого списка: " << endl;
    cin >> size;
    create_list(L1, size);                      //создаем список L1
    print(L1, 1);                               //печатаем
    cout << "Введите размер 2-ого списка: " << endl;
    cin >> size;
    create_list(L2, size);                      //создаем список L2
    print(L2, 2);                               //печатаем
    return 0;
}


2 часть:
#include <iostream>
using namespace std;

struct Node
{
    int num;
        int day1;
        int time1;
        int time2;
 //-------------------//
        int day2;
        int time3;
        int time4;
    int price;
    Node *next;
    Node *prev;
};

typedef Node *node;

node createBus()
{
    node bus = new Node();
    cout << endl << "--ВВОД РАСПИСАНИЯ АВТОБУСА--" << endl << endl;
    cout << "Введите номер автобуса: ";
    cin >> bus->num;
    cout << "Введите первую дату отправок автобуса: ";
    cin >> bus->day1;
    cout << "Введите время первой отправки: ";
    cin >> bus->time1;
    cout << "Введите время второй отправки: ";
    cin >> bus->time2;
    cout << "Введите вторую дату отправок автобуса: ";
    cin >> bus->day2;
    cout << "Введите время третьей отправки: ";
    cin >> bus->time3;
    cout << "Введите время четвёртой отправки: ";
    cin >> bus->time4;
    cout << "Введите стоимость: ";
    cin >> bus->price;
    bus->next = NULL;

    return bus;
}

void addBusAfter (node &head, node &tail, node pos, node bus)
{
    if (!head)
    {
        bus->next = bus->prev = nullptr;
        head = tail = bus;
    }
    else if (!pos)
    {
        bus->next = nullptr;
        bus->prev = tail;
        tail = tail->next = bus;
    }
    else if (pos == head)
    {
        bus->prev = nullptr;
        bus->next = head;
        head = head->prev = bus;
    }
    else
    {
        bus->prev = pos->prev;
        bus->next = pos;
        pos->prev = pos->prev->next = bus;
    }
    cout << endl << endl;
}

void delBus (node &list, node &head, node &tail, node &current, int num)
{
    list = head;
    while(list)
    {
        if(list->num == num)
        {
            if(list == head)
            {
                head = head->next;
                if(head)
                    head->prev = NULL;
                else
                    tail = NULL;
                if(current == list)
                    current = head;
                delete list;
                break;
            }
            if (list == tail)
            {
                tail = tail->prev;
                if(tail)
                    tail->next = NULL;
                if(current == list)
                    current = tail;
                
                delete list;
                break;
            }
            list->prev->next = list->next;
            list->next->prev = list->prev;
            current = list->prev;
            
            delete list;
            break;
        }
        list = list->next;
    }
}

void countRaice (node &head, node pos, int &nun, int &count)
{
    int prove;
    cout << endl << "--ПОИСК КОЛ-ВО ПРОЙДЕННЫХ МАРШРУТОВ ЗА ОПРЕДЕЛЁННЫЙ ДЕНЬ--" << endl << endl;
    cout << "Введите дату: ";
    cin >> prove;
    cout << endl << "--РЕЗУЛЬТАТ--" << endl << endl;
    for (auto* pos = head; pos; pos = pos->next)
    {
        if (prove == pos->day1)
        {
            cout << "Номер автобуса: " << pos->num << endl;
            if (pos->time1 != nun)
                count++;
            if (pos->time2 != nun)
                count++;
            cout << "Всего за день пройдено маршрутов: " << count << endl << endl;
            count = 0;
        }
        
        else if (prove == pos->day2)
        {
            cout << "Номер автобуса: " << pos->num << endl;
            if (pos->time3 != nun)
                count++;
            if (pos->time4 != nun)
                count++;
            cout << "Всего за день пройдено маршрутов: " << count << endl << endl;
            count = 0;
        }
    }
    cout << endl;
}

void outputAllBus (node &head, node pos)
{
    cout << endl << "--ВЫВОД РАСПИСАНИЯ АВТОБУСОВ--" << endl << endl;
    for (auto* pos = head; pos; pos = pos->next)
    {
        cout << "Номер автобуса: " << pos->num << endl;
        cout << "Первая дата отправки автобуса: " << pos->day1 << endl;
        cout << "Время первой отправки: " << pos->time1 << endl;
        cout << "Время второй отправки: " << pos->time2 << endl;
        cout << "Вторая дата отправки автобуса: " << pos->day2 << endl;
        cout << "Время третьей отправки: " << pos->time3 << endl;
        cout << "Время четвёртой отправки: " << pos->time4 << endl;
        cout << "Стоимость: " << pos->price << endl;
        cout << endl;
    }
}

void outputAllBus2 (node &tail, node pos)
{
    cout << endl << "--ВЫВОД РАСПИСАНИЯ АВТОБУСОВ--" << endl << endl;
    pos = tail;
    while (pos->next != NULL)
        pos = pos->next;
    
    do
    {
        cout << "Номер автобуса: " << pos->num << endl;
        cout << "Первая дата отправки автобуса: " << pos->day1 << endl;
        cout << "Время первой отправки: " << pos->time1 << endl;
        cout << "Время второй отправки: " << pos->time2 << endl;
        cout << "Вторая дата отправки автобуса: " << pos->day2 << endl;
        cout << "Время третьей отправки: " << pos->time3 << endl;
        cout << "Время четвёртой отправки: " << pos->time4 << endl;
        cout << "Стоимость: " << pos->price << endl;
        pos = pos->prev;
        cout << endl;
    }
    while (pos != NULL);
}

void variation (node &head, node &tail, node pos, node &list, node &current, int &vvod, int &nun, int &count)
{
    int var;
    cout << "0 - Выход" << endl << "1 - Начать работу" << endl;
    cin >> var;
    if (var > 1 || var < 0)
    {
        cout << endl << "Такой функции нет!" << endl;
        exit(1);
    }
    cout << endl;

    while (var != 0)
    {
        cout << "0 - Выход" << endl
        << "1 - Создать расписание в конце списка" << endl
        << "2 - Удалить выбранный автобус" << endl
        << "3 - Нахождение кол-во пройденных маршрутов за определённый день" << endl
        << "4 - Вывод всех расписаний автобусов" << endl
        << "5 - Вывод всех расписаний автобусов в обратном порядке" << endl;
        cin >> var;
        if (var == 1)
            addBusAfter(head, tail, pos, createBus());
        
        if (var == 2)
        {
            cout << endl << "--УДАЛЕНИЕ АВТОБУСА ИЗ СПИСКА--" << endl << endl;
            cout << "Введите номер автобуса, который нужно удалить: ";
            cin >> vvod;
            delBus(list, head, tail, current, vvod);
            outputAllBus(head, pos);
            cout << endl;
        }
        if (var == 3)
            countRaice(head, pos, nun, count);
        
        if (var == 4)
        {
            outputAllBus(head, pos);
            cout << endl;
        }
        if (var == 5)
        {
            outputAllBus2(tail, pos);
            cout << endl;
        }
    }
}

int main() {
    setlocale(0, "");
    node head = NULL;
    node tail = NULL;
    node pos = NULL;
    node list = NULL;
    node current = NULL;
    int vvod;
    int count = 0;
    int nun = 00;
    
    variation(head, tail, pos, list, current, vvod, nun, count);
    
    return 0;
}






№1:
#include <iostream>
#include <unordered_set>

using namespace std;

struct Node {
    int data;
    Node* next;
};

void insert(Node*& head, int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = head;
    head = newNode;
}

Node* createList(int arr[], int n) {
    Node* head = NULL;
    for (int i = n - 1; i >= 0; i--) {
        insert(head, arr[i]);
    }
    return head;
}

Node* unionLists(Node* L1, Node* L2) {
    unordered_set<int> set;
    Node* L = NULL;

    // Add elements of L1 to L
    while (L1 != NULL) {
        int val = L1->data;
        if (set.find(val) == set.end()) {
            insert(L, val);
            set.insert(val);
        }
        L1 = L1->next;
    }

    // Add elements of L2 to L
    while (L2 != NULL) {
        int val = L2->data;
        if (set.find(val) == set.end()) {
            insert(L, val);
            set.insert(val);
        }
        L2 = L2->next;
    }

    return L;
}

void printList(Node* head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    int arr1[] = { 1, 2, 3, 4, 5 };
    int arr2[] = { 4, 5, 6, 7 };
    Node* L1 = createList(arr1, 5);
    Node* L2 = createList(arr2, 4);
    Node* L = unionLists(L1, L2);
    printList(L);
    return 0;
}
Объяснение: 

The insert()Функция вставляет новый узел в начало списка.   createList()Функция создает список из массива целых чисел.   unionLists()функция создает новый список Lпутем перебора списков L1и L2и добавление элементов в Lкоторых еще нет в наборе set.   printList()функция печатает элементы списка. 

в main()функция, мы создаем два списка L1и L2из массивов, а затем вызвать unionLists()функция для создания нового списка Lкоторый содержит объединение элементов в L1и L2.  Наконец, мы печатаем элементы Lиспользуя printList()функция. 

