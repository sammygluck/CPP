#include "../incl/ClapTrap.hpp"

// CANONICAL FORM
ClapTrap::ClapTrap(void) : _name("Default"), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
    std::cout << "ClapTrap Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
    std::cout << "ClapTrap Name constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &copy)
{
    std::cout << "ClapTrap Copy constructor called" << std::endl;
    *this = copy;
}

ClapTrap::~ClapTrap(void)
{
    std::cout << "ClapTrap Destructor called" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap &copy)
{
    std::cout << "ClapTrap Assignation operator called" << std::endl;
    if (this != &copy)
    {
        this->_name = copy._name;
        this->_hitPoints = copy._hitPoints;
        this->_energyPoints = copy._energyPoints;
        this->_attackDamage = copy._attackDamage;
    }
    return (*this);
}

// MEMBER FUNCTIONS

void ClapTrap::attack(const std::string &target)
{
    if (this->_hitPoints == 0)
    {
        std::cout << "ClapTrap " << this->_name << " is dead and cannot attack" << std::endl;
        return ;
    }
    else if  (this->_energyPoints == 0)
    {
        std::cout << "ClapTrap " << this->_name << " is out of energy and cannot attack" << std::endl;
        return ;
    }
    this->_energyPoints -= 1;
    std::cout << "ClapTrap " << this->_name << " attacks " << target << " causing " << this->_attackDamage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (this->_hitPoints == 0)
    {
        std::cout << "ClapTrap " << this->_name << " is already dead" << std::endl;
        return ;
    }
    unsigned int allowedDamage = amount;
    if (this->_hitPoints < amount)
        allowedDamage = this->_hitPoints;
    std::cout << "ClapTrap " << this->_name << " takes " << allowedDamage << " points of damage!" << std::endl;
    this->_hitPoints -= allowedDamage;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (this->_hitPoints == 0)
    {
        std::cout << "ClapTrap " << this->_name << " is dead and cannot be repaired" << std::endl;
        return ;
    }
    else if (this->_energyPoints == 0)
    {
        std::cout << "ClapTrap " << this->_name << " is out of energy and cannot be repaired" << std::endl;
        return ;
    }
    std::cout << "ClapTrap " << this->_name << " is repaired for " << amount << " hitpoints!" << std::endl;
    this->_hitPoints += amount;
    this->_energyPoints -= 1;
}

