// my_class.h
#include <vector>

using namespace std;
class sortingFuncs{
    public:
          bool   intSorted(vector<int> ls);
          bool   floatSorted(vector<float> ls);
           int   randInt(int min,int max);
   vector<int>   intBubble(vector<int> unsorted);
 vector<float>   floatBubble(vector<float> unsorted);
           int   intPrintL(vector<int> ls);
           int   floatPrintL(std::vector<float> ls);
};