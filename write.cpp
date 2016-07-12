#include "write.hpp"

template <typename TYPE>
void writeCSVContents(const std::string filename, std::vector<TYPE>& container, unsigned NCOLS)
{
  try{

    std::ofstream outfile;
    outfile.open( filename.data() , std::ios::app );

    const unsigned ContainerLength= container.size();
    if(not ((ContainerLength % NCOLS)==0)) throw 121;

    if(outfile){
      for(unsigned containerIndex(0); containerIndex<ContainerLength; ){
        for(unsigned lineIndex(0); lineIndex < (NCOLS-1); ++lineIndex){
          outfile << container[containerIndex++] << " ";
        }
        outfile << container[containerIndex++] << "\n";
      }
    }
    outfile.close();
  }
  catch(int e){
    std::cout << "An exception occured. Nr. " << e << '\n';
  }
}


template void writeCSVContents<double>(const std::string, std::vector<double>&, unsigned);
template void writeCSVContents<float>(const std::string, std::vector<float>&, unsigned);
template void writeCSVContents<int>(const std::string, std::vector<int>&, unsigned);
template void writeCSVContents<std::string>(const std::string, std::vector<std::string>&, unsigned);
