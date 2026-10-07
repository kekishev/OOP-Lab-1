#include "array.h"

#include <random>
#include <climits>
#include <cstdlib>
#include <iostream>
#include <stdexcept>

namespace array {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(1, 100);

    int* array_create(std::size_t size) {
        int* arr_created = new int[size]{};

        return arr_created;
    }

    void array_delete(int*& arr) {
        if (arr == nullptr) {
            return;
        }

        delete[] arr;
        arr = nullptr;
    }

    int* array_resize(int* arr, std::size_t size, std::size_t new_size) {
        if (arr == nullptr) {
            return nullptr;
        }

        int* new_array = array_create(new_size);

        for (std::size_t i = 0; i < size && i < new_size; i++) {
            new_array[i] = arr[i];
        }

        array_delete(arr);
        arr = new_array;
        new_array = nullptr;

        return arr;
    }

    int* array_insert(int* arr, std::size_t& size, std::size_t pos, int value) {
        if (arr == nullptr) {
            return arr;
        }

        if (pos >= size) {
            throw std::out_of_range("position is out of range");
        }

        arr = array_resize(arr, size, size + 1);

        int buffer = arr[pos];
        arr[pos] = value;
        
        for (std::size_t i = pos + 1; i < size + 1; i++) {
            value = arr[i];
            arr[i] = buffer;
            buffer = value;
        }

        size++;
        return arr;
    }

    int* array_remove(int* arr, std::size_t& size, std::size_t pos) {
        if (arr == nullptr) {
            return arr;
        }

        if (pos >= size) {
            throw std::out_of_range("position is out of range");
        }

        for (std::size_t i = pos; i <= size - 1; i++) {
            arr[i] = arr[i + 1];
        }

        arr = array_resize(arr, size, size - 1); 

        size--;
        return arr;
    }

    void array_print(const int* arr, std::size_t size) {
        if (arr == nullptr) {
            return;
        }

        std::cout << "[";

        for (std::size_t i = 0; i < size - 1; i++) {
            std::cout << arr[i] << " ";
        }

        std::cout << arr[size - 1] << "]" << std::endl;
    }

    /**
     * @param sorted_array a pointer to an array sorted in ascending order.
     */
    bool array_binary_search(const int* sorted_arr, std::size_t size, int target, std::size_t& out_index) {
        if (sorted_arr == nullptr) {
            return false;
        }

        std::size_t left = 0;
        std::size_t right = size - 1;

        while (left <= right) {
            std::size_t mid = (left + right) / 2;

            if (sorted_arr[mid] == target) {
                out_index = mid;
                return true;
            } else if (sorted_arr[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return false;
    }

    void bubblesort(int* arr, std::size_t size) {
        if (arr == nullptr) {
            return;
        }

        bool is_swapped = true;
        
        while (is_swapped) {
            is_swapped = false;
            for (std::size_t j = 0; j < size - 1;  j++) {
                if (arr[j + 1] < arr[j]) {
                    int buffer = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = buffer;
                    is_swapped = true;
                }
            }
        }
    }

    std::size_t array_unique(int* arr, std::size_t size) {
        if (arr == nullptr) {
            return NULL;
        }

        std::size_t new_size = 0;

        for (std::size_t i = 0; i < size; i++) {
            bool is_duplicate = false;

            for (std::size_t j = 0; j < new_size; j++) {
                if (arr[j] == arr[i]) {
                    is_duplicate = true;
                    break;
                }
            }

            if (!is_duplicate) {
                arr[new_size] = arr[i];
                new_size++;
            }
        }

        arr = array_resize(arr, size, new_size);

        return new_size;
    }

    void array_set_value(int* arr, std::size_t size, std::size_t pos, int new_value) {
        if (arr == nullptr || pos >= size) {
            return;
        }

        arr[pos] = new_value;
    }

    void array_fill_random(int* arr, std::size_t size) {
        if (arr == nullptr) {
            return;
        }

        for (std::size_t i = 0; i < size; i++) {
            arr[i] = dist(gen);
        }
    }
}