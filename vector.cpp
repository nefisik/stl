#include <iostream>
using namespace std;

template <typename T>
class Vector {
private:
    unsigned int m_size;
    unsigned int m_capacity;
    T* ptr;
public:
    using iterator = T*;

    Vector();
    Vector(unsigned int);
    Vector(unsigned int, const T&);
    Vector(const Vector<T>&);      
    ~Vector();

    unsigned int capacity() const;
    unsigned int size() const;
    bool empty() const;
    iterator begin();
    iterator end();
    T& front();
    T& back();
    void push_back(const T&); 
    void pop_back();
    void reserve(unsigned int);   
    void resize(unsigned int); 

    T& operator[](unsigned int);  
    Vector<T>& operator=(const Vector<T>&);
    void clear();
};

template <typename T>
inline Vector<T>::Vector() {
    m_capacity = 0;
    m_size = 0;
    ptr = nullptr;
}

template <typename T>
inline Vector<T>::Vector(const Vector<T>& v) {
    m_size = v.m_size;
    m_capacity = v.m_capacity;
    ptr = new T[m_size];  
    for (unsigned int i = 0; i < m_size; i++)
        ptr[i] = v.ptr[i];  
}

template <typename T>
inline Vector<T>::Vector(unsigned int size) {
    m_capacity = size;
    m_size = size;
    ptr = new T[size];
}

template <typename T>
inline Vector<T>::Vector(unsigned int size, const T& initial) {
    m_size = size;
    m_capacity = size;
    ptr = new T [size];
    for (unsigned int i = 0; i < size; i++)
        ptr[i] = initial;
}

template <typename T>
inline Vector<T>& Vector<T>::operator=(const Vector<T>& v) {
    delete[] ptr;
    m_size = v.m_size;
    m_capacity = v.m_capacity;
    ptr = new T [m_size];
    for(unsigned int i = 0; i < m_size; i++)
        ptr[i] = v.ptr[i];
    return *this;
}

template <typename T>
typename Vector<T>::iterator Vector<T>::begin() {
    return ptr;
}

template <typename T>
typename Vector<T>::iterator Vector<T>::end() {
    return ptr + size();
}

template <typename T>
inline T& Vector<T>::front() {
    return ptr[0];
}

template <typename T>
inline T& Vector<T>::back() {
    return ptr[m_size - 1];
}

template <typename T>
inline void Vector<T>::push_back(const T& v) {
    if(m_size >= m_capacity)
        reserve(m_capacity + 5);
    ptr[m_size++] = v;
}

template <typename T>
inline void Vector<T>::pop_back() {
    m_size--;
}

template <typename T>
inline void Vector<T>::reserve(unsigned int capacity) {
    if(ptr == nullptr) {
        m_size = 0;
        m_capacity = 0;
    } 
    T* Newptr = new T [capacity];
    
    unsigned int l_Size = capacity < m_size ? capacity : m_size;

    for (unsigned int i = 0; i < l_Size; i++)
        Newptr[i] = ptr[i];

    m_capacity = capacity;
    delete[] ptr;
    ptr = Newptr;
}

template <typename T>
inline unsigned int Vector<T>::size() const {
    return m_size;
}

template <typename T>
inline void Vector<T>::resize(unsigned int size) {
    reserve(size);
    m_size = size;
}

template <typename T>
inline T& Vector<T>::operator[](unsigned int index) {
    return ptr[index];
}  

template <typename T>
inline unsigned int Vector<T>::capacity() const {
    return m_capacity;
}

template <typename T>
inline Vector<T>::~Vector() {
    delete[] ptr;
}

template <typename T>
inline void Vector<T>::clear() {
    m_capacity = 0;
    m_size = 0;
    ptr = nullptr;
}

int main() {
   int size;
   cin>>size;

   Vector<int> v1(size);
   for(Vector<int>::iterator it = v1.begin(); it < v1.end(); ++it) {
        cin>>*it;
    }
   //Vector<int> v2(7);
 
    v1.push_back(25);
    v1.push_back(13);
 
    for(int i = 0; i < v1.size(); ++i) {
        std::cout << v1[i] << '\n';
    }
    v1.clear();

    //if(v1.size()==v1.empty()) {
    	//
    //}

   v1.reserve(2);
/*   v.capacity();

   Vector<string> v1(2);
   v1.capacity() == 2;
   v1.size();
   v1[0] == "";
   v1[1] == "";

   v1[0] = "hi";

   Vector<int> v2(2, 7);
   v2[1] == 7;

   Vector<int> v10(v2);
   v10[1] == 7;

   Vector<string> v3(2, "hello");
   v3.size() == 2;
   v3.capacity() == 2;
   v3[0] == "hello";
   v3[1] == "hello";

   v3.resize(1);
   v3.size() == 1;
   v3[0] == "hello";

   Vector<string> v4 = v3;
   v4.size() == 1;
   v4[0] == v3[0];
   v3[0] = "test";
   v4[0] != v3[0];  
   v4[0] == "hello";

   v3.pop_back();
   v3.size() == 0;

   Vector<int> v5(7, 9);
   Vector<int>::iterator it = v5.begin();
   while (it != v5.end())
   {
      *it == 9;
      ++it;
   }*/
}