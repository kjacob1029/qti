
template <class T>
class CircularBuffer
{
  typedef std::atomic<int> AtomicInt;

 public:
  CircularBuffer(int n_);
  ~CicularBuffer();

  CircularBuffer(CircularBuffer& t_);
  CircularBuffer& operator= (CircularBuffer& t_);

  CircularBuffer(CircularBuffer&& t_);

  bool empty() const;
  bool full() const;

  void push(const T& t_);
  T&   pop();

 private:
  T* _arrT;
  AtomicInt _head;
  AtomicInt _tail;

  int _maxElems;
};

