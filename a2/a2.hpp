/***
 *  File: a2.hpp
 *  Author: FirstName LastName UBITName
 */

#ifndef A2_HPP
#define A2_HPP

// MAKE SURE TO UPDATE YOUR INFORMATION IN THE HEADER OF THIS FILE
// IMPLEMENT MISSING FUNCTIONALITY OF sorted_sc_array IN THIS FILE
// YOU ARE NOT ALLOWED TO INCLUDE ANY OTHER HEADERS EXCEPT OF <algorithm>
// YOU CAN CHANGE/EDIT ANY CODE IN THIS FILE AS LONG AS SEMANTICS IS UNCHANGED
// AND MATCHES SPECIFICATION AS PROVIDED IN THE ASSIGNMENT TEXT

#include <algorithm>


class sorted_sc_array {
public:
    sorted_sc_array() : size_(0), ptr_(nullptr) { }

    ~sorted_sc_array() { delete[] ptr_; }

    // IMPLEMENT ME
    sorted_sc_array(const sorted_sc_array& A){
        size_ = A.size_;
        if (size_ == 0) ptr_ = nullptr;
         else {
             ptr_ = new signed char[size_];
             std::copy(A.ptr_, A.ptr_ + size_, ptr_);
         }


    }

    // IMPLEMENT ME
    sorted_sc_array& operator=(const sorted_sc_array& A){
        if (this == &A ) return *this;
        size_ = A.size_;
        delete[] ptr_;
        size_ = A.size_;
        if (size_ == 0) ptr_ = nullptr;
        else {
            ptr_ = new signed char[size_];
            std::copy(A.ptr_, A.ptr_ + size_, ptr_);
        }
        return *this;

    }

    // RETURNS SIZE OF THE ARRAY (i.e. HOW MANY ELEMENTS IT STORES)
    int size() const { return size_; }

    // RETURNS RAW POINTER TO THE ACTUAL DATA, CAN BE INVOKED AT ANY TIME
    const signed char* data() const { return ptr_; }


    // IMPLEMENT ME: AFTER INSERT COMPLETES THE ARRAY MUST BE IN ASCENDING ORDER
    void insert(signed char c){

        if (size_==0) {
            size_ += 1;
            ptr_ = new signed char[size_];
            ptr_[0] = c;
            return;
        }
        size_ +=1;
        int loc = 0;
        for (int i = 0; i < size_-1 ; ++i){
            if (ptr_[i] < c ) loc = i;
            else break;
        }

        signed char * newPtr ;
        newPtr = new signed char [size_];

        for (int i = 0; i < size_ ; ++i){
            if (i <= loc) {
                newPtr[i] = ptr_[i];
                continue;
            }
            if ( i == loc + 1){
                newPtr[i] = c;
            }
            newPtr[i+1] = ptr_[i];
        }

        signed char * temp = ptr_;
        ptr_ = newPtr;
        delete[] temp;

        return;
    }


private:
    int size_;         // size of the array
    signed char* ptr_; // pointer to the array

}; // class sorted_sc_array

#endif // A2_HPP
