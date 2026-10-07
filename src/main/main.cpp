#include <iostream>
#include <array.h>

void print_menu() {
    std::cout << " ------MENU------"                     << std::endl;
    std::cout << "0. print menu"                         << std::endl;
    std::cout << "1. create an array"                    << std::endl;
    std::cout << "2. delete an array"                    << std::endl;
    std::cout << "3. resize"                             << std::endl;
    std::cout << "4. insert"                             << std::endl;
    std::cout << "5. remove"                             << std::endl;
    std::cout << "6. print an array"                     << std::endl; 
    std::cout << "7. binary search"                      << std::endl;
    std::cout << "8. bubblesort"                         << std::endl;
    std::cout << "9. array_unique"                       << std::endl;
    std::cout << "10. array set value"                   << std::endl;
    std::cout << "11. fill up array with random numbers" << std::endl;
    std::cout << "12. exit"                              << std::endl;
}

int main() {
    int option = 0;

    int* arr = nullptr;
    std::size_t size = 0;

    while (option != 12) {
        switch (option) {
            case 0: {
                print_menu();
                break;
            } case 1: {
                std::cout << "Enter a size" << std::endl;
                std::cin >> std::dec >> size;

                arr = array::array_create(size);
                break;
            } case 2: {
                array::array_delete(arr);   
                break;
            } case 3: {
                std::size_t new_size;

                std::cout << "Enter a new size" << std::endl;
                std::cin >> std::dec >> new_size;

                arr = array::array_resize(arr, size, new_size);
                size = new_size;

                break;
            } case 4: {
                std::size_t pos;
                int value;

                std::cout << "Enter the positiion to insert" << std::endl;
                std::cin >> std::dec >> pos;

                std::cout << "Enter the value" << std::endl;
                std::cin >> std::dec >> value;

                arr = array::array_insert(arr, size, pos, value);

                break;
            } case 5: {
                std::size_t position;

                std::cout << "Enter the position to delete" << std::endl;
                std::cin >> position;

                arr = array::array_remove(arr, size, position);

                break;
            } case 6: {
                array::array_print(arr, size);
                break;
            } case 7: {
                int target;

                std::cout << "Enter a target to search" << std::endl;
                std::cin >> std::dec >> target;

                std::size_t found_pos;
                bool is_found = array::array_binary_search(arr, size, target, found_pos);

                if (is_found) {
                    std::cout << "Target is found; position=" << found_pos << std::endl;
                } else {
                    std::cout << "Target is not found" << std::endl;
                }
            
                break;
            } case 8: {
                array::bubblesort(arr, size);
                break;
            } case 9: {
                size = array::array_unique(arr, size);
                std::cout << "Number of unique elements equals " << size << std::endl;
                break;
            } case 10: {
                std::size_t pos;
                int new_value;

                std::cout << "Enter a position to set" << std::endl;
                std::cin >> pos;

                std::cout << "Enter a new value to set" << std::endl;
                std::cin >> new_value;

                array::array_set_value(arr, size, pos, new_value);
                break;
            } case 11: {
                array::array_fill_random(arr, size);
                break;
            } default: {
                std::cout << "unknown command" << std::endl;
                break;
            }
        }

        std::cout << "Enter the number of a command" << std::endl;
        std::cin >> std::dec >> option;
    }

    array::array_delete(arr);
    return 0;
}