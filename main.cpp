#include <iostream>
#include "Data.h"
#include <string>
using namespace std;

int main()
{
    Data d("abc.txt");
    d.read_data();
    d.learn();
    d.predict();
    return 0;
}
