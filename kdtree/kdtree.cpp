#include <iostream>
#include <vector>

using namespace std;

template <class t>

class kdtree
{
  public:
    
    kdtree (int k, int initCap)
    {
      size = 0;
      nodes.resize(initCap);
    }
    
    void addPoint (t p[])
    {
      
    }
    
    bool findPoint (t p[])
    {
    
    }
    
    bool deletePoint (t p[])
    {
    
    }
    
  
  private:
    struct kdnode{t coord[3];};
    vector <kdnode> nodes;
    int size;
};

int main ()
{
  kdtree <int> tree(2, 8);
	
	return 0;
}
