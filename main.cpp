#include <bits/stdc++.h>

using namespace std;

void printar(int len, int *a){
  for(int i=0; i<len; i++){
    cout<<a[i]<<' ';
  }
}

void random_input(int len, int *a){
    srand(time(0));
    int m;
    cout<<"Enter max number:\n>_";
    cin>>m;

    for(int i = 0; i<len; i++){
        a[i] = rand()%(m+1);
    }
}

void manual_input(int len, int *a){
    cout<<"Enter your numbers:\n>_";
    for(int i=0; i<len; i++){
        cin>>a[i];
    }
}

void bubble(int len, int *a){
  for(int k=1; k<len; k++){
    for(int i=0; i < len-k; i++){
      if(a[i]>a[i+1])
        swap(a[i], a[i+1]);
    }
  }
}

void vstavka(int len, int *a){
    for (int s = 0; s < len - 1; s++)
    {
        if (a[s] > a[s+1])
        {
            for(int j = 0; j < s+1 ; j++)
            {
                if (a[j] > a[s+1])
                    swap(a[j],a[s+1]);
            }
        }
 }
}

void vibor(int len, int *a){
 for (int s = 0; s < len - 1; s++)
 {
  int sm = s;
  for (int c = s + 1 ; c < len ; c++)
  {
   if (a[c] < a[sm])
   sm = c;
  }
  int k = a[s] ;
  a[s] = a[sm];
  a[sm] = k;
 }
}

void shaker(int len, int *a){
    int left_b = 0, right_b = len - 1, last_change = 0;

    do{
        for(int i = left_b; i < right_b; i++){
            if(a[i] > a[i+1]){
                swap(a[i], a[i+1]);
                last_change = i;
            }
        }

        right_b = last_change;

        for(int i = right_b; i >= left_b; i--){
            if(a[i] > a[i+1]){
                swap(a[i], a[i+1]);
                last_change = i;
            }
        }

        left_b = last_change;

    }while(left_b < right_b);
}

void shell(int len, int *a){
    bool swapped = true;
    int start = 0;
    int fin = len - 1;

    while (swapped) {
        swapped = false;

        for (int i = start; i < fin; ++i) {
            if (a[i] > a[i + 1]) {
                swap(a[i], a[i + 1]);
                swapped = true;
            }
        }

        if (!swapped)
            break;

        swapped = false;

        --fin;

        for (int i = fin - 1; i >= start; --i) {
            if (a[i] > a[i + 1]) {
                swap(a[i], a[i + 1]);
                swapped = true;
            }
        }

        ++start;
    }
}


int main()
{
    while(true){
    int n;
    string choice = "";

    cout<<"Enter array size:\n>_";
    cin>>n;

    int num[n];

    cout << "Choose mode:\n    \'m\' for manual, \'r\' for random.\n>_";
    cin>>choice;

    if(choice == "m" or choice == "M"){
        manual_input(n, num);
    }else{
        random_input(n, num);
        cout<<"Generated array is: ";
        printar(n, num);
        cout<<endl;
    }

    /////////////////////////////////////
    cout<<"Choose type:\n    \'bubble\' for bubble sort, \'insertion\' for insertion sort, \'choice\' for sort-by-choice, \'shaker\' for shaker sort, \'shell\' for Shell's sort.\n>_";
    cin>>choice;

    if(choice == "bubble") bubble(n, num);
    else if(choice == "insertion") vstavka(n, num);
    else if(choice == "choice") vibor(n, num);
    else if(choice == "shaker") shaker(n, num);
    else shell(n, num);

    cout<<"Array sorted by this method is: ";

    printar(n, num);
    cout<<"\n\n\n";
    }
    return 0;
}
