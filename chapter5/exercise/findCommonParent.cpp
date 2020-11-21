#include "../SqTree.h"

int Comm_Ancestor(SqTree T, int i, int j)
{
  if (T[i].value != '#' && T[j].value != '#')
  {
    while (i != j)
    {
      if (i > j)
        i /= 2;
      else
        j = j / 2;
    }
    return T[i].value;
  }
}