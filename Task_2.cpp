#include <iostream>
#include <vector>
#include <algorithm>

struct Person {
    std::string name;
    int amountPaid;
    int totalWeight;
    std::vector<int> apples;
};

void dApples(std::vector<Person>& persons, std::vector<int>& appleWeights) {

    std::sort(persons.begin(), persons.end(), [](const Person& a, const Person& b) {
        return a.amountPaid > b.amountPaid;
    });


    std::sort(appleWeights.begin(), appleWeights.end(), std::greater<int>());


    for (int weight : appleWeights) {
        for (auto& person : persons) {
            if (static_cast<double>(person.totalWeight + weight) / 1000 <= static_cast<double>(person.amountPaid) / 100) {
                person.totalWeight += weight;
                person.apples.push_back(weight);
                break;
            }
        }
    }
}

int main() {
    std::vector<Person> persons = {
        {"Ram", 50, 0, {}},
        {"Sham", 30, 0, {}},
        {"Rahim", 20, 0, {}}
    };

    std::vector<int> appleWeights;

    int weight;
    std::cout << "Enter apple weight in gram (-1 to stop): ";
    while (std::cin >> weight && weight != -1) {
        appleWeights.push_back(weight);
        std::cout << "Enter apple weight in gram (-1 to stop): ";
    }

    dApples(persons, appleWeights);

    std::cout << "Distribution Result:\n";
    for (const auto& person : persons) {
        std::cout << person.name << " : ";
        for (size_t i = 0; i < person.apples.size(); ++i) {
            std::cout << person.apples[i];
            if (i != person.apples.size() - 1) {
                if (person.name == "Sham" || person.name == "Rahim")
                    std::cout << " , ";
                else
                    std::cout << " ";
            }
        }
        std::cout << std::endl;
    }

    return 0;
}
