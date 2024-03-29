#include "../incl/FragTrap.hpp"

FragTrap::FragTrap(void): ClapTrap()
{
    std::cout << "FragTrap: default constructor called" << std::endl;
    this->_hitPoints = 100; 
    this->_energyPoints = 100;
    this->_attackDamage = 30;
}

FragTrap::FragTrap(std::string name): ClapTrap(name)
{
    std::cout << "FragTrap: constructor called" << std::endl;

    this->_hitPoints = 100;
    this->_energyPoints = 100;
    this->_attackDamage = 30;
}

FragTrap::FragTrap(const FragTrap& copy): ClapTrap(copy)
{
    std::cout << "FragTrap: copy constructor called" << std::endl;
    *this = copy;
}

FragTrap::~FragTrap(void)
{
    std::cout << "FragTrap: destructor called" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& copy)
{
    std::cout << "FragTrap: assignment operator overload" << std::endl;
    
    if (this != &copy)
    {
        this->_name = copy._name;
        this->_hitPoints = copy._hitPoints;
        this->_energyPoints = copy._energyPoints;
        this->_attackDamage = copy._attackDamage;
    }
    return (*this);
}

void FragTrap::highFivesGuys(void)
{
    std::cout << "FragTrap " << this->_name << " requests a high five" << std::endl;
}