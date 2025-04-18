#include <random>

//flips a biased coin a provided number of times, with the probability of
//heads determined by h_prob. The final number of heads should closely match
//flips * h_prob
inline int flip_coin(int flips, int h_prob)
{
    int result; //the result of a flip
    int num_heads{0};   //the running tally of heads obtained

    //flip the coin flips times
    for(int i = 0; i < flips; i++)
    {
        result = rand() % 100 + 1;

        //if the result falls within the range considered to be heads,
        //increment num_heads
        if(result < h_prob)
            num_heads++;
    }

    return num_heads;   //return the number of heads obtained
}
