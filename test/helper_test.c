#include "helper.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *bubble_up_dir(char *path, const char *dirname);

int main() {
	char *expect_dirpath = strdup(__FILE__);
	char *expect = bubble_up_dir(expect_dirpath, "file-merger");

	char *result_dirpath = strdup(__FILE__);
	helper_goto_parent(result_dirpath);
	char *result = helper_project_dir(result_dirpath);

	if (expect == NULL || result == NULL) {
		assert(0);

	} else {
		assert(strcmp(result, expect) == 0);
	}

	free(expect_dirpath);
	free(result_dirpath);
	free(result);

	return 0;
};

char *bubble_up_dir(char *path, const char *dirname) {
	char *dirname_ptr;
	while ((dirname_ptr = strrchr(path, '/')) != NULL) {
		if (strcmp(dirname_ptr + 1, dirname) == 0) {
			return path;
		}

		*dirname_ptr = '\0';
	}

	return NULL;
};
