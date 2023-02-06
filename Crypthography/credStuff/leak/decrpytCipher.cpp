#include<iostream>
#include<string>
#include<vector>
#include<cctype>
#include<fstream>


std::vector<std::string> readFile(const std::string filename) 
{
    std::vector<std::string> contents;
    std::fstream filecontents;
    std::string temp;
    filecontents.open(filename, std::ios::in) ;
    if(filecontents.is_open()) 
    {
        while(std::getline(filecontents, temp)) 
        {
            contents.push_back(temp);
            temp ="";
        }
    }
    filecontents.close();
    return contents;
}

std::string toLowerStr(std::string str)
{   
    std::string res;
    for(int i =0 ; i<str.size(); i++) 
    {
        res += std::tolower(str[i]);
    }
    return res;
}

void solve(std::string cipher) 
{
    std::vector<char> ans;
    for(int i = 0 ; i<cipher.size(); i++) 
    {

        if(std::isalpha(cipher[i])) 
        {

            int theChar = static_cast<int>(cipher[i]) + 13;
            char trueRepresentation ;
            if(theChar > 122) 
            {
                trueRepresentation = char(theChar - 26);
            }
            else 
            {
                trueRepresentation = char(theChar );
            }
            ans.push_back(trueRepresentation);
        }
        else 
        {
        ans.push_back(cipher[i]);
        }
    }

    for(auto a : ans) 
    {
        std::cout<<a;
    }
}

void display() 
{

}

int main() 
{
    std::string passwd = toLowerStr("cvpbPGS{P7e1S_54I35_71Z3}");
    std::cout<<passwd<<std::endl;
    solve(passwd);
    return 0;
}