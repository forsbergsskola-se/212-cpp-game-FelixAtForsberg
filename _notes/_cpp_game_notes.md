https://www.libsdl.org/release/

### SDL2
By Name:
https://wiki.libsdl.org/SDL2/CategoryAPI

By Category:
https://wiki.libsdl.org/SDL2/APIByCategory

### SDL2_ttf
https://wiki.libsdl.org/SDL2_ttf/CategoryAPI

---
# Cost of comparing a string

; -------------------------------------------------------------------------------------------------
; bool no_comp_s(const string& a, const string& b) {

;     cout << "no_comb: " << a << "\n" << b;

;     return 1;

; }

; cmp_string`no_comp_s:
    0x10c534510 <+0>:  pushq  %rbp
    0x10c534511 <+1>:  movq   %rsp, %rbp
    0x10c534514 <+4>:  subq   $0x10, %rsp
    
    0x10c534518 <+8>:  movq   %rdi, -0x8(%rbp)
    0x10c53451c <+12>: movq   %rsi, -0x10(%rbp)
    0x10c534520 <+16>: movq   0x1ae1(%rip), %rdi        ; (void *)0x00007ff84a820ca0: std::__1::cout
    0x10c534527 <+23>: leaq   0x19da(%rip), %rsi        ; "no_comb: "
    
    0x10c53452e <+30>: callq  0x10c535d30               ; symbol stub for: std::__1::basic_ostream<char, std::__1::char_traits<char>>& std::__1::operator<<<std::__1::char_traits<char>>(std::__1::basic_ostream<char, std::__1::char_traits<char>>&, char const*)
    
    
    
    
    
    
    
    0x10c534533 <+35>: movq   %rax, %rdi
    0x10c534536 <+38>: movq   -0x8(%rbp), %rsi

    0x10c53453a <+42>: callq  0x10c535d36               ; symbol stub for: std::__1::basic_ostream<char, std::__1::char_traits<char>>& std::__1::operator<<<char, std::__1::char_traits<char>, std::__1::allocator<char>>(std::__1::basic_ostream<char, std::__1::char_traits<char>>&, std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char>> const&)
    0x10c53453f <+47>: movq   %rax, %rdi
    0x10c534542 <+50>: leaq   0x19c9(%rip), %rsi        ; "'\n'"
    0x10c534549 <+57>: callq  0x10c535d30               ; symbol stub for: std::__1::basic_ostream<char, std::__1::char_traits<char>>& std::__1::operator<<<std::__1::char_traits<char>>(std::__1::basic_ostream<char, std::__1::char_traits<char>>&, char const*)
    0x10c53454e <+62>: movq   %rax, %rdi
    0x10c534551 <+65>: movq   -0x10(%rbp), %rsi
    0x10c534555 <+69>: callq  0x10c535d36               ; symbol stub for: std::__1::basic_ostream<char, std::__1::char_traits<char>>& std::__1::operator<<<char, std::__1::char_traits<char>, std::__1::allocator<char>>(std::__1::basic_ostream<char, std::__1::char_traits<char>>&, std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char>> const&)
->  0x10c53455a <+74>: movb   $0x1, %al
    0x10c53455c <+76>: andb   $0x1, %al
    0x10c53455e <+78>: movzbl %al, %eax
    0x10c534561 <+81>: addq   $0x10, %rsp
    0x10c534565 <+85>: popq   %rbp
    0x10c534566 <+86>: retq   


; -------------------------------------------------------------------------------------------------
; bool comp_s(const string& a, const string& b) {

;     bool equivalent = (a == b);

;     cout << "comp_s: " << a << "\n" << b;

;     return equivalent;
; }

(lldb) disassemble -n comp_s
; cmp_string`comp_s:
    0x10c534600 <+0>:   pushq  %rbp
    0x10c534601 <+1>:   movq   %rsp, %rbp
    0x10c534604 <+4>:   subq   $0x20, %rsp
    
    0x10c534608 <+8>:   movq   %rdi, -0x8(%rbp)
    0x10c53460c <+12>:  movq   %rsi, -0x10(%rbp)
