#include "Singleton.h"
#include "FactoryMethod.h"
#include "AbstractFactory.h"
#include "Adapter.h"
#include "Decorator.h"
#include "Facade.h"
#include "Composite.h"
#include "Observer.h"
#include "Strategy.h"
#include "Command.h"

int main(int argc, char *argv[])
{
    // START
    // Singleton Design Pattern
    std::cout << "***Singleton Design Pattern Example***" << std::endl;
    Singleton::GetInstance()->doSomething();
    Singleton::GetInstance()->doSomething();
    Singleton::GetInstance()->doSomething();
    // END



    // START
    // Factory Method Design Pattern
    std::cout << std::endl << "***Factory Method Design Pattern Example***" << std::endl;
    DatabaseFactory *mySqlFactory = new MySqlDatabaseFactory();
    DatabaseFactory *sqliteFactory = new SQLiteDatabaseFactory();

    DatabaseConnection *mySqlConnection = mySqlFactory->generateDatabaseConnection();
    DatabaseConnection *sqLiteConnection = sqliteFactory->generateDatabaseConnection();

    mySqlConnection->connectToDatabase();
    sqLiteConnection->connectToDatabase();

    delete mySqlFactory;
    delete sqliteFactory;
    delete mySqlConnection;
    delete sqLiteConnection;
    // END



    // START
    // Abstract Factory Method Design Pattern
    std::cout << std::endl << "***Factory Method Design Pattern Example***" << std::endl;

    // Pizza Factory -> New York Factory -> New York Cheese Pizza / New York Pepperoni Pizza
    // generate a New York Pizza Factory
    PizzaFactory* newYorkFactory = new NewYorkPizzaFactory();
    Pizza* newYorkCheesePizza = newYorkFactory->generateCheesePizza();
    Pizza* newYorkPepperoniPizza = newYorkFactory->generatePepperoniPizza();

    // Pizza Factory -> Chicago Factory -> Chicago Cheese Pizza / Chicaho Pepperoni Pizza
    // generate a Chicago Pizza Factory
    PizzaFactory* chicagoFactory = new ChicagoPizzaFactory();
    Pizza* chicagoCheesePizza = chicagoFactory->generateCheesePizza();
    Pizza* chicagoPepperoniPizza = chicagoFactory->generatePepperoniPizza();

    // Order and prepare the pizzas
    newYorkCheesePizza->bake();
    newYorkCheesePizza->cut();
    newYorkCheesePizza->box();

    newYorkPepperoniPizza->bake();
    newYorkPepperoniPizza->cut();
    newYorkPepperoniPizza->box();

    chicagoCheesePizza->bake();
    chicagoCheesePizza->cut();
    chicagoCheesePizza->box();

    chicagoPepperoniPizza->bake();
    chicagoPepperoniPizza->cut();
    chicagoPepperoniPizza->box();

    // Clean up
    delete newYorkFactory;
    delete newYorkCheesePizza;
    delete newYorkPepperoniPizza;
    delete chicagoFactory;
    delete chicagoCheesePizza;
    delete chicagoPepperoniPizza;
    // END



    // START
    // Adapter Design Pattern
    std::cout << std::endl << "***Adapter Design Pattern Example***" << std::endl;
    ModernComputer modernComputer;
    PrinterAdapter printerAdapter;

    modernComputer.sendCommand("Print this in lowercase");
    printerAdapter.sendCommand("Print this in lowercase (adapted)");
    // END



    // START
    // Decorator Design Pattern
    // Generate a vanilla ice cream
    IceCream* vanillaIceCream = new VanillaIceCream();
    cout << "Order: " << vanillaIceCream->getDescription()
         << ", Cost: Rs." << vanillaIceCream->cost()
         << endl;

    // Wrap it with ChocolateDecorator
    IceCream* chocolateIceCream = new ChocolateDecorator(vanillaIceCream);
    cout << "Order: " << chocolateIceCream->getDescription()
         << ", Cost: Rs." << chocolateIceCream->cost()
         << endl;

    // Wrap it with CaramelDecorator
    IceCream* caramelIceCream = new CaramelDecorator(chocolateIceCream);
    cout << "Order: " << caramelIceCream->getDescription()
         << ", Cost: Rs." << caramelIceCream->cost()
         << endl;

    delete vanillaIceCream;
    delete chocolateIceCream;
    delete caramelIceCream;
    // END



    // START
    // Facade Method Design Pattern
    std::cout << std::endl << "***Facade Method Design Pattern Example***" << std::endl;
    // Using the Facade to start and stop the car
    Car car;
    car.StartCar();
    // Simulate some driving
    car.StopCar();



    // START
    // Composite Design Pattern
    std::cout << std::endl << "***Composite Design Pattern Example***" << std::endl;
    Page elementA;
    Page elementB;
    Copy allcopy;
    allcopy.AddElement(elementA);
    allcopy.AddElement(elementB);

    allcopy.Add(elementA);
    elementA.Add(elementB);

    allcopy.Remove();
    elementB.Remove();
    // END



    // START
    // Observer Design Pattern
    std::cout << std::endl << "***Observer Design Pattern***" << std::endl;
    WeatherStation weatherStation;

    // Create displays
    Display display1;
    Display display2;

    // Register displays as observers
    weatherStation.registerObserver(&display1);
    weatherStation.registerObserver(&display2);

    // Simulate weather data updates
    weatherStation.setMeasurements(25.5, 60, 1013.2);
    weatherStation.setMeasurements(24.8, 58, 1014.5);
    // END



    // START
    // Strategy Method Design Pattern
    std::cout << std::endl << "***Strategy Method Design Pattern***" << std::endl;
    std::vector<int> data = {5, 2, 7, 1, 9};

    SortContext context;
    BubbleSort bubbleSort;
    QuickSort quickSort;

    context.setStrategy(&bubbleSort);
    context.executeStrategy(data); // Executes Bubble Sort

    context.setStrategy(&quickSort);
    context.executeStrategy(data); // Executes Quick Sort
    // END



    // START
    std::cout << std::endl << "***Command Design Pattern***" << std::endl;
    // Command Design Pattern
    // Generate a Receiver instance.
    Receiver receiver;

    // Generate a ConcreteCommand, passing the Receiver to it.
    ConcreteCommand command(receiver);

    // Generate an Invoker.
    Invoker invoker;

    // Set the command to be executed by the invoker.
    invoker.setCommand(&command);

    // Execute the command.
    invoker.executeCommand();
    // END

    return EXIT_SUCCESS;
}
