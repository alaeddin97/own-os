#include<iostream>
#include "product.h"

Product::Product():category(1,"name") { // this is a initializer list: used when dont have a  default constructor or when we want to use a specific constructor for category
    std::cout<<"call of the constructor of Product class"<<std::endl;
}

Product::~Product(){}

Product::Category::Category(int id, std::string name) {
    this->id = id;
    this->name = name;
}

std::string Product::Category::getName() {
    return this->name;
}

void Product::Category::setName(std::string name) {
    this->name = name;
}

