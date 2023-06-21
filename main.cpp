#include <iostream>
using std::cout;
using std::endl;
template <typename type1>
void GetArray(type1* arr, int size) //реализация шаблонной функции
{
    type1 arr1[size];  //создание массива такого же типа, как и исходный, для помещения туда уникальных элементов
    int k = 0; // переменная, которая впоследствии будет содержать точное количество элементов нов. массива
    cout << "First array: ";
    for (int i = 0; i < size;i++)
    {
        cout << arr[i] << ' ';
    }
    cout << endl; // вывод исходного массива
    for (int i = 0; i < size;i++)
    {
        int c = 1;   //проходим 2ным циклом по массиву, если этот элемент уже встречался, то некий счетчик заравниваем в нуль
        for (int j = 0;j < i; ++j)
        {
            if (arr[i] == arr[j]) c = 0;
        }
        if (c == 1) arr1[k++] = arr[i]; //в конце данный элемент добавляем в новый массив и увеличиваем его размер
    }
    cout << "New array: ";
    for (int i = 0;i<k;++i)
    {
        cout << arr1[i] << ' ';
    }
    cout << endl; // вывод нового массива
}
int main(){
    char arrch[] = {'H','e','l','l','o','W','o','r','l','d','!'};
    int arrint[] = {4,4,4,1,1,5,2,2,5,1,4,2,1,5,6};
    float arrfl[] = {5.0f,2.2f,5.0f,1.5f,1.9f,0.1f,0.05f,0.1f};
    double arrd[] = {5.0,2.2,5.0,1.5,1.9,0.1,0.05,0.1,13.1,3.2};
    GetArray<char>(arrch, sizeof(arrch)/sizeof(arrch[0]) );
    GetArray<int>( arrint, sizeof(arrint)/sizeof(arrint[0]) );
    GetArray<float>(arrfl, sizeof(arrfl)/sizeof(arrfl[0]) );
    GetArray<double>(arrd, sizeof(arrfl)/sizeof(arrfl[0]) ); //sizeof(arr)/sizeof(arr[0]) - размер массива
}