#include<iostream>
#include<vector>
#include<cmath>
#include"datavector.h"
using namespace std;
DataVector::DataVector (int dimension) : v(dimension,0.0){}
DataVector::DataVector(vector<double> vec) : v(vec){}
DataVector::~DataVector(){}
DataVector::DataVector(const DataVector& other) : v(other.v) {}
DataVector& DataVector::operator=(const DataVector &other)
{
    if(v!=other.v)
    {v=other.v;}
    return(*this);
}
void DataVector::setDimension(int dimension){v.clear(); v.resize(dimension,0.0);}
void DataVector::showDataVector()
{
    for(double value : v)
    {
        cout<<value<<" ";
    } 
    cout<<endl;
}
int DataVector::givesize()
{
    return(v.size());
}
DataVector DataVector::operator+(const DataVector &other)
{
    int n=v.size();
    if(other.v.size()!=n)
    {
        printf("Error. Dimension not same.\n");
        return *this;
    }
    DataVector res; res.v.resize(n);
    for(int i=0;i<n;i++)
    {
        res.v[i]=v[i]+other.v[i];
    }
    return res;
}
DataVector DataVector::operator-(const DataVector &other)
{
    int n=v.size();
    if(other.v.size()!=n)
    {
        printf("Error. Dimension not same.\n");
        return *this;
    }
    DataVector res; res.v.resize(n);
    for(int i=0;i<n;i++)
    {
        res.v[i]=v[i]-other.v[i];
    }
    return res;
}
double const DataVector::operator*(const DataVector &other)
{
    int n=v.size();
    if(other.v.size()!=n)
    {
        printf("Error. Dimension not same.\n");
        return 0.0;
    }
    float res=0;
    for(int i=0;i<n;i++)
    {
        res+=v[i]*other.v[i];
    }
    return res;
}
double const DataVector::norm()
{
    float nor=sqrt((*this)*(*this));
    return(nor);
}
double const DataVector ::dist(const DataVector &other)
{
    float dista=(*this-other).norm();
    return dista;
}