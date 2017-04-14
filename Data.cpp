#include "Data.h"
#include <string>
#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

Data::Data(string file)
{
    file_name=file;
}

void Data::read_data()
{
    try{
        cout<<file_name<<endl;
        ifstream f(file_name.c_str());
        if (f.is_open()==false)
            throw 1;
        for(int i=0;i<10;i++)
        {
            f>>y[i]>>x1[i]>>x2[i]>>x3[i];
        }
        print_data();

    }catch(int a)
    {
        cout<<"file not found, error code: "<<a<<endl;
    }

}

void Data::print_data()
{
    cout<<" the file "<< file_name<<"contains:"<<endl;
    cout<<"y    "<<"x1  "<<"x2  "<<"x3"<<endl;

    for(int i=0;i<10;i++){
        cout<<y[i]<<"     "<<x1[i]<<"   "<<x2[i]<<"   "<<x3[i]<<endl;
    }
}

void Data::learn()
{
    float alfa=0;//=.00045
    cout<<"enter thetas"<<endl;
    cin>>thetas[0]>>thetas[1]>>thetas[2]>>thetas[3];
    cout<<"enter learning rate"<<endl;
    cin>>alfa;
    double cost=0;
    int flag=0;
    cout<<thetas[0]<<"     "<<thetas[1]<<"    "<<thetas[2]<<"    "<<thetas[3]<<endl;
    for(int i=0;i<10;i++){
        cout<<y[i]<<"     "<<x1[i]<<"   "<<x2[i]<<"   "<<x3[i]<<endl;
    }
    do{

        double h[10];
        for(int i=0;i<10;i++){
            h[i]=(thetas[0]*x0[i])+(thetas[1]*x1[i])+(thetas[2]*x2[i])+(thetas[3]*x3[i]);
            cout<<h[i]<<endl;
            cost=cost+pow(y[i]-h[i],2);
            //cout<<cost<<endl;
        }
        cout<<"current cost is"<<cost<<endl;
        for(int i=0;i<10;i++){
                    thetas[0]=thetas[0]-(alfa*(h[i]-y[i])*x0[i]);
                    thetas[1]=thetas[1]-(alfa*(h[i]-y[i])*x1[i]);
                    thetas[2]=thetas[2]-(alfa*(h[i]-y[i])*x2[i]);
                    thetas[3]=thetas[3]-(alfa*(h[i]-y[i])*x3[i]);
        }
        if(cost<7)
            flag=1;
        cost=0;
        //cout<<"the current parameters are"<<endl;
        //cout<<thetas[0]<<"     "<<thetas[1]<<"    "<<thetas[2]<<"    "<<thetas[3]<<endl;
        //while(true){}
    }while(flag==0);
    cout<<"the parameters are"<<endl;
    cout<<thetas[0]<<"     "<<thetas[1]<<"    "<<thetas[2]<<"    "<<thetas[3]<<endl;
}

void Data::predict()
{
    float x0=1,x1,x2,x3;
    cout<<"enter xs"<<endl;
    cin>>x1>>x2>>x3;
    cout<<"the predicted value is"<<endl;
    cout<<thetas[0]*x0+thetas[1]*x1+thetas[2]*x2+thetas[3]*x3;
}

