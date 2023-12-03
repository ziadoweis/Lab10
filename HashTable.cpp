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
HashTable<keyType, valueType>::~HashTable(){
    //dtor
    m_hash_table.clear();
}

// Hash function: Computes the hash value based on the key
template <class keyType, class valueType>
int HashTable<keyType, valueType>::Hash(keyType& key, bool BadHash) {
    if(!BadHash){
    return static_cast<int>(key) % max_size;
    }
    else{
        return 0;
    }
}

// Add Item: Inserts a new key-value pair into the hash table
template<class keyType, class valueType>
bool HashTable<keyType, valueType>::AddItem(keyType key, valueType val) {
    int Index = Hash(key, false);
    if (GetItem(key) != nullptr){
        return false; 
    }

    if (m_count == m_hash_table.size()){
         return false; 
    }

    if (m_hash_table[Index] == nullptr){
        m_hash_table[Index] = std::make_shared<KVP<keyType, valueType>>(key, val);
        m_count++;
        return true;
    }
    else{
        while ((m_hash_table[Index] != nullptr) && (IncrementCount < m_hash_table.size())) {
            Index++;
            IncrementCount++;

            if (Index == m_hash_table.size()){
                Index = 0; 
            }
        }

        if (m_hash_table[Index] == nullptr) {
            m_hash_table[Index] = std::make_shared<KVP<keyType, valueType>>(key, val);
            m_count++;
            return true;
        }
    }
    std::cout << "No available slots in table\n";
    return false;
}

// Get Item: Retrieves the value associated with the given key
template<class keyType, class valueType>
std::shared_ptr<KVP<keyType, valueType>> HashTable<keyType, valueType>::GetItem(keyType& key) {
    int Index, OriginalIndex = Hash(key, false);

    while (m_hash_table[Index]->getKey() != key && m_hash_table[Index] != nullptr) {
        Index = (Index + 1) % max_size; // Linear probing
        if(Index = OriginalIndex){
            std::cout << "No key found\n";
            break;
        }
    }  

    if (m_hash_table[Index]->getKey() == key && m_hash_table[Index] != nullptr) {
            return m_hash_table[Index];
    }
    else{
        return nullptr;
    }   
}

// Contains: Counts the number of items in the hash table
template<class keyType, class valueType>
int HashTable<keyType, valueType>::Contains(){
    return m_count;
}

template<class keyType, class valueType>
void HashTable<keyType, valueType>::ClearTable() {
    // Sets shared pointer count to null
    for (auto& Item : m_hash_table) {
        Item.reset(); 
    }
    // Clears the values in the hashtable
    m_hash_table.clear();
    m_count = 0;
}