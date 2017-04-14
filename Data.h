#ifndef DATA_H
#define DATA_H
#include <string>

using namespace std;

class Data
{
    public:
        Data(string file);
        void read_data();
        void learn();
        void predict();
        void print_data();

    protected:

    private:
        float y[10];
        float x1[10];
        float x2[10];
        float x3[10];
        float x0[10]={1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0};
        string file_name;
        float thetas[4]={1,1,1,1};
};

#endif // DATA_H
