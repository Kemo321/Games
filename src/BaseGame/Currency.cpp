#include "Currency.hpp"

void Currency::set_value(int newValue)
{
	_value = newValue;
}

int Currency::get_value() const
{
	return _value;
}

void Currency::add_value(int valueToAdd)
{
	_value += valueToAdd;
}

void Currency::update_value(std::function<int(int old_value)> func)
{
	_value = func(_value);
}
