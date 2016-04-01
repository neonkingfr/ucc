#ifndef _STAT_H
#define _STAT_H

#include <sys/types.h>

/* File mode bits */
#define S_IRWXU  00700
#define S_IRUSR  00400
#define S_IWUSR  00200
#define S_IXUSR  00100
#define S_IRWXG  00070
#define S_IRGRP  00040
#define S_IWGRP  00020
#define S_IXGRP  00010
#define S_IRWXO  00007
#define S_IROTH  00004
#define S_IWOTH  00002
#define S_IXOTH  00001
#define S_ISUID  04000
#define S_ISGID  02000
#define S_ISVTX  01000

/* Hopefully this value should be big enough for all supported archs. */
#define _STAT_STRUCT_SIZE 256

struct stat {
    union {
        char _buf[_STAT_STRUCT_SIZE];
        long long _align;
    } _s;
};

int stat(const char *path, struct stat *buf);
int chmod(const char *path, mode_t mode);

#endif
