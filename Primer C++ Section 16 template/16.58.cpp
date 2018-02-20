#include<bits/stdc++.h>
using namespace std;
typedef long long LL;


class StrVec
{
public:
    // Big 3/5.
    StrVec():
        element(nullptr), first_free(nullptr), cap(nullptr)
    { }

    StrVec(std::initializer_list<std::string> l);


    StrVec(const StrVec& s);

    StrVec&
    operator =(const StrVec& rhs);

    ~StrVec();


    // public members
    void push_back(const std::string &s);

    // a variadic member template using its argumenst to construct
    // an element directly in space managed by the constainer
    template<typename... Args>

    std::size_t size() const        { return first_free - element; }
    std::size_t capacity() const    { return cap - element; }

    std::string* begin() const      { return element; }
    std::string* end() const        { return first_free; }

    template<typename... Args>
    void emplace_back(Args&&... args);

    // preallocate enough memory for specified number of elements
    void reserve(std::size_t n);

    // resize as required.
    void resize(std::size_t n);
    void resize(std::size_t n, const std::string& s);


private:

    // data members
    std::string* element;       //  pointer to the first element
    std::string* first_free;    //  pointer to the first free element
    std::string* cap;           //  pointer to one past the end

    std::allocator<std::string> alloc;

    // utilities for Big 3/5
    void reallocate();
    void chk_n_alloc()      { if (size() == capacity()) reallocate(); }
    void free();

    // utilities added
    // used in reallocate() reserve() and resize().
    void wy_alloc_n_move(std::size_t n);

    std::pair<std::string*, std::string*>
    alloc_n_copy (std::string* b, std::string* e);

};

template<typename... Args>
//记得加右值引用保持类型信息。
inline void StrVec::emplace_back(Args&&... args)
{
    chk_n_alloc();
    alloc.construct(first_free++,forward<Args>(args)...);
}




// copy constructor
StrVec::StrVec(const StrVec &s)
{
    /**
     * @brief newData is a pair of pointers pointing to newly allocated and copied
     *                  range : [b, e)
     */
    std::pair<std::string*, std::string*>
            newData = alloc_n_copy(s.begin(), s.end());

    element = newData.first;
    first_free = cap = newData.second;
}

/**
 * @brief   constructor taking initializer_list<string>
 *          for ex 13.40
 * @param l
 */
StrVec::StrVec(std::initializer_list<std::string> l)
{
    // allocate memory as large as l.size()
    std::string * const
            newData = alloc.allocate(l.size());

    // copy elements from l to the address allocated
    auto p = newData;
    for(const auto &s : l)
        alloc.construct(p++, s);

    // build the data structure
    element = newData;
    first_free = cap = element + l.size();
}


// operator =
StrVec&
StrVec::operator =(const StrVec& rhs)
{
    // allocate and copy first to protect against self-assignment
    std::pair<std::string*, std::string*>
            newData = alloc_n_copy(rhs.begin(), rhs.end());

    // destroy and deallocate
    free();

    element = newData.first;
    first_free = cap = newData.second;

    return *this;
}

// destructor
StrVec::~StrVec()
{
    free();
}

/**
 * @brief   allocate new room if nessary and push back the new string
 * @param s new string
 */
void StrVec::push_back(const std::string& s)
{
    chk_n_alloc();
    alloc.construct(first_free++, s);
}

/**
 * @brief   preallocate enough memory for specified number of elements
 * @param n number of elements required
 * @note    this function is implemented refering to StrVec::reallocate().
 */
void StrVec::reserve(std::size_t n)
{
    // if the n is too small, just ignore it.
    if(n <= capacity())  return;

    // allocate and move old ones into the new address.
    wy_alloc_n_move(n);
}


/**
 *  @brief  Resizes to the specified number of elements.
 *  @param  n  Number of elements the %vector should contain.
 *
 *  This function will resize it to the specified
 *  number of elements.  If the number is smaller than the
 *  current size it is truncated, otherwise
 *  default constructed elements are appended.
 */

void StrVec::resize(std::size_t n)
{
    resize(n, std::string());
}

/**
 *  @brief  Resizes it to the specified number of elements.
 *  @param  __new_size  Number of elements it should contain.
 *  @param  __x  Data with which new elements should be populated.
 *
 *  This function will resize it to the specified
 *  number of elements.  If the number is smaller than the
 *  current size the it is truncated, otherwise
 *  the it is extended and new elements are populated with
 *  given data.
 */
void StrVec::resize(std::size_t n, const std::string &s)
{
    if(n < size())
    {
        // destroy the range : [element+n, first_free) using destructor
        for(auto p = element + n; p != first_free; /* empty */)
            alloc.destroy(p++);

        // move frist_free point to the new address element + n
        first_free = element + n;
    }
    else if( n > size() )
    {
        for(auto i = size(); i != n; ++i)
            push_back(std::string(s));
    }
}

/**
 * @brief   Double the capacity and using std::move move the original strings to the newly
 *          allocated memory
 */
void StrVec::reallocate()
{
    // calculate the new capacity required.
    std::size_t newCapacity = size() ? 2 * size() : 1;

    // allocate and move old ones into the new address.
    wy_alloc_n_move(newCapacity);
}

/**
 * @brief   allocate new space for the given range and copy them into it
 * @param b
 * @param e
 * @return  a pair of pointers pointing to [first element , one past the last) in the new space
 */
std::pair<std::string *, std::string *>
StrVec::alloc_n_copy(std::string *b, std::string *e)
{
    // calculate the size needed and allocate space accordingly
    std::string* data = alloc.allocate(e - b);

    return { data, std::uninitialized_copy(b, e, data) };
    //            ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
    // which copies the range [first, last) into the space of which
    // the starting address p_data is pointing to.
    // This function returns a pointer pointing to one past the last element.
}

/**
 * @brief   destroy the elements and deallocate the space previously allocated.
 */
void StrVec::free()
{

    if(element)     //  if not nullptr
    {
        // destory it  in reverse order.
        for(auto p = first_free; p != element; /* empty */)
            alloc.destroy(--p);

        alloc.deallocate(element, capacity());
    }
}

/**
 * @brief   allocate memory for spicified number of elements
 * @param n
 * @note    it's user's responsibility to ensure that @param n is greater than
 *          the current capacity.
 */
void StrVec::wy_alloc_n_move(std::size_t n)
{
    std::size_t newCapacity = n;

    std::string*
            newData = alloc.allocate(newCapacity);

    std::string*
            dest    = newData;
    std::string*
            elem    = element;

    // move the old to newly allocated space.
    for(std::size_t i = 0; i != size(); ++i)
        alloc.construct(dest++, std::move(*elem++));

    free();

    // update data structure
    element     =   newData;
    first_free  =   dest;
    cap         =   element + newCapacity;
}

int main()
{
    //freopen("I:\\Algorithms\\git\\Algorithm\\Algorithm\\input.txt","r",stdin);//
    
    ios::sync_with_stdio(false);
    
    
    
    
    return 0;
}
