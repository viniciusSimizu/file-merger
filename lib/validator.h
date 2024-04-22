#ifndef VALIDATOR_H
#define VALIDATOR_H

#include <dirent.h>

int validator_check_entries(char *pattern, char *dirpath, DIR *dir);

#endif
