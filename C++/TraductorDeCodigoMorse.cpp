#include <iostream>
#include <string>
#include <windows.h>
#define MAX 42

using namespace std;

string morse[] = {
    // Letras
    ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---",
    "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-",
    "..-", "...-", ".--", "-..-", "-.--", "--..",
    // Números
    "-----", ".----", "..---", "...--", "....-", ".....", "-....", "--...",
    "---..", "----.",
    // Símbolos comunes
    ".-.-.-", "--..--", "..--..", "-.-.--", ".--.-.", "...-..-",
    // Agrega más símbolos según tus necesidades
};

string ascii[] = {
    // Letras
    "A", "B", "C", "D", "E", "F", "G", "H", "I", "J",
    "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T",
    "U", "V", "W", "X", "Y", "Z",
    // Números
    "0", "1", "2", "3", "4", "5", "6", "7", "8", "9",
    // Símbolos comunes
    ".", ",", "?", "!", "/", "@"
    // Agrega más símbolos según tus necesidades
};

void convertir(string cadena){
    for (size_t i = 0; i < cadena.length(); i++)
    {
        char letra = toupper(cadena[i]);
        if (letra == ' ')
        {
            cout << " ";
            Sleep(500);
            continue;
        }
        for (size_t j = 0; j < MAX; j++)
        {
            if (letra == ascii[j][0])
            {
                for (size_t jj = 0; jj < morse[j].length(); jj++)
                {
                    if (morse[j][jj] == '.')
                    {
                        cout << ".";
                        Beep(300, 100);
                        Sleep(200);
                    }
                    else if (morse[j][jj] == '-')
                    {
                        cout << "-";
                        Beep(700, 100);
                        Sleep(200);
                    }
                }
                cout << " ";
                break;
            }
            
        }
        Sleep(500);
        
    }
    
}

int main(){
    string escritura;
    cout<<"Ingrese una palabra o numeros para convertir en morse: \n";
    cin >> escritura;
    convertir(escritura);
    Sleep(1999);

    return 0;
}