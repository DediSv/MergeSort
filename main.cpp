///Merge-Sort threw Recursion
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

vector <int> CreateArray(){ //Creating a random massive
    srand (static_cast <unsigned int>(time(0))); //Seed
    vector <int> array(rand() % 13 + 1);
    for (int i = 0; i < array.size(); i++)
        array[i] = rand() % 100;
    return array;
}

void Vypis(vector <int> &array){
    for (int i = 0; i < array.size(); i++)
        cout << array[i] << " ";
    cout << "\n";
}

void merge(vector <int> &array, int l, int middle, int r){ //Spojení 2 array
    int n1 = middle - l + 1; //Velikost 1. subarray (l a middle jsou indexy)
    int n2 = r - middle; //Velikost 2. subarray
    ///Tmp arrays///
    vector <int> L(n1);
    vector <int> R(n2);
    ///Coping to tmp arrays///
    for (int i = 0; i < n1; i++)
        L[i] = array[l + i]; //Zapisujeme do L[] prvky z array od (l)
    for (int j = 0; j < n2; j++)
        R[j] = array[middle + 1 + j]; //Zapisujeme do R[] prvky z array od (middle + 1)
    ///Merging tmp arrays///
    int i = 0; //index 1. subarray
    int j = 0; //index 2. subarray
    int k = l; //index tmp[]
    while(i < n1 && j < n2){
        if (L[i] <= R[j]){
            array[k] = L[i];
            i++; //posun i
        } else {
            array[k] = R[j];
            j++; //posun j
        }
        k++; //posun tmp po odebraní prvku
    }
    ///Jestli jsme nedošli do konce L[]///
    while (i < n1){
        array[k] = L[i];
        i++;
        k++;
    }
    ///IJestli jsme nedošli do konce R[]///
    while (j < n2){
        array[k] = R[j];
        j++;
        k++;
    }


    /*vector <int> tmp; //Temporary array for saving
    int i = l; //pointer on the 1st array start
    int j = middle + 1; //pointer on the 2st array start
    int k = l; //pointer on the tmp array start
    while (i <= middle && j <= r){
        if (array[i] < array[j]){ //jeli element zleva < el zprava
            tmp[k] = array[i]; //zapsat levý
            i++; //posun i-tého pointra
            k++; //rozšíření tmp
        }
        tmp[k] = array[j]; //zapsat pravý
        j++; //posun j-tého pointra
        k++;
    }
    return tmp;*/
}

void MergeSort(vector <int> &array, int left, int right){
    if (left < right) {
        int middle = (left + right) / 2; //Našli jsme střed array
        MergeSort(array, left, middle); //Rekurzivně se volame na levou čast
        MergeSort(array, middle + 1, right); // -||- na pravou čast
        merge(array, left, middle, right);
    }
}


int main() {
    vector <int> input = CreateArray();//Just gen the massive
    cout << "Random generated massive: " << endl;
    Vypis(input);
///Merge sort///
    MergeSort(input,0,input.size());
    cout << "Merged sorted vector:" << endl;
    Vypis(input);
    return 0;
}