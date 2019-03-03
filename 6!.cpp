//Напишите программу, проверяющую последовательность скобок на корректность. В последовательности встречаются 3 вида скобок: ( ),{ },[ ].
//Скобочная последовательность называется корректной, если каждая скобка закрыта соответствующей.


#include <iostream>
using namespace std;



int main() {
    int n;
    cin >> n;
    char* arr = new char [n];
    for (int i = 0; i < n; i++){
      cin >> *(arr + i);
    } 

   bool correct;
     int m1 = 0,s1 = 0,t1 = 0,m2 = 0, s2 = 0, t2 = 0;
     for (int i = 0; i < n; i++){
     if (arr[i] == ")") m1++;
     if (arr[i] == "(") m2++;
     if (arr[i] == "[") s1++;
     if (arr[i] == "]") s2++;
     if (arr[i] == "{") t1++;
     if (arr[i] == "}") t2++;
     }
     if (m1 != m2 || s1 != s2 || t1 != t2) {
       correct = 0; 
     } else {
       for (int i = 0; i < n; i++){
        if (arr[i] == "("){
          for (int j = i; j < n; j++){
            if (arr[j] == ")"){
             char * arr2 = new char [n - 2];
             for (int g = 0; g < i; g++){
               arr2 [g] = arr [g];
             }
             for (int g = i + 1; g < j; g++){
               arr2 [g] = arr [g + 1];
             }
             for (int g = j + 1; g < n; g++){
               arr2 [g] = arr [g + 2];
             }
             n -= 2;
             arr = arr2;
            }
            break;
          }
        }
  
        if (arr[i] == "{"){
          for (int j = i; j < n; j++){
            if (arr[j] == "}"){
             char * arr2 = new char [n - 2];
             for (int g = 0; g < i; g++){
               arr2 [g] = arr [g];
             }
             for (int g = i + 1; g < j; g++){
               arr2 [g] = arr [g + 1];
             }
             for (int g = j + 1; g < n; g++){
               arr2 [g] = arr [g + 2];
             }
             n -= 2;
             arr = arr2;
            }
            break;
          }
        }

        if (arr[i] == "["){
          for (int j = i; j < n; j++){
            if (arr[j] == "]"){
             char * arr2 = new char [n - 2];
             for (int g = 0; g < i; g++){
               arr2 [g] = arr [g];
             }
             for (int g = i + 1; g < j; g++){
               arr2 [g] = arr [g + 1];
             }
             for (int g = j + 1; g < n; g++){
               arr2 [g] = arr [g + 2];
             }
             n -= 2;
             arr = arr2;
            }
            break;
     }
    }
    }
    if (n == 0) {
      correct = 1;
    } else {
      correct = 0;
    }
    }
   


  if (correct == 0) cout << "incorrect";
  else cout << "correct";







 return 0;
}
