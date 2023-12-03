#include <gtest/gtest.h>
#include "HashTable.h"

TEST(HashTableTests, Hash1) {
    HashTable<int, std::string> HashTable(10);
    
    int firstKey = 34;
    int secondKey = 43;

    int val1 = HashTable.Hash(firstKey, false);
    int val2 = HashTable.Hash(secondKey, false);

    ASSERT_NE(val1, val2);    
}

TEST(HashTableTests, Hash2) {
    HashTable<int, std::string> HashTable(100);
    
    int firstKey = 254;
    int secondKey = 976;

    int val1 = HashTable.Hash(firstKey, false);
    int val2 = HashTable.Hash(secondKey, false);

    int expectedVal1 = firstKey % 100;
    int expectedVal2 = secondKey % 100;

    ASSERT_EQ(val1, expectedVal1);
    ASSERT_EQ(val2, expectedVal2);   
}

TEST(HashTableTests, AddItem1) {
    HashTable<int, std::string> HashTable(5);
    
    int firstKey = 123;
    int secondKey = 456;

    HashTable.AddItem(firstKey, "123");
    HashTable.AddItem(secondKey, "456");

    ASSERT_EQ(HashTable.Contains(), 2);
    ASSERT_EQ(HashTable.GetItem(firstKey)->getValue(), "123");
    ASSERT_EQ(HashTable.GetItem(secondKey)->getValue(), "456"); 
}


int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}