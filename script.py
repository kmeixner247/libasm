from os import walk
import filecmp

dirs = next(walk('tests'))[1]
for dir in dirs:
	filenames = next(walk("tests/"+ dir), (None, None, []))[2]  # [] if no file
	filenames = [file[:-3] for file in filenames]
	del filenames[::2]

	lol = "\u001b[35;1m" + dir + "\u001b[0m: "
	for file in filenames:
		f1 = "tests/" + dir + "/" + file + "_ft"
		f2 = "tests/" + dir + "/" + file + "_st"
		lol += str(filenames.index(file) + 1) + ": "
		result = filecmp.cmp(f1, f2)
		if result :
			out = "\u001b[32mOK\u001b[0m"
		else :
			out = "\u001b[31mKO\u001b[0m"
		lol += out + " "
	print(lol)
