#include <iostream>
#include <random>
#include <ctime>

std::mt19937 gen(static_cast<unsigned>(time(nullptr))); // seed the generator

int dice(int min, int max) {
    std::uniform_int_distribution<> distr(min, max); // define the range
    return distr(gen);
}

using namespace std;
struct pr {
    int x = 0; // stoder value
    int y = 0;
    int xp = 0; // stoder value
    int yp = 0;
    int m = 0; // pointer to next Node
};


void rand_mass_linn(int aaa[], int N, int sd) {
    unsigned seed = sd;
    
    std::default_random_engine rng(seed);
    std::uniform_int_distribution<unsigned>dstr(0, N);
    
    for (int counter = 0; counter < N; ++counter) {
        aaa[counter] = dstr(rng);
    }
}


void print(int a[], int N){
    for(int i = 0; i < N; i++){
        cout << a[i] << " ";
    }
}

void move(pr a[], int n, int k, int t){
    int aa[51];
    int v;
    for (int i = 0; i < 51; i++){
        aa[i] = i;
    }
    
    for(int i = 0; i < k; i++){
        //if (a[i].m == 0){
        //rand_mass_linn(aa, 51, 1000 + t * 23 + i);
        //print(aa, 51);
        //cout << endl;
        int proebat_vremya = 0;
        for(int i = 0; i < 1000; i++){
            proebat_vremya = proebat_vremya + 2 -1;
        }
        int rp;
        rp = dice(0, 1);
        //cout << rp;
        //cout << endl;
        if(rp == 0){
            //cout << 555555 << " ";
            
            v = a[i].xp;
            a[i].xp = a[i].x;
            a[i].x--;
            for(int ii = 0; ii < k; ii++){
                if(a[ii].x == a[i].x and a[ii].y == a[i].y and i != ii){
                    a[i].xp = v;
                    a[i].x++;
                    a[i].m = 1;
                    a[ii].m = 1;
                }
            }
            //return;
        }
        
        if(rp == 1){
            v = a[i].xp;
            a[i].xp = a[i].x;
            a[i].x++;
            for(int ii = 0; ii < k; ii++){
                if(a[ii].x == a[i].x and a[ii].y == a[i].y and i != ii){
                    a[i].xp = v;
                    a[i].x--;
                    a[i].m = 1;
                    a[ii].m = 1;
                }
            }
            //return;
        }
        
        }
    
}


void moroz(pr a[], int n, int k){
    for(int i = 0; i < k; i++){
        if (a[i].x <= 1 or a[i].x >= (n - 1) or a[i].y <= 1 or a[i].y >= (n - 1)){
            a[i].m = 1;
        }
        for(int ii = 0; ii < k; ii++){
            if (a[i].m == 0 and a[ii].m == 0){
            if(i != ii){
                
                //if(a[i].x == a[ii].x and a[i].y == a[ii].y){
                    //if(a[i].m == 0){
                    //a[i].x = a[i].xp;
                    //a[i].y = a[i].yp;
                    //a[i].m = 1;
                    //a[ii].m = 1;}
                    //if(a[ii].m == 0){
                    //a[ii].x = a[ii].xp;
                    //a[ii].y = a[ii].yp;
                    //a[i].m = 1;
                  //  a[ii].m = 1;}
                //}
                
                if((a[i].x - a[ii].x) < 2 and (a[i].x - a[ii].x) > -2 and (a[i].y - a[ii].y) < 2 and (a[i].y - a[ii].y) > -2){
                    a[i].m = 1;
                    a[ii].m = 1;
                }
            }}
        }
    }
    //return a;
}


int konec(pr a[], int n, int k){
    int ans = 1;
    for(int i = 0; i < k; i++){
        //cout << a[i].m;
        if (a[i].m == 0){
            ans = 0;
            //cout << 555;
        }
    }
    return ans;
}


int main(){
    int pv = 0;
    
    //for(int j = 10; j < 1000; j = j + 10){
    int j = 100;
    int t = 0;
    
    for (int k = 1; k < j; k+=1){
        t = 0;
    for(int o = 0; o < 20; o++){
    pr a[k];
    //int vsp[2 * j];
    //rand_mass_linn(vsp, 2 * j, 1488);
    //print(vsp, 2 * j);
    //cout << endl;
    //cout << " ";
    //cout << endl;
    for (int i = 0; i < k; i++){
        pr f;
        for(int u = 0; u < 100000; u++){
            pv = pv + 2 -1;
        }
        f.x = dice(0, j);
        for(int u = 0; u < 100000; u++){
            pv = pv + 2 -1;
        }
        f.y = 15;
        f.xp = f.x;
        f.yp = f.y;
        f.m = 0;
        a[i] = f;
    }
    //a[0].x = 50;
    //a[0].y = 50;
    //a[0].xp = 50;
    //a[0].yp = 50;
    //for(int i = 0; i < k; i++){
        //cout << a[i].x << " ";
    //}
    
    
    int konecc = 0;
    while(konecc != 1){
        move(a, j, k, t + 1);
        moroz(a, j, k);
        //cout << a[0].m << " " << konecc << " "; 
        konecc = konec(a, j, k);
        t++;
        //cout << t << " " << a[0] << " ";
        //cout << endl;
        //cout << a[0].m << " " << konecc << " "; 
        //for(int i = 0; i < k; i++){
            //cout << a[i].m << " ";
        //}
        //cout << t << " " << a[0].x << " " << a[0].y;
        //cout << endl;
    }
    //cout << endl;
    //cout << 555555555555 << endl;
    }
    cout << t / 20 << " ";
    }
    
}

