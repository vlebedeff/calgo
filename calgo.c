#include <stdio.h>

#include "minunit.h"
#include "gcd.h"
#include "list.h"

int mu_tests_run = 0;

static char * test_gcd() {
    mu_assert("GCD(36, 24) should equal to 12", gcd(36, 24) == 12);
    mu_assert("GCD(100, 300) should equal to 100", gcd(100, 300) == 100);
    mu_assert("GCD(12, 8, 16) should equal to 4", gcd(12, gcd(8, 16)) == 4);
    return 0;
}

static char * test_list_init() {
    List *list = List_init();
    mu_assert("New List count should be 0", list->count == 0);
    mu_assert("New List's head & tail should be the same", list->head == list->tail);
    return 0;
}

static char * test_list_unshift() {
    List *list = List_init();
    List_unshift(list, 'A');
    List_unshift(list, 'B');
    mu_assert("The first element should be A", *(list->head->data) == 'A');
    mu_assert("The second element should be B", *(list->head->next->data) == 'B');
    mu_assert("The last element should be B", *(list->tail->data) == 'B');
    mu_assert("The list has total of two elements", list->head->next == list->tail && list->count == 2);
    return 0;
}

static char * test_list_push() {
    List *list = List_init();
    List_push(list, 'A');
    return 0;
}

static char * all_tests() {
    mu_run_test(test_gcd);
    mu_run_test(test_list_init);
    mu_run_test(test_list_unshift);
    return 0;
}

int main() {
    char * result = all_tests();
    if (result != 0) {
        printf("\033[31m%s\n\033[0m", result);
    } else {
        printf("\033[32mALL TESTS PASSED\n\033[0m");
    }
    printf("Tests run: %d\n", mu_tests_run);
    return result != 0;
}
