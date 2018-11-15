#include "transaction.h"
#include "translog.h"

#include <iostream>
#include <string>
#include <vector>

using namespace std;

void fill_log(Trans_log log)
{
   log.add_entry(Transaction(1, 1154.00, "Initial balance"));
}

int main()
{
    Trans_log log;
    fill_log(log);

    log.print_daily_report();

   return 0;
}
