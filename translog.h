#ifndef TRANSLOG_H
#define TRANSLOG_H

#include <string>
#include <vector>

using namespace std;

class Trans_log
{
    public:
        Trans_log();
        void add_entry(Transaction t);    // add Transaction object to vector "m_entries"
        vector<double> daily_balances();    // adds up total balance for each day, returns data in a vector
        double get_total_for_day(int day);      // Add up money deposited or withdrawn for given day
        int max_day();      // get maximum number of days

        void print_transactions_for_day(int day);
        void print_daily_report();
        
        double average(vector<double> balances);   // Calculate average balance in vector
        double minimum(vector<double> balances);   // Calculate smallest balance in vector
        double interest(double balance);    // Calculate interest from given balance


    private:
        vector<Transaction> m_entries;
};

#endif
