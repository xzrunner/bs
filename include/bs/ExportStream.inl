#pragma once

#include "bs/Serializer.h"

namespace bs
{
template<typename T>
void ExportStream::Write(const T& data)
{
	pack(data, &m_stream);
	m_size -= pack_size(data);
	GD_ASSERT(m_size >= 0, "export error.");
}

}