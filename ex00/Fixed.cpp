#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	this->FixedPointNumber = 0;
}

Fixed::Fixed(Fixed& a)
{
	std::cout << "Copy constructor called" << std::endl;
	this->FixedPointNumber = a.getRawBits();
}

Fixed& Fixed::operator=(Fixed& a)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->FixedPointNumber = a.FixedPointNumber;
	return (*this);
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits() const
{
	std::cout << "getRawBits member function called" << std::endl;	
	return (this->FixedPointNumber);
}

void Fixed::setRawBits(int const raw)
{
	this->FixedPointNumber = raw;
}
