#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <string>
#include <vector>

using namespace std;

class Transaction
{
public:
   Transaction(int day, double amount, string description);     // constructor
   int get_day() const;     // m_day accessor
   double get_amount() const;   // m_amount accessor
   void print() const;      // prints data

private:
   int m_day;
   double m_amount;
   string m_description;
};

#endif
