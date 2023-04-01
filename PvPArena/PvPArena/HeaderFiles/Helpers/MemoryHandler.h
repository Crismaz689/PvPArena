#pragma once

class MemoryHandler {
private:
	MemoryHandler() {}

	~MemoryHandler() {}

public:
	template <typename T>
	static void deletePointer(T* const pointer) { delete pointer; }
};