            swap(a[i], a[j]);
        }
    }
    swap(a[i+1], a[high]);
    return i+1;
}

void deterministic(int a[], int low, int high){
    if(low < high){
        int p = partition(a, low, high);
        deterministic(a, low, p-1);
        deterministic(a, p+1, high);
    }
}


void randomise(int a[], int low, int high){
    if(low < high){
        int r = low + rand() % (high - low + 1);
        swap(a[r], a[high]);

        int p = partition(a, low, high);
        randomise(a, low, p-1);
        randomise(a, p+1, high);
    }
}
int main(){
    srand(time(0));

    int n;
    cout<<"Enter size: ";
    cin>>n;

    int a[n];
    int b[n];

    cout<<"Enter the elements: ";

    for(int i= 0; i<n; i++){
        cin>>a[i];
        b[i] = a[i];
    }

    deterministic(a, 0, n-1);
    randomise(b, 0, n-1);
