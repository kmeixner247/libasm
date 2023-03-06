#include "libasm.h"
#include "tests/tests.h"
#include "bonus_tests/bonus_tests.h"

int main(void)
{
	test_strlen();
	test_strcmp();
	test_strcpy();
	test_read();
	test_write();
	test_strdup();

	test_atoi_base();
	test_list_push_front();
	test_list_size();
	test_list_sort();
	test_list_remove_if();
	return 0;
}