

#include <iostream>
using namespace std;

class double_stack {

 public:
 unsigned int length;
 int m,n;

 public:
 double_stack(){   //конструктор без аргументов
  	double_stack * arr = new double_stack [1];
    *(double_stack + 0) = 0;
	} 

 double_stack(int length){   //конструктор с одним аргументом
	 double_stack * arr = new double_stack [unsigned int length];
   for (int i = 0; i < length; i++){
   *(double_stack + i) = 0;
   }
	}

 const double_stack &operator = (const double_stack &A){   //оператор присвоения
		m = A.m;
		n = A.n;
		return *this;
	}

  double_stack operator[](unsigned int n){   //оператор индексации
    return arr [n];
  }

 void resize_plus (double_stack * arr, double x){   //увеличение длины
  double_stack * arr2 = new double_stack [length + x];
  for (int i = 0; i < length; i++){
    *(arr2 + i) = *(arr + i);
  }
  for (int i = length; i < length + x; i++){
    *(arr2 + i) = 0;
  }
 arr = arr2;
 }

 void resize_minus (double_stack * arr, double x){   //уменьшение длины с конца
  double_stack * arr2 = new double_stack [length - x];
  for (int i = 0; i < length - x; i++){
    *(arr2 + i) = *(arr + i);
  }
 arr = arr2;
 }

 ~ double_stack(){   //деструктор
   delete [] arr;
  }

  void push_front (double_stack * arr, double x){   //добавление в начало
  resize_plus(1);
  length += 1;
  for (int i = length - 1; i > 0; i--){
    *(arr + i) = *(arr + i - 1);
  }
  *(arr + 0) = x;
 }

 void pop_front(double_stack * arr){   //удаление из начала
  for (int i = 1; i < length; i++){
    *(arr + i - 1) = *(arr + i);
  }
  resize_minus(1);
 }

 void push_back (double_stack * arr, double x){   //добавление в конец
  resize_plus(1);
  length += 1;
  *(arr + length) = x;
 }

  double pop_back(double_stack * arr){   //извлечение из конца
  int k = *(arr + length - 1);
  resize_minus(1);
  return k;
 }


 double_stack &operator + (double_stack A, const double_stack &B) {    // +
	return A += B;
}
double_stack &operator - (double_stack A, const double_stack &B) {    // -
	return A -= B;
}
double_stack &operator * (double_stack A, const double_stack &B) {    // *
	return A *= B;
}
double_stack &operator / (double_stack A, const double_stack &B) {    // /
	return A /= B;
}


bool operator == (const double_stack &A, const double_stack &B) {    // ==
	return ((A.m == B.m) && (A.n == B.n));
}
bool operator != (const double_stack &A, const double_stack &B) {    // !=
	return ! (A == B);
}
bool operator > (const double_stack &A, const double_stack &B) {    // >
	return ((((A.m*B.n) - (B.m * A.n)>0) && (A.n*B.n > 0)) || (((A.m*B.n) - (B.m * A.n) < 0) && (A.n*B.n < 0)));
}
bool operator < (const double_stack &A, const double_stack &B) {    // <
	return ((((A.m*B.n) - (B.m * A.n)<0) && (A.n*B.n > 0)) || (((A.m*B.n) - (B.m * A.n) > 0) && (A.n*B.n < 0)));
}
bool operator >= (const double_stack &A, const double_stack &B) {    // >=
	return !(A < B);
}
bool operator <= (const double_stack &A, const double_stack &B) {    // <=
	return !(A > B);
}

istream &operator >>(istream &in, double_stack &A)    // ввод
{
	in >> A.m;
	return in;
}

ostream &operator <<(ostream &out, const double_stack &A)    // вывод
{
	out << A.m;
	return out;
}

};



int main() {

    int size,x;
    cin >> size;

    double_stack * arr = new double_stack [size];
    for (int i = 0; i < size; i++){
      cin >> *(arr + i);
    }

    cin >> x;
    push_back (arr , x);
    for (int i = 0; i <= size; i++){
      cout <<  *(arr + i);
    }
    pop_back(arr);

    push_front (arr, x);
    for (int i = 0; i <= size; i++){
      cout <<  *(arr + i);
    }
    pop_front(arr);


 return 0;
}
