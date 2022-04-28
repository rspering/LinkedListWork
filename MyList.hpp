
void get_identity(std::string & my_id)
{
	my_id = "rjstrd";
}

template <typename T>
MyList<T>::MyList()
{
  m_size = 0;
  m_sentinel = new Node<T>(nullptr, nullptr);
}

template <typename T>
MyList<T>::~MyList()
{
  while(m_sentinel != nullptr)
  {
          Node<T> *temp = m_sentinel;
          m_sentinel = m_sentinel->m_next;
          delete temp;
  }
  delete m_sentinel;
}

template <typename T>
MyList<T>::MyList(const MyList<T> &source)
{
  m_size = 0;
  m_sentinel = new Node<T>(nullptr, nullptr);

  if(source.size() > 0)
  {
    Node<T> *curr = source.m_sentinel->m_next;
    while(curr != nullptr)
    {
      push_back(curr->m_element);
      curr = curr->m_next;
    }
  }
}

template <typename T>
MyList<T> & MyList<T>::operator=(const MyList<T> &source)
{
  if(size() == 0)
  {
    return *this;
  }
  Node<T> *curr = source.m_sentinel->m_next;
  while(curr != nullptr)
  {
    push_back(curr->m_element);
    curr = curr->m_next;
  }
  return *this;
}


template <typename T>
void MyList<T>::assign(int count, const T &value)
{

}


template <typename T>
void MyList<T>::clear()
{
  while(m_sentinel->m_next != nullptr)
  {
    m_sentinel->m_next = m_sentinel->m_next->m_next;
  }
  m_size = 0;
  m_sentinel->m_next = nullptr;
  m_sentinel->m_prev = nullptr;
}


template <typename T>
T & MyList<T>::front()
{

}


template <typename T>
T & MyList<T>::back()
{

}


template <typename T>
void MyList<T>::push_front(const T &x)
{

}


template <typename T>
void MyList<T>::push_back(const T &x)
{
  if(size() == 0)
  {
    Node<T> *newNode = new Node<T>(x, nullptr, nullptr);
    m_sentinel->m_next = newNode;
    m_sentinel->m_prev = newNode;
  }
  else
  {
    Node<T> *newNode = new Node<T>(x, nullptr, nullptr);
    m_sentinel->m_prev->m_next = newNode;
    m_sentinel->m_next = newNode;
  }
}


template <typename T>
void MyList<T>::pop_front()
{

}



template <typename T>
void MyList<T>::pop_back()
{

}


template <typename T>
void MyList<T>::insert(int i, const T &x)
{

}


template <typename T>
void MyList<T>::remove(T value)
{

}


template <typename T>
void MyList<T>::erase(int i)
{

}


template <typename T>
void MyList<T>::reverse()
{

}

template <typename T>
bool MyList<T>::empty()
{
  return (m_size == 0);
}


template <typename T>
int MyList<T>::size()
{
  return m_size;
}


