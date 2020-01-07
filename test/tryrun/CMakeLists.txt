add_executable(tryrun
tryrun.cpp)

target_link_libraries(tryrun
AST
Lexer
Parser)