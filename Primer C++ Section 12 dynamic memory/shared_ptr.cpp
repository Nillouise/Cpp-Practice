#include<iostream>  
#include<cstring>  
#include<string>  
#include<memory>  
  
using namespace std;  
  
class Simple  
{  
    public:  
        Simple(int p = 0)  
        {     
            number = p;  
            std::cout << "Simple::" << number << std::endl;  
        }     
  
        ~Simple()  
        {     
            std::cout << "~Simple::" << number << std::endl;  
        }     
  
        void PrintSomething()  
        {     
            std::cout << "PrintSomething:" << info_extend.c_str() << std::endl;  
        }     
  
        std::string info_extend;  
        int number;  
};  
  
void TestSharedPtr()  
{  
    std::shared_ptr<Simple> my_memory(new Simple(1));  
    if(my_memory.get())  
    {  
        my_memory->PrintSomething();  
  
        my_memory.get()->info_extend = "Additon";  
        my_memory->PrintSomething();  
  
        (*my_memory).info_extend += "other";  
        my_memory->PrintSomething();  
    }  
  
}  
  
  
int main()  
{  
    TestSharedPtr();  
    return 0;  
} 
