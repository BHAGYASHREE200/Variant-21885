#include "Functionalities.h"
#include "DataModeller.h"
#include <vector>

void CreateObjects(Container &data)
{
    data.emplace_back(
        std::make_unique<DataModeller>(

            // instance
            std::make_unique<Employee>(
                "Bhagyashree",
                EmployeeType::REGULAR,
                780000.0f),

            // vector of floats
            std::vector<float>{19.21f, 145.31f, 204.5f}));

    data.emplace_back(
        std::make_unique<DataModeller>(

            std::make_unique<BusinessOwner>(
                1000000.0f,
                2000000.0f,
                "XYZ Corporation",
                BusinessType::MNC),

            std::vector<float>{19.21f, 145.31f, 204.5f}));
}

/*
    This function will accept a Container of DataModeller pointer
    For EACH POINTER, perform the following
    a. capture the instance reference
    b. Use holds_alternative to verify which type of pointer is present in the _instance
    c. if pointer is of type BusinessOwner
        i. use std::get to fetch BusinessOwnerPointer (THis will be safe because if has been
        checked)
        ii.use the fetched pointer in BUsinessOwner to calculate tax for business

        else when pointer is of type Employee
        i. use std::get to fetch Emppointer
        ii. use the fetched pointer to fetch type of employee
        iii. if type is REGULAR tax is 10% else it should be 20% of salary
        */

void CalculateTaxPayable(const Container &data)
{
    for (const dataPointer &ptr : data)
    {
        const Vtype &val = ptr->instance();

        // if variant has businesspointer condition is true
        if (std::holds_alternative<BusinessPointer>(val))
        {
            const BusinessPointer &p = std::get<BusinessPointer>(val);
            std::cout << 0.1f * (p->revenue() - p->expense());
        }
        else
        {
            const EmpPointer &p = std::get<EmpPointer>(val);
            if (p->type() == EmployeeType::REGULAR)
            {
                std::cout << "Tax is 10%: " << 0.01f * p->salary() << "\n";
            }
            else
            {
                    
                  std::cout << "Tax is 20%: " << 0.02f * p->salary() << "\n";   
            }
           
        }
    }
}

void CallParenOperator(const Container &data)
{
    if(data.empty())
    {
        throw std::runtime_error("Data is Empty");
    }
    else
    {
        for( const dataPointer& ptr : data)
        {
            ptr->operator()();
        }
    }
}
