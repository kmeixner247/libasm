#include "libasm.h"
#include "tests/tests.h"

int main(void)
{
	test_strlen();
	test_strcmp();
	test_strcpy();
	test_read();
	test_write();
	test_strdup();
	return 0;
}