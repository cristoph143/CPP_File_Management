#ifndef MENU_H
#define MENU_H

#include <functional>
#include <string>
#include <vector>

namespace FileOps {

// Define a struct that holds a menu item's description and its associated
// function.
struct MenuItem {
  std::string description;
  std::function<void()> action;
};

class Menu {
public:
  Menu();
  ~Menu();

  void printMenu() const;
  void processChoice(int choice);
  int getValidChoice() const;
  void run();
  void addMenuItem(const MenuItem &item);
  static void clearInputBuffer();

private:
  std::vector<MenuItem> menuItems;
  static void goodbye();
};

void createAndSaveFile();
void readFiles();

} // namespace FileOps

#endif /* MENU_H */
