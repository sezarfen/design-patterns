#ifndef COMPOSITE_H
#define COMPOSITE_H

/*
    Composite pattern is one of the most widely used patterns in
    the industry and addresses a very significant and subtle problem.
    It is used whenever the user wants to treat the individual object
    in the same way as the collection of those individual objects for e.g
    you might want to consider a page from the copy as same as the whole copy
    which is basically a collection of the pages or if you want to generate
    a hierarchy of something where you might want to consider the whole thing as the object.

    Compose objects into tree structures to represent part-whole hierarchies.
    Composite lets clients treat individual objects and compositions of objects uniformly.

    In the case of photoshop where we draw many individual objects and then those objects
    compose a whole unique object and you might want to apply some operation
    on the whole object instead of the each of the individual objects.
*/

// CPP program to illustrate
// Composite design pattern

#include <iostream>
#include <vector>

using namespace std;

class PageObject {
public:
    virtual void Add(PageObject a) {}
    virtual void Remove() {}
    virtual void Delete(PageObject a) {}
};

class Page : public PageObject {
public:
    void Add(PageObject a)
    {
        cout << "something is added to the page" << endl;
    }
    void Remove()
    {
        cout << "something is removed from the page"
             << endl;
    }
    void Delete(PageObject a)
    {
        cout << "something is deleted from page " << endl;
    }
};

class Copy : public PageObject {
    vector<PageObject> copyPages;

public:
    void AddElement(PageObject a)
    {
        copyPages.push_back(a);
    }

    void Add(PageObject a)
    {
        cout << "something is added to the copy" << endl;
    }
    void Remove()
    {
        cout << "something is removed from the copy"
             << endl;
    }
    void Delete(PageObject a)
    {
        cout << "something is deleted from the copy";
    }
};

#endif // COMPOSITE_H
