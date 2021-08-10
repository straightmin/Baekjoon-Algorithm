/* Min Heap */
#include <iostream>

using namespace std;

const int MAX_SIZE = 100001;
int heap[MAX_SIZE];
int Size;

void insertHeap(int x){
    Size++;
    int idx = Size;
    while(idx/2 > 0){
        if(x >= heap[idx/2]){
            break;
        }
        heap[idx] = heap[idx/2];
        idx /= 2;
    }
    heap[idx] = x;
}

int deleteHeap(){
    if(!Size) return 0;
    
    int value = heap[1];
    int tmp = heap[Size];
    Size--;
    
    int parent = 1;
    int child = 2;
    while(child <= Size){
        if(child < Size){
            if(heap[child] > heap[child+1]){
                child++;
            }
        }
        if(tmp <= heap[child]){
            break;
        }
        
        heap[parent] = heap[child];
        parent = child;
        child *= 2;
    }
    
    heap[parent] = tmp;
    return value;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, x;
    cin >> n;
    while(n--){
        cin >> x;
        if(x != 0) insertHeap(x);
        else cout << deleteHeap() << "\n";
    }
    
    return 0;
}

