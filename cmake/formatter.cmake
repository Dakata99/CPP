# TODO: make build system automatically download needed tools

# How to use?
## clang-format --style="{BasedOnStyle: Google, IndentWidth: 4, TabWidth: 4}" -i <file>
find_program(FORMATTER clang-format REQUIRED)
