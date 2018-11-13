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
    

    // find and print deposits
    cout << "Deposits:" << endl;
    for(int i=0; i < log.get_entries().size(); i++)
    {
        if(log.get_entries[i].get_amount() > 0)
                log.get_entries[i].print();
        cout << "Balance: $" << log.balance(i) << endl;
    }
    
    // find and print withdrawals
    cout << "Withdrawals:" << endl;
    for(int i=0; i < log.get_entries().size(); i++)
    {
        if(log.get_entries[i].get_amount() < 0)
                log.get_entries[i].print();
        cout << "Balance: $" << log.balance(i) << endl;
    }
    
    // Print interest earned
    cout << "Interest earned (minimum): $" << log.get_minbal() << endl;
    cout << "Interest earned (average): $" << log.get_avbal() << endl;

#endif

    return 0;
}
