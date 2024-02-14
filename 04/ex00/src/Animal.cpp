#include "../incl/Animal.hpp"

Animal::Animal()
{
    std::cout << "Default Animal constructor called" << std::endl;
    this->_type = "Animal";
}

Animal::Animal(const Animal& copy)
{
    std::cout << "Animal copy constructor called" << std::endl;
    *this = copy;
}

Animal::~Animal()
{
    std::cout << "Animal destructor called" << std::endl;
}

Animal& Animal::operator=(const Animal& copy)
{
    if (this != &copy)
    {
        this->_type = copy._type;
    }
    return (*this);
}

std::string Animal::getType() const
{
    return (this->_type);
}

void Animal::makeSound ()const
{
    std::cout << "I'm an animal" << std::endl;
}