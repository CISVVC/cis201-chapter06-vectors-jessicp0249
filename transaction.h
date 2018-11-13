#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Transaction
{
public:
   Transaction();
   void set_amount(double amount);
   void set_description(string description);
   int get_day() const;
   double get_amount() const;
   void print() const;

private:
   int m_day;
   double m_amount;
   string m_description;
};
#endif
