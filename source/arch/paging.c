#include "paging.h"

#define PAGE_HEAP_SIZE  0x1000
#define PAGE_HEAP       0xC040000
#define USER_OFFSET     0x100000
#define FRAME_SIZE      0x1000

/*typedef u32 page_frame_t;

static page_dir_t   *paging_create_kernel_page_dir ();

static page_table_t *page_table_new             ();
static void          page_table_create_entry    (page_table_t *table,
                                                 u32 entry,
                                                 u32 present,
                                                 u32 rw,
                                                 page_frame_t frame);

static page_dir_t  *page_dir_new          ();
static void         page_dir_create_entry (page_dir_t *dir,
                                           u32 entry,
                                           u32 present,
                                           u32 rw,
                                           page_table_t *table);

static void bitmap_set_page_frame_used (page_frame_t frame);
static void bitmai_set_page_frame_free (page_frame_t frame);
static page_frame_t bitmap_alloc_frame ();

static u8 bitmap[PAGE_HEAP_SIZE];
static page_dir_t *kernel_page_dir;

void paging_initialize ()
{

}

page_dir_t *paging_create_user_page_dir (u32 size)
{
    return 0;
}

static page_dir_t *paging_create_kernel_page_dir ()
{
    return 0;
}

static page_dir_t *page_dir_new ()
{
    page_dir_t* dir = (page_dir_t*) bitmap_alloc_frame ();
    memset (dir, 0, 4096);
    return dir;
}

static void page_dir_create_entry (page_dir_t *dir,
                                   u32 entry,
                                   u32 present,
                                   u32 rw,
                                   page_table_t *table)
{
    dir->tables[entry].present = present;
    dir->tables[entry].rw = rw;
    dir->tables[entry].page_table_base = ((u32)table) >> 12;
}

static void bitmap_set_page_frame_used (page_frame_t frame)
{
    bitmap[frame/8] |= (1 << (frame % 8));
}

static void bitmai_set_page_frame_free (page_frame_t frame)
{
    bitmap[frame/8] &= ~(1 << (frame % 8));
}

static page_frame_t bitmap_alloc_frame ()
{
    for (u32 i = 0; i < PAGE_HEAP_SIZE; i++)
    {
        u8 byte = bitmap[i];
        if (byte != 0xFF)
        {
            for (u32 j = 0; j < 8; j++)
            {
                u8 bit = byte & (1 << j);
                if (bit == 0)
                {
                    u32 page = 8 * i + j;
                    bitmap_set_page_frame_used (page);
                    return (page_frame_t) PAGE_HEAP + (page * 4096);
                }
            }
        }
    }

    return -1;
}
static void SetPageFrameUsed (u32 page)
{

}

static void SetPageFrameFree (u32 pAddr)
{

}*/
