#ifndef DATAMODELLER_H
#define DATAMODELLER_H

#include <memory>
#include "Employee.h"
#include "BusinessOwner.h"
#include <variant>
#include <vector>

using BusinessPointer = std::unique_ptr<BusinessOwner>;
using EmpPointer = std::unique_ptr<Employee>;
using Vtype = std::variant<BusinessPointer, EmpPointer>;

class DataModeller
{
private:
    Vtype _instance;
    std::vector<float> _goodsprices;

public:
    DataModeller() = default;

    DataModeller(Vtype v, const std::vector<float>& prices);
    void operator()();

    DataModeller(const DataModeller &) = delete;
    DataModeller(DataModeller &&) = delete;

    DataModeller operator=(const DataModeller &) = delete;
    DataModeller operator=(DataModeller &&) = delete;

    ~DataModeller() = default;

     const Vtype& instance() const { return _instance; } //return type ref and add const

    std::vector<float> goodsprices() const { return _goodsprices; }

    
};

#endif // DATAMODELLER_H
