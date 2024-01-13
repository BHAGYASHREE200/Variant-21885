#include "DataModeller.h"

DataModeller::DataModeller(Vtype v,const std::vector<float>& prices)
:_instance(std::move(v)), _goodsprices(prices)
{

}

void DataModeller::operator()()
{
    if(_goodsprices.empty())
    {
        throw std::runtime_error("\n Not Found");
    }

    float total =0.0f;
    for(float val : _goodsprices)
    {
        total += val;
    }

    std::cout<< "\n Average value is: " << total / _goodsprices.size() << "\n";

}
