

#include<iostream>

using namespace std;

struct House {
    string owner;
    int squareFeet;
    int numBedRooms;
    int numBaths;
};

int (*pAdd)(int,int);

void pointerVsArray();
void pointerToPointer();
void voidAndNullPointer(House house);
void * myAlloc(size_t _size);
int add(int a, int b);
int compare(const void *a, const void *b);
void order();

int main(int argc, char *argv[]) {

    cout<<"<<<<<<Understand Pointers How They Work<<<<<<<<<<<<<<<<<<"<<endl;
    House friendHouse;
    friendHouse.owner = "My friend\'s dad";
    friendHouse.squareFeet = 1000;
    friendHouse.numBedRooms = 4;
    friendHouse.numBaths = 2;

    House *pHouse = &friendHouse;

    cout << "Square Feet: " << pHouse->squareFeet << endl;
    cout << "BedRooms: " << pHouse->numBedRooms << endl;
    cout << "Baths: " << pHouse->numBaths << endl;
    cout << "Owner: " << pHouse->owner << endl;
    cout << "Size of the square Feet: " << sizeof(pHouse->squareFeet) << endl;
    cout << "Size of the bed rooms: " << sizeof(pHouse->numBedRooms) << endl;
    cout << "Size of the baths: " << sizeof(pHouse->numBaths) << endl;
    cout << "Size of the owner: " << sizeof(pHouse->owner) << endl;
    cout << "Address to my friendHouse: " << &friendHouse << endl;
    cout << "Size of the address to my friendHouse: " << sizeof(&friendHouse) << endl;
    cout << "Size of my friendHouse as if They want to bring the house\n to offer me a tour instead of just giving me the address: " << sizeof(friendHouse) << endl;

    cout<<"<<<<<<<<<<<<<<<<<<<<Pointers and Arrays<<<<<<<<<<"<<endl<<endl;
    pointerVsArray();
    pointerToPointer();

    cout<<"<<<<<<<<<<<<<<<<<<<<<Void Pointer<<<<<<<<<<<<<<<"<<endl<<endl;

    House myHouse;
    myHouse.numBaths = 4;
    myHouse.owner = "Me";
    voidAndNullPointer(myHouse);

    cout<<"<<<<<<<<<<<<<<<<<<<Function Pointer<<<<<<<<<<<<<<"<<endl<<endl;
    cout<<"Address of pAdd: "<<&pAdd<<endl;
    cout<<"Address of add: "<<&add<<endl;
    pAdd = add;
    int sum = (*pAdd)(5,3);
    cout<<"Sum of 5 and 3: "<<sum<<endl;
    cout<<endl<<endl;
    order();


    return 0;
}




void pointerVsArray() {

    char szText[] = "Hello world mate !";
    char * pText = szText;

    cout << "Size of an array of string: " << sizeof(szText) << endl;
    cout << "Size of pointer to an array of string: " << sizeof(pText) << endl;
    //static_assert(sizeof(szText) == 12, "szText is not 12 bytes long");
    //static_assert(sizeof(pText) == 4, "szText is not 4 bytes long");
}


void pointerToPointer() {

    char name[] = "Yassine";
    char * bro = name;
    char ** toBro = &bro;

    cout << "Address to bro: " << &bro << endl;
    cout << "Value to which point the bro pointer: " << *bro << endl;
    cout << "Address to toBro: " << &toBro << endl;
    cout << "Value to which point the toBro pointer: " << *toBro << endl;
}


void voidAndNullPointer(House house) {
    House * myHouse = (House *) myAlloc(40);

    myHouse = &house;
    cout << "Address to myHouse: " <<&myHouse<<endl;
    cout << "Baths: " <<myHouse->numBaths<<endl;
    cout << "Owner: " <<myHouse->owner<<endl;
}

void * myAlloc(size_t _size) {
    return malloc(_size);
}

int add(int a, int b) {
    return a + b;
}

int compare(const void* a, const void* b) {
    int int_a = *((int*) a);
    int int_b = *((int*) b);

    if(int_a == int_b) return 0;
    else if(int_a < int_b) return -1;
    else return 1;
}

void order() {

    int tab[] = {5,1,3,7,2,1,9};

    int tabSize = sizeof(tab)/sizeof(*tab);
    qsort(tab,tabSize,sizeof(int),compare);

    for(int i=0;i<tabSize;i++) {
        cout<<"tab["<<i<<"]="<<tab[i]<<endl;
    }
}






