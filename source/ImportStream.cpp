#include "bs/ImportStream.h"

#include <guard/check.h>

#include <string.h>

namespace bs
{

ImportStream::ImportStream(const char* data, int sz)
	: m_stream(data)
	, m_size(sz)
{
}

ImportStream::~ImportStream()
{
}

uint8_t ImportStream::UInt8()
{
	GD_ASSERT(m_size > 0, "Invalid import UInt8");

	uint8_t ret = (uint8_t)*(m_stream);
	++m_stream;
	--m_size;
	return ret;	
}

uint16_t ImportStream::UInt16()
{
	GD_ASSERT(m_size >= 2, "Invalid import UInt16");

	uint8_t low = (uint8_t)*(m_stream);
	uint8_t high = (uint8_t)*(m_stream + 1);
	m_stream += 2;
	m_size -= 2;

	return low | (uint32_t)high << 8;
}

uint32_t ImportStream::UInt32()
{
	GD_ASSERT(m_size >= 4, "Invalid import UInt32");

	uint8_t b[4];
	b[0] = (uint8_t)*(m_stream);
	b[1] = (uint8_t)*(m_stream + 1);
	b[2] = (uint8_t)*(m_stream + 2);
	b[3] = (uint8_t)*(m_stream + 3);
	m_stream += 4;
	m_size -= 4;

	return b[0] | (uint32_t)b[1] << 8 | (uint32_t)b[2] << 16 | (uint32_t)b[3] << 24;
}

float ImportStream::Float()
{
	uint32_t i = UInt32();
	float f;
	memcpy(&f, &i, 4);
	return f;
}

std::string ImportStream::String()
{
	int n = UInt16();
	if (n == 0xffff) {
		return "";
	}
	GD_ASSERT(m_size >= n, "Invalid import String");

	std::string str(m_stream, n);
	m_stream += n;
	m_size -= n;

	return str;
}

const char* ImportStream::Block(int sz)
{
	GD_ASSERT(m_size >= sz, "Invalid import Block");

	const char* ret = m_stream;
	m_stream += sz;
	m_size -= sz;

	return ret;
}

}
