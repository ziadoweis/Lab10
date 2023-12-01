#include <iostream>
#include <memory>
#include "HashTable.h"

// Constructor: Initializes the hash table with given size
template <class keyType, class valueType>
HashTable<keyType, valueType>::HashTable(int input_size){
    max_size = input_size;
    m_count = 0;
    // Create a vector of shared pointers to KVP instances, initializing all elements to nullptr
    m_hash_table = std::vector<std::shared_ptr<KVP<keyType, valueType>>>(input_size, nullptr);
}

// Destructor: Clears the hash table
template<class keyType, class valueType>
HashTable<keyType, valueType>::~HashTable()
{
    //dtor
    m_hash_table.clear();
}

// Hash function: Computes the hash value based on the key
template <class keyType, class valueType>
int HashTable<keyType, valueType>::Hash(keyType& key, bool badHash) {
    if (badHash != true) {
        return static_cast<int>(key) % max_size;
    }
    else { return 0; }
}

// Add Item: Inserts a new key-value pair into the hash table
template<class keyType, class valueType>
bool HashTable<keyType, valueType>::AddEntry(keyType key, valueType val, bool badHash) {
    
    std::shared_ptr<KVP<keyType, valueType>> entry = GetEntry(key, false);
    if (entry != nullptr) { return false; }

    if (Contains() == m_hash_table.size()) { return false; }

    int i = Hash(key, badHash);

    if (m_hash_table[i] == nullptr) {
        m_hash_table[i] = std::make_shared<KVP<keyType, valueType>>(key, val);
        m_count++;
        return true;
    }
    else {
        //int initial_i = i;
        int moves = 0;

        while ((m_hash_table[i] != nullptr) && (moves < m_hash_table.size())) {
        
            if (i == m_hash_table.size()) { i = 0; }

            i++;
            moves++;
        }

        if (m_hash_table[i] == nullptr) {
            m_hash_table[i] = std::make_shared<KVP<keyType, valueType>>(key, val);
            m_count++;
            return true;
        }
    }
}

// Get Item: Retrieves the value associated with the given key
template<class keyType, class valueType>
std::shared_ptr<KVP<keyType, valueType>> HashTable<keyType, valueType>::GetEntry(keyType& key, bool badHash) {
    int i = Hash(key, badHash);
    while (m_hash_table[i] != nullptr) {
        if (m_hash_table[i]->getKey() == key) {
            return m_hash_table[i];
        }
        i = (i + 1) % max_size; // Linear probing
    }    
    return nullptr;
}

// Contains: Counts the number of items in the hash table
template<class keyType, class valueType>
int HashTable<keyType, valueType>::Contains(){
    return m_count;
}

template<class keyType, class valueType>
void HashTable<keyType, valueType>::clear() {
    for (auto& entry : m_hash_table) {
        entry.reset(); // Resetting shared_ptr to nullptr deallocates the object it points to
    }
    m_count = 0;
}