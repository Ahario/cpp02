#include "Fixed.hpp"


const int	Fixed::NumberofFractionalBits = 8;
Fixed::Fixed()
{
	this->FixedPointNumber = 0;
}

Fixed::Fixed(Fixed const & a)
{
	*this = a;
}

Fixed& Fixed::operator=(Fixed const& a)
{
	this->FixedPointNumber = a.FixedPointNumber;
	return (*this);
}

Fixed::~Fixed()
{
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
	setRawBits(i << this->NumberofFractionalBits);
}

Fixed::Fixed(const float f)
{
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

int Fixed::operator>(Fixed const& a) const
{
	if (this->getRawBits() > a.getRawBits())
		return (1);
	return (0);
}

int Fixed::operator<(Fixed const& a) const
{
	if (this->getRawBits() < a.getRawBits())
		return (1);
	return (0);
}

int Fixed::operator>=(Fixed const& a) const
{
	if (this->getRawBits() >= a.getRawBits())
		return (1);
	return (0);
}

int Fixed::operator<=(Fixed const& a) const
{
	if (this->getRawBits() <= a.getRawBits())
		return (1);
	return (0);
}

int Fixed::operator==(Fixed const& a) const
{
	if (this->getRawBits() == a.getRawBits())
		return (1);
	return (0);
}

int Fixed::operator!=(Fixed const& a) const
{
	if (this->getRawBits() != a.getRawBits())
		return (1);
	return (0);
}

Fixed Fixed::operator+(Fixed const& a)
{
	Fixed b(this->toFloat() + a.toFloat());
	return (b);	
}

Fixed Fixed::operator-(Fixed const& a)
{
	Fixed b(this->toFloat() - a.toFloat());
	return (b);
}

Fixed Fixed::operator*(Fixed const& a)
{
	Fixed b(this->toFloat() * a.toFloat());
	return (b);
}

Fixed Fixed::operator/(Fixed const& a)
{
	Fixed b(this->toFloat() / a.toFloat());
	return (b);
}

Fixed& Fixed::operator++(void)
{
	this->FixedPointNumber += 1;
	return (*this);
}

Fixed& Fixed::operator--(void)
{
	this->FixedPointNumber -= 1;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed a = *this;

	this->FixedPointNumber += 1;
	return (a);
}

Fixed Fixed::operator--(int)
{
	Fixed a = *this;

	this->FixedPointNumber -= 1;
	return (a);
}
 
const Fixed& Fixed::min(const Fixed & a, const Fixed & b)
{
	if (a < b)
		return (a);
	return (b);
}
	
const Fixed& Fixed::max(const Fixed & a, const Fixed & b)
{
	if (a > b)
		return (a);
	return (b);
}

Fixed& Fixed::min(Fixed & a, Fixed & b)
{
	if (a < b)
		return (a);
	return (b);
}
	
Fixed& Fixed::max(Fixed & a, Fixed & b)
{
	if (a > b)
		return (a);
	return (b);
}