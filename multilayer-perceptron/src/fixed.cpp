#include "../inc/fixed.hpp"

fixed::fixed( void ) : i(0)
{
	// std::cout << "Default Constructor called" << std::endl;
}

fixed::~fixed(void) {

	// std::cout << "Deconstructor called\n";
}

int	fixed::getRawBits( void ) const
{
	// std::cout << "getRawBits member funtion called" << std::endl;
	return(this->i);
}

fixed::fixed( int const what )
{
	this->i = what << this->fraction;
	// std::cout << "Int constructor called\n";
}

fixed::fixed( fixed const & cpy ) {
	*this = cpy;
	// std::cout << "Copy constructor called\n";
}

fixed	&	fixed::operator=(fixed const & rhs) {

	if (this != &rhs) {
		this->i = rhs.getRawBits(); }
	// std::cout << "Copy assignment called" << std::endl;
	return *this;
}

fixed::fixed(float const floot)
{
	int pow = power(2, this->fraction);
	this->i = roundf(floot * pow);
}

float	fixed::toFloat(void) const {

	int		pow = power(2, this->fraction);
	float	ret = (float)this->i / pow;
	return (ret);
}

int	fixed::toInt(void) const {

	return i >> fraction;
}

std::ostream &	operator<<( std::ostream & os, fixed const & oui) {
	
	os << oui.toFloat() << "\n"; 
	return os;
}

int	fixed::power(int val, int pow) const {

	int	ret = 1;
    for (int i = 0; i < pow; i++)
		ret *= val;
	return ret;
}

bool fixed::operator>(fixed const & rhs) const {

	if (this->getRawBits() > rhs.getRawBits())
		return true;
	return false;
}

bool fixed::operator<(fixed const & rhs) const {

	if (this->getRawBits() < rhs.getRawBits())
		return true;
	return false;
}

bool fixed::operator<=(fixed const & rhs) const {

	if (this->getRawBits() <= rhs.getRawBits())
		return true;
	return false;
}

bool fixed::operator>=(fixed const & rhs) const {

	if (this->getRawBits() >= rhs.getRawBits())
		return true;
	return false;
}

bool fixed::operator==(fixed const & rhs) const {

	if (this->getRawBits() == rhs.getRawBits())
		return true;
	return false;
}

bool fixed::operator!=(fixed const & rhs) const {

	if (this->getRawBits() != rhs.getRawBits())
		return true;
	return false;
}

fixed fixed::operator+(fixed const & rhs) const {

	return (this->toFloat() + rhs.toFloat());
}

fixed fixed::operator-(fixed const & rhs) const {

	return (this->toFloat() - rhs.toFloat());
}

fixed fixed::operator*(fixed const & rhs) const {

	fixed oui;

	oui = this->toFloat() * rhs.toFloat();
	return oui;
}

fixed fixed::operator/(fixed const & rhs) const {

	return (this->toFloat() / rhs.toFloat());
}

fixed & fixed::operator++(void) {

	this->i++;
	return *this;
}

fixed fixed::operator++(int) {

	fixed wow(*this);
	this->i++;
	return wow;
}

fixed & fixed::operator--(void) {

	this->i--;
	return *this;
}

fixed fixed::operator--(int) {

	fixed wow(*this);
	this->i--;
	return wow;
}

fixed fixed::min(fixed &nb1, fixed &nb2) {

	return (nb1.i < nb2.i ? nb1 : nb2);
}

fixed fixed::min(fixed const &nb1, fixed const &nb2) {

	return (nb1.i < nb2.i ? nb1 : nb2);
}

fixed fixed::max(fixed &nb1, fixed &nb2) {

	return (nb1.i > nb2.i ? nb1 : nb2);
}

fixed fixed::max(fixed const &nb1, fixed const &nb2) {

	return (nb1.i > nb2.i ? nb1 : nb2);
}

