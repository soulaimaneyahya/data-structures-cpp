#include <iostream>
#include <map>
#include <string>

using namespace std;

/**
 * @class MemTable
 */
class MemTable
{
public:
    /**
     * @brief Insert a key-value pair into the MemTable
     * 
     * @param  string key
     * @param  string value
     * @param  int64_t timestamp
     * @return void
     */
    void insert(const string &key, const string &value, const int64_t &timestamp)
    {
        memTable[key] = to_string(timestamp) + ":" + value;
    }

    /**
     * @brief Check if a key exists in the MemTable
     * 
     * @param  string key 
     * @return bool
     */
    bool exists(const string &key)
    {
        return memTable.find(key) != memTable.end();
    }

    /**
     * @brief Retrieve a value by key
     * 
     * @param  string key 
     * @return string
     */
    string get(const string &key)
    {
        if (exists(key))
        {
            return memTable[key];
        }

        return ""; // or throw error if key doesn't exist
    }

    /**
     * @brief Print all keys in sorted order (as in an ordered map)
     * 
     * @return void
     */
    void print()
    {
        for (const auto &entry : memTable)
        {
            cout << entry.first << " => " << entry.second << endl;
        }
    }

    /**
     * @brief Simulate flushing to SSTable (by dumping current MemTable to disk)
     * 
     * @return void
     */
    void flushToSSTable()
    {
        // In real-world, this would write to a file or database storage.
        // For simplicity, we'll just clear the MemTable after flushing.
        memTable.clear();
    }

private:
    /**
     * @brief Sorted data structure (red-black tree)
     * 
     * @var map<string, string> memTable
     */
    map<string, string> memTable;
};

int main()
{
    /**
     * @brief MemTable object
     * 
     * @var MemTable mem
     */
    MemTable mem;

    // Insert key-value pairs
    mem.insert("user_001", "Alice", 1704067200);
    mem.insert("user_003", "Bob", 1704153600);
    mem.insert("user_005", "Charlie", 1704240000);

    // Access and print data
    cout << "Accessing and printing data:" << endl;
    cout << "user_001: " << mem.get("user_001") << endl;

    // Print all keys in sorted order
    cout << "Printing all keys in sorted order:" << endl;
    mem.print();

    // Simulate MemTable flush to SSTable
    cout << "Flushing MemTable to SSTable..." << endl;
    mem.flushToSSTable();

    return 0;
}
