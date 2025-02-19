# Design Patterns

This Repository is design give brief information about most known design patterns, if we would like the mention some of them
we can categorize them under this 3 category:
**Creational Patterns**: Singleton, Factory Method, Abstract Factory
**Structural Patterns**: Adapter, Decorator, Facade, Composite
**Behavioral Patterns**: Observer, Strategy, Command

*Lets have a look each of them in more detail.*

## Singleton Design Pattern

The Singleton Method Design Pattern ensures a class has only one instance and provides a global access point to it. It's ideal for scenarios requiring centralized control, like managing database connections or configuration settings.

`The Singleton method or Singleton Design pattern is one of the simplest design patterns. It ensures a class only has one instance, and provides a global point of access to it. `

#### Singleton Design Pattern Principles

**Single Instance:** Singleton ensures that only one instance of the class exists throughout the application.

**Global Access:** Provide a global point of access to that instance.

**Lazy or Eager Initialization:** Support creating the instance either when needed (lazy) or when the class is loaded (eager).

**Thread Safety:** Implement mechanisms to prevent multiple threads from creating separate instances simultaneously.

**Private Constructor:** Restrict direct instantiation by making the constructor private, forcing the use of the access point.

Let's assume you want to make database connection and executing query on single database, it is not a good practice to generate new instance of a class and do the connections again and again for every single operation, but applying singleton method like the example below.

**C++**
```cpp
  DatabaseConnection::GetInstance()->executeQuery();
```
**Java**
```java
  DatabaseConnection.GetInstance().executeQuery();
```
in each example, it is important that, we didn't generate direct instances ourselves, using it's static attributes obtain
instance of a class without using **new** keyword in both languages.

Reference for Singleton : https://www.geeksforgeeks.org/singleton-design-pattern/

## Factory Method Design Pattern
