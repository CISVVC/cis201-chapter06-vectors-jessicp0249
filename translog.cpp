/* File: Translog.cpp
Description: Implementation for member functions of the Trans_log class.
Author: Jessica Priester
Email: jessicp0249@student.vvc.edu
Date created: 11/16/2018 (completed)
*/


#include "transaction.h"
#include "translog.h"
#include <iostream>
#include <iomanip>
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
    double total = 0;

    for(int day=0; (day+1) <= max_day(); day++)
    {
        total += get_total_for_day(day+1);      // Day = vector position; day+1 = m_day value
        balances.push_back(total);      // Add total to balances vector

    }

    return balances;
}

double Trans_log::get_total_for_day(int day)
{
    double total = 0;

    for(int i=0; i<m_entries.size(); i++)
    {
        // Add amount to total if m_day at i position matches the given day
        if(m_entries[i].get_day() == day)
            total = total + m_entries[i].get_amount();
    }
    
    return total;
}

int Trans_log::max_day()
{
    int max = 0;    // maximum day value in m_entries vector


    for(int i=0; i<m_entries.size(); i++)
    {
        // if m_day value at i position is bigger than max, update max with it
        if(max < m_entries[i].get_day())
            max = m_entries[i].get_day();
    }

    return max;
}

double Trans_log::average_balance(const vector<double>& balances)
{
    // add all balances together, divide by number of values
    double total = balances[0];

    for(int i=1; i<balances.size(); i++)
        total += balances[i];

    return (static_cast<double>(total/balances.size()) );
}

double Trans_log::minimum(const vector<double>& balances)
{
    double minimum = balances[0];

    // if value at i position is smaller than minimum, update minimum with it
    for(int i=1; i<balances.size(); i++)
    {
        if(minimum > balances[i])
            minimum = balances[i];
    }

    return minimum;
}

double Trans_log::interest(double balance, int periods)
{
    double rate = 0.5;  // percent per month
    rate = rate/100.0;  // convert rate from percentage

    return balance*rate*periods;
}

void Trans_log::print_transactions_for_day(int day)
{
    // If m_day at i position matches given day, print entry at i
    for(int i=0; i < m_entries.size(); i++)
    {
        if(m_entries[i].get_day() == day)
            m_entries[i].print();
    }
}

void Trans_log::print_daily_report()
{
    const int INT_PERIOD = 30;  // Number of days before account earns interest
    // create vector of daily dalances
    vector<double> balances = daily_balances();

    // print tranasactions and balance for each day
    for(int day=0; day < max_day(); day++)
    {
        print_transactions_for_day(day+1);
        if(balances[day] != balances[day-1])   // skip if balance is the same as previous day
            cout << "Day" << day+1 << " balance:" << "\t" << balances[day] << endl << endl;
    }

    // Add interest every time INT_PERIOD passes
    if(balances.size() >= INT_PERIOD)
        print_interest(balances.size()/INT_PERIOD, balances);
}

void Trans_log::print_interest(int periods, const vector<double>& balances)
{ 
    double bal = average_balance(balances);
    double interest_accrued = interest(bal, periods);    // calculate interest earned from given amount
    double end_balance = balances[balances.size()-1];

    cout << "Average daily balance: " << bal << endl;
    cout << "Interest earned: \t" << setprecision(2) << fixed << interest_accrued << endl;   // print interest with 2 decimal places
    cout << "Final balance with interest: \t" << interest_accrued + end_balance << endl << endl;    // print balance with added interest

    bal = minimum(balances);
    interest_accrued = interest(bal, periods);    // calculate interest earned from given amount

    cout << "Minimum daily balance: " << bal << endl;
    cout << "Interest earned: \t" << setprecision(2) << fixed << interest_accrued << endl;   // print interest with 2 decimal places
    cout << "Final balance with interest: \t" << interest_accrued + end_balance << endl << endl;    // print balance with added interest
}

