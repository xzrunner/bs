#pragma once

#include <stdint.h>

namespace mm { class LinearAllocator; }

namespace bs
{

class ImportStream;

template<typename T>
size_t pack_size(const T&);

template<typename T>
void pack(const T& d, uint8_t** ptr);

template<typename T>
void unpack(T& d, const uint8_t** ptr);


template<typename T>
size_t pack_size(const T*);

template<typename T>
void pack(const T* d, uint8_t** ptr);

uint8_t*  unpack_array8(mm::LinearAllocator& alloc, ImportStream& is, int count, uint16_t& array_n);
uint16_t* unpack_array16(mm::LinearAllocator& alloc, ImportStream& is, int count, uint16_t& array_n);
uint32_t* unpack_array32(mm::LinearAllocator& alloc, ImportStream& is, int count, uint16_t& array_n);

}

#include "bs/Serializer.inl"