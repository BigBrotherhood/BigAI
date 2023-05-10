#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>


class Fixed {
	private:
		int i;
		static const int fraction = 8;

	public:
		Fixed( void );
		Fixed( const int what );
		Fixed( const float floot);
		Fixed ( Fixed const & cpy );
		~Fixed( void );
		Fixed	&	operator=(Fixed const & rhs);
		int	getRawBits( void ) const;
		void	setRawBits( int const raw);
		int	toInt( void ) const;
		float	toFloat( void ) const;
		int	power(int val, int pow) const;


		bool operator>(Fixed const & rhs) const;
		bool operator<(Fixed const & rhs) const;
		bool operator<=(Fixed const & rhs) const;
		bool operator>=(Fixed const & rhs) const;
		bool operator==(Fixed const & rhs) const;
		bool operator!=(Fixed const & rhs) const;

		Fixed operator+(Fixed const & rhs) const;
		Fixed operator-(Fixed const & rhs) const;
		Fixed operator*(Fixed const & rhs) const;
		Fixed operator/(Fixed const & rhs) const;

		Fixed	& operator++(void);
		Fixed operator++(int);

		Fixed & operator--(void);
		Fixed operator--(int);

		static Fixed min(Fixed &nb1, Fixed &nb2);
		static Fixed min(Fixed const &nb1, Fixed const &nb2);

		static Fixed max(Fixed &nb1, Fixed &nb2);
		static Fixed max(Fixed const &nb1, Fixed const &nb2);


};

std::ostream &	operator<<( std::ostream & os, Fixed const & oui);

#endif