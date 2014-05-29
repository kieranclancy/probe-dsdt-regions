#ifndef _REGIONS_C
#define _REGIONS_C

#define ABSOFF ""
#define Offset(o) {ABSOFF, o}

typedef struct {
    const char *name;
    int bits;
} fieldlist_t;

typedef struct {
    const char *name;
    off_t target;
    size_t length;
    fieldlist_t *fields;
} region_t;

region_t regions[] = {
    {NULL}
};

#endif /* _REGIONS_C */
