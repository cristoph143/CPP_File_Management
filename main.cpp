#include "Menu.h"
#include <iostream>

int main() {
  FileOps::Menu menu;
  FileOps::MenuItem items[] = {
      {"Create and save file", FileOps::createAndSaveFile},
      {"Read file", FileOps::readFiles}};

  for (const auto &item : items) {
    menu.addMenuItem(item);
  }

  menu.run();

  std::cout << "Exiting...\n";
  return 0;
}
