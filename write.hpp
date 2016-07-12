#include <exception>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

template <typename TYPE>
void writeCSVContents(const std::string filename, std::vector<TYPE>& container, unsigned NCOLS);
