#ifndef __PRODUCT_H
#define __PRODUCT_H
#include<string>

class Product
{
public:
    class Category
    {
    private:
        int id;
        std::string name;

    public:
        Category(int id, std::string name);

        std::string getName();

        void setName(std::string name);
    };
    
    Category category;

public:
    Product();
    ~Product();
};

#endif