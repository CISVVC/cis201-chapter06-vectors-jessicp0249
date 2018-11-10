#include "transaction.h"
#include "translog.h"

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
#if 0
    Trans_log log;  // Create log - contains empty  vector<Transaction>, min balance, average balance
    log.fill();     // Fill vector with Transaction objects
    cout << log.print();

    // find and print deposits
    cout << "Deposits:" << endl;
    for(int i=0; i < log.get_entries().size(); i++)
    {
        if(log.get_entries[i].get_amount() > 0)
                log.get_entries[i].print();
    }
    
    // find and print withdrawals
    cout << "Withdrawals:" << endl;
    for(int i=0; i < log.get_entries().size(); i++)
    {
        if(log.get_entries[i].get_amount() < 0)
                log.get_entries[i].print();
    }


#endif

    return 0;
}
