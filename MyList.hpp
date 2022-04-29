using namespace std;

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
  clear();
  for(int i = 0; i < count; i++)
  {
    push_back(value);
  }
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
  return m_sentinel->m_next->m_element;
}


template <typename T>
T & MyList<T>::back()
{
  return m_sentinel->m_prev->m_element;
}


template <typename T>
void MyList<T>::push_front(const T &x)
{
  if(size() == 0)
  {
    Node<T> *newNode = new Node<T>(x, nullptr, nullptr);
    m_sentinel->m_next = newNode;
    m_sentinel->m_prev = newNode;
  }
  else
  {
    Node<T> *newNode = new Node<T>(x, nullptr, m_sentinel->m_next);
    m_sentinel->m_next->m_prev = newNode;
    m_sentinel->m_next = newNode;
  }
  m_size++;
}


template <typename T>
void MyList<T>::push_back(const T &x)
{
  if(m_size == 0)
  {
    Node<T> *newNode = new Node<T>(x, nullptr, nullptr);
    m_sentinel->m_next = newNode;
    m_sentinel->m_prev = newNode;
  }
  else
  {
    Node<T> *newNode = new Node<T>(x, m_sentinel->m_prev, nullptr);
    m_sentinel->m_prev->m_next = newNode;
    m_sentinel->m_prev = newNode;
  }
  m_size++;
}


template <typename T>
void MyList<T>::pop_front()
{
	if(m_size  <= 1)
  {
    clear();
  }
  else
  {
    Node<T> *temp = m_sentinel->m_next;
    m_sentinel->m_next = m_sentinel->m_next->m_next;
    m_sentinel->m_next->m_prev = nullptr;
    m_size--;
    delete temp;
  }
}



template <typename T>
void MyList<T>::pop_back()
{
  if(m_size  <= 1)
	{
		clear();
	}
  else
  {
    Node<T> *temp = m_sentinel->m_prev;
    m_sentinel->m_prev = m_sentinel->m_prev->m_prev;
    m_sentinel->m_prev->m_next = nullptr;
    m_size--;
    delete temp;
  }	
}


template <typename T>
void MyList<T>::insert(int i, const T &x)
{
  Node<T> *curr = nullptr; 
	if(i >= size())
	{
		push_back(x);
	}
  else if(i <= 0)
	{
		push_front(x);
	}
  else
	{
		curr = m_sentinel;
    for(int j = 0; j < i; j++)
    {
      curr = curr->m_next;
    }

    Node<T> *newNode = new Node<T> (x, curr, curr->m_next);
    curr->m_next->m_prev = newNode;
    curr->m_next = newNode;
    m_size++;
	}
}


template <typename T>
void MyList<T>::remove(T value)
{  
  Node<T> *curr = m_sentinel;
	for(int i = 0; i < m_size && curr != nullptr; i++)
	{
		curr = curr -> m_next;
		if( curr ->  m_element == value)
		{
			erase(i);
			i--;
		}
	}
}


template <typename T>
void MyList<T>::erase(int i)
{
  Node<T> *currentptr = m_sentinel;
	if(i == 0)
	{
		pop_front();
	}
  else if(i == m_size-1)
	{
		pop_back();
	}
  else
	{
	  Node<T> *currentptr = m_sentinel->m_next;
		for(int j = 0; j < i && j < m_size-1; j++)
		{
			currentptr = currentptr->m_next;
		}
		
		currentptr->m_prev->m_next = currentptr->m_next;
		currentptr->m_next->m_prev = currentptr->m_prev;
		delete currentptr;
		m_size--;
	}
}


template <typename T>
void MyList<T>::reverse()
{
  Node<T> *currentptr = m_sentinel->m_next;
	while(currentptr != nullptr)
	{
		std::swap(currentptr->m_prev, currentptr->m_next);
		currentptr = currentptr->m_prev;	
	}
	std::swap(m_sentinel->m_prev, m_sentinel->m_next);
	currentptr = nullptr;
	delete currentptr;
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


