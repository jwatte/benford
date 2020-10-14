Illustrate Benford's law: In random / naturally occurring distributions,
numbers that start with "1" are more common than other numbers (following
a downsloping scale to "9.")

Idea: generate a bunch of random distributions, and then draw random
numbers from those distributions. Those distributions are more likely
to include numbers starting with "1", because drawing a top of "1999"
is as likely as drawing a top of "9999" but of course the former has
many more numbers starting with "1."

result:
=======

    /tmp/benford$ make
    g++ -g -Wall -o benford -O1 benford.cpp
    ./benford
    [0] =        0
    [1] =   246070
    [2] =   171387
    [3] =   137249
    [4] =   112211
    [5] =    96732
    [6] =    81642
    [7] =    65368
    [8] =    53049
    [9] =    36292

jwatte 20201013
