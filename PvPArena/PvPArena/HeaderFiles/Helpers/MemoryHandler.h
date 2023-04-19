#pragma once

/// <summary>
/// handles memory management
/// </summary>
class MemoryHandler {
private:
	MemoryHandler() {}

	~MemoryHandler() {}

public:
	/// <summary>
	/// deletes pointer
	/// </summary>
	/// <typeparam name="T">generic parameter</typeparam>
	/// <param name="pointer">pointer to T type</param>
	template <typename T>
	static void deletePointer(T* const pointer) { delete pointer; }
};