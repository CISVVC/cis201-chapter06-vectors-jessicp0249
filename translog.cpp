#include "transaction.h"
#include "translog.h"
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
#if 0
    vector<Transaction> entries();
    for(int i=0; i<10; i++)
    {
        entries.push_back(i++, static_cast<double>(rand()*1.0), "description");
        if(entries[i].get_amount() > 0) entries[i].set_description("ATM deposit");
        else if(entries[i].get_amount() < 0)
        {
            entries[i].set_description("Check");
            if(abs(entries[i].get_amount() ) > entries.get_bal())
                entries[i].set_amount(entries[i].get_amount() + entries.get_bal());
        }
    }

#endif

}

vector<Transaction> Trans_log::get_entries() const
{
    return m_entries;
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
    m_avbal = sum()/m_entries.size();
    return m_avbal;
}

double Trans_log::minimum()
{
    double minimum = balance(0);
    for(int i = 1; i < m_entries.size(); i++)
    {
        if(balance(i) < minimum)
            minimum = balance(i);
    }
    m_minbal = minimum;
    return minimum;
}

double Trans_log::interest(double balance)
{
    double rate = 0.05;
    int period = 30;
    return static_cast<double>(balance * rate * period);
}

void Trans_log::print() const
{
    for(int i = 0; i < m_entries.size(); i++)
        m_entries[i].print();
}
