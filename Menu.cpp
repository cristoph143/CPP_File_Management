#include "Menu.h"
#include <chrono>
#include <iostream>
#include <limits>
#include <thread>

namespace FileOps {

Menu::Menu() {}

Menu::~Menu() {}

void Menu::printMenu() const {
  std::cout << "------------------------------------------------------------\n";
  std::cout << "Menu\n";
  std::cout << "------------------------------------------------------------\n";
  int index = 1;
  for (const auto &item : menuItems) {
    std::cout << index++ << ". " << item.description << "\n";
  }
  std::cout << "0. Exit\n";
  std::cout << "------------------------------------------------------------\n";
  std::cout << "Enter Choice: ";
}

void Menu::processChoice(int choice) {
  if (choice > 0 && choice <= static_cast<int>(menuItems.size())) {
    menuItems[choice - 1].action();
  } else {
    std::cout << "Invalid choice. Please enter a valid option.\n";
  }
}

int Menu::getValidChoice() const {
  int choice;
  while (!(std::cin >> choice) || choice < 0 ||
         choice > static_cast<int>(menuItems.size())) {
    std::cout << "Invalid choice. Please enter a valid option: ";
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  }
  return choice;
}

void Menu::run() {
  int choice = -1;
  do {
    std::cout << std::string(50, '\n');
    printMenu();
    choice = getValidChoice();
    clearInputBuffer();
    if (choice != 0) {
      processChoice(choice);
      // Add a delay to allow the user to read any output from their choice
      std::this_thread::sleep_for(std::chrono::seconds(1));
    }
  } while (choice != 0);
}

void Menu::clearInputBuffer() {
  std::cin.clear();
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void Menu::addMenuItem(const MenuItem &item) { menuItems.push_back(item); }

void Menu::goodbye() { std::cout << "Goodbye\n"; }

void createAndSaveFile() { std::cout << "Creating and saving a file.\n"; }

void readFiles() { std::cout << "Reading files.\n"; }

} // namespace FileOps
