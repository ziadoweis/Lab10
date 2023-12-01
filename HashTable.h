#pragma once

#include "KVP.h"
#include <iostream>
#include <memory>
#include <vector>

template<class keyType, class valueType>
class HashTable {

public:
    HashTable(int input_size);

    int Hash(keyType& key);

    bool AddItem(keyType key, valueType val);

    std::shared_ptr<KVP<keyType, valueType>> GetItem(keyType& key);

    int Contains();
    
    virtual ~HashTable();
    
    void clear();

private:
    int max_size;
    int m_count;
    
    std::vector<std::shared_ptr<KVP<keyType, valueType>>> m_hash_table;
};

#include "HashTable.cpp"