#ifndef STRATEGY_H
#define STRATEGY_H

/*
    Strategy Pattern is a behavioral design pattern
    that defines a family of interchangeable algorithms
    and allows them to be used interchangeably within a context.
    This pattern enables the algorithm to be selected at runtime,
    providing flexibility and promoting code reusability.

    Example Problem Statement:
        Suppose you are working on a data processing application,
        and you need to implement a sorting feature that
        allows users to sort data in various ways.
        You decide to use the Strategy Pattern to handle
        different sorting algorithms.
*/

#include <iostream>
#include <vector>

class SortingStrategy {
public:
    virtual void sort(std::vector<int>& arr) = 0;
};

class BubbleSort : public SortingStrategy {
public:
    void sort(std::vector<int>& arr) override {
        (void)arr;
        // Implement Bubble Sort algorithm
    }
};

class QuickSort : public SortingStrategy {
public:
    void sort(std::vector<int>& arr) override {
        (void)arr;
        // Implement Quick Sort algorithm
    }
};

// Add more sorting algorithms as needed

class SortContext {
private:
    SortingStrategy* strategy;

public:
    void setStrategy(SortingStrategy* strategy) {
        this->strategy = strategy;
    }

    void executeStrategy(std::vector<int>& arr) {
        strategy->sort(arr);
    }
};

#endif // STRATEGY_H
