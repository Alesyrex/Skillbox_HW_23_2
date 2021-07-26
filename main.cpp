#include <iostream>

#define INPUT for(int i=0;i < 10;++i)
#define CHECK_WAGONS(passang,check,optimal) check ## Wagon ## (## passang ##,## optimal ##)

bool overcrowdedWagon (int count, int optimal) {
    return count > optimal;
}
bool emptyWagon (int count, int optimal) {
    return count < optimal;
}

int main() {

    int optimalCount = 20;
    int wagons[10];
    int countOverWagon = 0, countEmptyWagon = 0, countPassengers = 0;

    INPUT {
        std::cout << "Enter the number of passengers in wagon " << i+1 << ":";
        std::cin >> wagons[i];
        countEmptyWagon += CHECK_WAGONS(wagons[i],empty,optimalCount);
        countOverWagon += CHECK_WAGONS(wagons[i],overcrowded,optimalCount);
        countPassengers += wagons[i];
    };

    std::cout << "Overcrowded wagons: " << countEmptyWagon << std::endl;
    std::cout << "Unfilled wagons: " << countOverWagon << std::endl;
    std::cout << "Total passengers: " << countPassengers << std::endl;
    return 0;
}
