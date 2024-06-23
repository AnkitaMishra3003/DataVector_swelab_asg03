#include<vector>
class DataVector {
    std::vector<double> v;
    public:
    DataVector(int dimension=0);
    DataVector(std::vector<double>);
    ~DataVector();
    DataVector(const DataVector&);
    DataVector & operator=(const DataVector &);
    void setDimension(int dimension=0);
    void showDataVector();
    int givesize();
    DataVector operator+(const DataVector &);
    DataVector operator-(const DataVector &);
    double const operator*(const DataVector &);
    double const norm();
    double const dist(const DataVector &);
};