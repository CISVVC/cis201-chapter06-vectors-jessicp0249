#ifndef TRANS_LOG_H
#define TRANS_LOG_H

#include "transaction.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Trans_log
{
    public:
        Trans_log();
        void fill();
        double balance(int day);
        double sum();
        double average();
        double minimum();
        double interest(double balance);

    private:
        vector<Transaction> m_entries;
        double m_minbal;
        double m_avbal;
};

#endif
