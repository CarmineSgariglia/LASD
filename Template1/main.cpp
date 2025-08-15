#include "zlasdtest/test.hpp"

#include "zmytest/test.hpp"

/* ************************************************************************** */

#include <iostream>

/* ************************************************************************** */

int main() {
    int choice = 0;

    while(true) {
        std::cout << "\n LASD TEMPLATE1 TEST SUITE 2025";
        std::cout << "\nSelect which test to run:\n"
                  << "  1) lasdtest() and mytest()\n"
                  << "  2) lasdtest()\n"
                  << "  3) mytest()\n"
                  << "Choice: ";
        if(!(std::cin >> choice)) {
            std::cin.clear();               
            std::cin.ignore(1000, '\n');   
            std::cout << "Invalid input, please try again.\n";
            continue;
        }
        switch(choice) {
        case 1:
            std::cout << "Running lasdtest() and mytest()...\n";
            lasdtest();
            mytest();
            break;
            std::cout << "Running lasdtest()...\n";
            lasdtest();
            break;
        case 2:
            std::cout << "Running lasdtest()...\n";
            lasdtest();
            break;
        case 3:
            std::cout << "Running mytest()...\n";
            mytest();
            break;
        default:
            std::cout << "Invalid choice, enter 1, 2 or 3.\n";
            continue;
        }
        break; 
    }
    return 0;
}
