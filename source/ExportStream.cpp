#include "bs/ExportStream.h"

namespace bs
{

ExportStream::ExportStream(uint8_t* data, size_t sz)
	: m_stream(data)
	, m_size(sz)
{
}

void ExportStream::WriteBlock(const uint8_t* data, size_t len)
{
	memcpy(m_stream, data, len);
	m_stream += len;
	m_size -= len;
}

}