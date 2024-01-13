#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

#include<iostream>
#include<memory>
#include "DataModeller.h"
#include<vector>
#include"Employee.h"
#include "BusinessOwner.h"

using dataPointer = std::unique_ptr<DataModeller>; //(datavariant)
using Container = std::vector<dataPointer>;


void CreateObjects(Container& data);

void CalculateTaxPayable(const Container& data);

/*

*/
void CallParenOperator(const Container& data);


#endif // FUNCTIONALITIES_H
