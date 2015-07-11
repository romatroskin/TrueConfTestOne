#include <iostream>
#include <algorithm>
#include <iterator>
#include <ctime>
#include "Constants.h"
#include "ContainersFactory.h"
using namespace std;

typedef Factories::ContainersFactory<uint16_t> TFactory;

int main(int argc, char** argv)
{
  srand( unsigned(time(0)) );

  TFactory::TMap mapRand;
  TFactory::TVector vRand;

  TFactory::Generate(vRand, CONTAINERS_SIZE, 1, 9);
  TFactory::Generate(mapRand, CONTAINERS_SIZE, 1, 9);

  cout << "Generated containers: " << endl;
  TFactory::Print(vRand);
  TFactory::Print(mapRand);
  cout << endl;

  TFactory::Erase(vRand, 1, 15);
  TFactory::Erase(mapRand, 1, 15);

  cout << "Erased containers: " << endl;
  TFactory::Print(vRand);
  TFactory::Print(mapRand);
  cout << endl;

  TFactory::Synchronize(vRand, mapRand);

  cout << "Synchronized containers: " << endl;
  TFactory::Print(vRand);
  TFactory::Print(mapRand);
  cout << endl;

  return 0;

}