->  0x10c534610 <+16>:  movq   -0x8(%rbp), %rdi
    0x10c534614 <+20>:  movq   -0x10(%rbp), %rsi
    
    0x10c534618 <+24>:  callq  0x10c534670               ; std::__1::operator==<std::__1::allocator<char>> at string:4087
    0x10c53461d <+29>:  andb   $0x1, %al
    0x10c53461f <+31>:  movb   %al, -0x11(%rbp)
    0x10c534622 <+34>:  movq   0x19df(%rip), %rdi        ; (void *)0x00007ff84a820ca0: std::__1::cout
    0x10c534629 <+41>:  leaq   0x18e4(%rip), %rsi        ; "comp_s: "

    0x10c534630 <+48>:  callq  0x10c535d30               ; symbol stub for: std::__1::basic_ostream<char, std::__1::char_traits<char>>& std::__1::operator<<<std::__1::char_traits<char>>(std::__1::basic_ostream<char, std::__1::char_traits<char>>&, char const*)

    0x10c534635 <+53>:  movq   %rax, %rdi
    0x10c534638 <+56>:  movq   -0x8(%rbp), %rsi
    
    0x10c53463c <+60>:  callq  0x10c535d36               ; symbol stub for: std::__1::basic_ostream<char, std::__1::char_traits<char>>& std::__1::operator<<<char, std::__1::char_traits<char>, std::__1::allocator<char>>(std::__1::basic_ostream<char, std::__1::char_traits<char>>&, std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char>> const&)
    0x10c534641 <+65>:  movq   %rax, %rdi
    0x10c534644 <+68>:  leaq   0x18c7(%rip), %rsi        ; "'\n'"
    0x10c53464b <+75>:  callq  0x10c535d30               ; symbol stub for: std::__1::basic_ostream<char, std::__1::char_traits<char>>& std::__1::operator<<<std::__1::char_traits<char>>(std::__1::basic_ostream<char, std::__1::char_traits<char>>&, char const*)
    0x10c534650 <+80>:  movq   %rax, %rdi
    0x10c534653 <+83>:  movq   -0x10(%rbp), %rsi
    0x10c534657 <+87>:  callq  0x10c535d36               ; symbol stub for: std::__1::basic_ostream<char, std::__1::char_traits<char>>& std::__1::operator<<<char, std::__1::char_traits<char>, std::__1::allocator<char>>(std::__1::basic_ostream<char, std::__1::char_traits<char>>&, std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char>> const&)
    0x10c53465c <+92>:  movb   -0x11(%rbp), %al
    0x10c53465f <+95>:  andb   $0x1, %al
    0x10c534661 <+97>:  movzbl %al, %eax
    0x10c534664 <+100>: addq   $0x20, %rsp
    0x10c534668 <+104>: popq   %rbp
    0x10c534669 <+105>: retq   


