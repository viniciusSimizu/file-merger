#ifndef READER_H
#define READER_H

#include <dirent.h>
#include <stdio.h>

#define READER_FILES_DIR = "input";

FILE *reader_read(DIR *dir);

#endif
