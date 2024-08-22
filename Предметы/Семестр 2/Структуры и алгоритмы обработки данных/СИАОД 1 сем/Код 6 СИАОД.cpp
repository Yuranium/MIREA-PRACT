//Алгоритм Кнута-Морриса-Пратта:
#include <iostream>
#include <string>
#include <vector>
using namespace std;
vector<int> PrefixFunc(const string& word) 
{
    int m = word.length();
    vector<int> pi(m);
    pi[0] = 0;
    int k = 0;
    for (int q = 1; q < m; ++q)
    {
        while (k > 0 && word[k] != word[q])
            k = pi[k - 1];
        if (word[k] == word[q])
            ++k;
        pi[q] = k;
    }
    return pi;
}
void KMP(const string& text, const string& word) 
{
    int n = text.length();
    int m = word.length();
    vector<int> pi = PrefixFunc(word);
    int q = 0;
    for (int i = 0; i < n; ++i) 
    {
        while (q > 0 && word[q] != text[i])
            q = pi[q - 1];
        if (word[q] == text[i])
            ++q;
        if (q == m) 
        {
            cout << "Cлово \"" << word << "\" найдено в тексте с индексом " << i - m + 1 << "\n";
            q = pi[q - 1];
        }
    }
}
int main() 
{
    setlocale(0, "");
    string word, text = "Despite the fact that not much time has passed since Prince Andrei left Russia, he has changed a lot during this time.";
    do
    {
        cout << "Введите слово для поиска: ";
        cin >> word;
        if (text.find(word) == -1)
            cout << "Такого слова нет в тексте!" << endl << endl;
    } while (text.find(word) == -1);
    KMP(text, word);
    return 0;
}

//Алгоритм прямого поиска:
#include <iostream>
#include <string>

using namespace std;

int search(string text, string pattern) {
    int n = text.size();
    int m = pattern.size();

    for (int i = 0; i <= n - m; i++) {
	int j;
        for (j = 0; j < m; j++) {
            if (text[i + j] != pattern[j]) {
                break;
            }
        }
        if (j == m) {
            return i;
        }
    }

    return -1;
}

int main() {
    setlocale(0, "");
    string text, pattern;
    text = "Having inspected the carriage and the packing of the suitcases himself, he ordered to lay it down. Only those things remained in the room that Prince Andrei always took with him: a casket, a large silver cellar, two Turkish pistols and a saber - a gift from his father, brought from near Ochakov.";
    cout << "Введите слово для поиска: ";
    getline(cin, pattern);
    int index = search(text, pattern);
    if (index == -1) {
        cout << "Слова нет в тексте." << endl;
    }
    else {
        cout << "Слово начинается с " << index << " индекса в тексте." << endl;
    }
    return 0;
}