#include<iostream>
#include<algorithm>
#include <fstream>
#include<sstream>
#include <sys/time.h>
#include <iomanip>
#include<queue>
// #include<bits/stdc++.h>
#include"VectorDataset.h"
using namespace std;
vector<double> getNextLineAndSplitIntoTokens(const string& line)
{
    vector<double> result; double d;
    stringstream lineStream(line);
    string cell;
    while(std::getline(lineStream,cell, ','))
    {
        d=stod(cell);
        result.push_back(d);
    }
    return result;
}
void ReadVectorDataSet(VectorDataset& vecdat)
{
    ifstream file; vector<double> v;
    file.open("fmnist-train.csv",ios::in);
    string line;
    while (getline(file, line)) {
        v=getNextLineAndSplitIntoTokens(line);
        DataVector vec(v);
        vecdat.AddDataVector(vec);
    } 
    file.close();
}
VectorDataset knearestneighbor(VectorDataset& vd, DataVector& d,const int& k)
{
    VectorDataset near;
    priority_queue<pair<double,int>> pq; int i=0;
    for(DataVector dat: vd.datv)
    pq.push({-d.dist(dat),i++});
    for(int j=0;j<k;j++) {near.AddDataVector(vd.datv[(pq.top()).second]); pq.pop();}
    return near;
}
int main()
{
    VectorDataset vecdat; int k=5;
    ReadVectorDataSet(vecdat);
    clock_t start, end;
    ifstream file; vector<double> v;
    file.open("fmnist-test.csv",ios::in);
    string line; int i=100;
    start = clock();
    while (i--) {
        cout<<100-i<<"> "<<"\n";
        getline(file, line);
        v=getNextLineAndSplitIntoTokens(line);
        DataVector vec(v);
        VectorDataset knearest=knearestneighbor(vecdat,vec,k);
        knearest.ShowVectorDataset();
    } 
    file.close();
    end = clock();
    double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
    cout << "Average Time taken by program is : " << fixed 
         << time_taken/100.0 << setprecision(5);
    cout << " sec " << endl;
}