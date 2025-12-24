gcc -o tests.out \
    -lcunit \
    ./tests/main.c \
    ./tests/string/string_length/test_string_length.c \
    ./tests/string/string_copy/test_string_copy.c \
    ./tests/string/string_ncopy/test_string_ncopy.c \
    ./tests/string/create_empty/test_create_empty.c \
    ./tests/string/create_from_string/test_create_from_string.c \
    ./tests/string/size/test_size.c \
    ./tests/string/value/test_value.c \
    ./tests/string/valid/test_valid.c \
    ./tests/string/equals/test_equals.c \
    ./tests/string/includes/test_includes.c \
    ./tests/string/ends_with/test_ends_with.c \
    ./tests/string/starts_with/test_starts_with.c \
    ./tests/string/at/test_at.c \
    ./tests/string/upper/test_upper.c \
    ./tests/string/lower/test_lower.c \
    ./tests/string/concat/test_concat.c \
    ./tests/string/repeat/test_repeat.c \
    ./tests/string/replace/test_replace.c \
    ./tests/string/index_of/test_index_of.c \
    ./tests/string/destroy/test_destroy.c \
    ./libs/string/string.c 

./tests.out
