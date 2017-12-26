#pragma once

#include <cu/uncopyable.h>

#include <string>

#include <stdint.h>

namespace mm { class LinearAllocator;  }

namespace bs
{

class ImportStream : private cu::Uncopyable
{
public:
	ImportStream(const char* data, int sz);
	virtual ~ImportStream();

	uint8_t  UInt8();
	uint16_t UInt16();
	uint32_t UInt32();

	float Float();

	std::string String();
	const char* String(mm::LinearAllocator& alloc);

	const char* Block(int sz);

	const char* Stream() const { return m_stream; }
	int Size() const { return m_size; }

	bool Empty() const { return m_size == 0; }

protected:
	const char* m_stream;
	int m_size;

}; // ImportStream

}