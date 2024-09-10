// source file for the median function
#include <algorithm> // to get the declaration of sort
#include <stdexcept> // to get the declaration of domain_error
#include <vector> // to get the declaration of vector
using std::domain_error; using std::sort; using std::vector;
// compute the median of a vector<double>
// note that calling this function copies the entire argument vector
double median(vector<double> vec){
    vector<double>::size_type size = vec.size();
    if (size == 0)
        throw domain_error("median of an empty vector");
    sort(vec.begin(), vec.end());
    if(size%2==0) return (vec[size/2-1]+vec[size/2])/2;
    else return vec[size/2];
}