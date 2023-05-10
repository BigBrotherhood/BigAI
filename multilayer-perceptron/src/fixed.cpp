#include "Fixed.hpp"

Fixed::Fixed( void ) : i(0)
{
	// std::cout << "Default Constructor called" << std::endl;
}

Fixed::~Fixed(void) {

	// std::cout << "Deconstructor called\n";
}

int	Fixed::getRawBits( void ) const
{
	// std::cout << "getRawBits member funtion called" << std::endl;
	return(this->i);
}

Fixed::Fixed( int const what )
{
	this->i = what << this->fraction;
	// std::cout << "Int constructor called\n";
}

Fixed::Fixed( Fixed const & cpy ) {
	*this = cpy;
	// std::cout << "Copy constructor called\n";
}

Fixed	&	Fixed::operator=(Fixed const & rhs) {

	if (this != &rhs) {
		this->i = rhs.getRawBits(); }
	// std::cout << "Copy assignment called" << std::endl;
	return *this;
}

Fixed::Fixed(float const floot)
{
	int pow = power(2, this->fraction);
	this->i = roundf(floot * pow);
}

float	Fixed::toFloat(void) const {

	int		pow = power(2, this->fraction);
	float	ret = (float)this->i / pow;
	return (ret);
}

int	Fixed::toInt(void) const {

	return i >> fraction;
}

std::ostream &	operator<<( std::ostream & os, Fixed const & oui) {
	
	os << oui.toFloat() << "\n"; 
	return os;
}

int	Fixed::power(int val, int pow) const {

	int	ret = 1;
    for (int i = 0; i < pow; i++)
		ret *= val;
	return ret;
}

bool Fixed::operator>(Fixed const & rhs) const {

	if (this->getRawBits() > rhs.getRawBits())
		return true;
	return false;
}

bool Fixed::operator<(Fixed const & rhs) const {

	if (this->getRawBits() < rhs.getRawBits())
		return true;
	return false;
}

bool Fixed::operator<=(Fixed const & rhs) const {

	if (this->getRawBits() <= rhs.getRawBits())
		return true;
	return false;
}

bool Fixed::operator>=(Fixed const & rhs) const {

	if (this->getRawBits() >= rhs.getRawBits())
		return true;
	return false;
}

bool Fixed::operator==(Fixed const & rhs) const {

	if (this->getRawBits() == rhs.getRawBits())
		return true;
	return false;
}

bool Fixed::operator!=(Fixed const & rhs) const {

	if (this->getRawBits() != rhs.getRawBits())
		return true;
	return false;
}

Fixed Fixed::operator+(Fixed const & rhs) const {

	return (this->toFloat() + rhs.toFloat());
}

Fixed Fixed::operator-(Fixed const & rhs) const {

	return (this->toFloat() - rhs.toFloat());
}

Fixed Fixed::operator*(Fixed const & rhs) const {

	Fixed oui;

	oui = this->toFloat() * rhs.toFloat();
	return oui;
}

Fixed Fixed::operator/(Fixed const & rhs) const {

	return (this->toFloat() / rhs.toFloat());
}

Fixed & Fixed::operator++(void) {

	this->i++;
	return *this;
}

Fixed Fixed::operator++(int) {

	Fixed wow(*this);
	this->i++;
	return wow;
}

Fixed & Fixed::operator--(void) {

	this->i--;
	return *this;
}

Fixed Fixed::operator--(int) {

	Fixed wow(*this);
	this->i--;
	return wow;
}

Fixed Fixed::min(Fixed &nb1, Fixed &nb2) {

	return (nb1.i < nb2.i ? nb1 : nb2);
}

Fixed Fixed::min(Fixed const &nb1, Fixed const &nb2) {

	return (nb1.i < nb2.i ? nb1 : nb2);
}

Fixed Fixed::max(Fixed &nb1, Fixed &nb2) {

	return (nb1.i > nb2.i ? nb1 : nb2);
}

Fixed Fixed::max(Fixed const &nb1, Fixed const &nb2) {

	return (nb1.i > nb2.i ? nb1 : nb2);
}

