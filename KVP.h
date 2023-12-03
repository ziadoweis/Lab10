#pragma once

template<class keyType, class valueType>
class KVP {
public:
    KVP(keyType key, valueType val){
        this->key = key;
        this->value = val;
    }

    valueType getValue(){
        return this->value;
    };
    keyType getKey(){
        return this->key;
    };

private:
    keyType key;
    valueType value;
};