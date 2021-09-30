#include <iostream>
#include <vector>

class Animal {
public:
    Animal() = default;
    std::string speak(){
        return "I am an animal";
    }

    virtual ~Animal() {
        std::cout << "in the Animal destructor" << std::endl;
    }

protected:
    int age {-1};
};

class Cat : public Animal {
public:
    Cat(){
        std::cout << "in the default constructor" << std::endl;
    }

    Cat(int age) { // how could I do this with an initializer list?
        Animal::age = age;
        std::cout << "in the parameterized constructor" << std::endl;
        
    }


    std::string speak()  {
        return "I am a cat!";
    }

    ~Cat() {
        std::cout << "In the Cat destructor" << std::endl;
    }
};

class HouseCat : public Cat {
public:
    virtual ~HouseCat() {
        std::cout << "In the HouseCat destructor" << std::endl;
    }
};

void printCat(Cat cat);

int main() {
    Animal* animal = new Cat;
    std::cout << animal->speak() << std::endl;

//    int x(2.5);
//    std::vector<Animal*> animals;
//    animals.push_back(new Cat);
//    for(Animal* a: animals){
//        std::cout << a->speak() << std::endl;
//    }
//    std::vector<std::shared_ptr<Animal>> animals2;
//    animals2.push_back(std::shared_ptr<Cat>(new HouseCat) );
//    for(auto catPtr : animals2){
//        catPtr->speak();
//    }

//    Cat cat;
//    std::cout << "Printing a cat" << std::endl;
//    printCat(cat);
//    printCat(10);
    return 0;
}

void printCat(Cat cat){
    cat.speak();
}
