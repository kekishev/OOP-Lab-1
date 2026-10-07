#include <gtest/gtest.h>
#include "array.h"

static void expect_array_eq(const int* arr, std::size_t size, const int* expected) {
    for (std::size_t i = 0; i < size; i++) {
        EXPECT_EQ(arr[i], expected[i]) << "mismatch at index " << i;
    }
} 

TEST(ArrayTest, Create) {
    int* arr = array::array_create(5);
    ASSERT_NE(arr, nullptr);

    int* test_arr = new int[5]{};
    expect_array_eq(const_cast<int *>(arr), std::size_t{5}, const_cast<int *>(test_arr));

    free(arr);
    arr = nullptr;
}

TEST (ArrayTest, CreateArrayWithZeroLength) {
        int* arr = array::array_create(0);
        ASSERT_NE(arr, nullptr);

        free(arr);
        arr = nullptr;
}

TEST(ArrayTest, Delete) {
    int* arr = array::array_create(5);
    array::array_delete(arr);
    EXPECT_EQ(arr, nullptr);
}

TEST(ArrayTest, DeleteNullptrArray) {
    int* arr = nullptr;
    array::array_delete(arr);
    EXPECT_EQ(arr, nullptr);
}

TEST(ArrayTest, Resize) {
    int* arr = array::array_create(5);
    int* old_pointer = arr;
    arr[3] = 100;
    arr[4] = 200;

    arr = array::array_resize(arr, std::size_t{5}, 3);
    
    EXPECT_NE(arr[3], 100);
    EXPECT_NE(arr[4], 200);
    EXPECT_NE(old_pointer, arr);

    array::array_delete(arr);
    old_pointer = nullptr;
}

TEST(ArrayTest, Insert) {
    std::size_t size = 3;
    int* arr = array::array_create(size);
    arr = array::array_insert(arr, size, 2, 100);

    ASSERT_EQ(size, 4);

    int expected[] = {0, 0, 100, 0};
    expect_array_eq(const_cast<int *>(arr), size, const_cast<int *>(expected));

    array::array_delete(arr);
}

TEST(ArrayTest, Remove) {
    std::size_t size = 3;
    int* arr = array::array_create(size);
    arr = array::array_remove(arr, size, 2);

    ASSERT_EQ(size, 2);

    int expected[] = {0, 0};
    expect_array_eq(const_cast<int *>(arr), size, const_cast<int *>(expected));

    array::array_delete(arr);
}

TEST(ArrayTest, BinarySearch) {
    std::size_t size = 3;
    int* arr = array::array_create(size);
    arr = array::array_insert(arr, size, 2, 100);

    std::size_t out_index;
    EXPECT_EQ(array::array_binary_search(arr, size, 100, out_index), true);
    EXPECT_EQ(out_index, 2);

    EXPECT_EQ(array::array_binary_search(arr, size, 85, out_index), false);
    EXPECT_EQ(out_index, 2);
}

TEST(ArrayTest, BubbleSort) {
    std::size_t size = 1;
    int* arr = array::array_create(size);

    arr = array::array_insert(arr, size, 0, 100);
    arr = array::array_insert(arr, size, 1, 502);
    arr = array::array_insert(arr, size, 2, 206);
    arr = array::array_insert(arr, size, 3, 13);

    array::bubblesort(arr, size);

    int expected[] = {0, 13, 100, 206, 502};
    expect_array_eq(const_cast<int *>(expected), size, const_cast<int *>(arr));

    array::array_delete(arr);
}

TEST (ArrayTest, SetValue) {
    std::size_t size = 3;
    int* arr = array::array_create(size);
    array::array_set_value(arr, size, 0, 205);

    EXPECT_EQ(arr[0], 205);
}