#include <iostream>
#include <chrono>
#include <random>

int mass[1000000] = {};


void rand_mass_lin(int size) {
    std::default_random_engine rng((int)time(0));
    std::uniform_int_distribution<unsigned>dstr(0, size - 1);
    
    for (int counter = 0; counter < size; ++counter) {
        mass[counter] = dstr(rng);
    }
}


void rand_mass_bin(int size) {
    std::default_random_engine rng((int)time(0));
    std::uniform_int_distribution<unsigned>dstr(0, 10);
    
    for (int counter = 0; counter < size; ++counter) {
        if (counter == 0) {
            mass[counter] = dstr(rng);
        }
        else{
            mass[counter] = mass[counter - 1] + dstr(rng);
        }
    }
}




bool poisk_sum_lin(int beg, int end, int s){ 
    for (int i = 0; i < end+1; ++i) {
        for (int j = 0; j < end+1; ++j) {
            if (mass[i] + mass[j] == s){
                return true;
            }
        }
    }
    return false;
}


bool poisk_sum_smart(int beg, int end, int s){
    
    int cur_sum;
    while (beg != end){
        cur_sum = mass[beg] + mass[end];
        if (cur_sum < s){
            beg += 1;
        }
        else if (cur_sum > s){
            end -= 1;
        }
        else{
            return true;
        }
    }
    return false;
}



float poisk_time(bool(*poisk)(int beg, int end, int x), int size, int x) {
    long long repeat = 100000;
    auto begin = std::chrono::steady_clock::now();
    
    for (int j = 0; j < repeat; ++j) {
        poisk(0, size - 1, x);
    }
        
    auto end = std::chrono::steady_clock::now();
    auto time_span =
    std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
    return ((time_span.count() + 0.0)/repeat);
}




void data_max(void(*rand_mass)(int size), bool(*poisk)(int beg, int end, int x)){
    std::cout << "max data for lineral search\n";
    for (int size = 1; size <= 1000; size+=1) {
        rand_mass(size);
        std::cout << size << ' ' << poisk_time(poisk, size, -1) << ' ';
    }
    std::cout << '\n';
}

void data_average(void(*rand_mass)(int size), bool(*poisk)(int beg, int end, int x)){
    
    std::cout << "average data for lineral search\n";
    srand((int)time(0));
    int er = 50;
    for (int size = 1; size <= 500; size+=1) {
        float s = 0;
        for (int u = 0; u < er; ++u) {
            int r = rand() % size;
            rand_mass(size);
            s += poisk_time(poisk, size, r);
        }
        std::cout << size << ' ' << s/(er + 0.0) << ' ';
    }
        
}

int main(){
    data_max(rand_mass_lin, poisk_sum_lin);
    //data_average(rand_mass_lin, poisk_sum_lin);
    //data_max(rand_mass_bin, poisk_sum_smart);
    //data_average(rand_mass_bin, poisk_sum_smart);
    
    
    
    return 0;
}
