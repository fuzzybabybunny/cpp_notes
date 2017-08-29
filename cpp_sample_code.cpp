#include <iostream>

struct StudioInfo {
    std::string name, location;
};


struct Movies {
  std::string title;
  int year;
  StudioInfo studio;
};

Movies mov1 = {"Lord of the Rings", 2010, {"Disney", "Los Angeles"}};
Movies mov2 = {"John Wick", 2009, {"Universal", "Los Angeles"}};

StudioInfo ReturnStudio(Movies movie){
    return movie.studio;
};

int main() {

    std::cout << ReturnStudio(mov2).name << std::endl;
    return 0;

}
