#!/usr/bin/python

import re

fileHandler = open("base2", "r")
fileContent = 0

outputHandler = open("base_errno.c", "w");

outputHandler.write("const t_flag g_errno_tab[] = {\n")
while 1:
	fileContent = fileHandler.readline()
	if not fileContent:
		break
	searchObj = re.search(r"([A-Z0-9]+).+", fileContent, re.M|re.I)
	if searchObj:
		outputHandler.write("FLAG({}),\n".format(searchObj.group(1)))
outputHandler.write("};")