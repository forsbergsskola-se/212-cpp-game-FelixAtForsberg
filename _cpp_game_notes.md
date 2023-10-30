https://www.libsdl.org/release/

---

Run/Debug Configurations gets its info on targets from the project file CMake creates 
when ran on an empty build tree (`cmake .``)

CMake creates its

CMake runs _its_ build creation instruction (using a build system generator defined via argument 
    `-G <generator-name>` )when ran on "an empty build tree" (which I assume means that 
there's no pre-existing, populated directory at the path of `CMAKE_BINARY_DIR`)

"Makefile" 

---

Preferences | Build, Execution, Deployment | CMake 

---
## The following configuration files were considered but not accepted

/Library/Frameworks/SDL2_image.framework/Resources/CMake/sdl2_image-config.cmake, version: 2.6.3
/Library/Frameworks/SDL2_image.framework/Versions/A/Resources/CMake/sdl2_image-config.cmake, version: 2.6.3
/Library/Frameworks/SDL2_image.framework/Versions/Current/Resources/CMake/sdl2_image-config.cmake, version: 2.6.3

// https://discourse.cmake.org/t/find-package-error-the-following-configuration-files-were-considered-but-not-accepted-what-does-it-mean/5003/2
Possible cause: correct architecture target not selected?

#### FIX:
```bash
export ARCHFLAGS="x86_64" # in toolchain environment file (env_clion_eap_llvm.sh), 
                          # loaded by toolchain from: 
                          # Preferences | Build, Execution, Deployment | Toolchains 
```

--- 
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









-*
mpi-*
bugprone-*
-bugprone-signal-handler
-bugprone-narrowing-conversions
-bugprone-multiple-new-in-one-expression
-bugprone-unchecked-optional-access
-bugprone-implicit-widening-of-multiplication-result
-bugprone-signed-char-misuse
-bugprone-assignment-in-if-condition
-bugprone-bool-pointer-implicit-conversion
-bugprone-unhandled-exception-at-new
-bugprone-infinite-loop
-bugprone-easily-swappable-parameters
-bugprone-non-zero-enum-to-bool-conversion
-bugprone-stringview-nullptr
cert-err52-cpp
cert-err60-cpp
cert-err34-c
cert-str34-c
cert-dcl21-cpp
cert-msc50-cpp
cert-oop58-cpp
cert-dcl50-cpp
cert-oop57-cpp
cert-msc51-cpp
cert-dcl58-cpp
cert-flp30-c
clang-analyzer-core.uninitialized.CapturedBlockVariable
cppcoreguidelines-*
-cppcoreguidelines-avoid-capturing-lambda-coroutines
-cppcoreguidelines-non-private-member-variables-in-classes
-cppcoreguidelines-macro-usage
-cppcoreguidelines-misleading-capture-default-by-value
-cppcoreguidelines-pro-type-reinterpret-cast
-cppcoreguidelines-use-default-member-init
-cppcoreguidelines-explicit-virtual-functions
-cppcoreguidelines-avoid-reference-coroutine-parameters
-cppcoreguidelines-owning-memory
-cppcoreguidelines-pro-type-union-access
-cppcoreguidelines-avoid-do-while
-cppcoreguidelines-c-copy-assignment-signature
-cppcoreguidelines-special-member-functions
-cppcoreguidelines-avoid-magic-numbers
-cppcoreguidelines-avoid-c-arrays
google-default-arguments
google-runtime-operator
google-explicit-constructor
hicpp-multiway-paths-covered
hicpp-undelegated-constructor
hicpp-exception-baseclass
misc-*
-misc-unused-parameters
-misc-unused-alias-decls
-misc-use-anonymous-namespace
-misc-misleading-identifier
-misc-confusable-identifiers
-misc-unused-using-decls
-misc-misleading-bidirectional
-misc-non-private-member-variables-in-classes
modernize-*
-modernize-use-trailing-return-type
-modernize-macro-to-enum
openmp-use-default-none
performance-*
-performance-no-int-to-ptr
portability-*
-portability-restrict-system-includes
readability-*
-readability-named-parameter
-readability-function-size
-readability-identifier-length
-readability-magic-numbers
-readability-braces-around-statements
-readability-suspicious-call-argument
-readability-isolate-declaration
-readability-uppercase-literal-suffix
-readability-function-cognitive-complexity
-readability-operators-representation
-readability-implicit-bool-conversion