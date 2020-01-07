add_executable(testlexer
testlexer.cpp)

target_link_libraries(testlexer
AST
Lexer
Parser)