#include <gtest/gtest.h>
#include "HashTable.h"

<<<<<<< HEAD
TEST(HashTableTest1, Hash1) {
=======
TEST(Hash1, InsertingValuesToKeys) {
>>>>>>> 4b1696ae630d4806bfa6c30851b766be3b507769
    HashTable<int, std::string> HashTable(10);
    
    int firstKey = 34;
    int secondKey = 43;
    int thirdKey = 56;
    int fourtKey = 65;

    int val1 = HashTable.Hash(firstKey, false);
    int val2 = HashTable.Hash(secondKey, false);

    ASSERT_NE(val1, val2);    
}

<<<<<<< HEAD
TEST(HashTableTest2, Hash2) {
    HashTable<int, std::string> HashTable(100);
=======
TEST(Hash2, VerifyingTheModulusValue) {
    HashTable<int, std::string> HashTable(50);
>>>>>>> 4b1696ae630d4806bfa6c30851b766be3b507769
    
    int firstKey = 25;
    int secondKey = 97;
    int thirdKey = 42;
    int fourthKey = 73;

    int val1 = HashTable.Hash(firstKey, false);
    int val2 = HashTable.Hash(secondKey, false);
    int val3 = HashTable.Hash(thirdKey, false);
    int val4 = HashTable.Hash(fourthKey, false);

    int expectedVal1 = firstKey % 50;
    int expectedVal2 = secondKey % 50;
    int expectedVal3 = thirdKey % 50;
    int expectedVal4 = fourthKey % 50;

    ASSERT_EQ(val1, expectedVal1);
    ASSERT_EQ(val2, expectedVal2);
    ASSERT_EQ(val3, expectedVal3);
    ASSERT_EQ(val4, expectedVal4);
}

TEST(AddItem1, AddingItemsToKeys) {
    HashTable<int, std::string> HashTable(5);
    
    int firstKey = 123;
    int secondKey = 456;

    ASSERT_TRUE(HashTable.AddItem(firstKey, "123"));
    ASSERT_TRUE(HashTable.AddItem(secondKey, "456"));

}

TEST(AddItem2, CheckingIfTheHashTableIsFull) {
    HashTable<int, std::string> HashTable(5);
    
    int firstKey = 123;
    int secondKey = 456;
    int thirdKey = 987;
    int fourthKey = 234;
    int fifthKey = 567;

    HashTable.AddItem(firstKey, "123");
    HashTable.AddItem(secondKey, "456");
    HashTable.AddItem(thirdKey, "987");
    HashTable.AddItem(fourthKey, "234");
    HashTable.AddItem(fifthKey, "567");

    int sixthKey = 10;

    ASSERT_FALSE(HashTable.AddItem(sixthKey, "10"));
}

TEST(GetItem1, GettingItemsFromKeys) {
    HashTable<int, std::string> HashTable(5);
    
    int firstKey = 123;
    int secondKey = 456;

    HashTable.AddItem(firstKey, "123");
    HashTable.AddItem(secondKey, "456");

    ASSERT_EQ(HashTable.GetItem(firstKey)->getValue(), "123");
    ASSERT_EQ(HashTable.GetItem(secondKey)->getValue(), "456"); 
}

TEST(GetItem2, GettingItemsThatDontExist) {
    HashTable<int, std::string> HashTable(5);
    
    int firstKey = 45;
    int secondKey = 67;

    HashTable.AddItem(firstKey, "45");

    ASSERT_NE(HashTable.GetItem(firstKey)->getValue(), "67");
}

TEST(Contains1, HowManyItemsCorrect) {
    HashTable<int, std::string> HashTable(5);
    
    int firstKey = 123;
    int secondKey = 456;
    int thirdKey = 987;
    int fourthKey = 234;
    int fifthKey = 567;

    HashTable.AddItem(firstKey, "123");
    HashTable.AddItem(secondKey, "456");
    HashTable.AddItem(thirdKey, "987");
    HashTable.AddItem(fourthKey, "234");
    HashTable.AddItem(fifthKey, "567");

    ASSERT_EQ(HashTable.Contains(), 5);
}


TEST(Contains2, HowManyItemsWrong) {
    HashTable<int, std::string> HashTable(5);
    
    int firstKey = 123;
    int secondKey = 456;
    int thirdKey = 987;
    int fourthKey = 234;
    int fifthKey = 567;

    HashTable.AddItem(firstKey, "123");
    HashTable.AddItem(secondKey, "456");
    HashTable.AddItem(thirdKey, "987");
    HashTable.AddItem(fourthKey, "234");

    ASSERT_NE(HashTable.Contains(), 5);

    HashTable.AddItem(fifthKey, "567");

    ASSERT_EQ(HashTable.Contains(), 5);
}

TEST(ClearTable1, ClearingTableFull) {
    HashTable<int, std::string> HashTable(5);
    
    int firstKey = 123;
    int secondKey = 456;
    int thirdKey = 987;
    int fourthKey = 234;
    int fifthKey = 567;

    HashTable.AddItem(firstKey, "123");
    HashTable.AddItem(secondKey, "456");
    HashTable.AddItem(thirdKey, "987");
    HashTable.AddItem(fourthKey, "234");

    ASSERT_EQ(HashTable.Contains(), 4);

    HashTable.ClearTable();

    ASSERT_EQ(HashTable.Contains(), 0);
}

TEST(ClearTable2, ClearingTableEmpty) {
    HashTable<int, std::string> HashTable(5);

    HashTable.ClearTable();
    ASSERT_EQ(HashTable.Contains(), 0);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}