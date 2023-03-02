#include <iostream>
#include <chrono>
#include <random>


int mass[1000000] = {};
int c[1000000] = {};


void rand_mass_lin(int size) {
    std::default_random_engine rng((int)time(0));
    std::uniform_int_distribution<unsigned>dstr(0, size - 1);
    
    for (int counter = 0; counter < size; ++counter) {
        mass[counter] = dstr(rng);
    }
}

bool poisk_lin(int beg, int end, int x){
    int size = end - beg + 1;
    for (int i = 0; i < size; ++i) {
        if (mass[i] == x) {
            return true;
        }
    }
    return false;
}

void poisk_lin_A(int beg, int end, int x){
    int temp;
    int size = end - beg + 1;
    for (int i = 0; i < size; ++i) {
        if (mass[i] == x) {
            temp = mass[0];
            mass[0] = mass[i];
            mass[i] = temp;
        }
    }
}

void poisk_lin_B(int beg, int end, int x){
    int temp;
    int size = end - beg + 1;
    for (int i = 0; i < size; ++i) {
        if (mass[i] == x and i != 0) {
            temp = mass[i-1];
            mass[i-1] = mass[i];
            mass[i] = temp;
        }
    }
}

void poisk_lin_C(int beg, int end, int x){
    int temp;
    int size = end - beg + 1;
    for (int i = 0; i < size; ++i) {
        if (mass[i] == x) {
            c[i] += 1;
            if (i != 0){
                if (c[i] > c[i-1]){
                    temp = mass[i-1];
                    mass[i-1] = mass[i];
                    mass[i] = temp;
                    
                    temp = c[i-1];
                    c[i-1] = c[i];
                    c[i] = temp;
                }
            }
        }
    }
}


float poisk_time(bool(*poisk)(int beg, int end, int x), int size, int x) {
    long long repeat = 200000;
    auto begin = std::chrono::steady_clock::now();
    
    for (int j = 0; j < repeat; ++j) {
        poisk(0, size - 1, x);
    }
        
    auto end = std::chrono::steady_clock::now();
    auto time_span =
    std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
    return ((time_span.count() + 0.0)/repeat);
}



void data_average(bool(*poisk)(int beg, int end, int x), int(*random)(int setting), int size){
    srand((int)time(0));
    int er = 50;
    float s = 0;
    for (int u = 0; u < er; ++u) {
        int r = random(size);
        s += poisk_time(poisk, size, r);
    }
    std::cout << size << ' ' << s/(er + 0.0) << ' ';
        
}

int random1(int setting){
    srand((int)time(0));
    return rand() % setting;
}

int random2(int setting){ 
    srand((int)time(0));
    return (setting/10) + rand() % (setting/2);
}

void first(void (*poisk_lin_i)(int beg, int end, int x)){
    for (int size = 100; size <= 500; size += 1){
        rand_mass_lin(size);
        for (int i = 0; i < 100; ++i){
            for (int j = 0; j < size; ++j){
                poisk_lin_i(0, size-1, j);
            }
        }
        data_average(poisk_lin, random1, size);
    }
}

void second(void (*poisk_lin_i)(int beg, int end, int x)){
    for (int size = 100; size <= 500; size += 1){
        rand_mass_lin(size);
        for (int i = 0; i < 100; ++i){
            for (int j = 0; j < size; ++j){
                poisk_lin_i(0, size-1, (size/10) + j % (size/2));
            }
        }
        data_average(poisk_lin, random2, size);
    }
}

int main() {
    first(poisk_lin_A);
    //first(poisk_lin_B);
    //first(poisk_lin_C);
    //second(poisk_lin_A);
    //second(poisk_lin_B);
    //second(poisk_lin_C);
    
    
    
    return 0;
}

