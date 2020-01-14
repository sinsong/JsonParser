# JsonParser

![C++](https://img.shields.io/badge/language-C%2B%2B-blue.svg)

Hand-made json parser, made with love by literal kernel.

Directory hierarchy is inspired by clang.
Source code are inspired by [dragonbook](https://suif.stanford.edu/dragonbook/).

* lexer  - scaner
* parser - recursive-descent parsing

directory hierarchy

```txt
include - include path
lib     - source
test    - test program source
json    - draft
```

test

```txt
lexer  - lexer tester
tryrun - test if parser work
data.json - test data
```

# build

to build is simple, just use CMake

```sh
$ cmake -S . -B ./build
```

then start build

```sh
$ cmake --build ./build
```

enjoy!
