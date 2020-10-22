#include "tree_dir.hpp"

namespace ott
{

namespace util
{
template<class Item>
ListIterator<Item>::ListIterator(
        const std::vector<Item>& a_list
        ) : list_(a_list), current_(0) 
{
}

template<class Item>
ListIterator<Item>::ListIterator(
        std::vector<Item>&& a_list
        ) : list_(std::move(a_list)), current_(0) 
{
    for(auto& p : list_ )
    {
        std::cout << p << std::endl;
    }
}


template<class Item>
void ListIterator<Item>::first()
{
    current_ = 0;
}

template<class Item>
void ListIterator<Item>::next() 
{
    current_++;
}

template<class Item>
bool ListIterator<Item>::isDone() const
{
    return current_ >= list_.size();
}

template<class Item>
Item ListIterator<Item>::current() const
{
    if ( isDone() )
        throw IteraterOutOfBound();
    return list_[current_];
}
template<class Item>
ListIterator<Item>& ListIterator<Item>::operator=(const ListIterator<Item>& other)
{
    this->list_ = other.list_;
    this->current_ = other.current_;
    return *this;
}
template<class Item>
ListIterator<Item>::~ListIterator()
{

}

template<class Item>
Iterator<Item>::~Iterator() {}

template<class Item>
Iterator<Item>::Iterator() {}

#include <filesystem>

namespace fs = std::__fs::filesystem;
DirWaker::DirWaker(const std::string& path, const bool is_recursive) : fileWaker_(nullptr),
                                                                 valid_(false), 
                                                                 recursive_(is_recursive)
{
    if ( !fs::exists(fs::path(path)) )
    {
        std::cout << "dir does not exist\n";
        return;
    }
    if ( !fs::is_directory(fs::status(path)) )
    {
        std::cout << "path is not a directory\n";
        return;
    }
    valid_ = true;
    fs::path absolutePath = fs::absolute(path);
    std::vector<fs::path> loop;
    if ( recursive_ )
    {
        for(auto& p: fs::recursive_directory_iterator(absolutePath))
        {
            loop.push_back(p.path());
        }
    }
    else
    {
        for(auto& p : fs::directory_iterator(absolutePath) )
        {
            loop.push_back(p.path());
        }
    }
    fileWaker_ = new FileWaker(std::move(loop));

}

DirWaker::DirWaker() : fileWaker_(nullptr), valid_(false), recursive_(false) {}

DirWaker::~DirWaker() 
{
    if ( fileWaker_ != nullptr ) delete fileWaker_;
}
FileWaker* DirWaker::iterator() const
{
    return fileWaker_;
}


bool DirWaker::isValid() const
{
    return valid_;
}

} // util namespace
} // ott namespace
