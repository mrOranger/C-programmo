char *clone(char *source, size_t n_bytes)
{
    if (source == NULL)
    {
        return source;
    }

    char* cloned_source = (char*)calloc(n_bytes, sizeof(char));

    for (size_t index = 0; index < n_bytes || source[index] != '\0'; index++)
    {
        cloned_source[index] = source[index];
    }

    return cloned_source;
}

char *copy(char *source, char *destination, size_t n_bytes)
{
    if (source == NULL || destination == NULL)
    {
        return NULL;
    }

    for (size_t index = 0; index < n_bytes || destination[index] != '\0'; index++)
    {
        destination[index] = source[index];
    }

    return destination;
}

size_t length(char *source)
{
    if (source == NULL)
    {
        return 0;
    }

    size_t length = 0;

    for (size_t index = 0; source[index] != '\0'; index++)
    {
        length = length + 1;
    }

    return length;
}
