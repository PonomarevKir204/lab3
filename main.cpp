#include <iostream>
#include <time.h>
#include <string>
#include <fstream>
#include <sstream>
#include "datetime.h"

using namespace std;

Datetime* Read_file_date(string file_name, int& n)
{
    ifstream file(file_name);
    string line;
    n = 0;
    while (getline(file, line))
    {
        n++;
    }
    Datetime* Date = new Datetime[n];
    int i = 0;
    file.clear();
    file.seekg(0, ios::beg);
    while (getline(file, line))
    {
        istringstream line_(line);
        line_ >> Date[i];
        i++;
    }
    file.close();
    return Date;
}

int Task()
{
    srand(time(0));
    Datetime date, next, prev;
    int n;
    Datetime* Date = Read_file_date("data.txt", n);
    Datetime* Prev = new Datetime[n];
    date.System_time(date); printf("\n\nSystem time: "); 
    cout << date;
    printf("\n\n\tData read from file:\n\n");
    for (int i = 0; i < n; i++)
    {
        Date[i].Get_next_date(next);
        Date[i].Get_prev_date(prev);
        printf("%i)\t", i + 1);
        cout << Date[i]; 
        printf("\t");
        cout << next;
        printf("\t");
        cout << prev;
        printf("\n");
        Prev[i] = prev;
    }
  
    delete[] Date;
    delete[] Prev;
    return 0;
}

int main()
{
    Task();

    system("pause");

    return 0;
}