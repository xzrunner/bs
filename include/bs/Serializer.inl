#pragma once

#include <guard/check.h>

#include <string>

namespace bs
{

template<typename T>
inline size_t pack_size(const T& d)
{
	return sizeof(d);
}

template<typename T>
inline void pack(const T& d, uint8_t** ptr)
{
	memcpy(*ptr, &d, sizeof(d));
	*ptr += sizeof(d);
}

template<typename T>
inline void unpack(T& d, const uint8_t** ptr)
{
	memcpy(&d, *ptr, sizeof(d));
	*ptr += sizeof(d);
}

template<>
inline size_t pack_size(const std::string& str)
{
	if (str.empty()) {
		return sizeof(uint16_t);
	} else {
		GD_ASSERT(str.size() <= 0xffff, "str too long");
		return sizeof(uint16_t) + str.size();
	}
}

template<>
inline void pack(const std::string& str, uint8_t** ptr)
{
	if (str.empty()) 
	{
		uint16_t c = 0xffff;
		pack(c, ptr);
	} 
	else 
	{
		GD_ASSERT(str.size() <= 0xffff, "str too long");
		uint16_t sz = static_cast<uint16_t>(str.size());
		pack(sz, ptr);
		for (int i = 0; i < sz; ++i) {
			uint8_t c = str[i];
			pack(c, ptr);
		}
	}
}

template<>
inline void unpack(std::string& str, const uint8_t** ptr)
{
	uint16_t sz;
	unpack(sz, ptr);
	if (sz == 0xffff) {
		str.clear();
		return;
	}

	str.reserve(sz);
	for (int i = 0; i < sz; ++i) {
		uint8_t c;
		unpack(c, ptr);
		str.push_back((char)c);
	}
}

template<typename T>
T* unpack_array(mm::LinearAllocator& alloc, ImportStream& is, int count, uint16_t& array_n)
{
	array_n = is.UInt16();
	uint8_t* array = static_cast<uint8_t*>(alloc.Alloc(ALIGN_4BYTE(sizeof(uint8_t) * count* array_n)));
	for (int i = 0, n = count * array_n; i < n; ++i) {
		array[i] = is.UInt8();
	}
	return array;
}

}