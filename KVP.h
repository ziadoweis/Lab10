#pragma once

template<class keyType, class valueType>
class KVP {
public:
    // Constructor that takes in a key and a value
    KVP(keyType key, valueType val){
        this->key = key;
        this->value = val;
    }

    //Get function to return the value
    valueType getValue(){
        return this->value;
    };
    
    //Get function to return the key
    keyType getKey(){
        return this->key;
    };

private:
    keyType key;
    valueType value;
};