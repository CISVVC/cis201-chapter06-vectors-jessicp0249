#include "transaction.h"
#include "translog.h"

#include <iostream>
#include <string>
#include <vector>

using namespace std;

void fill_log(Trans_log &log)
{
   log.add_entry(Transaction(1, 1154.0, "Initial balance"));
   log.add_entry(Transaction(1, -240.56, "Check"));
   log.add_entry(Transaction(1, 15.05, "Deposit"));
   log.add_entry(Transaction(2, 60.0, "Deposit"));
   log.add_entry(Transaction(4, -10.0, "Check"));
   log.add_entry(Transaction(4, -32.98, "Check"));
   log.add_entry(Transaction(5, 200.0, "Deposit"));
   log.add_entry(Transaction(5, -20.04, "Check"));
   log.add_entry(Transaction(5, 15.0, "Deposit"));

   log.add_entry(Transaction(23, 15.05, "Deposit"));
   log.add_entry(Transaction(28, 60.0, "Deposit"));
   log.add_entry(Transaction(29, -10.0, "Check"));
   log.add_entry(Transaction(35, -240.56, "Check"));
}

int main()
{
    Trans_log log;
    fill_log(log);
    log.print_daily_report();

   return 0;
}
