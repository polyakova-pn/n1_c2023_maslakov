#include <iostream>

using namespace std;


struct Node {
    int key = 0; // stoder value
    Node *next = nullptr; // pointer to next Node
    Node* prev = nullptr;
};

struct List {
    Node *HEAD = nullptr; // pointer to next Node
    Node* TAIL = nullptr;
    Node* NIL = nullptr;
    size_t size = 0;
};


List* create_empty_list(){
  List *list = new List;
  
  list->NIL = new Node;
  list->TAIL = list->NIL;
  list->HEAD = list->NIL;
  
  return list; 
}


List* push_back(List *list_ptr, int new_key){
    if (list_ptr == nullptr){
      list_ptr = create_empty_list();
    }
    Node *a = new Node;
    a->key = new_key;
    
    
    if(list_ptr->HEAD == list_ptr->NIL){
        a->next = list_ptr->NIL;
        a->prev = list_ptr->NIL;
        list_ptr->size += 1;
        list_ptr->HEAD = a;
        list_ptr->TAIL = a;
        
        return list_ptr;
    }
    list_ptr->TAIL->next = a;
    a->prev = list_ptr->TAIL;
    a->next = list_ptr->NIL;
    list_ptr->size += 1;
    list_ptr->TAIL = a;
    return list_ptr;
}

void clear_list(List* list_ptr){

    if (list_ptr == nullptr){

        return;

    }

    Node *new_head_ref = list_ptr -> HEAD;

    while (new_head_ref != list_ptr->NIL) {

        Node *temp = new_head_ref;

        new_head_ref = new_head_ref -> next;

        delete temp;

    }

    list_ptr -> HEAD = list_ptr->NIL;

    list_ptr -> TAIL = list_ptr->NIL;

    list_ptr -> size = 0;

}

void print_list(const List* list_ptr, int sg){
    int vsp = 0;
	  if (list_ptr == nullptr){
		  return;
	  }
    if(list_ptr->size == 1 and list_ptr->HEAD->key == 0){
        cout << 0 << endl;
        return;

    }
  	Node* head_ref = list_ptr->HEAD;
    if(head_ref == nullptr){
        std::cout << std::endl;
		    return;	
    }
    Node *a = head_ref;
    if(sg == -1){
        cout << "-";
    }
    while (a != list_ptr->NIL) {
        if (a->key != 0){
            vsp = 1;
        }
        if (vsp == 1){
            std::cout << a->key;
        }
        //if(a->next != list_ptr->NIL){
		      //std::cout << " ";
        //}
        a = a->next;
    }
	
    std::cout << std::endl;
	return;
	
}


void destroy_list(List* list_ptr){
    if (list_ptr == nullptr){
		    return;
	  }
    Node* head_ref = list_ptr->HEAD;
    if(head_ref == list_ptr->NIL){
        delete list_ptr->NIL;
        delete list_ptr;
        return;
    }
    Node *b = head_ref;
    
    while(b != list_ptr->NIL){
      Node *tmp = b;
      b = b->next;
      delete tmp;
    }
    head_ref = list_ptr->NIL;
    list_ptr->HEAD = list_ptr->NIL;
    list_ptr->TAIL = list_ptr->NIL;
    delete list_ptr->NIL;
    delete list_ptr;
    return;
}

List* push_front(List *list_ptr, int new_key){
    if (list_ptr == nullptr){
      list_ptr = create_empty_list();
    }
    Node *a = new Node;
    a->key = new_key;
    
    
    if(list_ptr->HEAD == list_ptr->NIL){
        a->next = list_ptr->NIL;
        a->prev = list_ptr->NIL;
        list_ptr->size += 1;
        list_ptr->HEAD = a;
        list_ptr->TAIL = a;
        
        return list_ptr;
    }
    list_ptr->HEAD->prev = a;
    a->next = list_ptr->HEAD;
    a->prev = list_ptr->NIL;
    list_ptr->size += 1;
    list_ptr->HEAD = a;
    return list_ptr;
}

