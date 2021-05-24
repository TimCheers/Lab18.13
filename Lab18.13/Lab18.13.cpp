#include <iostream>
#include <deque>
#include <algorithm>
#include <time.h>
#include "Money.h"
#include "container.h"
#include <set>
typedef deque<Money> DQ;
using namespace std;
Money s;
typedef set<Money> Tset;
typedef Tset::iterator it;
Money avg;
struct Search
{
    bool operator()(Money t) { return t == s; }
};
void doubleNumber(Money& i)
{
    i += avg;
}
int SafeInput(bool strict)
{
    int result;
    while (!(cin >> result) || (cin.peek() != '\n') || (strict && result <= 0)) {
        cin.clear();
        while (cin.get() != '\n');
        cout << "Введите корректное число!" << endl;
    }
    cin.get();
    return result;
}
int random(int a, int b)
{
    if (a > 0) return a + rand() % (b - a);
    else return a + rand() % (abs(a) + b);
}
DQ MakeDeque(const int size)
{
    deque<Money> list;
    for (int i = 0; i < size; i++)
    {
        Money tmp;
        list.push_back(tmp);
    }
    cout << endl;
    return list;
}
void ShowDeque(DQ list)
{
    for (int i = 0; i < list.size(); i++)
    {
        cout << list[i] << endl;
    }
}
void PushMax(DQ& list)
{
    Money max(0, 0);
    for (int i = 0; i < list.size(); i++)
    {
        if (list[i] > max)
        {
            max = list[i];
        }
    }
    list.push_back(max);
}
Money FindAVG(DQ& A)
{
    int  k = A.size();
    Money sum(0, 0);
    auto iter = A.begin();
    for (iter; iter != A.end(); iter++)
    {
        sum = sum + *iter;
    }
    return (sum / k);
}
void AVGPlus(Money& dat)
{
    dat = dat + s;
}

/// /////////////////////////////////////////////////////////////
Tset MakeSet(int size)
{
    Tset A;
    for (int i = 0; i < size; i++)
    {
        Money tmp;
        A.insert(tmp);
    }
    return A;
}
void ShowSet(Tset A)
{
    auto iter = A.begin();
    for (iter; iter != A.end(); iter++)
    {
        cout << *iter << "  ";
    }
}
Money FindAVG(Tset& A)
{
    int  k = A.size();
    Money sum(0, 0);
    auto iter = A.begin();
    for (iter; iter != A.end(); iter++)
    {
        sum = sum + *iter;
    }
    return (sum / k);
}
int main()
{
    system("chcp 1251>nul");
    srand(time(NULL));
    //cout << "Введите количество элементов: ";
    //int size = SafeInput(1);
    //DQ list;
    //list = MakeDeque(size);
    //cout << "------------------------------------------------------------------\n";
    //ShowDeque(list);
    //PushMax(list);
    //cout << "\n------------------------------------------------------------------\n";
    //ShowDeque(list);
    //////////////////////////////////////////////
    //cout << "Введите ключ для удаления: ";
    //cin >> s;
    //DQ::iterator i;
    //i = find_if(list.begin(), list.end(), Search());
    //if (i != list.end())
    //{
    //    DQ TMP;
    //    while (list.front() != s)
    //    {
    //        TMP.push_back(list.front());
    //        list.pop_front();
    //    }
    //    list.pop_front();
    //    while (list.size() > 0)
    //    {
    //        TMP.push_back(list.front());
    //        list.pop_front();
    //    }
    //    while (TMP.size() > 0)
    //    {
    //        list.push_back(TMP.front());
    //        TMP.pop_front();
    //    }
    //    ShowDeque(list);
    //}
    //else
    //{
    //    cout << "Ошибка удаления! Элемент отсутствует!" << endl;
    //}
    /////////////////////////////////////////////////////////////////////////
    //cout << "\n------------------------------------------------------------------\n";
    //s = FindAVG(list);
    //for_each(list.begin(), list.end(), AVGPlus);
    //ShowDeque(list);
    //cout << "\n------------------------------------------------------------------\n";
    //cout << "Введите количество элементов: ";
    //size = SafeInput(1);
    //container<Money> Vector(size);
    //cout << "-----------------------------------------------------------------\n";
    //Vector.show();
    //cout << "\n-----------------------------------------------------------------\n";
    //cout << "Введите ключ для удаления: ";
    //Money key;
    //cin >> key;
    //Vector.delKey(key);
    //Vector.show();
    //cout << "\n-----------------------------------------------------------------\n";





    ///////////////////////////////////////////////////////////////////////
    cout << "Введите количество элементов: ";
    int size = SafeInput(1);
    Tset A = MakeSet(size);
    cout << "-----------------------------------------------------------------\n";
    ShowSet(A);
    cout << "\n-----------------------------------------------------------------\n";
     avg = FindAVG(A);
    for_each(A.begin(), A.end(), doubleNumber);
    cout << "-----------------------------------------------------------------\n";
    ShowSet(A);
    cout << "\n-----------------------------------------------------------------\n";
    return 0;
}