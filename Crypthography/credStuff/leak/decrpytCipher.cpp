/*
    Creator : Xoros Lacknatas Ingradu Jernair
    Description : What is Description ?
    Qoute : Simply say its okay
    DATE : Uknown
*/

#include<iostream>
#include<string>
#include<vector>
#include<cctype>
#include<fstream>

std::string solve(std::string cipher) 
{
    std::string ans;
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
            ans += trueRepresentation;
        }
        else 
        {
        ans += cipher[i];
        }
    }
    return ans;
}

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
void writeFile(const std::vector<std::string> contents,
               const std::vector<std::string> passwords) 
        {
            std::ofstream outputFile("solutions.txt");
            std::string converted = "";
            for(int i = 0 ; i < passwords.size() ; i++) 
            {
                converted = solve(toLowerStr(passwords[i]));
                std::string c = contents[i];
                c.append(" : ").append(converted).append("\n");
                outputFile << c;
            }
            outputFile.close();
            std::cout<<"File written\n";
        }

int main() 
{
    std::vector<std::string> contents = readFile("usernames.txt");
    std::vector<std::string> passwords = readFile("passwords.txt");
    writeFile(contents, passwords);
    std::cout<<solve(toLowerStr("cvpbPGS{P7e1S_54I35_71Z3}"))<<std::endl;
    return 0;
}