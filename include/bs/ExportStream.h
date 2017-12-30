#pragma once

#include <cu/uncopyable.h>

#include <stdint.h>

namespace bs
{
	
class ExportStream : private cu::Uncopyable
{
public:
	ExportStream(uint8_t* data, size_t sz);

	template<typename T>
	void Write(const T&);

	void WriteBlock(const uint8_t* data, size_t len);
	
private:
	uint8_t* m_stream;
	int      m_size;

}; // ExportStream

}

#include "bs/ExportStream.inl"