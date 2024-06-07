#include "reader.h"
#include <dirent.h>
#include <stdio.h>

FILE *reader_read(DIR *dir) {
	struct dirent *entry = readdir(dir);
	if (entry == NULL) {
	}
}
