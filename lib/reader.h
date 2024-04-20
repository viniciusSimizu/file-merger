#ifndef READER_H
#define READER_H

#include <stdio.h>
#define READER_FILES_DIR = "input";

struct reader_files {
	unsigned int size;
	char **files;
};

struct reader_files *reader_read_files();
FILE *reader_read(char *file);

#endif
