#pragma once

#ifndef ALIGN_4BYTE
#define ALIGN_4BYTE(x) (((x) + 3) & ~3)
#endif // ALIGN_4BYTE

#ifndef PTR_SIZE_DIFF
#define PTR_SIZE_DIFF (8 - sizeof(void *))
#endif // PTR_SIZE_DIFF

#ifndef SIZEOF_POINTER
#define SIZEOF_POINTER 8
#endif // SIZEOF_POINTER