void inp(string s, const int n, List* & a, int & zn1){
    
    int nach = 0;
    if (s[0] == '-'){
        zn1 = -1;
        nach = 1;
    }
    for (int i = nach; i < n; i++){
        
        if(s[i] == '0'){
            push_back(a, 0);
      
        }
        if(s[i] == '1'){
            push_back(a, 1);
            
        }
        if(s[i] == '2'){
            push_back(a, 2);
            
        }
        if(s[i] == '3'){
            push_back(a, 3);
            
        }
        if(s[i] == '4'){
            push_back(a, 4);
            
        }
        if(s[i] == '5'){
            push_back(a, 5);
        }
        if(s[i] == '6'){
            push_back(a, 6);
        }
        if(s[i] == '7'){
            push_back(a, 7);
        }
        if(s[i] == '8'){
            push_back(a, 8);
        }
        if(s[i] == '9'){
            push_back(a, 9);
        }
    }
}


List* cop(List* b){
    //clear_list(anss);
    List* anss = create_empty_list();
    Node* elb = b->TAIL;
    while(elb != b->NIL){
        push_front(anss, elb->key);
        elb = elb->prev;
        //cout << elb->key << endl;
    }
    return anss;
}

void copp(List* b, List* anss){
    //clear_list(anss);
    //List* anss = create_empty_list();
    Node* elb = b->TAIL;
    while(elb != b->NIL){
        push_front(anss, elb->key);
        elb = elb->prev;
        //cout << elb->key << endl;
    }
    //return anss;
}

void split(string s, const int n, List* & a, List* & b, char & oper, int & zn1, int & zn2){
    List* & mass = a;
    int nach = 0;
    if (s[0] = '-'){
        zn1 = -1;
        nach = 1;
    }
    for (int i = nach; i < n; i++){
        if(s[i] == '-'){
            oper = '-';
            mass = b;
            if( s[i+1] == '-'){
                zn2 = -1;
                i = i + 1;
            }
            
        }

        if(s[i] == '+'){
            oper = '+';
            mass = b;
            if( s[i+1] == '-'){
                zn2 = -1;
                i = i + 1;
            }
           
        }
        
        if(s[i] == '*'){
            oper = '*';
            mass = b;
            if( s[i+1] == '-'){
                zn2 = -1;
                i = i + 1;
            }
            
        }
        if(s[i] == '/'){
            oper = '/';
            mass = b;
            if( s[i+1] == '-'){
                zn2 = -1;
                i = i + 1;
            }
           
        }
        if(s[i] == '0'){
            push_back(mass, 0);
      
        }
        if(s[i] == '1'){
            push_back(mass, 1);
            
        }
        if(s[i] == '2'){
            push_back(mass, 2);
            
        }
        if(s[i] == '3'){
            push_back(mass, 3);
            
        }
        if(s[i] == '4'){
            push_back(mass, 4);
            
        }
        if(s[i] == '5'){
            push_back(mass, 5);
        }
        if(s[i] == '6'){
            push_back(mass, 6);
        }
        if(s[i] == '7'){
            push_back(mass, 7);
        }
        if(s[i] == '8'){
            push_back(mass, 8);
        }
        if(s[i] == '9'){
            push_back(mass, 9);
        }
    }
}


void pluss(List* & a, List* & b, List* & c){
    clear_list(c);
    if (b->size > a->size){
        List* tmpp = a;
        a = b;
        b = tmpp;
    }
    if(b->size == 0){
        //destroy_list(a);
        copp(a, c);
        return;
    }
    int r = 0;
    Node* ela = a->TAIL; 
    Node* elb = b->TAIL; 
    int elc = 0;
    while(elb != b->NIL){
        elc = (r + ela->key + elb->key) % 10;
        r = (r + ela->key + elb->key) / 10;
        push_front(c, elc);
        ela = ela->prev;
        elb = elb->prev;
    }
    while(ela != a->NIL){
        elc = (r + ela->key) % 10;
        r = (r + ela->key) / 10;
        push_front(c, elc);
        ela = ela->prev;
        
    }
    push_front(c, r);
    
}


