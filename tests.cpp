#include <gtest/gtest.h>
#include "HashTable.h"

TEST(HashTableTests, Hash1) {
    HashTable<int, std::string> hashTable(10);
    
    int firstKey = 34;
    int secondKey = 43;

    int val1 = hashTable.Hash(firstKey, false);
    int val2 = hashTable.Hash(secondKey, false);

    ASSERT_NE(val1, val2);    
}

TEST(HashTableTests, Hash2) {
    HashTable<int, std::string> hashTable(100);
    
    int firstKey = 254;
    int secondKey = 976;

    int val1 = hashTable.Hash(firstKey, false);
    int val2 = hashTable.Hash(secondKey, false);

    int expectedVal1 = firstKey % 100;
    int expectedVal2 = secondKey % 100;

    ASSERT_EQ(val1, expectedVal1);
    ASSERT_EQ(val2, expectedVal2);   
}

TEST(HashTableTests, AddEntry1) {
    HashTable<int, std::string> hashTable(5);
    
    int firstKey = 123;
    int secondKey = 456;

    hashTable.AddEntry(firstKey, "123", false);
    hashTable.AddEntry(secondKey, "456", false);

    ASSERT_EQ(hashTable.Contains(), 2);
    ASSERT_EQ(hashTable.GetEntry(firstKey, false)->getValue(), "123");
    ASSERT_EQ(hashTable.GetEntry(secondKey, false)->getValue(), "456"); 
}


int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}