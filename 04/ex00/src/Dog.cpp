#include "../incl/Dog.hpp"

Dog::Dog(void): Animal()
{
    this->_type = "Dog";
    std::cout << "Default Dog constructor called" << std::endl;
}

Dog::Dog(const Dog& copy): Animal(copy)
{
    std::cout << "Dog copy constructor called" << std::endl;
    *this = copy;
}

Dog::~Dog(void)
{
    std::cout << "Dog destructor called" << std::endl;
}

Dog& Dog::operator=(const Dog& copy)
{
    std::cout << "Dog assignation operator called" << std::endl;
    if (this != &copy)
        this->_type = copy._type;
    return (*this);
}

void Dog::makeSound() const
{
    std::cout << "Bark" << std::endl;
}