void simp_mult(List* & a, int b, int deg, List* & c){
    clear_list(c);
    Node* ela = a->TAIL;
    int elc;
    int r = 0;
    while(ela != a->NIL){
        elc = (r + ela->key * b) % 10;
        r = (r + ela->key * b) / 10;
        push_front(c, elc);
        ela = ela->prev;
        
    }
    while(r > 0){
        push_front(c, r % 10);
        r = r / 10;
    }
    for (int i = 0; i < deg; i++){
        push_back(c, 0);
    }
    
}



void multt(List* & a, List* & b, List* & ans){
    if(a->HEAD->key == 0 or b->HEAD->key == 0){
        cout << 0;
    }
    int dg = 0;
    Node* elb = b->TAIL; 
    List* simp_ans = create_empty_list();
    
    while(elb != b->NIL){
        
        List* mass = cop(ans);
        //mass = ans;
        simp_mult(a, elb->key, dg, simp_ans);

        //cout << endl;
        //cout << endl;
        //print_list(simp_ans, 1);
        //print_list(mass, 1);
        //clear_list(ans);
        //print_list(ans, 1);

        pluss(simp_ans, mass, ans);
        //print_list(simp_ans, 1);

        //print_list(simp_ans, 1);
        //cout << elb->key;
        //cout << endl;

        dg = dg + 1;
        elb = elb->prev;
        destroy_list(mass);
    }
    destroy_list(simp_ans);
    
}


void minuss(List* & a, List* & b, List* & c, int & sig){
    //cout << 'r';
    if (b->size > a->size){
        List* tmpp = a;
        a = b;
        b = tmpp;
        sig = -1 * sig;
    }
    int r = 0;
    Node* ela = a->TAIL; 
    Node* elb = b->TAIL; 
    int elc;
    while(elb != b->NIL){
        elc = (r + ela->key - elb->key);
        if(elc < 0){
            elc = elc + 10;
            r = -1;
        }else{
            r = 0;
        }
        //r = (r + ela->key + elb->key) / 10;
        push_front(c, elc);
        ela = ela->prev;
        elb = elb->prev;
        //cout << ela->key;
    }
    while(ela != a->NIL){
        elc = (r + ela->key);
        if(elc < 0){
            elc = elc + 10;
            r = -1;
        }else{
            r = 0;
        }
        //r = (r + ela->key + elb->key) / 10;
        push_front(c, elc);
        ela = ela->prev;
        
        
    }
    
}

int main(){
    string sa;
    string sb;
    char op;
    cin >> sa;
    cin >> op;
    cin >> sb;
    const int na = sa.size();
    const int nb = sb.size();
    //char op = '+';
    List* a = create_empty_list();
    List* b = create_empty_list();
    List* c = create_empty_list();
    int zna = 1;
    int znb = 1;
    int znc = 1;

    //List* = a;
    //List* & d = b;
    inp(sa, na, a, zna);
    inp(sb, nb, b, znb);
    //split(s, n, a, b, op, zn1, zn2);
    //print_list(a);
    //cout << endl;
    //print_list(b);
    //cout << endl;
    //cout << op;
    //cout << endl;
    int zn = 0;
    if(op == '+'){
        zn = 1;
        //pluss(a, b, c);
    }
    if(op == '-'){
        zn = -1;
        //minuss(a, b, c, znc);
    }
    if (zn != 0){
        if (zna > 0){
            if (znb * zn > 0){
                pluss(a, b, c);
            }
            if (znb * zn < 0){
                minuss(a, b, c, znc);
            }
        }
        if (zna < 0){
            znc = -1;
            if (znb * zn < 0){
                pluss(a, b, c);
            }
            if (znb * zn > 0){
                minuss(a, b, c, znc);
            }
        }
    }
    if(op == '*' and zn == 0){
        
        multt(a, b, c);
        znc = zna * znb;
    }
    //simp_mult(a, 9, 2, c);
    print_list(c, znc);
    destroy_list(a);
    destroy_list(b);
    destroy_list(c);


}