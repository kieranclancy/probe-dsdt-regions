#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <err.h>
#include <string.h>

#include "regions.c"

void dump_region (const char *region, off_t target, size_t length, fieldlist_t *fields) {
    unsigned char *mem;
    int fd;
    off_t offset, foffset;
    int pages;
    int i, j;
    int bytes;

    for (i=0; fields[i].name; i++) {
        if (strcmp(fields[i].name, ABSOFF) == 0) continue;
        if (fields[i].bits < 1 || fields[i].bits % 8 != 0)
            errx(2, "Bad field: %s (%d bits)\n", fields[i].name, fields[i].bits);
    }

    fd = open("/dev/mem", O_RDONLY);
    if (fd < 0)
        err(1, "/dev/mem");

    offset = target % getpagesize();
    pages = (offset + length-1)/getpagesize() + 1;

    mem = mmap(NULL, pages*getpagesize(), PROT_READ, MAP_SHARED, fd, target - offset);
    if (mem == MAP_FAILED)
        err(1, "mmap");

    printf("Region: %s (%p) (%zd bytes)\n", region, (void *) target, length);

    foffset = 0;
    for (i=0; fields[i].name; i++) {
        if (strcmp(fields[i].name, ABSOFF) == 0) {
            foffset = fields[i].bits;
            continue;
        }
        printf("  %s.%4s:", region, fields[i].name);
        bytes = fields[i].bits/8;
        for (j=bytes-1; j>=0; j--) {
            printf(" %02x", *(mem+offset+foffset+j));
        }
        foffset += bytes;
        printf("\n");
    }

    munmap(mem, pages*getpagesize());
    close(fd);
}

int main (void) {
    int i;

    for (i=0; regions[i].name; i++)
        dump_region(regions[i].name, regions[i].target, regions[i].length, regions[i].fields);

    return 0;
}
