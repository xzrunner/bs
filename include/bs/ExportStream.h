#pragma once

#include <boost/noncopyable.hpp>

#include <stdint.h>

//#define BS_ES_AUTO_ALLOC

namespace bs
{

class ExportStream : boost::noncopyable
{
public:
#ifdef BS_ES_AUTO_ALLOC
	ExportStream();
#endif // BS_ES_AUTO_ALLOC
	ExportStream(uint8_t* data, size_t sz);
#ifdef BS_ES_AUTO_ALLOC
	~ExportStream();
#endif // BS_ES_AUTO_ALLOC

	template<typename T>
	void Write(const T&);

	void WriteBlock(const uint8_t* data, size_t len);

	bool Empty() const;

	size_t Size() const;

#ifdef BS_ES_AUTO_ALLOC
private:
	void PrepareBuf(size_t need);
#endif // BS_ES_AUTO_ALLOC

private:
	uint8_t* m_stream = nullptr;
	size_t   m_stream_sz = 0;

#ifdef BS_ES_AUTO_ALLOC
	uint8_t* m_buf = nullptr;
	size_t   m_buf_sz = 0;
	size_t   m_buf_cap = 0;
#endif // BS_ES_AUTO_ALLOC

}; // ExportStream

}

#include "bs/ExportStream.inl"