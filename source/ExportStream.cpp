#include "bs/ExportStream.h"

#include <guard/check.h>

namespace bs
{

#ifdef BS_ES_AUTO_ALLOC
ExportStream::ExportStream()
{
	m_buf_cap = 32;
	m_buf = new uint8_t[m_buf_cap];
}
#endif // BS_ES_AUTO_ALLOC

ExportStream::ExportStream(uint8_t* data, size_t sz)
	: m_stream(data)
	, m_stream_sz(sz)
{
}

#ifdef BS_ES_AUTO_ALLOC
ExportStream::~ExportStream()
{
	if (m_buf) {
		delete[] m_buf;
	}
}
#endif // BS_ES_AUTO_ALLOC

void ExportStream::WriteBlock(const uint8_t* data, size_t len)
{
#ifdef BS_ES_AUTO_ALLOC
	if (m_stream)
	{
		memcpy(m_stream, data, len);
		m_stream += len;
		m_stream_sz -= len;
	}
	else
	{
		GD_ASSERT(m_buf, "err buf");

		PrepareBuf(len);
		memcpy(m_buf, data, len);
		m_buf_sz += len;
	}
#else
	memcpy(m_stream, data, len);
	m_stream += len;
	m_stream_sz -= len;
#endif // BS_ES_AUTO_ALLOC
}

#ifdef BS_ES_AUTO_ALLOC
void ExportStream::PrepareBuf(size_t need)
{
	bool enlarge = false;
	while (m_buf_cap - m_buf_sz < need) {
		enlarge = true;
		m_buf_cap *= 2;
	}
	GD_ASSERT(m_buf_sz + need < m_buf_cap, "no space");
	if (enlarge)
	{
		uint8_t* new_buf = new uint8_t[m_buf_cap];
		memcpy(new_buf, m_buf, m_buf_sz);
		delete[] m_buf;
		m_buf = new_buf;
	}
}
#endif // BS_ES_AUTO_ALLOC

}