#include "transaction.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

Transaction::Transaction()
{
    m_day = 0;
    m_amount = 0.0;
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
