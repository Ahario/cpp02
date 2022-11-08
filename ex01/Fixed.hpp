#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <string.h>
#include <cmath>

class Fixed{
	public:
		Fixed();
		Fixed(Fixed const& a);
		Fixed &operator=(Fixed const& a);
		~Fixed();
		int getRawBits(void) const;
		void setRawBits(int const raw);

		Fixed(const int i);
		Fixed(const float f);
		float toFloat(void) const;
		int toInt(void) const;
	private:
		int FixedPointNumber;
		const static int NumberofFractionalBits;
};
std::ostream& operator<<(std::ostream& ofile, Fixed const& fxd);

#endif