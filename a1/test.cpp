#include <iostream>
#include <stdlib.h>
#include <fstream>

/*
int main(int argc,char * argv[]){

    int size = 0;
    if (argc >1){
        size = atoi(argv[1]);
    }
    int * name;
    name = new int[size];

    for (int i = 0; i < size ; ++i){
        name[i] = i;
    }

    for (int i = 0; i < size ; ++i){
        std::cout << name[i] << " ";
    }

    delete[] name;

}

*/

void change(int * array, int a, int b ){
    array[a] = array[b];
}
int main (){
    int * x;
    x = new int [5];
    //x = { 5, 4, 3, 2, 1 };

    for (int i = 0; i<5 ; i++){
        x[i] = i+4;
    }

    change(x, 2, 4);
    for (int i = 0; i< 5; i++){
        std::cout << x[i] << std::endl;
    }


    delete[] x;
  return 0;
}
