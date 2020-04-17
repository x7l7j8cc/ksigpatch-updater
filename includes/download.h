#ifndef _DOWNLOAD_H_
#define _DOWNLOAD_H_

#define ON              1
#define OFF             0

#include <stdbool.h>

bool downloadFile(const char *url, const char *output, int api);

#endif