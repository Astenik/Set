#include <iostream>
#include "Set.h"

int main()
{
    Set<int> ob;
    for(int i = 0; i < 7; ++i)
    {
        ob.insert(i);
    }
    ob.print();
    std::cout << ob.contain(10) << " " << ob.contain(4) << std::endl;
    ob.remove_elem(4);
    ob.remove_elem(0);
    ob.remove_elem(6);
    ob.print();
    
    Set<int> ob2(ob);
    ob2.print();
    ob2.insert(0);
    ob2.insert(4);
    ob2.insert(6);
    
    Set<int> ob3;
    ob3 = ob + ob2;
    ob3.print();
    
    return 0;
}
