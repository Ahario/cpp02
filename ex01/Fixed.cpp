#include "Fixed.hpp"


const int	Fixed::NumberofFractionalBits = 8;
Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	this->FixedPointNumber = 0;
}

Fixed::Fixed(Fixed const & a)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = a;
}

Fixed& Fixed::operator=(Fixed const& a)
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
	return (this->FixedPointNumber);
}

void Fixed::setRawBits(int const raw)
{
	this->FixedPointNumber = raw;
}

Fixed::Fixed(const int i)
{
	std::cout << "Int constructor called" << std::endl;
	setRawBits(i << this->NumberofFractionalBits);
}

Fixed::Fixed(const float f)
{
	std::cout << "Float constructor called" << std::endl;
	this->setRawBits((int)roundf(f * (1 << this->NumberofFractionalBits)));
}

float Fixed::toFloat() const
{
	float	f;

	f = (float)this->getRawBits() / (1 << this->NumberofFractionalBits);
	return (f);
}

int Fixed::toInt() const
{
	return (this->getRawBits() >> this->NumberofFractionalBits);
}

std::ostream& operator<<(std::ostream& ofile, Fixed const& fxd)
{
	ofile << fxd.toFloat();
	return (ofile);
}
