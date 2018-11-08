#include "transaction.h"
#include "trans_log.h"
#include <iostream>
#include <string>
#include <vector>
#include <cassert>

using namespace std;

Trans_log::Trans_log()
{
    m_minbal = 0.0;
    m_avbal = 0.0;
}

void Trans_log::fill()
{
    vector<Transaction> entries;
    bool more = true;
    while(more)
        {
            Transaction t;
            t.read();
            entries.push_back(t);
            cout<< "enter more?";
            char response;
            if(tolower(response) != 'y')
                more = false;
        }
    m_entries = entries;
}

double Trans_log::balance(int day)
{
    assert( day < m_entries.size());
    double balance = m_entries[0].get_amount();

    for(int i = 1; i <= day; i++)
    {
        balance += m_entries[i].get_amount();
    }
    return balance;
}

double Trans_log::sum()
{
    double sum = 0.0;
    for(int i = 0; i < m_entries.size(); i++)
        sum += m_entries[i].get_amount();
    return sum;
}

double Trans_log:: average()
{
    return sum()/m_entries.size();
}

double Trans_log::minimum()
{
    double minimum = balance(0);
    for(int i = 1; i < m_entries.size(); i++)
    {
        if(balance(i) < minimum)
            minimum = balance(i);
    }
    return minimum;
}

double Trans_log::interest(double balance)
{
    double rate = 0.05;
    int period = 30;
    double earned = 0.0;
    

    return earned;
    
}
