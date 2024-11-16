
#include "product.cpp"
#include<bitset>
#include<sys/socket.h>>


void printBinaryAddress(void* address) {
    uintptr_t addressVal = reinterpret_cast<uintptr_t>(address);
    std::bitset<sizeof(uintptr_t) * 8> binaryAddress(addressVal);
    std::cout << "Address in binary:\n " << binaryAddress << std::endl;
    std::cout << "Address in binary << 19:\n " << (binaryAddress << 19) << std::endl;
}


int main(int argc, char const *argv[])
{
    Product product;

    Product* pointerToProduct = & product;

    printBinaryAddress(pointerToProduct);

    std::cout<<"15 << 1 = "<<(15 << 1)<<std::endl;
    std::cout<<"16 >> 1 = "<<(16 >> 1)<<std::endl;

    int flags = 0b1010;      // Binary: 1010
    int mask = 1 << 2;       // Left shift to create mask 0100
    bool isBitSet = flags & mask; // Check if the 3rd bit is set
    std::cout<<"isBitSet = "<<isBitSet<<std::endl;

    return 0;
}
