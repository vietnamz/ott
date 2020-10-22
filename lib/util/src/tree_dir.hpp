#pragma once

#include <iostream>
#include <vector>
#include <filesystem>

namespace ott
{

namespace util
{


/*
 * abstract iterator class
 * must be implemented by sub classes
 */
template<class Item>
class Iterator
{
public:
    virtual ~Iterator();
    virtual void first() = 0;
    virtual void next() = 0;
    virtual bool isDone() const = 0;
    virtual Item current() const = 0;
protected:
    Iterator();
};

/*
 * the iterator class
 *
 * usage:
 *  vector<Employee*> employees;
 *  ListIterator<Employee*> forward(employees);
 *  PrintEmployees(forward);
 *
 */
template <class Item>
class ListIterator : public Iterator<Item>
{
public:
    // constructor
    ListIterator(const std::vector<Item>& a_list);

    ListIterator(std::vector<Item>&& a_list);
    virtual ~ListIterator();
    ListIterator& operator=(const ListIterator& other);
    // first element =
    virtual void first();
    // move to next element
    virtual void next();
    // test if there is no element
    virtual bool isDone() const;
    // take the current element
    virtual Item current() const;
private:
    // list container.
    const std::vector<Item> list_;
    // the current item index.
    long current_;
};

typedef ListIterator<std::__fs::filesystem::path> FileWaker;

#include <stdexcept>
#include <exception>

class IteraterOutOfBound : public std::exception
{

};
/*
 * provide a abstract class to handle dir traverse.
 *
 * input: a string represent an absolute path.
 *
 * usage:
 *  DirWaker dirWaker("/tmp");
 *
 *  auto& iter = dirWaker.iterator();
 *
 *  while( !iter.isDone() )
 *  {
 *      auto& item = iter.current();
 *      processItem();
 *      item.next();
 *  }
 *
 *  thread safe: we disallow copy and assignment operation to ensure thread safe.
 *
 */
class DirWaker
{
public:
    // constructor 
    DirWaker(const std::string& path, const bool is_recursive = false);
    DirWaker();
    // disable all dangerous method. do not allow copy and assignment 
    // to avoid double free.
    DirWaker(const DirWaker& other) = delete;
    DirWaker(DirWaker&& other) = delete;
    DirWaker& operator=(const DirWaker&) = delete;
    DirWaker& operator=(DirWaker&& ) = delete;

    virtual ~DirWaker();    
    FileWaker* iterator() const;
    bool isValid() const;
private:
    FileWaker* fileWaker_;
    bool valid_;
    bool recursive_;
};

} // util namespace
} // ott namespace
