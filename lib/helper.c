#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "helper.h"

char *helper_find_root_file(char *dirname);
void helper_goto_parent(char *haystack);

char *helper_project_dir(const char *dirname) {
	if (*dirname != '/') {
		perror("dirname must be an absolute path");
		return NULL;
	};

	char *dirname_cpy = malloc(sizeof(char) * (strlen(dirname) + 1));
	strcpy(dirname_cpy, dirname);
	return helper_find_root_file(dirname_cpy);
};

char *helper_find_root_file(char *dirname) {
	DIR *dir = opendir(dirname);
	if (dir == NULL) {
		return NULL;
	}

	struct dirent *entry;
	while ((entry = readdir(dir)) != NULL) {
		if (entry->d_type != DT_REG) {
			continue;
		};

		if (strcmp(entry->d_name, ROOT_EXEC) == 0) {
			closedir(dir);
			return dirname;
		};
	};

	closedir(dir);
	helper_goto_parent(dirname);

	if (strlen(dirname) == 0) {
		return NULL;
	};

	return helper_find_root_file(dirname);
};

void helper_goto_parent(char *haystack) {
	char *needle = strrchr(haystack, '/');
	if (needle != NULL) {
		*needle = '\0';
	};
};
