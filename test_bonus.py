from os import walk
import filecmp

bdirs = next(walk('bonus_tests'))[1]
for dir in bdirs:
	filenames = next(walk("bonus_tests/"+ dir), (None, None, []))[2]  # [] if no file
	filenames = [file[:-3] for file in filenames]
	del filenames[::2]
	lol = "\u001b[35;1m" + dir + "\u001b[0m: "
	for file in filenames:
		f1 = "bonus_tests/" + dir + "/" + file + "_st"
		f2 = "bonus_tests/" + dir + "/" + file + "_ft"
		lol += str(filenames.index(file) + 1) + ": "
		filecmp.clear_cache()
		result = filecmp.cmp(f1, f2, shallow=False)
		if result :
			out = "\u001b[32mOK\u001b[0m"
		else :
			out = "\u001b[31mKO\u001b[0m"
		lol += out + " "
	lol = lol[:-1]
	print(lol)
