#ifndef ABSTRACTFACTORY_H
#define ABSTRACTFACTORY_H

/*
 * The Abstract Factory Pattern is one of the generational design patterns
 * that provides an interface for generating families
 * of related or dependentobjects without specifying
 * their concrete classes and implementation,
 * in simpler terms the Abstract Factory Pattern is a way of organizing
 * how you generate groups of things that are related to each other.
 */

/*
 * Example:
 *
    We'll have two styles of pizza: "New York" and "Chicago," each with its own set of pizza types.

    Step 1: We'll define an abstract factory interface (PizzaFactory) with methods for generating different
    types of pizzas for different styles.

    Step 2: We'll create two concrete factories (NewYorkPizzaFactory and ChicagoPizzaFactory)
    implementing this interface and generate corresponding New York and Chicago style pizzas.

    Step 3: We'll create an abstract product interface (Pizza) that defines the methods
    that concrete pizzas must implement.
    Concrete pizza classes(NewYorkCheesePizza, NewYorkPepperoniPizza, ChicagoCheesePizza, ChicagoPepperoniPizza)
    implement the abstract Pizza interface for each style.
    The client code will generate and prepare pizzas using
    the abstract factories and interact with them without needing to know the specific pizza styles or implementations.

*/

#include <iostream>

// Abstract Product Interface
class Pizza {
public:
    virtual void bake() = 0;
    virtual void cut() = 0;
    virtual void box() = 0;

    virtual ~Pizza( void ){

    }
};

// Concrete New York Cheese Pizza
class NewYorkCheesePizza : public Pizza {
public:
    void bake() override
    {
        std::cout << "Baking New York-style cheese pizza."
                  << std::endl;
    }

    void cut() override
    {
        std::cout << "Cutting New York-style cheese pizza."
                  << std::endl;
    }

    void box() override
    {
        std::cout << "Boxing New York-style cheese pizza."
                  << std::endl;
    }
};

// Concrete New York Pepperoni Pizza
class NewYorkPepperoniPizza : public Pizza {
public:
    void bake() override
    {
        std::cout
            << "Baking New York-style pepperoni pizza."
            << std::endl;
    }

    void cut() override
    {
        std::cout
            << "Cutting New York-style pepperoni pizza."
            << std::endl;
    }

    void box() override
    {
        std::cout
            << "Boxing New York-style pepperoni pizza."
            << std::endl;
    }
};

// Concrete Chicago Cheese Pizza
class ChicagoCheesePizza : public Pizza {
public:
    void bake() override
    {
        std::cout << "Baking Chicago-style cheese pizza."
                  << std::endl;
    }

    void cut() override
    {
        std::cout << "Cutting Chicago-style cheese pizza."
                  << std::endl;
    }

    void box() override
    {
        std::cout << "Boxing Chicago-style cheese pizza."
                  << std::endl;
    }
};

// Concrete Chicago Pepperoni Pizza
class ChicagoPepperoniPizza : public Pizza {
public:
    void bake() override
    {
        std::cout << "Baking Chicago-style pepperoni pizza."
                  << std::endl;
    }

    void cut() override
    {
        std::cout
            << "Cutting Chicago-style pepperoni pizza."
            << std::endl;
    }

    void box() override
    {
        std::cout << "Boxing Chicago-style pepperoni pizza."
                  << std::endl;
    }
};

// Abstract Factory Interface
class PizzaFactory{
public:
    virtual Pizza* generateCheesePizza() = 0;
    virtual Pizza* generatePepperoniPizza() = 0;
};

// Concrete New York Pizza Factory
class NewYorkPizzaFactory : public PizzaFactory{
public:
    Pizza * generateCheesePizza() override{
        return new NewYorkCheesePizza();
    }

    Pizza * generatePepperoniPizza() override{
        return new NewYorkPepperoniPizza();
    }
};

// Concrete Chicago Pizza Factory
class ChicagoPizzaFactory : public PizzaFactory {
public:
    Pizza* generateCheesePizza() override
    {
        return new ChicagoCheesePizza();
    }

    Pizza* generatePepperoniPizza() override
    {
        return new ChicagoPepperoniPizza();
    }
};


#endif // ABSTRACTFACTORY_H
