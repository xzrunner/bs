#pragma once

#include "bs/Serializer.h"

namespace bs
{

template<typename T>
void ExportStream::Write(const T& data)
{
#ifdef BS_ES_AUTO_ALLOC
	if (m_stream)
	{
		pack(data, &m_stream);
		m_stream_sz -= pack_size(data);
		GD_ASSERT(m_stream_sz >= 0, "export error.");
	}
	else
	{
		GD_ASSERT(m_buf, "err buf");

		size_t need = pack_size(data);
		PrepareBuf(need);
		pack(data, &m_buf);
		m_buf_sz += need;
		GD_ASSERT(m_buf_sz <= m_buf_cap, "export error.");
	}
#else
	pack(data, &m_stream);
	m_stream_sz -= pack_size(data);
	GD_ASSERT(m_stream_sz >= 0, "export error.");
#endif // BS_ES_AUTO_ALLOC
}

inline bool ExportStream::Empty() const
{
#ifdef BS_ES_AUTO_ALLOC
	return m_stream ? m_stream_sz : m_buf_sz;
#else
	return m_stream_sz;
#endif // BS_ES_AUTO_ALLOC
}

}