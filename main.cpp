#include "HashTable.h"
#include <ctime>
#include <chrono>
#include <string>
#include <unordered_set> // Makes it so that we can only have unique objects, so we do not allow duplicates
using namespace std;

using Clock = chrono::high_resolution_clock;

vector<int> NumGen(int Items){ // Creates a vector of numbers that keeps track to numbers to have a completetly uniqie set of vector to be returned to be used for the tasks
    unordered_set<int> UniqueItems;
    vector<int> ItemGen;
    
    while (ItemGen.size() < Items){
        int value = rand() % (2 * Items);
    // Compares the values to see if there is only one copy in the unique vector
        if (UniqueItems.find(value) == UniqueItems.end()){
            UniqueItems.insert(value);
            ItemGen.push_back(value);
        }
    }
    return ItemGen;
}

int main() {
    srand((unsigned) time(NULL)); //Sets the seed of the number generator to current time
    vector<int> TestValuesTask3 = NumGen(5000);
    vector<int> TestValuesTask4 = NumGen(25000);
    int TestHashTime;
    // Task 3 for adding 500, 1000, 2000, and 5000 random items with Hash Table sized to hold 150% of max numbers
    //Hash Table 
    HashTable<int, string> HashTable500(750);
    HashTable<int, string> HashTable1000(1500);
    HashTable<int, string> HashTable2000(3000);
    HashTable<int, string> HashTable5000(7500);

    cout << "Task 3: \n";
    // Adding 500 Items
    auto t1 = Clock::now();
    for(int i = 0; i < 500; i++)
    {
        HashTable500.AddItem(TestValuesTask3[i], to_string(TestValuesTask3[i]), false);
    }
    auto t2 = Clock::now();
    TestHashTime = std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count();
    cout << "Hash Time for Adding 500 Random Items: " << TestHashTime << " microseconds" << endl;

    // Adding 1000 Items
    t1 = Clock::now();
    for(int i = 0; i < 1000; i++)
    {
        HashTable1000.AddItem(TestValuesTask3[i], to_string(TestValuesTask3[i]), false);
    }
    t2 = Clock::now();
    TestHashTime = std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count();
    cout << "Hash Time for Adding 1000 Random Items: " << TestHashTime << " microseconds" << endl;

    // Adding 2000 Items
    t1 = Clock::now();
    for(int i = 0; i < 2000; i++)
    {
        HashTable2000.AddItem(TestValuesTask3[i], to_string(TestValuesTask3[i]), false);
    }

    t2 = Clock::now();
    TestHashTime = std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count();
    cout << "Hash Time for Adding 2000 Random Items: " << TestHashTime << " microseconds" << endl;

    // Adding 5000 Items
    t1 = Clock::now();
    for(int i = 0; i < 5000; i++)
    {
        HashTable5000.AddItem(TestValuesTask3[i], to_string(TestValuesTask3[i]), false);
    }

    t2 = Clock::now();
    TestHashTime = std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count();
    cout << "Hash Time for Adding 5000 Random Items: " << TestHashTime << " microseconds" << endl;

     // Task 4
    cout << "\nTask 4: \n";

    // HashTable Size to fit 100%, 200%, 500% for adding 500, 1000, 2000, and 5000 random items (HashTable___(Amount of Items)T_(Task Number)___(Percent of Max Items))
    HashTable<int, string> HashTable500T4100(500);
    HashTable<int, string> HashTable1000T4100(1000);
    HashTable<int, string> HashTable2000T4100(2000);
    HashTable<int, string> HashTable5000T4100(5000);
    
    HashTable<int, string> HashTable500T4200(1000);
    HashTable<int, string> HashTable1000T4200(2000);
    HashTable<int, string> HashTable2000T4200(4000);
    HashTable<int, string> HashTable5000T4200(10000);

    HashTable<int, string> HashTable500T4500(2500);
    HashTable<int, string> HashTable1000T4500(5000);
    HashTable<int, string> HashTable2000T4500(10000);
    HashTable<int, string> HashTable5000T4500(25000);
    // Adding 500 Items at 100% of max numbers
    
    t1 = Clock::now();
    for(int i = 0; i < 500; i++)
    {
        HashTable500T4100.AddItem(TestValuesTask4[i], to_string(TestValuesTask4[i]), false);
    }

    t2 = Clock::now();
    TestHashTime = chrono::duration_cast<chrono::microseconds>(t2 - t1).count();
    cout << "Hash Time for Adding 500 Random Items at 100%: " << TestHashTime << " microseconds" << endl;
    
    // Adding 500 Items at 200% of max numbers
    t1 = Clock::now();
    for(int i = 0; i < 1000; i++)
    {
        HashTable500T4200.AddItem(TestValuesTask4[i], to_string(TestValuesTask4[i]), false);
    }

    t2 = Clock::now();
    TestHashTime = chrono::duration_cast<chrono::microseconds>(t2 - t1).count();
    cout << "Hash Time for Adding 500 Random Items at 200%: " << TestHashTime << " microseconds" << endl;
    
    // Adding 500 Items at 500% of max numbers
    t1 = Clock::now();
    for(int i = 0; i < 2500; i++)
    {
        HashTable500T4500.AddItem(TestValuesTask4[i], to_string(TestValuesTask4[i]), false);
    }

    t2 = Clock::now();
    TestHashTime = chrono::duration_cast<chrono::microseconds>(t2 - t1).count();
    cout << "Hash Time for Adding 500 Random Items at 500%: " << TestHashTime << " microseconds\n" << endl;

    // Adding 1000 Items at 100% of max numbers
    t1 = Clock::now();
    for(int i = 0; i < 1000; i++)
    {
        HashTable1000T4100.AddItem(TestValuesTask4[i], to_string(TestValuesTask4[i]), false);
    }

    t2 = Clock::now();
    TestHashTime = chrono::duration_cast<chrono::microseconds>(t2 - t1).count();
    cout << "Hash Time for Adding 1000 Random Items at 100%: " << TestHashTime << " microseconds" << endl;
    
    // Adding 1000 Items at 200% of max numbers
    t1 = Clock::now();
    for(int i = 0; i < 2000; i++)
    {
        HashTable1000T4200.AddItem(TestValuesTask4[i], to_string(TestValuesTask4[i]), false);
    }

    t2 = Clock::now();
    TestHashTime = chrono::duration_cast<chrono::microseconds>(t2 - t1).count();
    cout << "Hash Time for Adding 1000 Random Items at 200%: " << TestHashTime << " microseconds" << endl;
    
    // Adding 1000 Items at 500% of max numbers
    t1 = Clock::now();
    for(int i = 0; i < 5000; i++)
    {
        HashTable1000T4500.AddItem(TestValuesTask4[i], to_string(TestValuesTask4[i]), false);
    }
    t2 = Clock::now();
    TestHashTime = chrono::duration_cast<chrono::microseconds>(t2 - t1).count();
    cout << "Hash Time for Adding 1000 Random Items at 500: " << TestHashTime << " microseconds\n" << endl;

    // Adding 2000 Items at 100% of max numbers
    t1 = Clock::now();
    for(int i = 0; i < 2000; i++)
    {
        HashTable2000T4100.AddItem(TestValuesTask4[i], to_string(TestValuesTask4[i]), false);
    }

    t2 = Clock::now();
    TestHashTime = chrono::duration_cast<chrono::microseconds>(t2 - t1).count();
    cout << "Hash Time for Adding 2000 Random Items at 100%: " << TestHashTime << " microseconds" << endl;
    
    // Adding 2000 Items at 200% of max numbers
    t1 = Clock::now();
    for(int i = 0; i < 4000; i++)
    {
        HashTable2000T4200.AddItem(TestValuesTask4[i], to_string(TestValuesTask4[i]), false);
    }
    t2 = Clock::now();
    TestHashTime = chrono::duration_cast<chrono::microseconds>(t2 - t1).count();
    cout << "Hash Time for Adding 2000 Random Items at 200%: " << TestHashTime << " microseconds" << endl;
    
    // Adding 2000 Items at 500% of max numbers
    t1 = Clock::now();
    for(int i = 0; i < 10000; i++)
    {
        HashTable2000T4500.AddItem(TestValuesTask4[i], to_string(TestValuesTask4[i]), false);
    }

    t2 = Clock::now();
    TestHashTime = chrono::duration_cast<chrono::microseconds>(t2 - t1).count();
    cout << "Hash Time for Adding 2000 Random Items at 500%: " << TestHashTime << " microseconds\n" << endl;

    //Adding 5000 Items at 100% of max numbers
    t1 = Clock::now();
    for(int i = 0; i < 5000; i++)
    {
        HashTable5000T4100.AddItem(TestValuesTask4[i], to_string(TestValuesTask4[i]), false);
    }

    t2 = Clock::now();
    TestHashTime = chrono::duration_cast<chrono::microseconds>(t2 - t1).count();
    cout << "Hash Time for Adding 5000 Random Items at 100%: " << TestHashTime << " microseconds" << endl;
    
    // IAdding 5000 Items at 200% of max numbers
    t1 = Clock::now();
    for(int i = 0; i < 10000; i++)
    {
        HashTable5000T4200.AddItem(TestValuesTask4[i], to_string(TestValuesTask4[i]), false);
    }
    t2 = Clock::now();
    TestHashTime = chrono::duration_cast<chrono::microseconds>(t2 - t1).count();
    cout << "Hash Time for Adding 5000 Random Items at 200%: " << TestHashTime << " microseconds" << endl;
    
    // Adding 5000 Items at 500% of max numbers
    t1 = Clock::now();
    for(int i = 0; i < 25000; i++)
    {
        HashTable5000T4500.AddItem(TestValuesTask4[i], to_string(TestValuesTask4[i]), false);
    }

    t2 = Clock::now();
    TestHashTime = chrono::duration_cast<chrono::microseconds>(t2 - t1).count();
    cout << "Hash Time for Adding 5000 Random Items at 500%: " << TestHashTime << " microseconds\n" << endl;

    cout << "Task 5: \n";
    // Clears the hash table from Task 3 to be re-used
    HashTable500.ClearTable();
    HashTable1000.ClearTable();
    HashTable2000.ClearTable();
    HashTable5000.ClearTable();

    //Adding 500 Items with bad hash at 150% max items
    t1 = Clock::now();
    for(int i = 0; i < 500; i++)
    {
        HashTable500.AddItem(TestValuesTask3[i], to_string(TestValuesTask3[i]), true);
    }

    
    t2 = Clock::now();
    TestHashTime = chrono::duration_cast<chrono::microseconds>(t2 - t1).count();
    cout << "Hash Time for Adding 500 Random Items with a Bad Hash Function: " << TestHashTime << " microseconds" << endl;

    // Adding 1000 Items with bad hash
    t1 = Clock::now();
    for(int i = 0; i < 1000; i++)
    {
        HashTable1000.AddItem(TestValuesTask3[i], to_string(TestValuesTask3[i]), true);
    }

    t2 = Clock::now();
    TestHashTime = chrono::duration_cast<chrono::microseconds>(t2 - t1).count();
    cout << "Hash Time for Adding 1000 Random Items with a Bad Hash Function: " << TestHashTime << " microseconds" << endl;

    // Adding 2000 Items with bad hash
    t1 = Clock::now();
    for(int i = 0; i < 2000; i++)
    {
        HashTable2000.AddItem(TestValuesTask3[i], to_string(TestValuesTask3[i]), true);
    }

    t2 = Clock::now();
    TestHashTime = chrono::duration_cast<chrono::microseconds>(t2 - t1).count();
    cout << "Hash Time for Adding 2000 Random Items with a Bad Hash Function: " << TestHashTime << " microseconds" << endl;

    // Adding 5000 Items with bad hash
    t1 = Clock::now();
    for(int i = 0; i < 5000; i++)
    {
        HashTable5000.AddItem(TestValuesTask3[i], to_string(TestValuesTask3[i]), true);
    }

    t2 = Clock::now();
    TestHashTime = chrono::duration_cast<chrono::microseconds>(t2 - t1).count();
    cout << "Hash Time for Adding 5000 Random Items with a Bad Hash Function: " << TestHashTime << " microseconds" << endl;

    return 0;
}