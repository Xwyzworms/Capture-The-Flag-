"""
    Created by : Xoros Lacknatas Ingradu Jernain
    Description : Just a simple script
    DATE : Unknown
    Qoute : What is it ?
"""
from typing import List
import re
def readText(fileName : str) -> List[int]:
    """
        Read the Text file content
    """
    content : List[int] = []
    with open(fileName, "r") as fuf:
        contents = fuf.readline().split(" ")
        for c in contents:
            if(c != ""):
                content.append(int(c))
    return content

def dec(listContent : List[int]):
    """
        Decrpyt Content
        1. Mod it with 37
        2. Map it to 
            0-25 --> ALphabet ( UPPERCASE )
            26-35 --> Decimal 
            36 --> Underscore        

        Ans 
        Ascii Table 65 - 90 {Represent the Char Uppercase} ( 0 - 25 )
        Ascii table 0 - 9 {Represent the Decimal } (26 - 35)
        Ascii table 95 { Represent underscore}
    """
    modded37 : List[int] = []
    chars : List[str] = []
    for c in listContent:
        modded37.append(c % 37)
    
    for m in modded37:
        if(m <= 25):
            chars.append(chr(m + 65))
        elif (m > 25 and m <=35 ):
            chars.append(str(m-26))
        else :
            chars.append(chr(95))
    
    print("picoCTF{%s}" % "".join(chars))

if __name__ == "__main__":
    c : List[int] = readText("message.txt")
    dec(c)
