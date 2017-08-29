# Notes on C++

## IDE

Currently using **CodeBlocks**
**Eclipse** is the big one.

## General Notes

- C++ requires importing of different libraries to do even the most basic things.

- White space does not matter at all.

- Every C++ program requires a `main()` function and it must return an **int**.

- **namespace** allows you to use the same variable name in the same program as long as you specify the namespace while calling it.

- **char** needs to be wrapped in single quotes `'A'`

These two are the same:

```C++
#include <iostream>

int main(){

    std::cout << "Hello world!";
    
}
```

```C++
#include <iostream>

using namespace std;

int main(){

    cout << "Hello world!";

}
```
## Arrays

- Arrays of **char** need to end in `'\0' `.
- Declaring arrays requires the type of data to be stored inside the array and sometimes the size of the array. `float array1[4];` is an array of floating numbers that's a size of 4.
- C++ does not having limit checking, so a random value will still be returned to you even if the index you specify is out of range of the array.
- `sizeof` does not return the number of elements, but the number of bytes in the array
- To return the number of elements, use `sizeof(arr)/sizeof(arr[0])`
- Arrays are typed using `{ }` instead of `[ ]`.
- `myArray.size()` can return the number of elements, but requires **ISO C++ 2011 standard** support in the compiler and library.
- You cannot declare the array and then completely assign it all at once later on, unless you're using C++ 2011. This doesn't work:
```C++
int arr2[5];
arr2 = {3, 2, 6, 3, 1};
```
This works:
```C++
#include <iostream>

int main() {

    char arr1[4] = {'B', 'A', 'C', 'K'};
    std::cout << sizeof(arr1)/sizeof(arr1[0]) << std::endl;

    int arr2[5] = {3, 2, 6, 3, 1};
    std::cout << sizeof(arr2)/sizeof(arr2[0]) << std::endl;

    return 0;

}
```
## Struct
- Kind of like an object.
```C++
#include <iostream>

struct Movies {
  std::string title;
  int year;
};

Movies mov1 = {"Lord of the Rings", 2010};

int main() {

    std::cout << mov1.title << std::endl;
    // prints "Lord of the Rings"
    return 0;

}

```
Nested Struct:
```C++
#include <iostream>

struct StudioInfo {
    std::string name;
    std::string location;
};


struct Movies {
  std::string title;
  int year;
  StudioInfo studio;
};

Movies mov1 = {"Lord of the Rings", 2010, {"Disney", "Los Angeles"}};

int main() {

    std::cout << mov1.title << std::endl;
    std::cout << mov1.studio.location << std::endl;
    return 0;

}

```

##Functions
- Need to specify what type of data it will return.
- If not returning anything, type is **void**

```C++
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
	// prints "Universal"
    std::cout << ReturnStudio(mov2).name << std::endl;
    return 0;

}
```