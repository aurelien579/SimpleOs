#ifndef PAGING_H
#define PAGING_H

#include "../types.h"

/*typedef struct _page_dir_entry
{
    u32 present     :1;
    u32 rw          :1;
    u32 user        :1;
    u32 pwt         :1;
    u32 pcd         :1;
    u32 accessed    :1;
    u32 _unused     :1;
    u32 pageSize    :1;
    u32 global      :1;
    u32 available   :3;

    u32 page_table_base :20;
} __attribute__ ((packed)) page_dir_entry_t;

typedef struct _page_table_entry
{
    u32 present     :1;
    u32 rw          :1;
    u32 user        :1;
    u32 pwt         :1;
    u32 pcd         :1;
    u32 accessed    :1;
    u32 dirty       :1;
    u32 pat         :1;
    u32 global      :1;
    u32 available   :3;

    u32 page_base    :20;
} __attribute__ ((packed)) page_table_entry_t;

typedef struct
{
    page_table_entry_t entries[1024];
}  __attribute__((packed)) page_table_t;

typedef struct
{
    page_dir_entry_t tables[1024];
}  __attribute__((packed)) page_dir_t;

void        paging_initialize           ();
void        paging_switch_dir           (page_dir_t *directory);
page_dir_t *paging_create_user_page_dir (u32 size);*/

#endif
