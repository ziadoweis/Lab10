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
int HashTable<keyType, valueType>::Hash(keyType& key) {
    return 0;
}

// Add Item: Inserts a new key-value pair into the hash table
template<class keyType, class valueType>
bool HashTable<keyType, valueType>::AddItem(keyType key, valueType val) {

    m_hash_table[42] =  std::make_shared<KVP<keyType, valueType> >(key,val);

    auto v = m_hash_table[42];
    return false;

}

// Get Item: Retrieves the value associated with the given key
template<class keyType, class valueType>
std::shared_ptr<KVP<keyType, valueType>> HashTable<keyType, valueType>::GetItem(keyType& key) {
    return nullptr; // Item not found
}

// Contains: Counts the number of items in the hash table
template<class keyType, class valueType>
int HashTable<keyType, valueType>::Contains(){
    return m_count;
}

template<class keyType, class valueType>
void HashTable<keyType, valueType>::clear() {
    for (auto& item : m_hash_table) {
        item.reset(); // Resetting shared_ptr to nullptr deallocates the object it points to
    }
    m_count = 0;
}