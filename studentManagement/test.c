#include <CUnit/Basic.h>
#include "hash_map_with_binary_tree.c" // include your source file

void test_find() {
    Node* root = NULL;
    root = insert(root, "John", "john@example.com");
    root = insert(root, "Jane", "jane@example.com");
    root = insert(root, "Bob", "bob@example.com");

    Node* john = find(root, "John");
    CU_ASSERT_PTR_NOT_NULL(john);
    CU_ASSERT_STRING_EQUAL(john->name, "John");
    CU_ASSERT_STRING_EQUAL(john->email, "john@example.com");

    Node* not_found = find(root, "Alice");
    CU_ASSERT_PTR_NULL(not_found);
}

void test_findMin() {
    Node* root = NULL;
    root = insert(root, "John", "john@example.com");
    root = insert(root, "Jane", "jane@example.com");
    root = insert(root, "Bob", "bob@example.com");

    Node* min = findMin(root);
    CU_ASSERT_PTR_NOT_NULL(min);
    CU_ASSERT_STRING_EQUAL(min->name, "Bob");
}

int main() {
    CU_initialize_registry();

    CU_pSuite suite = CU_add_suite("hash_map_with_binary_tree_test", 0, 0);
    CU_add_test(suite, "test_find", test_find);
    CU_add_test(suite, "test_findMin", test_findMin);

    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();

    return 0;
}