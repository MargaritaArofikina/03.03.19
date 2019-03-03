//Реализуйте структуру данных циклический массив пар целых чисел. 
//Циклический массив размера N - массив в котором за последним элементом(N-1) снова идет первый(0) и так далее. 
//В этой задаче необходимо использовать структуру pair из STL
// а) Стандартные для массива (array) поля и методы. 
// б) Сдвиг всех элементов массива на k позиций влево по циклу, работающий за O(1). 
//k - целое число.


#include <iostream>
#include <utility>
using namespace std;

struct array {
  
    pair <int, int>* data;         // a) 
    int k = 0;
    int size;

    array (int n) {
        size = n;
        data = new pair <int, int> [n];
    };

    array (array& A) {
        size = A.size;
        data = A.data;
    };

    pair <int, int> &operator[](int i){ //размер массива
        while (i >= size) {
            i -= size;
        }
        return data[i];
    };

    void input () {
        int j, a, b;
        for (int i = k; i < size + k; i++) {
            j  = i;
            while (j >= size)
                j -= size;
            cin >> a >> b;
            data[j] = make_pair(a, b);
        }
    };

    void output() {
        int j;
        for (int i = k; i < size + k; i++) {
            j = i;
            while (j >= size)
                j -= size;
            cout << endl << data[j].first << " " << data[j].second;
        }
    };

    void trans (int m) {      // б)
        k += m;
    }
};

int main() {

    int n, m;
    cin >> n;
    cout << endl << endl;

    array A (n);
    A.input();
    A.output();
    cout << endl << endl;

    cin >> m;
    A.trans (m);
    A.output();

    return 0;
}
