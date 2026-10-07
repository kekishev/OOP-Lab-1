#pragma once
#include <cstddef>

namespace array {

int* array_create(std::size_t size);

void array_delete(int*& arr);

int* array_resize(int* arr, std::size_t size, std::size_t new_size);

int* array_insert(int* arr, std::size_t& size, std::size_t pos, int value);

int* array_remove(int* arr, std::size_t& size, std::size_t pos);

void array_print(const int* arr, std::size_t size);

bool array_binary_search(const int* array, std::size_t size, int target, std::size_t& out_index);

void bubblesort(int* arr, std::size_t size);

 /**
  * Deletes all duplicates in the provided array.
  * 
  * @return the number of unique elements in the provided array.
  */
std::size_t array_unique(int* arr, std::size_t size);

void array_set_value(int* arr, std::size_t size, std::size_t pos, int new_value);

void array_fill_random(int* arr, std::size_t size);

}