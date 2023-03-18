#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "CPlusPlusCars.h"

using namespace std;

class Car {
protected:
    string brand;
    string model;
    int year;
    int speed;

public:
    Car(string b, string m, int y, int s) {
        brand = b;
        model = m;
        year = y;
        speed = s;
    }
    virtual ~Car() {}
    void increaseSpeed(int value) {
        speed += value;
    }

    void decreaseSpeed(int value) {
        speed -= value;
    }

    string getBrand() {
        return brand;
    }

    string getModel() {
        return model;
    }

    int getYear() {
        return year;
    }

    int getSpeed() {
        return speed;
    }
};

class Truck : public Car {
private:
    int payloadCapacity;

public:
    Truck(string b, string m, int y, int s, int pc) : Car(b, m, y, s) {
        payloadCapacity = pc;
    }

    int getPayloadCapacity() {
        return payloadCapacity;
    }
};

bool ASCCompareBySpeed(Car* a, Car* b) {
    return a->getSpeed() < b->getSpeed();
}

bool DESCCompareBySpeed(Car* a, Car* b) {
    return a->getSpeed() > b->getSpeed();
}
void printCars(vector<Car*> cars) {
    for (Car* car : cars) {
        if (dynamic_cast<Truck*>(car)) {
            cout << "Truck - ";
        }
        else {
            cout << "Car - ";
        }
        cout << car->getBrand() << " " << car->getModel() << " " << car->getYear() << " " << car->getSpeed();
        if (dynamic_cast<Truck*>(car)) {
            cout << " " << dynamic_cast<Truck*>(car)->getPayloadCapacity();
        }
        cout << endl;
    }
}

int main() {
    vector<Car*> cars;

    cars.push_back(new Car("Toyota", "Corolla", 2010, 120));
    cars.push_back(new Car("Honda", "Accord", 2015, 150));
    cars.push_back(new Car("Nissan", "Altima", 2012, 110));
    cars.push_back(new Truck("Ford", "F-150", 2018, 100, 1500));
    cars.push_back(new Truck("Chevrolet", "Silverado", 2016, 120, 2000));
    cars.push_back(new Truck("Dodge", "Ram", 2014, 90, 2500));
    cars.push_back(new Car("Volkswagen", "Jetta", 2019, 130));
    cars.push_back(new Car("BMW", "X5", 2017, 160));
    cars.push_back(new Car("Mercedes-Benz", "C-Class", 2013, 140));
    cars.push_back(new Truck("GMC", "Sierra", 2020, 110, 1800));

    cout << "Вывод без сортировки по скорости\n\n";
    printCars(cars);

    cout << "Вывод с сортировки по скорости в порядке возрастания\n\n";
    sort(cars.begin(), cars.end(), ASCCompareBySpeed);
    printCars(cars);
    
    cout << "Вывод с сортировки по скорости в порядке убывания\n\n";
    sort(cars.begin(), cars.end(), DESCCompareBySpeed);
    printCars(cars);
    
    for (Car* car : cars) {
        delete car;
    }
}