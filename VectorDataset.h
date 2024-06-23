#include"datavector.h"
class VectorDataset{
    std::vector<DataVector> datv;
    public:
    VectorDataset();
    ~VectorDataset();
    void AddDataVector(const DataVector&);
    void const ShowVectorDataset();
    friend VectorDataset knearestneighbor(VectorDataset&,DataVector&,const int&);
};