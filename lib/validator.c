#include <dirent.h>
#include <regex.h>
#include <stdio.h>
#include <stdlib.h>

#include "validator.h"

int validator_check_entries(char *pattern, char *dirpath, DIR *dir) {
	regex_t regex;
	int status;
	char filepath[1024];
	char buff[1024];
	struct dirent *entry;

	status = regcomp(&regex, pattern, 0);
	if (status == 0) {
		return 0;
	}

	while ((entry = readdir(dir)) != NULL) {
		sprintf(filepath, "%s/%s", dirpath, entry->d_name);
		FILE *file = fopen(filepath, "r");

		if (file == NULL) {
			regfree(&regex);
			return 0;
		}

		fgets(buff, sizeof(buff), file);
		status = regexec(&regex, buff, 0, NULL, 0);

		if (status != 0) {
			regfree(&regex);
			return 1;
		}
	}

	regfree(&regex);
	return 0;
};
