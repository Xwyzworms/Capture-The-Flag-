#include<iostream>
#include<string>
#include<cctype>



std::string convertTolower(std::string str) 
{
    std::string returnStr = "";
    for(int i = 0; i< str.size(); i++) 
    {
        char c = tolower(str[i]);
        returnStr += (c);
    }
    return returnStr;

}

std::string decrypt(std::string str) 
{
    std::string dec = "";
    for(int i =0 ; i < str.size(); i++) 
    {
        char theWord = str[i];
        if(std::isalpha(str[i])) 
        {
            int currentChar = static_cast<int>(str[i]);
            if(currentChar + 13 > 122 )
            {
               
                theWord = char(currentChar + 13 - 26);
            }
            else 
            {
                theWord = char(currentChar + 13);
            }
        }
        dec += theWord;

    }
    return dec;
}

int main() 
{
    std::string input = convertTolower("cvpbPGS{arkg_gvzr_V'yy_gel_2_ebhaqf_bs_ebg13_uJdSftmh}");
    std::cout<<decrypt(input)<<std::endl;
    
    return 0;
}