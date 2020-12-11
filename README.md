Minimal example to show the weird linker issues I'm seeing on `osx-arm64`

To reproduce:

```
mamba env create
conda activate gtest-fail
./check.sh
```

This gives the following output for me:

```
% ./check.sh
+ rm -rf build
+ mkdir build
+ pushd build
~/Development/gtest-fail/build ~/Development/gtest-fail
+ cmake -GNinja ..
-- The C compiler identification is Clang 11.0.0
-- The CXX compiler identification is Clang 11.0.0
-- Detecting C compiler ABI info
-- Detecting C compiler ABI info - done
-- Check for working C compiler: /Users/uwe/mambaforge/envs/gtest-fail/bin/arm64-apple-darwin20.0.0-clang - skipped
-- Detecting C compile features
-- Detecting C compile features - done
-- Detecting CXX compiler ABI info
-- Detecting CXX compiler ABI info - done
-- Check for working CXX compiler: /Users/uwe/mambaforge/envs/gtest-fail/bin/arm64-apple-darwin20.0.0-clang++ - skipped
-- Detecting CXX compile features
-- Detecting CXX compile features - done
-- Found GTest: /Users/uwe/mambaforge/envs/gtest-fail/lib/libgtest.dylib
-- Configuring done
-- Generating done
-- Build files have been written to: /Users/uwe/Development/gtest-fail/build
+ ninja
[2/2] Linking CXX executable test
FAILED: test
: && /Users/uwe/mambaforge/envs/gtest-fail/bin/arm64-apple-darwin20.0.0-clang++ -ftree-vectorize -fPIC -fPIE -fstack-protector-strong -O2 -pipe -stdlib=libc++ -fvisibility-inlines-hidden -std=c++14 -fmessage-length=0 -isystem /Users/uwe/mambaforge/envs/gtest-fail/include -O3 -DNDEBUG -arch arm64 -isysroot /Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk -Wl,-search_paths_first -Wl,-headerpad_max_install_names -Wl,-pie -Wl,-headerpad_max_install_names -Wl,-dead_strip_dylibs -Wl,-rpath,/Users/uwe/mambaforge/envs/gtest-fail/lib -L/Users/uwe/mambaforge/envs/gtest-fail/lib CMakeFiles/test.dir/test.cpp.o -o test  /Users/uwe/mambaforge/envs/gtest-fail/lib/libgtest_main.dylib  /Users/uwe/mambaforge/envs/gtest-fail/lib/libgtest.dylib && :
clang-11: error: unable to execute command: Killed: 9
clang-11: error: linker command failed due to signal (use -v to see invocation)
ninja: build stopped: subcommand failed.
```
