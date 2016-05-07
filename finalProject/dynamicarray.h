/**
 *  @file dynamicarray.h
 *  @author Jordan Giacone, Shae Bolt , CS5201 Section A
 *  @date Feb 23, 2016
 *  @brief Description:
 *  @details Details:
 */

#ifndef DYNAMICARRAY_H_
#define DYNAMICARRAY_H_

#include <iostream>
#include <utility>

///@brief Defines a dynamic array with dynamic memory and usefull array
///  manipulation functions
template<typename T>
class DynamicArray;

template<typename T>
void swap(DynamicArray<T>& first, DynamicArray<T>& second);

template<typename T>
class DynamicArray
{
  public:

    /// @brief default initializes the array
    /// @pre none
    /// @post calling object initialized with 0 m_length, 0 m_size,
    /// and nullptr for the m_array
    DynamicArray() :
        m_length(0), m_size(0), m_array(nullptr)
    {
    }

    /// @brief initializes the array by specifying how large it will be with
    /// size, and initializes every entry with value
    /// @pre T = T is defined
    /// @post the calling objects m_size is set to size, m_length to 2*size,
    /// and m_array allocated and initialized with all values = value
    DynamicArray(const size_t size, const T& value);

    /// @brief parameterized constructor, initializes member variables to
    /// parameters
    /// @pre T = T is defined
    /// @post m_length is set to length, m_size is set to size and array is
    /// deep copied to m_array
    DynamicArray(const size_t length, const size_t size, const T* array);

    /// @brief single value constructor, initializes array with one item
    /// @pre T = T is defined
    /// @post initializes the calling object to have a m_size of 1 and
    /// m_length = 2, and intializing m_array with just item
    DynamicArray(const T& item);

    /// @brief move constructor, initializes array with contents of other
    /// @pre T = T is defined
    /// @post the calling objects member variables are all deep copied from other
    DynamicArray(DynamicArray<T> && other);

    /// @brief copy constructor, initializes array with contents of other
    /// @pre T = T is defined
    /// @post the calling objects member variables are all deep copied from other
    DynamicArray(const DynamicArray<T>& other);

    /// @brief assignment operator, sets *this to rhs
    /// @pre T = T is defined
    /// @post calling objects member variables are all deep copied from rhs,
    /// and a reference to the calling object is returned
    DynamicArray<T>& operator=(DynamicArray<T> rhs);

    /// @brief destructor
    /// @pre none
    /// @post de-allocates m_array
    ~DynamicArray();

    /// @brief indexes into m_array
    /// @pre index is < m_size
    /// @post if index is not out of bounds, the corresponding reference at
    /// the index is returned from the array.
    T& operator[](const size_t index);

    /// @brief indexes into m_array
    /// @pre index < m_size
    /// @post if index is not out of bounds, the corresponding constant
    /// reference at the index is returned from the array.
    const T& operator[](const size_t index) const;

    /// @brief appends the given item to the end of the calling object
    /// @pre T = T is defined
    /// T default construction is defined
    /// @post the array values of item are put onto the end of m_array
    void append(const DynamicArray<T>& item);

    /// @brief appends a single item to the end of the calling object
    /// @pre T = T is defined
    /// T default construction is defined
    /// @post the item is put onto the end of m_array
    void append(const T& item);

    /// @brief inserts the given item to the given index of the calling object
    /// @pre T = T is defined
    /// T default construction is defined
    /// index <= m_size
    /// @post the array values of item are inserted into the calling object
    /// starting at index
    void insert(const DynamicArray<T>& item, const size_t index);

    /// @brief removes items from the given start to the start + offset
    /// @pre T = T is defined
    /// T default construction is defined
    /// start + offset < m_size;
    /// @post the calling object has all values from start to start + offset
    /// removed
    void remove(const size_t start, const size_t offset = 0);

    /// @brief reduces the size of m_array
    /// @pre T = T is defined
    /// T default construction is defined
    /// size < m_size;
    /// @post m_size is set to size, and if small enough the physical size of
    /// the m_array will shrink as well
    void truncate(const size_t size);

    /// @brief clears the array
    /// @pre none
    /// @post calling object dynamic memory is de allocated and the m_size
    /// and m_length are set to 0
    void clear();

    /// @brief reverses the elements in the array
    /// @pre none
    /// @post all elements in the array are reversed.
    void reverse();

    /// @brief reserves space for the array
    /// @pre none
    /// @post changes the logical size and physical size of
    /// the array m_size, m_length to match size.
    void reserve(const size_t size);

    /// @brief returns the logical size of the array
    /// @pre none
    /// @post returns m_size
    size_t size() const;

    /// @brief retrieves the physical size of the array
    /// @pre none
    /// @post returns m_length
    size_t length() const;

    /// @brief finds whether or not the array contains any elements
    /// @pre none
    /// @post returns !m_size.
    bool isEmpty() const;

    /// @brief swaps the elements from first and second
    /// @pre array swapping for T is defined
    /// @post all elements first is now the same as the initial state of second
    /// and second is the same as the initial state of first
    friend void swap<T>(DynamicArray<T>& first, DynamicArray<T>& second);
  private:
    /// @brief represents physical length
    size_t m_length;
    /// @brief represents logical size
    size_t m_size;
    /// @brief array of T elements
    T* m_array;

    /// @brief changes the physical size of m_array
    /// @pre T = T is defined
    /// T default construction is defined
    /// @post m_array is allocated to the sizeof(T) * length
    void resize(const size_t length);
};

#include "dynamicarray.hpp"

#endif /* DYNAMICARRAY_H_ */
