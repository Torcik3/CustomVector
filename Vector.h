#pragma once

template<typename T>
class Vector {
public:
    Vector()
    {
        ReAllec(2);
    }
    ~Vector() {
        delete[] m_Data;
    }
    void PushBack(const T& value)
    {
        if (m_Size>=m_Capacity)
            ReAllec(m_Capacity + m_Capacity/2);

        m_Data[m_Size] = value;
        m_Size++;
    }

    void PushBack(T&& value)
    {
        if (m_Size>=m_Capacity)
            ReAllec(m_Capacity + m_Capacity/2);

        m_Data[m_Size] = std::move(value);
        m_Size++;
    }

    template<typename... Args>
    T& EmplaceBack(Args&&... args) {
        if (m_Size>=m_Capacity)
            ReAllec(m_Capacity + m_Capacity/2);

            m_Data[m_Size]=T(std::forward<Args>(args) ...);

        return m_Data[m_Size++];
    }

const T& operator[](unsigned long long index) const
    {
    if (index >= m_Size)
        {
        //  assert
        }
    return m_Data[index];
    }

    T& operator[](unsigned long long index)
    {
        return m_Data[index];
    }

   unsigned long long Size() const { return m_Size; }
private:
    void ReAllec(unsigned long long newCapacity)
    {
        T* newBlock = new T[newCapacity];

        if (newCapacity<m_Size)
            m_Size = newCapacity;

        for(unsigned long long i = 0; i < m_Size; i++)
        {
         newBlock[i] = std::move(m_Data[i]);
        }
        delete[] m_Data;
        m_Data=newBlock;
        m_Capacity=newCapacity;
    }
private:
    T* m_Data = nullptr;
    unsigned long long m_Size = 0;
    unsigned long long m_Capacity = 0;
};