#ifndef TRANSLOG_H
#define TRANSLOG_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Trans_log
{
    public:
        Trans_log();
        void fill();    // Fill vector "m_entries"
        vector<Transaction> get_entries() const;
        double balance(int day);    // Find balance on a given day
        double sum();   // Add together all amounts
        double average();   // Calculate average balance in vector
        double minimum();   // Calculate smallest balance in vector
        double interest(double balance);    // Calculate interest from given balance
        void print() const;

    private:
        vector<Transaction> m_entries;
        double m_minbal;
        double m_avbal;
};

#endif
