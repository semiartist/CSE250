/***
*  File: a3.hpp
*  Author: FirstName LastName UBITName
*/

#ifndef A3_HPP
#define A3_HPP

// MAKE SURE TO UPDATE YOUR INFORMATION IN THE HEADER OF THIS FILE
// IMPLEMENT MISSING FUNCTIONALITY OF key_value_sequences IN THIS FILE
// YOU ARE NOT ALLOWED TO INCLUDE ANY OTHER HEADERS THAN
// <algorithm>, <list>, <vector>
// YOU CAN CHANGE/EDIT ANY CODE IN THIS FILE AS LONG AS SEMANTICS IS UNCHANGED
// AND MATCHES SPECIFICATION PROVIDED IN THE ASSIGNMENT TEXT

#include <algorithm>
#include <list>
#include <vector>

using std::vector;
class key_value_sequences {
public:
    ~key_value_sequences(){
        delete[] sequence;
    }
    // YOU SHOULD USE C++ CONTAINERS TO AVOID RAW POINTERS
    // IF YOU DECIDE TO USE POINTERS, MAKE SURE THAT YOU MANAGE MEMORY PROPERLY

    // IMPLEMENT ME: SHOULD RETURN SIZE OF A SEQUENCE FOR GIVEN KEY
    // IF NO SEQUENCE EXISTS FOR A GIVEN KEY RETURN -1
    int size(int key){
        vector<int>::iterator keyIt;
        keyIt = std::find (_key.begin(), _key.end(), key);
        if (keyIt == _key.end()) return -1;
        return _value[keyIt-_key.begin()].size();
    }

    // IMPLEMENT ME: SHOULD RETURN POINTER TO A SEQUENCE FOR GIVEN KEY
    // IF NO SEQUENCE EXISTS FOR A GIVEN KEY RETURN nullptr
    const int* data(int key) {
        delete[] sequence;
        int * sequence;
        vector<int>::iterator keyIt;
        keyIt = std::find (_key.begin(), _key.end(), key);

        // if not found
        if (keyIt == _key.end()) return nullptr;

        // if found
        int ind = keyIt - _key.begin();
        int size = _value[ind].size();
        sequence = new int[size];

        for (int i = 0; i < size ; i++){
            sequence[i] = _value[ind][i];
        }
        return sequence;
    }

    // IMPLEMENT ME: INSERT VALUE INTO A SEQUENCE IDENTIFIED BY GIVEN KEY
    void insert(int key, int value){
        vector<int>::iterator keyIt;
        keyIt = std::find (_key.begin(), _key.end(), key);

        // case not std::find existing key;
        if (keyIt == _key.end()){
            _key.push_back(key);
            vector<int> temp;
            temp.push_back(value);
            _value.push_back(temp);
            return;
        }

        // case found exisint key
        _value[keyIt-_key.begin()].push_back(value);
    }


private:
    vector<int> _key;
    vector< vector<int> > _value;
    int * sequence;

}; // class key_value_sequences

#endif // A3_HPP
