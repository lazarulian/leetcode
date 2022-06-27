#include <iostream>
#include <cassert>
#include <string>

using namespace std;


int main()
{
    // Attendees (Change to Change Calculations)
    const double n_children = 5;
    const double n_adults = 10;

    // Calculations
    // Ticket Sales
    double childrens_trev = n_children*6;
    double adults_trev = n_adults*20;

    // Concession Sales

    double childrens_crev = n_children*17;
    double adults_crev = n_children*13;

    // Percentages:
    double adult_tpercent = (adults_trev/(adults_trev+childrens_trev))*100;
    double chidlren_tpercent = (childrens_trev/(adults_trev+childrens_trev))*100;
    double chidlren_cpercent = (childrens_crev / (childrens_crev+adults_crev))*100;
    double adult_cpercent = (adults_crev/(childrens_crev+adults_crev))*100;
    
    // Text Output
    cout << "Analysis of Sales: " << endl;
    cout << "=============================" << endl;
    cout << "The percent of ticket sales that came from adults is: " << adult_tpercent << "%" << endl;
    cout << "The percent of ticket sales that came from children is: " << chidlren_tpercent << "%" <<endl;
    cout << "The percent of concession sales that came from adults is: " << adult_cpercent << "%" <<endl;
    cout << "The percent of concession sales that came from children is: " << chidlren_cpercent << "%" <<endl;

    return 0;
}