#include <gtest/gtest.h>
#include "HashTable.h"

TEST(Hash1, InsertingValuesToKeys) {
    HashTable<int, std::string> HashTable(10);
    
    //Initializing the keys
    int firstKey = 34;
    int secondKey = 43;
    int thirdKey = 56;
    int fourtKey = 65;

    //Creating our hash values from the keys
    int val1 = HashTable.Hash(firstKey, false);
    int val2 = HashTable.Hash(secondKey, false);

    //Checking that they're unique
    ASSERT_NE(val1, val2);    
}

TEST(Hash2, VerifyingTheModulusValue) {
    HashTable<int, std::string> HashTable(50);
    
    //Initializing the keys
    int firstKey = 25;
    int secondKey = 97;
    int thirdKey = 42;
    int fourthKey = 73;

    //Creating our hash values from the keys
    int val1 = HashTable.Hash(firstKey, false);
    int val2 = HashTable.Hash(secondKey, false);
    int val3 = HashTable.Hash(thirdKey, false);
    int val4 = HashTable.Hash(fourthKey, false);

    //getting our expected values
    int expectedVal1 = firstKey % 50;
    int expectedVal2 = secondKey % 50;
    int expectedVal3 = thirdKey % 50;
    int expectedVal4 = fourthKey % 50;

    //checking that our hash values match our expectations
    ASSERT_EQ(val1, expectedVal1);
    ASSERT_EQ(val2, expectedVal2);
    ASSERT_EQ(val3, expectedVal3);
    ASSERT_EQ(val4, expectedVal4);
}

TEST(AddItem1, AddingItemsToKeys) {
    HashTable<int, std::string> HashTable(5);
    
    //Initializing the keys
    int firstKey = 123;
    int secondKey = 456;

    //Checking if the items were added successfully
    ASSERT_TRUE(HashTable.AddItem(firstKey, "123", false));
    ASSERT_TRUE(HashTable.AddItem(secondKey, "456", false));

}

TEST(AddItem2, CheckingIfTheHashTableIsFull) {
    HashTable<int, std::string> HashTable(5);
    
    //Initializing the keys
    int firstKey = 123;
    int secondKey = 456;
    int thirdKey = 987;
    int fourthKey = 234;
    int fifthKey = 567;

    //Adding a bunch of items to the table
    HashTable.AddItem(firstKey, "123", false);
    HashTable.AddItem(secondKey, "456", false);
    HashTable.AddItem(thirdKey, "987", false);
    HashTable.AddItem(fourthKey, "234", false);
    HashTable.AddItem(fifthKey, "567", false);

    //Adding a key to a non-existent sixth spot in the table
    int sixthKey = 10;

    //Checking that it's not there (it's not supposed to be)
    ASSERT_FALSE(HashTable.AddItem(sixthKey, "10", false));
}

TEST(GetItem1, GettingItemsFromKeys) {
    HashTable<int, std::string> HashTable(5);
    
    //Initializing the keys
    int firstKey = 123;
    int secondKey = 456;

    //Adding some items
    HashTable.AddItem(firstKey, "123", false);
    HashTable.AddItem(secondKey, "456", false);

    //Checking that we're getting the right values when we try to get those items
    ASSERT_EQ(HashTable.GetItem(firstKey, false)->getValue(), "123");
    ASSERT_EQ(HashTable.GetItem(secondKey, false)->getValue(), "456"); 
}

TEST(GetItem2, GettingItemsThatDontExist) {
    HashTable<int, std::string> HashTable(5);
    
    //Initializing the keys
    int firstKey = 45;
    int secondKey = 67;

    //Adding one time for fun
    HashTable.AddItem(firstKey, "45", false);

    //Checking the case for a wrong key or item value 
    ASSERT_NE(HashTable.GetItem(firstKey, false)->getValue(), "67");
}

TEST(Contains1, HowManyItemsCorrect) {
    HashTable<int, std::string> HashTable(5);
    
    //Initializing the keys
    int firstKey = 123;
    int secondKey = 456;
    int thirdKey = 987;
    int fourthKey = 234;
    int fifthKey = 567;

    //Adding a bunch of items
    HashTable.AddItem(firstKey, "123", false);
    HashTable.AddItem(secondKey, "456", false);
    HashTable.AddItem(thirdKey, "987", false);
    HashTable.AddItem(fourthKey, "234", false);
    HashTable.AddItem(fifthKey, "567", false);

    //Checking that the function returns the right number of items in the table
    ASSERT_EQ(HashTable.Contains(), 5);
}


TEST(Contains2, HowManyItemsWrong) {
    HashTable<int, std::string> HashTable(5);
    
    //Initializing the keys
    int firstKey = 123;
    int secondKey = 456;
    int thirdKey = 987;
    int fourthKey = 234;
    int fifthKey = 567;

    //Adding a bunch of items
    HashTable.AddItem(firstKey, "123", false);
    HashTable.AddItem(secondKey, "456", false);
    HashTable.AddItem(thirdKey, "987", false);
    HashTable.AddItem(fourthKey, "234", false);

    //Checking that the function returns the wrong number of items in the table
    ASSERT_NE(HashTable.Contains(), 5);

    //Adding one more item to test the correct number
    HashTable.AddItem(fifthKey, "567", false);

    //Checking that the function returns the right number of items in the table
    ASSERT_EQ(HashTable.Contains(), 5);
}

TEST(ClearTable1, ClearingTableFull) {
    HashTable<int, std::string> HashTable(5);
    
    //Initializing the keys
    int firstKey = 123;
    int secondKey = 456;
    int thirdKey = 987;
    int fourthKey = 234;
    int fifthKey = 567;

    //Adding a bunch of items
    HashTable.AddItem(firstKey, "123", false);
    HashTable.AddItem(secondKey, "456", false);
    HashTable.AddItem(thirdKey, "987", false);
    HashTable.AddItem(fourthKey, "234", false);

    //Checking that the function returns the right number of items in the table
    ASSERT_EQ(HashTable.Contains(), 4);
    
    //Clearing the number, thus reverting the number of items to 0
    HashTable.ClearTable();

    //Checking that the number of items is in fact now 0
    ASSERT_EQ(HashTable.Contains(), 0);
}

TEST(ClearTable2, ClearingTableEmpty) {
    HashTable<int, std::string> HashTable(5);

    //Clearing an already empty table
    HashTable.ClearTable();
    
    //Checking that the number of items is still 0
    ASSERT_EQ(HashTable.Contains(), 0);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}