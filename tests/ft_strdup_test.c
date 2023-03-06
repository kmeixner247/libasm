#include "../libasm.h"
#include "tests.h"

static void execute_test(char *dir, int mode, char *str, char *(*f_strdup)()) {
	char	*suffix = (mode == FT) ? "_ft" : "_st";
	FILE	*fptr;
	char	*strdup_return;
	char	*path = ft_strjoin(dir, suffix);

	fptr = fopen(path, "w");
	if (!fptr)
		exit(EXIT_FAILURE);
	fprintf(fptr, "str before: %s\n", str);
	strdup_return = f_strdup(str);
	fprintf(fptr, "str after: %s\nreturn: %s\ndiff (should be 0): %d\n", str, strdup_return, strcmp(str, strdup_return));
	fclose(fptr);
	free(path);
	free(strdup_return);
}

static void strdup_test(char *testname, char *str) {
	char *path = ft_strjoin("tests/ft_strdup/", testname);

	execute_test(path, FT, str, &ft_strdup);
	execute_test(path, ST, str, &strdup);

	free(path);
}

void	test_strdup() {
	strdup_test("0_empty_string", "");
	strdup_test("1_one_byte", "a");
	strdup_test("2_6_bytes", "hummus");
	strdup_test("2_a_sentence", "Sometimes I accidentally spit on my monitor when I sneeze");
	strdup_test("4_longer", "The house stood on a slight rise just on the edge of the village. It stood on its own and looked out over a broad spread of West Country farmland. Not a remarkable house by any means—it was about thirty years old, squattish, squarish, made of brick, and had four windows set in the front of a size and proportion which more or less exactly failed to please the eye.\nThe only person for whom the house was in any way special was Arthur Dent, and that was only because it happened to be the one he lived in. He had lived in it for about three years, ever since he had moved out of London because it made him nervous and irritable. He was about thirty as well, tall, dark-haired and never quite at ease with himself. The thing that used to worry him most was the fact that people always used to ask him what he was looking so worried about. He worked in local radio which he always used to tell his friends was a lot more interesting than they probably thought. It was, too—most of his friends worked in advertising.\nOn Wednesday night it had rained very heavily, the lane was wet and muddy, but the Thursday morning sun was bright and clear as it shone on Arthur Dent’s house for what was to be the last time.\nIt hadn’t properly registered yet with Arthur that the council wanted to knock it down and build a bypass instead.\nAt eight o’clock on Thursday morning Arthur didn’t feel very good. He woke up blearily, got up, wandered blearily round his room, opened a window, saw a bulldozer, found his slippers, and stomped off to the bathroom to wash.\nToothpaste on the brush—so. Scrub.\nShaving mirror—pointing at the ceiling. He adjusted it. For a moment it reflected a second bulldozer through the bathroom window. Properly adjusted, it reflected Arthur Dent’s bristles. He shaved them off, washed, dried and stomped off to the kitchen to find something pleasant to put in his mouth.\nKettle, plug, fridge, milk, coffee. Yawn.\nThe word bulldozer wandered through his mind for a moment in search of something to connect with.\nThe bulldozer outside the kitchen window was quite a big one.\nHe stared at it.\n'Yellow,' he thought, and stomped off back to his bedroom to get dressed.");
	char *very_long_string = malloc(sizeof(char) * 1000001);
	memset(very_long_string, 'X', 1000000);
	very_long_string[1000000] = 0;
	strdup_test("5_damn_long", very_long_string);
	free(very_long_string);
}