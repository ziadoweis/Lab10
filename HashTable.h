#pragma once

#include "KVP.h"
#include <iostream>
#include <memory>
#include <vector>

template<class keyType, class valueType>
class HashTable {

public:
    //Constructor that takes in a table size
    HashTable(int input_size);

    //Hashing function
    int Hash(keyType& key, bool BadHash);

    //Adds an item to the table
    bool AddItem(keyType key, valueType val, bool BadHash);

    //Gets an item from the table using a key
    std::shared_ptr<KVP<keyType, valueType>> GetItem(keyType& key, bool BadHash);

    //Checks the occupied size of the table
    int Contains();
    
    virtual ~HashTable();
    
    //Clears the table
    void ClearTable();

private:
    int max_size;
    int m_count;
    int IncrementCount;
    
    std::vector<std::shared_ptr<KVP<keyType, valueType>>> m_hash_table;
};

#include "HashTable.cpp"