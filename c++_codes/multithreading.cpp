extern "C"
 {
    #include <unistd.h>
 }
 
#include <iostream> 
 
using namespace std;
 
void function1();
void function2();
 
int main()
{
function1();
function2();
return 0;
}
 
void function1()
{
 
    std::cout << "hello..." << endl ;
    sleep(2); // fall asLeep here for 2 seconds...
 
}
 
void function2()
{
    std::cout << " ....world" << endl ;
}