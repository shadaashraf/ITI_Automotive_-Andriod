#include <iostream>
#include <string>

class Car {
private:
    std::string company;
    std::string model;
    int year;

public:
    
    Car(std::string c, std::string m, int y) : company(c), model(m), year(y) {}

    
    void setCompany(const std::string &c) {
        company = c;
    }

    std::string getCompany() const {
        return company;
    }

    
    void setModel(const std::string &m) {
        model = m;
    }

    std::string getModel() const {
        return model;
    }

    
    void setYear(int y) {
        year = y;
    }

    int getYear() const {
        return year;
    }

    
    void display() const {
        std::cout << "Company: " << company << "\n";
        std::cout << "Model: " << model << "\n";
        std::cout << "Year: " << year << "\n";
    }
};

int main() {
    
    Car myCar("Toyota", "Camry", 2020);

    
    myCar.display();

    
    myCar.setCompany("Honda");
    myCar.setModel("Accord");
    myCar.setYear(2022);

    
    myCar.display();

    return 0;
}
