
# Paths
* **llvm**
* **clang** -> clang17
* **clang-tidy**
* etc  
/usr/local/Cellar/llvm/17.0.3/bin

**Build Tool**:
/usr/local/Cellar/ninja/1.11.1/bin/ninja

**C / C++ Compiler**:  
/usr/local/Cellar/llvm/17.0.3/bin/clang-17


---

# CMake

LLVM Relevant:  
https://llvm.org/docs/CMake.html

## Frequently-used CMake variables[¶](https://llvm.org/docs/CMake.html#frequently-used-cmake-variables "Permalink to this heading")

**CMAKE_BUILD_TYPE**:STRING  
This configures the optimization level for make or ninja builds.
```md
Build Type      Optimizations   Debug Info  Assertions  Best suited for
-------------------------------------------------------------------------------------
Release         For Speed       No          No          Users of LLVM and Clang     
Debug           None            Yes         Yes         Developers of LLVM
RelWithDebInfo  For Speed       Yes         No          Users that also need Debug
MinSizeRel      For Size        No          No          When disk space matters
```

**CMAKE\_INSTALL\_PREFIX**:PATH  
Path where LLVM will be installed when the “install” target is built.

**CMAKE_{C,CXX}_FLAGS**:STRING  
Extra flags to use when compiling C and C++ source files respectively.

**CMAKE_{C,CXX}_COMPILER**:STRING   
Specify the C and C++ compilers to use. 
If you have multiple compilers installed, 
CMake might not default to the one you wish to **use.**


**LLVM_ENABLE_PROJECTS**:STRING  
    Control which projects are enabled. For example you may want to work on clang or lldb by specifying `-DLLVM_ENABLE_PROJECTS="clang;lldb"`.

**LLVM_ENABLE_RUNTIMES**:STRING  
    Control which runtimes are enabled. For example you may want to work on libc++ or libc++abi by specifying `-DLLVM_ENABLE_RUNTIMES="libcxx;libcxxabi"`.

**LLVM_LIBDIR_SUFFIX**:STRING  
    Extra suffix to append to the directory where libraries are to be installed. On a 64-bit architecture, one could use -DLLVM_LIBDIR_SUFFIX=64 to install libraries to /usr**/lib64**.

**LLVM_PARALLEL_{COMPILE,LINK}_JOBS**:STRING  
    Building the llvm toolchain can use a lot of resources, particularly linking. These options, when you use the Ninja generator, allow you to restrict the parallelism.  
    For example, to avoid OOMs or going into swap, permit only one link job per 15GB of RAM available on a 32GB machine, specify `-G Ninja -DLLVM_PARALLEL_LINK_JOBS=2`.

**LLVM_TARGETS_TO_BUILD**:STRING  
  Control which targets are enabled. 
  For example you may only need to enable your native target with, for example, `-DLLVM_TARGETS_TO_BUILD=X86`.

**LLVM_USE_LINKER**:STRING  
    Override the system’s default linker. For instance use lld with `-DLLVM_USE_LINKER=lld`.

## Less commonly used

**CMAKE\_CXX\_STANDARD**:STRING

Sets the C++ standard to conform to when building LLVM. Possible values are 17 and 20. LLVM Requires C++ 17 or higher. This defaults to 17.

**CMAKE\_INSTALL\_BINDIR**:PATH

The path to install executables, relative to the _CMAKE\_INSTALL\_PREFIX_. Defaults to “bin”.

**CMAKE\_INSTALL\_INCLUDEDIR**:PATH

The path to install header files, relative to the _CMAKE\_INSTALL\_PREFIX_. Defaults to “include”.

**CMAKE\_INSTALL\_DOCDIR**:PATH

The path to install documentation, relative to the _CMAKE\_INSTALL\_PREFIX_. Defaults to “share/doc”.

**CMAKE\_INSTALL\_MANDIR**:PATH

The path to install manpage files, relative to the _CMAKE\_INSTALL\_PREFIX_. Defaults to “share/man”.

## CMake caches
... Clang provides a collection of CMake cache scripts to make these features more approachable.

CMake cache files are utilized using CMake’s -C flag:  
`cmake -C <path to cache file> <path to sources>`

#### A few notes about CMake Caches:
* Order of command line arguments is important
    * `-D` arguments specified before `-C` are set before the cache is processed and can be read inside the cache file
    * `-D` arguments specified after `-C` are set after the cache is processed and are unset inside the cache file
* All `-D` arguments will override cache file settings
* `CMAKE_TOOLCHAIN_FILE` is evaluated after both the cache file and the command line arguments
* It is recommended that all `-D` options should be specified _before_ `-C`

## [Embedding LLVM in your project](https://llvm.org/docs/CMake.html#id19)[¶](https://llvm.org/docs/CMake.html#embedding-llvm-in-your-project "Permalink to this heading")


## [LLVM build-related variables (for building LLVM)](https://llvm.org/docs/CMake.html#llvm-related-variables)  


