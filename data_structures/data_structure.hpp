

#include <array>     /// for std::array
#include <cassert>   /// for assert
#include <iostream>  /// for io operations


namespace data_structures {

template <typename T>
class list_array {
public:
    list_array() = default;

    /**
     * @brief Insert the new element in the list
     * @param val element that will be inserted
     * @returns void
     */
    void insert(const T val);

    /**
     * @brief To remove the element from the list
     * @param val element that will be removed
     * @returns void
     */
    void remove(const T val);

    /**
     * @brief Utility function to print array
     * @returns void
     */
    void print_list();

    /*
     * @brief Parent function of binarySearch and linearSearch methods
     * @param val element that will be searched
     * @return index of element in the list if present else -1
     */
    int search(const T val);

    /**
     * @brief Search an element in the list using binarySearch.
     * @param first pointer to the first element in the remaining list
     * @param last pointer to the last element in the remaining list
     * @param val element that will be searched
     * @return index of element in the list if present else -1
     */
    int BinarySearch(const int first, const int last, const T val);

    /**
     * @brief Search an element using linear search
     * @param val element that will be searched
     * @return index of element in the list if present else -1
     */
    int LinearSearch(const T val);

    /**
     * @brief Sort the list
     * @returns void
     */
    void sort();

    /**
    * @brief Get top element
    * @returns top element
    */
    T size() { return top; }

    /**
    * @brief Get whether list is sorted or not
    * @returns bool
    */
    bool isSortedList() { return isSorted; }

private:
    std::array<T, 50> data;
    uint64_t top = 0;
    bool isSorted = false;
}; // class list_array


} // namespace data_structures