#include<iostream>
#include<vector>

std::string dec(std::vector<int> inputs ) 
{
    std::string ans="";
    for(int a : inputs) 
    {
        char ch = char(96+a);
        ans+=ch;
    }
    return ans;
} 



int main() 
{
    std::vector<int> inputs = {16, 9, 3, 15, 3, 20, 6, 20,8, 5,14,21,13,2,5,18,19,13,1,19,15,14};
    std::cout<<dec(inputs)<<std::endl;
    return 0;
}