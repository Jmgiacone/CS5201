/**
 *  @file dynamicarray.hpp
 *  @author shae, CS5201 Section A
 *  @date Feb 23, 2016
 *  @brief Description:
 *  @details Details:
 */

template<typename T>
DynamicArray<T>::DynamicArray(const size_t length, const size_t size,
    const T* array) :
    m_length(length), m_size(size), m_array(new T[length])
{
  for (size_t i = 0; i < m_size; i++)
  {
    m_array[i] = array[i];
  }
}

template<typename T>
DynamicArray<T>::DynamicArray(const T& item)
{
  m_size = 1;
  m_length = m_size * 2;
  m_array = new T[m_length];
  m_array[0] = item;
}

template<typename T>
DynamicArray<T>::DynamicArray(DynamicArray<T> && other) :
    DynamicArray<T>()
{
  swap(*this, other);
}

template<typename T>
DynamicArray<T>::DynamicArray(const DynamicArray<T>& other) :
    m_length(other.m_length), m_size(other.m_size), m_array(new T[m_length])
{

  for (size_t i = 0; i < m_size; i++)
  {
    m_array[i] = other.m_array[i];
  }
}

template<typename T>
DynamicArray<T>::DynamicArray(const size_t size, const T& value)
{
  m_length = size * 2;
  m_size = size;
  m_array = new T[m_length];
  for (size_t i = 0; i < m_size; i++)
  {
    m_array[i] = value;
  }
}

template<typename T>
DynamicArray<T>& DynamicArray<T>::operator=(DynamicArray<T> rhs)
{
  swap(*this, rhs);
  return *this;
}

template<typename T>
DynamicArray<T>::~DynamicArray()
{
  delete[] m_array;
}

template<typename T>
T& DynamicArray<T>::operator[](const size_t index)
{
  try
  {
    if (index >= m_size)
    {
      throw index;
    }

  }
  catch (size_t i)
  {
    std::cerr << "//ERROR index out of bounds: " << i << ", when size = "
        << m_size << std::endl;
  }
  return m_array[index];
}

template<typename T>
const T& DynamicArray<T>::operator[](const size_t index) const
{
  try
  {
    if (index >= m_size)
    {
      throw index;
    }

  }
  catch (size_t i)
  {
    std::cerr << "//ERROR index out of bounds: " << i << ", when size = "
        << m_size << std::endl;
  }
  return m_array[index];
}

/*
 template<typename T>
 void DynamicArray<T>::append(const  T& item)
 {
 if ((m_size + 1) >= m_length)
 {
 resize((m_size + 1) * 2);
 }
 m_array[m_size] = item;
 m_size += 1;
 }
 */

template<typename T>
void DynamicArray<T>::append(const DynamicArray<T>& item)
{
  size_t combined_size = m_size + item.size();
  if (combined_size >= m_length)
  {
    resize((combined_size) * 2);
  }
  for (size_t i = m_size; i < combined_size; i++)
  {
    m_array[i] = item.m_array[(i - m_size)];
  }
  m_size = combined_size;
}

template<typename T>
void DynamicArray<T>::append(const T& item)
{
  size_t combined_size = m_size + 1;
  if (combined_size >= m_length)
  {
    resize((combined_size) * 2);
  }
  m_array[m_size] = item;
  m_size = combined_size;
}

template<typename T>
void DynamicArray<T>::insert(const DynamicArray<T>& item, const size_t index)
{
  try
  {
    size_t combined_size = m_size + item.size();
    size_t combined_start = index + item.size();
    if (index > m_size)
    {
      throw index;
    }

    else if (index == m_size)
    {
      append(item);
    }

    else
    {
      T* temp_array;
      if (combined_size >= m_length)
      {
        temp_array = new T[combined_size * 2];
        m_length = combined_size * 2;
      }
      else
      {
        temp_array = new T[m_length];
      }

      for (size_t i = 0; i < index; i++)
      {
        temp_array[i] = m_array[i];
      }

      for (size_t i = index; i < combined_start; i++)
      {
        temp_array[i] = item.m_array[i - index];
      }

      for (size_t i = index; i < m_size; i++)
      {
        temp_array[item.size() + i] = m_array[i];
      }
      m_size = combined_size;

      delete[] m_array;
      m_array = temp_array;
    }
  }
  catch (size_t i)
  {
    std::cerr << "//ERROR index out of bounds: " << i << ", when size = "
        << m_size << std::endl;
  }
}

template<typename T>
void DynamicArray<T>::remove(const size_t start, const size_t offset)
{
  try
  {
    if (start >= m_size)
    {
      throw start;
    }

    if (start + offset >= m_size)
    {
      throw(start + offset);
    }
    T* temp_array;
    if ((m_size - (offset + 1)) <= (m_length / 2))
    {
      temp_array = new T[(m_length / 2)];
      m_length = (m_length / 2);
    }
    else
    {
      temp_array = new T[m_length];
    }

    for (size_t i = 0; i < start; i++)
    {
      temp_array[i] = m_array[i];
    }

    for (size_t i = start + (offset + 1); i < m_size; i++)
    {
      temp_array[i - (offset + 1)] = m_array[i];
    }

    m_size -= offset + 1;
    delete[] m_array;
    m_array = temp_array;
  }
  catch (size_t i)
  {
    std::cerr << "//ERROR remove index out of bounds: " << i << ", when size = "
        << m_size << std::endl;
  }
}

template<typename T>
void DynamicArray<T>::truncate(const size_t size)
{
  try
  {
    if (size >= m_size)
    {
      throw size;
    }
    if (size <= (m_length / 2))
    {
      m_size = size;
      resize(m_length / 2);
    }
    else
    {
      m_size = size;
    }
  }
  catch (size_t s)
  {
    std::cerr << "//ERROR size out of bounds, can't truncate: " << s
        << ", when size = " << m_size << std::endl;
  }
}

template<typename T>
void DynamicArray<T>::clear()
{
  delete[] m_array;
  m_size = 0;
  m_length = 0;
  m_array = nullptr;
}

template<typename T>
void DynamicArray<T>::reverse()
{
  T* temp = new T[m_length];
  for (size_t i = 0; i < m_size; i++)
  {
    temp[i] = m_array[(m_size - 1) - i];
  }
  delete[] m_array;
  m_array = temp;
}

template<typename T>
void DynamicArray<T>::reserve(const size_t size)
{
  if (m_length < size)
  {
    resize(size);
  }
  if (m_size < size)
  {
    m_size = size;
  }
}

template<typename T>
size_t DynamicArray<T>::size() const
{
  return m_size;
}

template<typename T>
size_t DynamicArray<T>::length() const
{
  return m_length;
}

template<typename T>
bool DynamicArray<T>::isEmpty() const
{
  return !m_size;
}

template<typename T>
void DynamicArray<T>::resize(const size_t length)
{
  T* temp_array = new T[length];
  m_length = length;
  for (size_t i = 0; i < m_size; i++)
  {
    temp_array[i] = m_array[i];
  }
  delete[] m_array;
  m_array = temp_array;
}

template<typename T>
void swap(DynamicArray<T>& first, DynamicArray<T>& second)
{

  using std::swap;

  swap(first.m_size, second.m_size);
  swap(first.m_length, second.m_length);
  swap(first.m_array, second.m_array);
}
