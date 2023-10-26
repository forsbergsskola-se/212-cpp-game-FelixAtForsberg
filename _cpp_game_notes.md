https://www.libsdl.org/release/

# Including (works):


`#include <SDL.h>` -> `#include <SDL2/SDL.h>`
    
https://lazyfoo.net/tutorials/SDL/01_hello_SDL/mac/xcode/index.php#4
https://lazyfoo.net/tutorials/SDL/06_extension_libraries_and_loading_other_image_formats/mac/xcode/index.php
"SDL on Mac OS X does things differently, so we have to include the headers like this:"
    Windows                     Mac
    `#include <SDL/SDL.h>`   -> `#include <SDL2/SDL.h>`
    `#include <SDL_image.h>` -> `#include <SDL2_image/SDL_image.h>`



# CMake & XCode Problem:
    I think it could be that CLion switched to the xcode compiler
    and I think It previously used a brew installed one.
    

    error: "ld: symbol(s) not found for architecture x86_64"

    "This error indicates that your code, usually from the C family language, 
    has imported a header but has not yet been linked to it's implementation."

https://www.reddit.com/r/cpp/comments/137a572/cmake_and_linking_external_libraries_is_a_kick_in/
"CMake and Linking External libraries is a kick in the nuts if i've ever seen it."

https://izzys.casa/2020/12/how-to-find-packages-with-cmake-the-basics/
"whether we want to or not, many folks have to interact with CMake at least once in their life.
If they are unlucky, they might have to find dependencies using find_package.
If they are extremely unlucky, they might have to write a file to work with find_package."

"Worse, sometimes these libraries provide <Library>Config.cmake/<library>-config.cmake files which might not create imported targets and simply export cache variables.
One such library is SDL2. 
SDL2 is a wonderfully neat library, but it’s CMake experience leaves a lot to be desired."


## Algorithms & Data Structures Final Assignment: Hand-In 

### [Pathfinding Assignment - Github - Task Description](https://github.com/marczaku/200-project-period-2/blob/main/assignments/chapter1.md)

### [Pathfinding Assignment - Learnpoint - Assignment](https://forsbergs.learnpoint.se/GroupForms/Group_LearningContent_Item.aspx?Id=7&ItemId=240)


## 212 - C++ Game Programming
### [C++ Game Programming - Github - Instructions](https://github.com/marczaku/212-cpp-game-programming)

### [C++ Game Programming - Learnpoint - Assignment](https://forsbergs.learnpoint.se/GroupForms/Group_LearningContent_Item.aspx?Id=7&ItemId=267)

