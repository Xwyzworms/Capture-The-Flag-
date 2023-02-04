/*
    Creator : Xoros Lacknatas Ingradu Jernair
    Description : Em em em
    Qoute : Nothing matters
    DATE : Unknown
*/

#include<iostream>
#include<fstream>
#include<string>
#include<vector>

std::string openFile()
{
    std::fstream fileco;
    std::string tp;
    fileco.open("message.txt", std::ios::in); // To perform read operation
    if(fileco.is_open())  
    {
        while(std::getline(fileco, tp)); // Read the file and put it into tp
    }   
    fileco.close();
    return tp;
}

std::vector<std::string> splitString(std::string str, char sep)
{
    int startIndex = 0 ;
    int endIndex = 0;
    std::vector<std::string> vect; 
    for (int i = 0 ; i < str.size() ; i++) 
    {
        if(str[i] == sep || i ==str.size()) 
        {
            std::string temp;
            endIndex = i;
            temp.append(str, startIndex, endIndex - startIndex); // Get the string ( from current start index to endIndex - startINdex) ( biar si delimiter ga diambil)
            vect.push_back(temp);
            startIndex = endIndex + 1; // Just increse the start index
                   
        }
    }
    return vect;
}

std::vector<int> convertListStrToInt(std::vector<std::string> vect) 
{
    std::vector<int> intVector;
    for(std::string str : vect) 
    {
        intVector.push_back(std::stoi(str));
    }
    return intVector;
}

int modInverse(int A, int M) 
{
    // A* b % M == 1 
    // Find the B
    int ans = -1;
    for(int i = 1 ; i < M; i++) 
    {
        int calc = A  * i  ; // Menghindari nilai I / A yang melebihi M
        if(calc % M == 1) 
        {
            ans = i;
        }
    }
    return ans;
}

void solve(std::vector<int> vect) 
{   
    /*
        Solver 
        1. Get The Modular then Inverse it
        2. Map it 
            {1 - 26} Alphabet 
            Ascii Table 65 - 90 {Represent the Char Uppercase} ( 1 - 26 )
            Ascii table 0 - 9 {Represent the Decimal } (27 - 36)
            Ascii table 27 { Represent underscore}
    */
   
    std::string ans="picoCTF{";
    for(int ve : vect) 
    {
        int inverseModular = modInverse(ve,41);
        
        if(inverseModular <= 26) 
        {
            ans.append(1,char(65+inverseModular - 1));
        }
        else  if(inverseModular > 26 && inverseModular <=36) 
        {
            ans.append(1,'0' + (inverseModular - 27));
        }
        else 
        {
            ans.append(1,char(95));
        }
    }
    ans.append("}");
    std::cout<<ans<<std::endl;
}




int main()
{
    std::string content = openFile();
    std::vector<std::string> cst = splitString(content, ' ');
    std::vector<int> slw = convertListStrToInt(cst);
    solve(slw);

    return 0;
}