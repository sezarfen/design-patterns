#ifndef DECORATOR_H
#define DECORATOR_H

/*
    The Decorator Pattern is a structural design pattern in software engineering
    that enables the dynamic addition of new behaviors or responsibilities to
    individual objects without altering their underlying class structure.
    It achieves this by generating a set of decorator classes
    that are used to wrap concrete components, which represent the core functionality.

    The Decorator Pattern is commonly used in scenarios where a variety of optional
    features or behaviors need to be added to objects in a flexible and reusable manner,
    such as in text formatting, graphical user interfaces, or customization of products like coffee or ice cream.
*/

#include <iostream>
using namespace std;

// Component interface - defines the basic ice cream operations.
class IceCream {
public:
    virtual string getDescription() const = 0;
    virtual double cost() const = 0;
};

// Concrete Component - the basic ice cream class.
class VanillaIceCream : public IceCream {
public:
    string getDescription() const override
    {
        return "Vanilla Ice Cream";
    }

    double cost() const override { return 160.0; }
};

// Decorator - abstract class that extends IceCream.
class IceCreamDecorator : public IceCream {
protected:
    IceCream* iceCream;

public:
    IceCreamDecorator(IceCream* ic)
        : iceCream(ic)
    {
    }

    string getDescription() const override
    {
        return iceCream->getDescription();
    }

    double cost() const override
    {
        return iceCream->cost();
    }
};

// Concrete Decorator - adds chocolate topping.
class ChocolateDecorator : public IceCreamDecorator {
public:
    ChocolateDecorator(IceCream* ic)
        : IceCreamDecorator(ic)
    {
    }

    string getDescription() const override
    {
        return iceCream->getDescription()
               + " with Chocolate";
    }

    double cost() const override
    {
        return iceCream->cost() + 100.0;
    }
};

// Concrete Decorator - adds caramel topping.
class CaramelDecorator : public IceCreamDecorator {
public:
    CaramelDecorator(IceCream* ic)
        : IceCreamDecorator(ic)
    {
    }

    string getDescription() const override
    {
        return iceCream->getDescription() + " with Caramel";
    }

    double cost() const override
    {
        return iceCream->cost() + 150.0;
    }
};



#endif // DECORATOR_H
