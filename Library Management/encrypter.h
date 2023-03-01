#pragma once
#include<iostream>
#include<cstring>
#include<string>
using namespace std;

namespace encrypt
{
    char Encrypt(char alpha)
    {
        switch (alpha)
        {
        case 'A':return '`';
            break;
        case 'a':return '~';
            break;
        case 'B':return '1';
            break;
        case 'b':return '!';
            break;
        case 'C':return '2';
            break;
        case 'c':return '@';
            break;
        case 'D':return '3';
            break;
        case 'd':return '#';
            break;
        case 'E':return '4';
            break;
        case 'e':return '$';
            break;
        case 'F':return '5';
            break;
        case 'f':return '%';
            break;
        case 'G':return '6';
            break;
        case 'g':return '^';
            break;
        case 'H':return '7';
            break;
        case 'h':return '&';
            break;
        case 'I':return '8';
            break;
        case 'i':return '*';
            break;
        case 'J':return '9';
            break;
        case 'j':return '(';
            break;
        case 'K':return '0';
            break;
        case 'k':return ')';
            break;
        case 'L':return '-';
            break;
        case 'l':return '_';
            break;
        case 'M':return '=';
            break;
        case 'm':return '+';
            break;
        case 'N':return '|';
            break;
        case 'n':return ']';
            break;
        case 'O':return '}';
            break;
        case 'o':return '[';
            break;
        case 'P':return '{';
            break;
        case 'p':return ';';
            break;
        case 'Q':return ':';
            break;
        case 'q':return '"';
            break;
        case 'R':return '?';
            break;
        case 'r':return '/';
            break;
        case 'S':return '.';
            break;
        case 's':return '>';
            break;
        case 'T':return '<';
            break;
        case 't':return ',';
            break;
        case 'U':return 'a';
            break;
        case 'u':return 'b';
            break;
        case 'V':return 'c';
            break;
        case 'v':return 'd';
            break;
        case 'W':return 'e';
            break;
        case 'w':return 'f';
            break;
        case 'X':return 'g';
            break;
        case 'x':return 'h';
            break;
        case 'Y':return 'i';
            break;
        case 'y':return 'j';
            break;
        case 'Z':return 'k';
            break;
        case 'z':return 'l';
            break;
        case '1':return 'm';
            break;
        case '2':return 'n';
            break;
        case '3':return 'o';
            break;
        case '4':return 'p';
            break;
        case '5':return 'q';
            break;
        case '6':return 'r';
            break;
        case '7':return 's';
            break;
        case '8':return 't';
            break;
        case '9':return 'u';
            break;
        case '<':return 'v'; //edited
            break;
        case '>':return  'w'; //edited
            break;
        case '0':return 'x';
            break;
        case '@':return 'y'; //edited
            break;
        case '~':return 'z'; //edited
            break;
        case ' ': return 'Q';
            break;
        case '.': return 'R';
            break;
        case '\'':return 'S';
            break;
        case '"': return 'T';
            break;
        case ',': return 'U';
            break;
        case '?': return 'V';
            break;
        case ':': return 'W';
            break;
        case '_': return 'X';
            break;
        case '/': return 'Y';
            break;
        case '\\': return 'Z';
            break;
        case ';': return 'A';
            break;
        case '#': return 'B'; //edited
            break;
        case '$': return 'C'; //edited
            break;
        case '%': return 'E'; //edited
            break;
        case '^': return 'F'; //edited
            break;
        case '&': return 'G'; //edited
            break;
        case '*': return 'H'; //edited
            break;
        case '(': return 'I'; //edited
            break;
        case ')': return 'J'; //edited
            break;
        case '-': return 'K'; //edited
            break;
        case '+': return 'L'; //edited
            break;
        case '=': return 'M'; //edited
            break;
        case '|': return 'N'; //edited
            break;
        case '}': return 'O'; //edited
            break;
        case '{': return 'P'; //edited
            break;
        case '!': return 'D';
            break;
        default:cout << "Invalid Character '" << alpha << "'" << endl;
        }
        return NULL;

    }
     
    /*void write(char encrypt_datas[], int total_line)
    {
        int j = 0;
        fstream write_;
        write_.open("encryptfile.txt", ios::out | ios::in | ios::app);
        if (write_.is_open())
        {
            while (j <= total_line) {
                write_ << encrypt_datas[j];
                j++;
            }
            write_ << endl;
        }
    }
    */
	 string entry(string name)
	{     
         string return_string ="";
		  int n = (int) name.length();
          char write_data[20];
          char encrypted_data[20];
		 strcpy_s(write_data,name.c_str());

         for (int i = 0; i < n; i++) {
             encrypted_data[i] = Encrypt(write_data[i]);
             return_string += encrypted_data[i];
         }
         
         return return_string;

	}
}
