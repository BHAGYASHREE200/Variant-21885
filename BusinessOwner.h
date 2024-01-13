#ifndef BUSINESSOWNER_H
#define BUSINESSOWNER_H

#include<iostream>
#include"BusinessType.h"

class BusinessOwner
{
private:
float _expense;
float _revenue;
std::string _registeredBusinessName;
BusinessType _type;


public:

BusinessOwner(float expense, float revenue, std::string name, BusinessType type);

BusinessOwner()=default;
~BusinessOwner()=default;

BusinessOwner(const BusinessOwner&)=delete;
BusinessOwner(BusinessOwner&&)=delete;

BusinessOwner &operator=(const BusinessOwner&)=delete;
BusinessOwner &operator=(BusinessOwner&&)=delete;

float expense() const { return _expense; }

float revenue() const { return _revenue; }

std::string registeredBusinessName() const { return _registeredBusinessName; }

BusinessType type() const { return _type; }

friend std::ostream &operator<<(std::ostream &os, const BusinessOwner &rhs);

};

#endif // BUSINESSOWNER_H
