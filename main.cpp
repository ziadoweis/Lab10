#include "HashTable.h"
#include <ctime>
#include <chrono>
#include <string>
#include <thread>
#include <unordered_set> // Makes it so that we can only have unique objects, so we do not allow duplicates
using Clock = std::chrono::high_resolution_clock;
std::vector<int> NumGen(int Items){
    std::vector<int> ItemGen;
    std::unordered_set<int> UniqueItems; // To track unique values
    while (ItemGen.size() < Items){
        int value = rand() % (2 * Items);
        if (UniqueItems.find(value) == UniqueItems.end()){
            // If the number is not already in the set, add it to the vector and set
            UniqueItems.insert(value);
            ItemGen.push_back(value);
        }
    }
    return ItemGen;
}

int main() {
    srand((unsigned) time(NULL)); //Sets the seed of the number generator to current time
    return 0;
}