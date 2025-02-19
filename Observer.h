#ifndef OBSERVER_H
#define OBSERVER_H

/*
    The Observer Pattern is a behavioral design pattern that defines
    a one-to-many dependency between objects, meaning that
    when one object (the subject) changes its state, all its dependents (observers)
    are notified and updated automatically. This pattern is used to build
    distributed event-handling systems and is a crucial part
    of many software architectures, including Model-View-Controller (MVC).

    Example Problem statement:
        Suppose you are developing a weather monitoring application,
        in which multiple weather stations are responsible for collecting weather data,
        and you want to create a system where multiple displays can show real-time
        weather updates. When a weather station collects new data, all registered displays
        should be updated automatically with the latest information.
*/

#include <iostream>
#include <forward_list>

// Observer interface
class Observer {
public:
    virtual void update(float temperature, float humidity, float pressure) = 0;
};

// Subject (WeatherStation) class
class WeatherStation {
private:
    float temperature;
    float humidity;
    float pressure;
    std::forward_list<Observer*> observers;

public:
    void registerObserver(Observer* observer) {
        observers.push_front(observer);
    }

    void removeObserver(Observer* observer) {
        observers.remove(observer);
    }

    void notifyObservers() {
        for (Observer* observer : observers) {
            observer->update(temperature, humidity, pressure);
        }
    }

    void setMeasurements(float temp, float hum, float press) {
        temperature = temp;
        humidity = hum;
        pressure = press;
        notifyObservers();
    }
};

// Concrete Observer
class Display : public Observer {
public:
    void update(float temperature, float humidity, float pressure) {
        std::cout << "Display Receive an update! : Temperature = " << temperature
                  << "°C, Humidity = " << humidity
                  << "%, Pressure = " << pressure << " hPa"
                  << std::endl;
    }
};


#endif // OBSERVER_H
