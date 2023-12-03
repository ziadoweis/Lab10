#pragma once

#include "KVP.h"
#include <iostream>
#include <memory>
#include <vector>

template<class keyType, class valueType>
class HashTable {

public:
    HashTable(int input_size);

    int Hash(keyType& key, bool BadHash);

    bool AddItem(keyType key, valueType val, bool BadHash);

    std::shared_ptr<KVP<keyType, valueType>> GetItem(keyType& key, bool BadHash);

    int Contains();
    
    virtual ~HashTable();
    
    void ClearTable();

private:
    int max_size;
    int m_count;
    int IncrementCount;
    
    std::vector<std::shared_ptr<KVP<keyType, valueType>>> m_hash_table;
};

#include "HashTable.cpp"