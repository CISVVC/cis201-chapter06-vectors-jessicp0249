#include "transaction.h"
#include "translog.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

Trans_log::Trans_log()
{
}

void Trans_log::add_entry(Transaction t)
{
    m_entries.push_back(t);    
}

vector<double> Trans_log::daily_balances()
{
    vector<double> balances;
    int total = 0;

    for(int day=0; day<max_day(); day++)
    {
        total += get_total_for_day(day+1);
        balances.push_back(total);
    }
    return balances;
}

double Trans_log::get_total_for_day(int day)
{
    double total = 0;

    for(int i=0; i<m_entries.size(); i++)
    {
        if(m_entries[i].get_day() == day)
            total += m_entries[i].get_amount();
    }
    return total;
}

int Trans_log::max_day()
{
    int max = 0;

    for(int i=0; i<m_entries.size(); i++)
    {
        if(max < m_entries[i].get_day())
            max = m_entries[i].get_day();
    }
    return max;
}

double Trans_log::average(vector<double> balances)
{
    double total = balances[0];
    for(int i=1; i<balances.size(); i++)
        total += balances[i];

    return static_cast<double>(total/balances.size());
}

double Trans_log::minimum(vector<double> balances)
{
    double minimum = balances[0];
    for(int i=1; i<balances.size(); i++)
    {
        if(minimum > balances[i])
            minimum = balances[i];
    }
    return minimum;
}

double Trans_log::interest(double balance)
{
    double rate = 0.05;
    return balance*rate;
}

void Trans_log::print_transactions_for_day(int day)
{
    for(int i=0; i < m_entries.size(); i++)
    {
        if(m_entries[i].get_day() == day)
            m_entries[i].print();
    }
}

void Trans_log::print_daily_report()
{
    vector<double> balances = daily_balances();

    for(int day=0; day < max_day(); day++)
    {
        print_transactions_for_day(day+1);
        cout << "Day " << day+1 << " balance:" << "\t" << balances[day] << endl;
    }

    cout << "Average daily balance:" << average(balances) << endl;
    cout << "\t Interest:" << interest(average(balances)) << endl;
    cout << "Final balance with average interest: \t" << interest(average(balances)) + balances[balances.size() -1] << endl;
 
    cout << "Minimum daily balance:" << minimum(balances) << endl;
    cout << "\t Interest:" << interest(minimum(balances)) << endl;
    cout << "Final balance with minimum interest: \t" << interest(minimum(balances)) + balances[balances.size() -1] << endl;
}

