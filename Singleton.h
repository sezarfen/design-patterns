#ifndef SINGLETON_H
#define SINGLETON_H

#include <iostream>

class Singleton{
public:
    // To reach single instance of that object
    static Singleton *GetInstance( void ){
        if (staticInstance == nullptr){
            staticInstance = new Singleton();
        }
        return staticInstance;
    }

    // one of the operations that class has, can be reached through instance of an object
    void doSomething(){
        std::cout << "Basic operation called on Singleton class" << std::endl;
    }

private:
    // Private getter and setters to prevent initalizing the new keyword or
    // calling "delete Singleton::GetInstance()" private Destructor helps achieve that
    Singleton( void ) { std::cout << "First time initializing Singleton class" << std::endl; }
    ~Singleton( void ) { std::cout << "Desctructing the Singleton class" << std::endl; }

    // The instance that will be used through the program
    static Singleton *staticInstance;

    // we might also add mutex for thread safe operations
};

// To give initial value to that instance
Singleton *Singleton::staticInstance = nullptr;

#endif // SINGLETON_H
