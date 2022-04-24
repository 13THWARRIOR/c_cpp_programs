#include <iostream>

static void printa(int a) {
    std::cout<< "a is : " << a << std::endl;
}

static void sum(int a, int b) {
    std::cout<< "sum is : " << a+b << std::endl;
}

static void substract(int a, int b) {
    std::cout<< "sub is : " << a-b << std::endl;
}

static void division(int a, int b) {
    std::cout<< "div is : " << a/b << std::endl;
}

static void pointertofunction(void (*function_ptr)(int)) {
    function_ptr(12);
}

static void pointertofunctionarray(void (*function_array[])(int,int)) {
    function_array[0](15,6);
    function_array[1](13,6);
    function_array[2](18,6);
}

typedef void functiontypedef(int a , int b);
typedef void (*functionptrtypedef) (int, int);

// works with *a, &a or just a
// all answers are same
void typedefusage(functiontypedef a, int b, int c) {
    a(b,c);
}

int main() {
    void (*function_ptr)(int) = &printa;
    void (*function_array[])(int, int) = {sum, substract, division};
    (*function_ptr)(10); // can be written as this,
    // or like this both works
    function_ptr(10);
    function_array[0](12,6);
    function_array[1](12,6);
    function_array[2](12,6);
    pointertofunction(printa); // can be written as this,
    // or like this both works
    pointertofunction(function_ptr);
    pointertofunctionarray(function_array);

    // using typedef instead of pointers
    functionptrtypedef def = &sum;
    def(5,7);
    // or using typedef like this without pointer
    typedefusage(sum, 2, 3);
    return 0;
}


