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

void Transaction::read()
{
    cin >> m_day;
    cin >> m_amount;
    cin.ignore();
    getline(cin, m_description);
}

int Transaction::get_day()
{
    return m_day;
}

double Transaction::get_amount()
{
    return m_amount;
}

// Print Transaction object fields
void Transaction::print() const
{
    cout << "Day" << m_day << "  " << m_amount << "  " << m_description << endl;
}


/**
class Trans_log
{
    public:
        double average();
        double minimum();
        double interest();

    private:
        vector<Transaction> m_entries;
        double m_balance;
};
*/
