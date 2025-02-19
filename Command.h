#ifndef COMMAND_H
#define COMMAND_H

/*
    The Command Pattern is a behavioral design pattern
    that focuses on encapsulating a request as an object,
    thereby decoupling the sender of the request from the receiver.
    This pattern allows you to parameterize objects with commands,
    delay or queue a request's execution, and support
    undoable operations. It's a fundamental pattern for implementing
    a wide range of functionality in software systems.

    Example Problem Statement:
        Design a system that demonstrates the use of
        the Command Pattern to decouple the sender
        and receiver of a request. The system should
        consist of several key components:
        Command,
        Concrete Command,
        Receiver,
        and Invoker.
*/

#include <iostream>

// Receiver
class Receiver {
public:
    // Receiver class defines the action to be performed.
    void performAction()
    {
        std::cout << "Receiver is performing an action" << std::endl;
    }
};

// Command interface
class Command {
public:
    // The execute method is declared in the Command
    // interface.
    virtual void execute() = 0;
};

// Concrete Command
class ConcreteCommand : public Command {
private:
    Receiver &receiver;

public:
    // ConcreteCommand takes a reference to a Receiver
    // object in its constructor.
    ConcreteCommand(Receiver&rec)
        : receiver(rec)
    {
    }

    // The execute method calls the action on the Receiver.
    void execute() { receiver.performAction(); }
};

// Invoker
class Invoker {
private:
    Command* command;

public:
    // The setCommand method allows setting the command to
    // be executed.
    void setCommand(Command* cmd) { command = cmd; }

    // The executeCommand method triggers the execution of
    // the command.
    void executeCommand() { command->execute(); }
};

#endif // COMMAND_H