; -------------------------------------------------------------------------------------------------
; cmp_string`std::__1::operator==<std::__1::allocator<char>>:
    0x10c534670 <+0>:   pushq  %rbp
    0x10c534671 <+1>:   movq   %rsp, %rbp
    0x10c534674 <+4>:   subq   $0x40, %rsp
    0x10c534678 <+8>:   movq   %rdi, -0x10(%rbp)
    0x10c53467c <+12>:  movq   %rsi, -0x18(%rbp)
    0x10c534680 <+16>:  movq   -0x10(%rbp), %rdi
    0x10c534684 <+20>:  callq  0x10c535640               ; std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char>>::size at string:978
    0x10c534689 <+25>:  movq   %rax, -0x20(%rbp)
    0x10c53468d <+29>:  movq   -0x20(%rbp), %rax
    0x10c534691 <+33>:  movq   %rax, -0x38(%rbp)
    0x10c534695 <+37>:  movq   -0x18(%rbp), %rdi
    0x10c534699 <+41>:  callq  0x10c535640               ; std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char>>::size at string:978
    0x10c53469e <+46>:  movq   %rax, %rcx
    0x10c5346a1 <+49>:  movq   -0x38(%rbp), %rax
    0x10c5346a5 <+53>:  cmpq   %rcx, %rax
    0x10c5346a8 <+56>:  je     0x10c5346b7               ; <+71> at string:4091:24
    0x10c5346ae <+62>:  movb   $0x0, -0x1(%rbp)
    0x10c5346b2 <+66>:  jmp    0x10c534769               ; <+249> at string:4099:1
    0x10c5346b7 <+71>:  movq   -0x10(%rbp), %rdi
    0x10c5346bb <+75>:  callq  0x10c535610               ; std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char>>::data at string:1265
    0x10c5346c0 <+80>:  movq   %rax, -0x28(%rbp)
    0x10c5346c4 <+84>:  movq   -0x18(%rbp), %rdi
    0x10c5346c8 <+88>:  callq  0x10c535610               ; std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char>>::data at string:1265
    0x10c5346cd <+93>:  movq   %rax, -0x30(%rbp)
    0x10c5346d1 <+97>:  movq   -0x10(%rbp), %rdi
    0x10c5346d5 <+101>: callq  0x10c535330               ; std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char>>::__is_long at string:1459
    0x10c5346da <+106>: testb  $0x1, %al
    0x10c5346dc <+108>: jne    0x10c5346e7               ; <+119> at string:4094:43
    0x10c5346e2 <+114>: jmp    0x10c534708               ; <+152> at string:4095:5
    0x10c5346e7 <+119>: movq   -0x28(%rbp), %rdi
    0x10c5346eb <+123>: movq   -0x30(%rbp), %rsi
    0x10c5346ef <+127>: movq   -0x20(%rbp), %rdx
    0x10c5346f3 <+131>: callq  0x10c535cee               ; symbol stub for: std::__1::char_traits<char>::compare(char const*, char const*, unsigned long)
    0x10c5346f8 <+136>: cmpl   $0x0, %eax
    0x10c5346fb <+139>: sete   %al
    0x10c5346fe <+142>: andb   $0x1, %al
    0x10c534700 <+144>: movb   %al, -0x1(%rbp)
    0x10c534703 <+147>: jmp    0x10c534769               ; <+249> at string:4099:1
    0x10c534708 <+152>: jmp    0x10c53470d               ; <+157> at string:4095:21
    0x10c53470d <+157>: cmpq   $0x0, -0x20(%rbp)
    0x10c534712 <+162>: je     0x10c534765               ; <+245> at string:4098:5
    0x10c534718 <+168>: movq   -0x28(%rbp), %rax
    0x10c53471c <+172>: movsbl (%rax), %eax
    0x10c53471f <+175>: movq   -0x30(%rbp), %rcx
    0x10c534723 <+179>: movsbl (%rcx), %ecx
    0x10c534726 <+182>: cmpl   %ecx, %eax
    0x10c534728 <+184>: je     0x10c534737               ; <+199> at string:4096:23
    0x10c53472e <+190>: movb   $0x0, -0x1(%rbp)
    0x10c534732 <+194>: jmp    0x10c534769               ; <+249> at string:4099:1
    0x10c534737 <+199>: jmp    0x10c53473c               ; <+204> at string:4095:27
    0x10c53473c <+204>: movq   -0x20(%rbp), %rax
    0x10c534740 <+208>: addq   $-0x1, %rax
    0x10c534744 <+212>: movq   %rax, -0x20(%rbp)
    0x10c534748 <+216>: movq   -0x28(%rbp), %rax
    0x10c53474c <+220>: addq   $0x1, %rax
    0x10c534750 <+224>: movq   %rax, -0x28(%rbp)
    0x10c534754 <+228>: movq   -0x30(%rbp), %rax
    0x10c534758 <+232>: addq   $0x1, %rax
    0x10c53475c <+236>: movq   %rax, -0x30(%rbp)
    0x10c534760 <+240>: jmp    0x10c53470d               ; <+157> at string:4095:21
    0x10c534765 <+245>: movb   $0x1, -0x1(%rbp)
    0x10c534769 <+249>: movb   -0x1(%rbp), %al
    0x10c53476c <+252>: andb   $0x1, %al
    0x10c53476e <+254>: movzbl %al, %eax
    0x10c534771 <+257>: addq   $0x40, %rsp
    0x10c534775 <+261>: popq   %rbp
    0x10c534776 <+262>: retq   


---
### Problem ID: 3eb9bf17-0e72-463c-b961-c491236c3179
### Problem:
    I want to only update the texture of a label when the text changes, in C++, getters and setters are usually considered code smells which is how I would handle this in say C#; now how should I do it?
    I wish to follow "Tell Don't Ask" // https://wiki.c2.com/?TellDontAsk=



### Thinking about the solution:
    I could wrap std::string and define a new assignment operator
    But that would be more verbose than I'd like

### Solution:
    Modify text through a handle; which can also hold render context

---
### Problem:
  const shared_ptr&: doesn't work
    
  but shared_ptr by copy does work

#### const shared_ptr --- DOESN'T WORK
```c++
    // scene.cpp
    Scene::Scene( const std::shared_ptr<RenderContext>& context ) : // ...
                                                             renderContext { std::weak_ptr(context) }
    // ------------------------------------------------------------------------------
    // scene.h
    explicit Scene( const std::shared_ptr<RenderContext>& context );
    
