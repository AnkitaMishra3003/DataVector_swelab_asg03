#include<iostream>
#include"VectorDataset.h"
using namespace std;
VectorDataset::VectorDataset(){}
VectorDataset::~VectorDataset(){}
void VectorDataset::AddDataVector(const DataVector& other) 
{
    datv.push_back(other);
}
void const VectorDataset::ShowVectorDataset()
{
    for (DataVector vec : datv)
    {
        vec.showDataVector();
    }
    cout<<endl;
}