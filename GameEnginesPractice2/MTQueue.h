#pragma once

template <class T>
class MTQueue
{
private:
	T* m_pData;
	// amount of data
	size_t m_nSize;
	// amount of allocated memory
	size_t m_nCapacity;
public:
	MTQueue();
	~MTQueue();

	T* allocate();
	T* deallocate();
	// Increase the array size and return a pointer to the start of free memory
	T* Resize(size_t nNewSize);
	void Clear();
	// Get file size
	size_t capacity();
	T* operator*();
};

template<class T>
inline MTQueue<T>::MTQueue()
	: m_pData(nullptr), m_nSize(0), m_nCapacity(0) {}

template<class T>
MTQueue<T>::~MTQueue()
{
	if (m_pData)
		delete m_pData;
}

template<class T>
T* MTQueue<T>::allocate()
{
	return new T[m_nCapacity];
}

template<class T>
T* MTQueue<T>::deallocate()
{
	if (m_pData)
		delete m_pData;
	return nullptr;
}

template<class T>
T* MTQueue<T>::Resize(size_t nNewSize)
{
	m_nSize = m_nCapacity;
	m_nCapacity = nNewSize;
	auto newData = allocate();
	if (m_pData)
		memcpy(newData, m_pData, m_nCapacity);
	m_pData = deallocate();
	m_pData = newData;
	return m_pData + m_nSize;
}

template<class T>
void MTQueue<T>::Clear()
{
	m_pData = deallocate();
	m_nSize = 0;
	m_nCapacity = 0;
}

template<class T>
size_t MTQueue<T>::capacity()
{
	return m_nCapacity;
}

template<class T>
T* MTQueue<T>::operator*()
{
	return m_pData;
}