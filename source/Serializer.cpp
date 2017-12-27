#include "bs/Serializer.h"
#include "bs/typedef.h"
#include "bs/ImportStream.h"

#include <memmgr/LinearAllocator.h>

namespace bs
{

uint8_t* unpack_array8(mm::LinearAllocator& alloc, ImportStream& is, int count, uint16_t& array_n)
{
	array_n = is.UInt16();
	uint8_t* array = static_cast<uint8_t*>(alloc.alloc<char>(ALIGN_4BYTE(sizeof(uint8_t) * count* array_n)));
	for (int i = 0, n = count * array_n; i < n; ++i) {
		array[i] = is.UInt8();
	}
	return array;
}

uint16_t* unpack_array16(mm::LinearAllocator& alloc, ImportStream& is, int count, uint16_t& array_n)
{
	array_n = is.UInt16();
	uint16_t* array = static_cast<uint16_t*>(alloc.alloc<char>(ALIGN_4BYTE(sizeof(uint16_t) * count* array_n)));
	for (int i = 0, n = count * array_n; i < n; ++i) {
		array[i] = is.UInt16();
	}
	return array;
}

uint32_t* unpack_array32(mm::LinearAllocator& alloc, ImportStream& is, int count, uint16_t& array_n)
{
	array_n = is.UInt16();
	uint32_t* array = static_cast<uint32_t*>(alloc.alloc<char>(ALIGN_4BYTE(sizeof(uint32_t) * count* array_n)));
	for (int i = 0, n = count * array_n; i < n; ++i) {
		array[i] = is.UInt32();
	}
	return array;
}

}