---
# Mac SDKs
## [Where are the C headers in MacOS Mojave?](https://stackoverflow.com/questions/53169970/where-are-the-c-headers-in-macos-mojave)
>`sudo find /Library -name stdio.h`  

[//]: # (Output replaced)
```
/Library/Developer/CommandLineTools/usr/include/c++/v1/stdio.h
/Library/Developer/CommandLineTools/SDKs/MacOSX13.1.sdk/usr/include/c++/v1/stdio.h
/Library/Developer/CommandLineTools/SDKs/MacOSX13.1.sdk/usr/include/sys/stdio.h
/Library/Developer/CommandLineTools/SDKs/MacOSX13.1.sdk/usr/include/stdio.h
/Library/Developer/CommandLineTools/SDKs/MacOSX13.1.sdk/System/Library/Frameworks/Kernel.framework/Versions/A/Headers/sys/stdio.h
```

> "Using dtruss I can see that Apple clang uses the one in CommandLineTools/SDKs"  
> `sudo dtruss -f sudo -u $USER clang test.c -o test 2>&1`
```
"/System/Library/Frameworks/"
"/Users/felixberge/Library/Developer/Toolchains"
"/usr/bin/clang"
"/usr/lib/libc++.1.dylib"
"/usr/lib/libc++abi.dylib"
"/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/lib/clang/14.0.0"
"/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/lib/clang/14.0.0/lib/darwin/x86_64"
"/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/lib/clang/14.0.0/lib/x86_64-apple-darwin21.6.0"
"/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/../lib/x86_64-apple-darwin21.6.0"
"/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer"
"/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs"
"/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/SDKSettings.plist"
"/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX13.1.sdk/SDKSettings.plist"
"/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX13.sdk/SDKSettings.plist"
"/Library/Developer/CommandLineTools/SDKs"
"/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/SDKSettings.plist"
"/Library/Developer/CommandLineTools/SDKs/MacOSX13.1.sdk/SDKSettings.plist"
"/Library/Developer/CommandLineTools/SDKs/MacOSX13.sdk/SDKSettings.plist"
"/Library/Developer/Toolchains"

```

# OSX File Formats
https://stackoverflow.com/questions/2339679/what-are-the-differences-between-so-and-dylib-on-macos

## .dylib   - shared libraries  
"Mach-O shared libraries"'    
dynamically linked  
filetype: `MH_DYLIB`  

> They can be linked against with the usual static linker flags, e.g:  
`-lfoo` for `libfoo.dylib`

> created by passing the `-dynamiclib` to the compiler (`-fPIC` is the default and needen't be specified)

> can be dynamically loaded 

## .so      - static libraries
"Mach-O object file"

## .bundle  - loadable modules
filetype: `MH_BUNDLE`



---
# [Toolchains](https://clang.llvm.org/docs/Toolchain.html)

### llvm
(_formerly meant 'low level virtual machine', now it's just a name_)  
A project offering a variety of (modular, swappable parts) tools, to facilitate/aid C/C++ development


_Command line tools reference:_ https://llvm.org/docs/CommandGuide/index.html

## Compilers

#### clang

#### 

## Linkers

Clang can be configured to use one of several different linkers:

#### *`GNU ld`
#### * `GNU gold`
#### * `LLVM’s lld`
[//]: # (    MSVC’s link.exe)



## Compiler runtime

The default runtime library is target-specific.  
For targets where GCC is the dominant compiler,  
Clang currently defaults to using `libgcc_`.   
On most other targets, `compiler-rt` is used by default.

`compiler-rt (LLVM)`



## Runtime Library
### [LLVM’s compiler runtime library  ](https://compiler-rt.llvm.org/)  
provides a complete set of runtime library functions containing all functions that Clang will implicitly call, in `libclang_rt.builtins.<arch>.a`.

You can instruct Clang to use compiler-rt with the `--rtlib=compiler-rt` flag. This is not supported on every platform.

If using `libc++` and/or `libc++abi`, you may need to configure them to use `compiler-rt` rather than `libgcc_s` by passing `-DLIBCXX_USE_COMPILER_RT=YES` and/or `-DLIBCXXABI_USE_COMPILER_RT=YES` to `cmake`. Otherwise, you may end up with both runtime libraries linked into your program (this is typically harmless, but wasteful).

`libgcc_s (GNU)`[¶](https://clang.llvm.org/docs/Toolchain.html#libgcc-s-gnu "Permalink to this heading")


### [GCC’s runtime library](https://gcc.gnu.org/onlinedocs/gccint/Libgcc.html) can be used in place of compiler-rt. However, it lacks several functions that LLVM may emit references to, particularly when using Clang’s `__builtin_*_overflow` family of intrinsics.

You can instruct Clang to use libgcc_s with the `--rtlib=libgcc` flag. This is not supported on every platform.


## Atomics library [¶](https://clang.llvm.org/docs/Toolchain.html#atomics-library "Permalink to this heading")

If your program makes use of atomic operations and the compiler is not able to lower them all directly to machine instructions (because there either is no known suitable machine instruction or the operand is not known to be suitably aligned), a call to a runtime library `__atomic_*` function will be generated.
A runtime library containing these atomics functions is necessary for such programs.

#### `compiler-rt` (LLVM)[¶](https://clang.llvm.org/docs/Toolchain.html#id1 "Permalink to this heading")

`compiler-rt` contains an implementation of an atomics library.

#### `libatomic` (GNU)[¶](https://clang.llvm.org/docs/Toolchain.html#libatomic-gnu "Permalink to this heading")

`libgcc_s` does not provide an implementation of an atomics library. Instead, [GCC’s libatomic library](https://gcc.gnu.org/wiki/Atomic/GCCMM) can be used to supply these when using libgcc_s.

__Note:__ Clang does not currently automatically link against `libatomic` when using `libgcc_s`. You may need to manually add `-latomic` to support this configuration when using non-native atomic operations (if you see link errors referring to `__atomic_*` functions).



## Sanitizer runtime[¶](https://clang.llvm.org/docs/Toolchain.html#sanitizer-runtime "Permalink to this heading")

The instrumentation added by Clang’s sanitizers (`-fsanitize=...`) implicitly makes calls to a runtime library, in order to maintain side state about the execution of the program and to issue diagnostic messages when a problem is detected.

The only supported implementation of these runtimes is provided by LLVM’s compiler-rt, and the relevant portion of that library (`libclang_rt.<sanitizer>.<arch>.a`) will be implicitly linked when linking with a `-fsanitize=...` flag.



## C standard library[¶](https://clang.llvm.org/docs/Toolchain.html#c-standard-library "Permalink to this heading")

Clang supports a wide variety of [C standard library](https://en.cppreference.com/w/c) implementations.



## C++ ABI library[¶](https://clang.llvm.org/docs/Toolchain.html#c-abi-library "Permalink to this heading")

The C++ ABI library provides an implementation of the library portion of the Itanium C++ ABI, covering both the [support functionality in the main Itanium C++ ABI document](https://itanium-cxx-abi.github.io/cxx-abi/abi.html) and [Level II of the exception handling support](https://itanium-cxx-abi.github.io/cxx-abi/abi-eh.html#cxx-abi). References to the functions and objects in this library are implicitly generated by Clang when compiling C++ code.

While it is possible to link C++ code using `libstdc++` and code using `libc++` together into the same program (so long as you do not attempt to pass C++ standard library objects across the boundary), it is not generally possible to have more than one C++ ABI library in a program.

The version of the C++ ABI library used by Clang will be the one that the chosen C++ standard library was linked against. Several implementations are available:

## `libc++abi (LLVM)`[¶](https://clang.llvm.org/docs/Toolchain.html#libc-abi-llvm "Permalink to this heading")

[libc++abi](https://libcxxabi.llvm.org/) is LLVM’s implementation of this specification.



### `libsupc++ (GNU)`[¶](https://clang.llvm.org/docs/Toolchain.html#libsupc-gnu "Permalink to this heading")

`libsupc++` is GCC’s implementation of this specification. 
However, this library is only used when libstdc++ is linked statically. 
The dynamic library version of libstdc++ contains a copy of libsupc++.

**_Note:_** Clang does not currently automatically link against `libsupc++` when statically linking `libstdc++`. 
You may need to manually add `-lsupc++` to support this configuration when using `-static` or `-static-libstdc++`.



### `libcxxrt (PathScale)`[¶](https://clang.llvm.org/docs/Toolchain.html#libcxxrt-pathscale "Permalink to this heading")  
This is another implementation of the Itanium C++ ABI specification. See [libcxxrt](https://github.com/pathscale/libcxxrt).



## C++ standard library[¶](https://clang.llvm.org/docs/Toolchain.html#id6 "Permalink to this heading")
Clang supports use of either LLVM’s `libc++` or `GCC`’s `libstdc++` implementation of the [C++ standard library](https://en.cppreference.com/w/cpp).


### `libc++ (LLVM)`[¶](https://clang.llvm.org/docs/Toolchain.html#libc-llvm "Permalink to this heading")

[libc++](https://libcxx.llvm.org/) is LLVM’s implementation of the C++ standard library, aimed at being a complete implementation of the C++ standards from C++11 onwards.

You can instruct Clang to use `libc++` with the `-stdlib=libc++` flag.


### `libstdc++ (GNU)`[¶](https://clang.llvm.org/docs/Toolchain.html#libstdc-gnu "Permalink to this heading")

[libstdc++](https://gcc.gnu.org/onlinedocs/libstdc++/) is GCC’s implementation of the C++ standard library. 
Clang supports libstdc++ 4.8.3 (released 2014-05-22) and later. Historically Clang implemented workarounds for issues discovered in libstdc++, and these are removed as fixed libstdc++ becomes sufficiently old.

You can instruct Clang to use `libstdc++` with the `-stdlib=libstdc++` flag.