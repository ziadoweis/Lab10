#include <iostream>
#include <memory>
#include "HashTable.h"

//Constructor that takes in a table size
template <class keyType, class valueType>
HashTable<keyType, valueType>::HashTable(int input_size){
    max_size = input_size;
    m_count = 0;
    // Create a vector of shared pointers to KVP instances, initializing all elements to nullptr
    m_hash_table = std::vector<std::shared_ptr<KVP<keyType, valueType>>>(input_size, nullptr);
}

//Destructor using vector clear function
template<class keyType, class valueType>
HashTable<keyType, valueType>::~HashTable(){
    m_hash_table.clear();
}

//Hashing function using a key
template <class keyType, class valueType>
int HashTable<keyType, valueType>::Hash(keyType& key, bool BadHash) {
    if(!BadHash){
        return static_cast<int>(key) % max_size;
    }
    else{
        return 0;
    }
}

//Adds an item to the table
template<class keyType, class valueType>
bool HashTable<keyType, valueType>::AddItem(keyType key, valueType val, bool BadHash) {
    int AddIndex = Hash(key, BadHash);
    if (GetItem(key, BadHash) != nullptr){
        return false; 
    }

    if (m_count == m_hash_table.size()){
        return false; 
    }

    if (m_hash_table[AddIndex] == nullptr){
        m_hash_table[AddIndex] = std::make_shared<KVP<keyType, valueType>>(key, val);
        m_count++;
        return true;
    }
    else{
        IncrementCount = 0;
        while ((m_hash_table[AddIndex] != nullptr) && (IncrementCount < m_hash_table.size())) {   
            if (++AddIndex == m_hash_table.size()){
                AddIndex = 0; 
            }

            if(m_hash_table[AddIndex] != nullptr){
            IncrementCount++;
            }
        }

        if (m_hash_table[AddIndex] == nullptr){
            m_hash_table[AddIndex] = std::make_shared<KVP<keyType, valueType>>(key, val);
            m_count++;
            return true;
        }
        else{
            std::cout << "No available slots in table\n";
            return false;
        }
    }
}
//Gets an item from the table using a key
template<class keyType, class valueType>
std::shared_ptr<KVP<keyType, valueType>> HashTable<keyType, valueType>::GetItem(keyType& key, bool BadHash) {
    int Index = Hash(key, BadHash);
    int OriginalIndex = Index;

    while (m_hash_table[Index] != nullptr && m_hash_table[Index]->getKey() != key) {
        Index = (Index + 1) % max_size; // Linear probing
        if(Index == OriginalIndex){
            std::cout << "No key found\n";
            break;
        }
    }  

    if (m_hash_table[Index] != nullptr && m_hash_table[Index]->getKey() == key) {
        return m_hash_table[Index];
    }
    else{
        return nullptr;
    }   
}

//Checks the occupied size of the table
template<class keyType, class valueType>
int HashTable<keyType, valueType>::Contains(){
    return m_count;
}

//Clears the table
template<class keyType, class valueType>
void HashTable<keyType, valueType>::ClearTable() {
    for (auto& Item : m_hash_table) {
        Item.reset(); 
    }
    m_hash_table.clear();
    m_count = 0;
}