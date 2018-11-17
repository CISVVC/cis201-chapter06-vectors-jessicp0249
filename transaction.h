/* File: Transaction.h
Description: Header file for Transaction class. Transaction objects will
    contain data about deposits or withdrawals from an account, including
    the day the transaction occurred, the amount deposited or withdrawn,
    and a string description.
Author: Jessica Priester
Email: jessicp0249@student.vvc.edu
Date created: 11/16/2018 (completed)
*/

#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <string>

using namespace std;

class Transaction
{
public:
   Transaction(int day, double amount, string description);     // constructor
   int get_day() const;     // m_day accessor
   double get_amount() const;   // m_amount accessor
   void print() const;      // prints data

private:
   int m_day;   // the day transaction occurred
   double m_amount;     // how much was deposited or withdrawn
   string m_description;    // describes transaction
};

#endif
