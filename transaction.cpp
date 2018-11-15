#include "transaction.h"
#include <iostream>
#include <string>

using namespace std;

Transaction::Transaction(int day, double amount, string description)
{
    m_day = day;
    m_amount = amount;
    m_description = description;
}

int Transaction::get_day() const
{
    return m_day;
}

double Transaction::get_amount() const
{
    return m_amount;
}

void Transaction::print() const
{
    cout << "Day" << m_day << "\t" << m_amount << "\t" << m_description << endl;
}
