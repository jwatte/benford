#include <stdio.h>
#include <stdlib.h>
#include <random>
#include <functional>


//  Illustrate Benford's law: In random / naturally occurring distributions,
//  numbers that start with "1" are more common than other numbers (following
//  a downsloping scale to "9.")
//
//  jwatte 20201013
int start[10];

int main() {
    time_t t;
    //  Idea: generate a bunch of random distributions, and then draw random
    //  numbers from those distributions. Those distributions are more likely
    //  to include numbers starting with "1", because drawing a top of "1999"
    //  is as likely as drawing a top of "9999" but of course the former has
    //  many more numbers starting with "1."
    std::mt19937_64 generator(time(&t));
    //  cover many orders of magnitude per distribution
    std::uniform_int_distribution<int> distribution(1, 9999999);
    auto disttop = std::bind(distribution, generator);
    char buf[20];
    //  3,000 distributions
    for (int i = 0; i != 1000; ++i) {
        //  4,000 samples per distribution
        std::uniform_int_distribution<int> thisdist(1, disttop()+1);
        auto sampler = std::bind(thisdist, generator);
        for (int j = 0; j != 1000; ++j) {
            sprintf(buf, "%d", sampler());
            start[buf[0]-'0']++;
        }
    }
    for (int i = 0; i != 10; ++i) {
        printf("[%d] = %8d\n", i, start[i]);
    }
    return 0;
}

