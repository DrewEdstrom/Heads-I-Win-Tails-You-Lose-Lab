#include <iostream>
#include <iomanip>
#include <fstream>
#include "BiasedCoinFlip.h"

using namespace std;

void perform_trials(int flips, int trials, int h_prob, ostream &ostr);

int main()
{
     //output to csv for data analysis
    ofstream output{"biasedCoinFlipResults.csv"};

    srand(static_cast<int>(time(0)));
    perform_trials(100, 10, 45, output);    //100 flips, 10 trials, 45% chance of heads
    perform_trials(100, 10, 55, output);    //100 flips, 10 trials, 55% chance of heads
    perform_trials(100, 10, 65, output);    //100 flips, 10 trials, 65% chance of heads
    perform_trials(1000, 10, 45, output);   //1000 flips, 10 trials, 45% chance of heads
    perform_trials(1000, 10, 55, output);   //1000 flips, 10 trials, 55% chance of heads
    perform_trials(1000, 10, 65, output);   //1000 flips, 10 trials, 65% chance of heads
    perform_trials(10000, 10, 45, output);  //10000 flips, 10 trials, 45% chance of heads
    perform_trials(10000, 10, 55, output);  //10000 flips, 10 trials, 55% chance of heads
    perform_trials(10000, 10, 65, output);  //10000 flips, 10 trials, 75% chance of heads
    perform_trials(100000, 10, 45, output); //100000 flips, 10 trials, 45% chance of heads
    perform_trials(100000, 10, 55, output); //100000 flips, 10 trials, 55% chance of heads
    perform_trials(100000, 10, 65, output); //100000 flips, 10 trials, 65% chance of heads
    perform_trials(1000000, 10, 45, output);//1000000 flips, 10 trials, 45% chance of heads
    perform_trials(1000000, 10, 55, output);//1000000 flips, 10 trials, 55% chance of heads
    perform_trials(1000000, 10, 65, output);//1000000 flips, 10 trials, 65% chance of heads


    return 0;
}

//performs a set of trials for a set of coin flips
void perform_trials(int flips, int trials, int h_prob, ostream &ostr)
{
    cout << "\n\n"
            << "# of Flips | Trial # | Probability of Heads (p) | # of Heads\n"
            << "-----------+---------+--------------------------+-----------";

    ostr << "# of Flips, Trial #, Probability of Heads (p), # of Heads\n";
    
    for(int i = 0; i < trials; i++)
    {
        int num_heads{flip_coin(flips, h_prob)};

        //output to nicely formatted table for console
        cout << "\n" << setw(11) << left << flips      //# of flips
                << "| " << setw(8) << left << i+1      //trial #
                << "| " << setw(25) << left << h_prob  //probability of heads
                << "| " << num_heads;                  //# of heads

        //also write to csv file for importing data into excel
        ostr << flips << ',' << i+1 << ',' << h_prob << ',' << num_heads << "\n";
    }

    //space out the different sets of coin flip trials in csv file
    ostr << "\n\n";
}
