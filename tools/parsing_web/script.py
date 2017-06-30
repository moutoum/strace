#!/usr/bin/python

import re

file = open("syscall_tab.c", "w")
file.write("#include <syscall.h>\n#include \"strace.h\"\n\nt_syscall g_syscall_tab[] = {\n")

pattern = re.compile(r'<tr class=\"tbls-entry-collapsed\"><td>(\d+)</td><td>(\w+)</td><td>(\w+)</td><td><a href=\"\S+\">[^<]+</a></td></tr>(?:<tr class=\"tbls-arguments-collapsed\"><td colspan=\"(\d)\"><table><tbody><tr>((?:<td>.{0,10}</td>)*)</tr><tr>((?:<td><strong>[A-Za-z _*0-9]{0,40}</strong> \w+</td>)*)</tr></tbody></table></td></tr>|)')
pattern2 = re.compile(r'<strong>([A-Za-z _*0-9]{0,40})</strong> (\w+)</td>')

with open('page_web', 'r') as content_file:
    content = content_file.read()

for m in re.finditer(pattern, content):
        print "Id: {}\nMacro: SYS_{}\nFname: {}\nSname: {}".format(m.group(1), m.group(2), m.group(2), m.group(3))
	s = ""
	functions_pointers = ""
	result = []
	if m.group(6) != None:
		result = re.findall(pattern2, m.group(6));
		i = len(result)
		for m2 in result:
			if m2[0] == "const char __user *":
				f = "&print_str"
			elif re.search("\*", m2[0]):
				f = "&print_ptr"
			elif re.search("unsigned long addr", "{} {}".format(m2[0], m2[1])):
				f = "&print_ptr"
			else:
				f = "&print_integer"
			s += "\t- {} {} -> {}\n".format(m2[1], m2[0], f)
			functions_pointers += "{}".format(f)
			if i > 1:
				functions_pointers += ", "
			i -= 1

	print"NbParam: {}\nParams:\n{}".format(i, s);
	print "\n--------------------------------------------------------\n"
	file.write("\t{{.id = SYS_{},\n".format(m.group(2)))
	file.write("\t .name = \"{}\",\n".format(m.group(2)))
	file.write("\t .nparams = {},\n".format(len(result)))
	file.write("\t .params = {{{}}},\n".format(functions_pointers))
	file.write("\t .nreturn = 1,\n")
	file.write("\t .returnt = &print_integer},\n")

file.write("};");


