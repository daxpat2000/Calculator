//==============================================================================
/**
 * Honor Pledge:
 *
 * I pledge that I have neither given nor received any help
 * on this assignment.
 */
//==============================================================================

#ifndef ARRAY_BASE_H
#define ARRAY_BASE_H

#include <cstring>          // for size_t definition

template <typename T>
class Array_Base{
    public:
        /// Type definition of the element type.
        typedef T type;

        /// Default constructor
        Array_Base(void);

        /**
         * Initializing constructor.
         *
         * @param[in]      length        Initial size
         */
        Array_Base (size_t length);

        /**
         * Initializing constructor.
         *
         * @param[in]      length        Initial size
         * @param[in]      fill          Initial value for each element
         */
        Array_Base (size_t length, T fill);

        /**
         * Copy constructor
         *
         * @param[in]     arr         The source array.
         */
        Array_Base (const Array_Base & arr);

        /// Destructor.
        ~Array_Base (void);

        /**
         * Retrieve the current size of the array.
         *
         * @return          The current size
         */
        size_t size (void) const;

        /**
         * Retrieve the maximum size of the array.
         *
         * @return          The maximum size
         */
        size_t max_size (void) const;

        /**
         * Get the character at the specified index. If the index is not
         * within the range of the array, then std::out_of_range exception
         * is thrown.
         *
         * @param[in]       index               Zero-based location
         * @exception       std::out_of_range   Invalid \a index value
         */
        T & operator [] (size_t index);

        /**
         * @overload
         *
         * The returned character is not modifiable.
         */
        const T & operator [] (size_t index) const;

        /**
         * Get the character at the specified index. If the \a index is not within
         * the range of the array, then std::out_of_range exception is thrown.
         *
         * @param[in]       index                 Zero-based location
         * @return          Character at \index
         * @exception       std::out_of_range     Invalid index value
         */  
        T get (size_t index) const;

        /** 
         * Set the character at the specified \a index. If the \a index is not
         * within range of the array, then std::out_of_range exception is 
         * thrown.
         *
         * @param[in]       index                 Zero-based location
         * @param[in]       value                 New value for character
         * @exception       std::out_of_range     Invalid \a index value
         */
        void set (size_t index, T value); 

        /**
         * Locate the specified character in the array. The index of the first
         * occurrence of the character is returned. If the character is not
         * found in the array, then -1 is returned.
         *
         * @param[in]        ch        Character to search for
         * @return           Index value of the character
         * @retval           -1        Character not found
         */
        int find (T element) const;

        /**
         * @overload
         *
         * This version allows you to specify the start index of the search. If
         * the start index is not within the range of the array, then the
         * std::out_of_range exception is thrown.
         *
         * @param[in]       ch                   Character to search for
         * @param[in]       start                Index to begin search
         * @return          Index value of first occurrence
         * @retval          -1                   Character not found
         * @exception       std::out_of_range    Invalid index
         */
        int find (T element, size_t start) const;

        /**
         * Fill the contents of the array.
         *
         * @param[in]       ch                   Fill character
         */
        void fill (T element);

        /// Reverse the contents of the array such that the first element is now
        /// the last element and the last element is the first element.
        void reverse (void);

    protected:
        /// Data container
        T *data_;
        /// max size 
        size_t max_size_;
        /// cur size
        size_t cur_size_;
};

#include "Array_Base.inl"
#include "Array_Base.cpp"

#endif