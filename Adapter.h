#ifndef ADAPTER_H
#define ADAPTER_H

// Keywords: Work Together, Bridge, Interfaces, Third-Party Library

/* Adapter Pattern is a structural design pattern used to make
 * two incompatible interfaces work together.
 * It acts as a bridge between two incompatible interfaces,
 * allowing them to collaborate without modifying their source code.
 * This pattern is particularly useful when integrating legacy code
 * or third-party libraries into your application.
*/

/*
 * Possible Problem Statement:
 *
 * Suppose you have a legacy printer class that only understands commands
 * in uppercase, and a modern computer class that sends commands in lowercase.
 * You need to make the modern computer work with the legacy
 * printer without modifying the existing printer class.
*/

/*
 * It defines three classes:
    LegacyPrinter is the legacy component (Adaptee). It has a method 'printInUppercase' that can print text in uppercase.
    ModernComputer is the modern client class. It has a method 'sendCommand' to send commands, but it sends them in lowercase.
    PrinterAdapter is the adapter class. It encapsulates the 'LegacyPrinter' and adapts it to work with the 'ModernComputer'.
 */

#include <iostream>

// Legacy Printer Class (Adaptee)
/*
    The LegacyPrinter class has a single method, printInUppercase,
    which takes a string as an argument and prints it in uppercase.
*/
class LegacyPrinter{
public:
    void printInUppercase( const std::string &command ){
        std::cout << "Printing: " << command << std::endl;
    }
};

// Modern Computer (Client)
/*
    The ModernComputer class has a single method, sendCommand,
    which also takes a string as an argument but sends it as a command (in lowercase).
*/
class ModernComputer{
public:
    void sendCommand( const std::string &command ){
        std::cout << "Sending command: " << command << std::endl;
    }
};

// Adapter Class to make the LegacyPrinter compatible with ModernComputer
/*
    The PrinterAdapter class is the adapter. It contains an instance of LegacyPrinter.
    It has a method sendCommand that takes a lowercase command as an argument.
*/
class PrinterAdapter {
private:
    LegacyPrinter legacyPrinter;

public:
    void sendCommand( const std::string &command ){
        // Convert the command to uppercase and pass it to the LegacyPrinter
        std::string uppercaseCommand = command;
        for (char &c : uppercaseCommand){
            c = std::toupper(c);
        }
        legacyPrinter.printInUppercase(uppercaseCommand);
    }
};

#endif // ADAPTER_H
