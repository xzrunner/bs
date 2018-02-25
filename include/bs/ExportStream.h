#pragma once

#include <boost/noncopyable.hpp>

#include <stdint.h>

namespace bs
{
	
class ExportStream : boost::noncopyable
{
public:
	ExportStream(uint8_t* data, size_t sz);

	template<typename T>
	void Write(const T&);

	void WriteBlock(const uint8_t* data, size_t len);
	
	bool Empty() const { return m_size == 0; }

private:
	uint8_t* m_stream;
	int      m_size;

}; // ExportStream

}

#include "bs/ExportStream.inl"