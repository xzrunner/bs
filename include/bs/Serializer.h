#pragma once

namespace bs
{

template<typename T>
size_t pack_size(const T&);
	
template<typename T>
void pack(const T& d, uint8_t** ptr);

template<typename T>
void unpack(T& d, const uint8_t** ptr);

}

#include "bs/Serializer.inl"