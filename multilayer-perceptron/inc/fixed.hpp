#pragma once

# include <iostream>
# include <cmath>

class fixed {

private:

	int 				i;
	static const int	fraction = 8;

public:

	fixed();
	fixed(const int fxd);
	fixed(const float fxd);
	fixed(fixed const & fxd);
    fixed(std::string const & str);
	~fixed();

	fixed &	operator=(fixed const & rhs);

	int		getRawBits( void ) const;
	void	setRawBits( int const raw);

	int		toInt( void ) const;
	float	toFloat( void ) const;

	int		power(int val, int pow) const;

	bool operator>(fixed const & rhs) const;
	bool operator<(fixed const & rhs) const;
	bool operator<=(fixed const & rhs) const;
	bool operator>=(fixed const & rhs) const;
	bool operator==(fixed const & rhs) const;
	bool operator!=(fixed const & rhs) const;

	fixed operator+(fixed const & rhs) const;
	fixed operator-(fixed const & rhs) const;
	fixed operator*(fixed const & rhs) const;
	fixed operator/(fixed const & rhs) const;

	fixed	& operator++(void);
	fixed operator++(int);

	fixed & operator--(void);
	fixed operator--(int);

	static fixed min(fixed &nb1, fixed &nb2);
	static fixed min(fixed const &nb1, fixed const &nb2);

	static fixed max(fixed &nb1, fixed &nb2);
	static fixed max(fixed const &nb1, fixed const &nb2);
};

std::ostream &	operator<<( std::ostream & os, fixed const & oui);
