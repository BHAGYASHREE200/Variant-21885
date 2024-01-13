#include <iostream>
#include <thread>
#include "Functionalities.h"
#include "DataModeller.h"

int main()
{
    Container data;
    std::array<std::thread, 3> arr;
    arr[0] = std::thread(CreateObjects, std::ref(data));
    arr[0].join();

    arr[1] = std::thread(CalculateTaxPayable, std::ref(data));
    arr[2] = std::thread(CallParenOperator, std::ref(data));

    for (std::thread &th : arr)
    {
        if (th.joinable())
        {
            th.join();
        }
    }
}