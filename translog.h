/* File: Translog.h
Description: Header file for the Trans_log class.
    Trans_log objects will contain a vector of Transaction objects
    and use them to calculate daily balances, calculate the average
    and minimum daily balance, calculate interest, and print a daily 
    report of all transactions.
Author: Jessica Priester
Email: jessicp0249@student.vvc.edu
Date created: 11/16/2018 (completed)
*/

#ifndef TRANSLOG_H
#define TRANSLOG_H

#include <string>
#include <vector>

using namespace std;

class Trans_log
{
    public:
        Trans_log();
        void add_entry(Transaction t);    // adds given Transaction object to vector m_entries
        
        // adds up total balance for each day in m_entries. Returns data in a vector.
        vector<double> daily_balances();            
        double get_total_for_day(int day);      // adds up money deposited/withdrawn on a given day
        int max_day();      // get maximum day number in m_entries
        double average_balance(const vector<double>& balances);   // Calculates average balance in given vector

        double minimum(const vector<double>& balances);   // Calculates smallest balance in given vector
        double interest(double balance, int periods);    // Calculates interest from given balance


        // Prints Transaction objects with the given day
        void print_transactions_for_day(int day);

        // Prints all Transactions, daily balances, and interest accrued.
        void print_daily_report();

        // Prints interest accrued after given number of periods. Prints latest balance with interest added.
        void print_interest(int periods, const vector<double>& balances);

    private:
        vector<Transaction> m_entries;    // collection of Transaction objects
};

#endif
