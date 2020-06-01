#ifndef __LIB_KERNEL_BITMAP_H
#define __LIB_KERNEL_BITMAP_H

#include <stdbool.h>
#include <stddef.h>
#include <inttypes.h>

/* SimHognSub : Next Fit algorithm start point */
size_t next_fit_start;

/* Bitmap abstract data type. */

/* Creation and destruction. */
struct bitmap *bitmap_create (size_t bit_cnt);
struct bitmap *bitmap_create_in_buf (size_t bit_cnt, void *, size_t byte_cnt);
size_t bitmap_buf_size (size_t bit_cnt);
void bitmap_destroy (struct bitmap *);

/* Bitmap size. */
size_t bitmap_size (const struct bitmap *);

/* Setting and testing single bits. */
void bitmap_set (struct bitmap *, size_t idx, bool);
void bitmap_mark (struct bitmap *, size_t idx);
void bitmap_reset (struct bitmap *, size_t idx);
void bitmap_flip (struct bitmap *, size_t idx);
bool bitmap_test (const struct bitmap *, size_t idx);

/* Setting and testing multiple bits. */
void bitmap_set_all (struct bitmap *, bool);
void bitmap_set_multiple (struct bitmap *, size_t start, size_t cnt, bool);
size_t bitmap_count (const struct bitmap *, size_t start, size_t cnt, bool);
bool bitmap_contains (const struct bitmap *, size_t start, size_t cnt, bool);
bool bitmap_any (const struct bitmap *, size_t start, size_t cnt);
bool bitmap_none (const struct bitmap *, size_t start, size_t cnt);
bool bitmap_all (const struct bitmap *, size_t start, size_t cnt);

/* Finding set or unset bits. */
#define BITMAP_ERROR SIZE_MAX
size_t bitmap_scan (const struct bitmap *, size_t start, size_t cnt, bool);
size_t bitmap_scan_and_flip (struct bitmap *, size_t start, size_t cnt, bool);

/* File input and output. */
#ifdef FILESYS
struct file;
size_t bitmap_file_size (const struct bitmap *);
bool bitmap_read (struct bitmap *, struct file *);
bool bitmap_write (const struct bitmap *, struct file *);
#endif

/* Debugging. */
void bitmap_dump (const struct bitmap *);
void bitmap_dump2 (const struct bitmap *b);

/* SimHongSub : Add function for Best Fit algorithm */
size_t best_bitmap_scan_and_flip (struct bitmap *, size_t start, size_t cnt, bool);
size_t best_bitmap_scan (const struct bitmap *, size_t start, size_t cnt, bool);
size_t best_bitmap_size(const struct bitmap *b, size_t start, size_t cnt, bool value);

/* SimHongSub : buddy system tree node */
typedef struct buddy_node{
    struct buddy_node *left;
    struct buddy_node *right;
    size_t index;
    size_t size;          // allocated size
    size_t used;          // 0:not used, 1: used
}buddyNode;

extern buddyNode *buddy_first_node;

/* SimHongSub : Add function for Buddy system algorithm */
size_t buddy_bitmap_scan_and_flip (struct bitmap *, size_t cnt, bool);
size_t buddy_bitmap_scan(buddyNode* node, size_t cnt, size_t alloc_size, int node_size);
size_t buddy_bitmap_free();
buddyNode* set_child_node(size_t index);
void set_node_size(buddyNode* node, size_t size, size_t total_size);

#endif /* lib/kernel/bitmap.h */
