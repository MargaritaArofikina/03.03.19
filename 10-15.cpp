//Реализуйте класс АВЛ-дерево. Для АВЛ-дерева реализуйте методы, определяющую высоту дерева, 
//выписывание элементов порядке возрастания/убывания, определение количества элементов на уровне k. 

# include <iostream> 
using namespace std; 

struct Node{ 
int data; 
Node* left = NULL; 
Node* right = NULL; 
}; 

class AVL { 
  int data;
Node* root; 

AVL() {    //конструктор
root(NULL);
}

void del (Node* root){
  if (root -> left) del (root -> left);
  if (root -> right) del (root -> right);
  delete root;
} 

~AVL(){     //деструктор
  del (root);
}

int height (Node* root){  //определение высоты
int m = 0, n = 0;

if (root -> left != NULL) {
  m++;
  height(root -> left);
}
if (root -> right != NULL) {
  n++;
  height(root -> right);
}
if (n >= m) return n;
if (m > n) return m;
}

int push (Node* root){
  int s;
  s = (root -> data);
  return s;
}

int increase (Node* root,n){    //выписывание по возрастанию
  int* arr = new int [n];
  for (int i = 0; i < n; i++){
  *(arr + i) = AVL.push;
  if (root -> left != NULL) increase (root -> left);
  if (root -> right != NULL) increase (root -> right);
  }
  for (int i = 0; i < n; i++){   //сортировка
    for (int j = 0; j < n; j++){
     if (*(arr + j + 1) < *(arr + j)) {
       int k = *(arr + j + 1);
       *(arr + j + 1) = *(arr + j);
       *(arr + j) = k;
     }
    }
  }
  for (int i = 0; i < n; i++){
    cout << *(arr + i);
  }
  }

 int decrease (Node* root,n){    //выписывание по убыванию
  int* arr = new int [n];
  for (int i = 0; i < n; i++){
  *(arr + i) = AVL.push;
  if (root -> left != NULL) increase (root -> left);
  if (root -> right != NULL) increase (root -> right);
  }
  for (int i = 0; i < n; i++){   //сортировка
    for (int j = 0; j < n; j++){
     if (*(arr + j + 1) > *(arr + j)) {
       int k = *(arr + j + 1);
       *(arr + j + 1) = *(arr + j);
       *(arr + j) = k;
     }
    }
  }
  for (int i = 0; i < n; i++){
    cout << *(arr + i);
  }
  }

}



int main(){

 AVL tree = new AVL;
 

  return 0;
}
