#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <errno.h>

#include "helper.h"

char *helper_find_root_file(char *dirpath);

char *helper_project_dir(const char *dirpath) {
	struct stat st;

	if (stat(dirpath, &st) == -1) {
		fprintf(stderr, "Couldn't read the \"%s\" path:\n%s\n", dirpath, strerror(errno));
		return NULL;
	}

	if (S_ISDIR(st.st_mode) == 0) {
		fprintf(stderr, "The dirpath \"%s\" is not a directory", dirpath);
		return NULL;
	}

	char *dirpath_dup = strdup(dirpath);
	char *project_root = helper_find_root_file(dirpath_dup);

	if (project_root == NULL) {
		free(dirpath_dup);
		return NULL;
	}

	return project_root;
};

char *helper_find_root_file(char *dirpath) {
	DIR *dir = opendir(dirpath);
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
			return dirpath;
		};
	}

	closedir(dir);
	helper_goto_parent(dirpath);

	if (strlen(dirpath) == 0) {
		return NULL;
	}

	return helper_find_root_file(dirpath);
};

void helper_goto_parent(char *path) {
	char *needle = strrchr(path, '/');
	if (needle != NULL) {
		*needle = '\0';
	}
};
