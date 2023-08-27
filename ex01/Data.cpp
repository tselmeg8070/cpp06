#include "Data.hpp"

Data::Data() : _time(0)
{}

Data::Data(int time) : _time(time)
{}

Data::Data(Data &t) : _time(t.getTime())
{}

Data::~Data()
{}

Data & Data::operator=(const Data &t) {
	if (this != &t)
		this->_time = t.getTime();
	return (*this);
}

int		Data::getTime() const
{
	return (_time);
}

void	Data::setTime(int time)
{
	_time = time;
}
