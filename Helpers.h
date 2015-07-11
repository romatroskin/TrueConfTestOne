#pragma  once
#include <cstdint>
#include <cstdlib>
#include <vector>
#include <algorithm>

namespace Helpers
{
  template<typename T>
  class RandomGenerator
  {
  public:
    RandomGenerator(T start = 0, T end = 1) : m_start(start), m_end(end) {};
    ~RandomGenerator() {}

    T operator() () const
    { return (this->m_start + std::rand() % this->m_end); }

  private:
    T m_start;
    T m_end;
  };

  template<typename T>
  class VecRemover
  {
  public:
    VecRemover(std::map<size_t, T> dic) : m_map(dic) {};
    ~VecRemover() {}

    bool operator() (const T& a) const
    {
      for(typename std::map<size_t, T>::const_iterator it = m_map.begin();
          it != m_map.end(); it++)
      {
        if(it->second == a)
        {
          return false;
        }
      }
      return true;
    }

  private:
    std::map<size_t, T> m_map;
  };

}