```
#### pass shared_ptr by copy --- WORKS
```c++
    // scene.cpp
    Scene::Scene( std::shared_ptr<RenderContext> context ) : // ...
                                                            renderContext { std::weak_ptr(context) },
    // ------------------------------------------------------------------------------
    // scene.h
    explicit Scene( std::shared_ptr<RenderContext> context );

```
it should work:
    https://stackoverflow.com/questions/8385457/should-i-pass-a-shared-ptr-by-reference
    ""


---
```
+----------+     +------+ 
| Game_lib |     | SDL2 |
+----|-----+     +--|---+ 
     |              |
     +--------------+ 
     |
+----↓-----+
| Game_exe |
+----------+
```

                                 SDL2
Test_exe --[Dynamically]-> Game_lib 

Test --[]

---

Fix:
    Correct casing in path to real filename 
    "system/Window.h" -> "system/window.h"

Problem:

/Users/felixberge/Projects/ C++/212-cpp-game-FelixAtForsberg/tests/test_window.cpp:2:10: warning: non-portable path to file '"system/window.h"'; specified path differs in case from file name on disk [-Wnonportable-include-path]
#include "system/Window.h"
---

FIX: 
Same signature

after:
target_link_libraries( ${TEST_EXECUTABLE} PRIVATE GTest::gtest_main )

                
before :
target_link_libraries( ${TEST_EXECUTABLE} GTest::gtest_main )


Problem:

CMake Error at tests/CMakeLists.txt:30 (target_link_libraries):
  The keyword signature for target_link_libraries has already been used with
  the target "SDLGameProject_tests".  All uses of target_link_libraries with
  a target must be either all-keyword or all-plain.

---
CMake Project Examples:
CMake CPP-103
https://github.com/marczaku/cpp-103/tree/main/solution
    
https://github.com/marczaku/cpp-103/blob/main/solution/CMakeLists.txt
https://github.com/marczaku/cpp-103/blob/main/solution/src/class_library/CMakeLists.txt
https://github.com/marczaku/cpp-103/blob/main/solution/src/CMakeLists.txt
https://github.com/marczaku/cpp-103/blob/main/solution/src/CMakeLists.txt
https://github.com/marczaku/cpp-103/blob/main/solution/tests/class_library_tests/CMakeLists.txt
https://github.com/marczaku/cpp-103/blob/main/solution/tests/CMakeLists.txt


CMake CPP-103CPP Tests.cpp:
https://github.com/marczaku/cpp-103/blob/main/solution/tests/class_library_tests/vector3_test.cpp



CMake - Krita:
https://invent.kde.org/graphics/krita

CMake - Blender
https://projects.blender.org/blender/blender
https://projects.blender.org/blender/blender/src/branch/main/source/CMakeLists.txt

---
Fix:
initialize `Texture::renderer`
           `Texture::format` 

Problem:
  "Texture::renderer", referenced from:
      Texture::CreateSurface(std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char> >&) in texture_factory.cpp.o
      Texture::CreateTexture(std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char> >&) in texture_factory.cpp.o
      Window::SetWindowImage(std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char> >&) in window.cpp.o
ld: symbol(s) not found for architecture x86_64

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