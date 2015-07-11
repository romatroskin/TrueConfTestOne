#pragma  once
#include <iostream>
#include <map>
#include <vector>
#include "Constants.h"
#include "Helpers.h"

namespace Factories
{
  template<typename T>
  class ContainersFactory
  {
  public:
    typedef std::map<size_t, T> TMap;
    typedef std::vector<T> TVector;
    typedef Helpers::RandomGenerator<T> TRandomGenerator;
    typedef Helpers::RandomGenerator<size_t> TRandomSizeGenerator;
    typedef Helpers::VecRemover<T> TVecRemover;

    static void Generate(TMap& dic, size_t size, T start, T end)
    {
      if(!dic.empty())
      {
        dic.clear();
      }

      for(size_t i = 0; i < size; i++)
      {
        dic[i] = TRandomGenerator(start, end)();
      }
    }

    static void Generate(TVector& vec, size_t size, T start, T end)
    {
      vec.resize(size);
      generate(vec.begin(), vec.end(), TRandomGenerator(start, end));
    }

    static void Print(const TVector& vec)
    {
      std::cout << "[ ";
      std::copy(vec.begin(), vec.end(),
        std::ostream_iterator<T>(std::cout, " "));
      std::cout << "]" << std::endl;
    }

    static void Print(const TMap& dic)
    {
      std::cout << "{ ";
      for(typename TMap::const_iterator it = dic.begin(); it != dic.end();
          it++, std::cout << " ") { std::cout << it->second; }
      std::cout << "}" << std::endl;
    }

    static void Erase(TMap& dic, size_t start, size_t end)
    {
      size_t count = TRandomSizeGenerator(start, end)();
      typename TMap::const_iterator it = dic.begin();
      for(size_t i = 0; i < count; i++)
      {
        dic.erase(it++);
      }
    }

    static void Erase(TVector& vec, size_t start, size_t end)
    {
      size_t count = TRandomSizeGenerator(start, end)();
      typename TVector::const_iterator it = vec.begin();
      vec.erase(it, it + count);
    }

    static void Synchronize(TVector& vec, TMap& dic)
    {
      for(typename TMap::const_iterator it = dic.begin(); it != dic.end(); )
      {
        typename TMap::const_iterator curIt = it++;
        if(std::find(vec.begin(), vec.end(), curIt->second) == vec.end())
        {
          dic.erase(curIt);
        }
      }

      typename TVector::iterator pend = std::remove_if(vec.begin(), vec.end(), TVecRemover(dic));
      if(pend != vec.end()) {
        vec.erase(pend, vec.end());
      }
    }

  private:
      ContainersFactory();
      ~ContainersFactory();
  };
}
