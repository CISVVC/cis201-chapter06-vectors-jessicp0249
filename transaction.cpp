#include "transaction.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

Transaction::Transaction()
{
    m_day = 0;
    set_amount(0.0);
}

void Transaction::set_amount(double amount)
{
    m_amount = amount;
}

void set_description(string description)
{
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

// Print Transaction object fields
void Transaction::print() const
{
    cout << "Day" << m_day << "  $" << m_amount << " " << m_description << endl;
}
