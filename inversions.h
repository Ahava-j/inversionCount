#ifndef INVERSION_H
#define INVERSION_H

#include <vector>

int inversionCount(std::vector<int>& myArr);
int inversionRecursive(std::vector<int>& myArr, int lIndex, int rIndex);
int inversionCombine(std::vector<int>& myArr, int lIndex, int middleIndex, int rIndex);

#endif // INVERSION_H