#include "argo.h"

int argo(json *dst, FILE *stream);
void free_json(json *j);

void to_json(json j)
{
    if (j.type == INTEGER)
        printf("%d", j.integer);
    else if (j.type == STRING)
    {
        printf("\"");
        int i = -1;
        while (j.string[++i])
        {
            if (j.string[i] == '\\' || j.string[i] == '"')
                printf("\\");
            printf("%c", j.string[i]);
        }
        printf("\"");
    }
    else if (j.type == MAP)
    {
        printf("{");
        int i = -1;
        while (++i < j.map.size)
        {
            if (i != 0)
                printf(",");
            json key_json;
            key_json.type = STRING;
            key_json.string = j.map.data[i].key;
            to_json(key_json);
            printf(":");
            to_json(j.map.data[i].value);
        }
        printf("}");
    }
}

int main(int argc, char **argv)
{
    if (argc != 2)
        return 1;
    char *filename = argv[1];
    FILE *stream = fopen(filename, "r");
    if (!stream) return 1;
    json j;
    if (argo(&j, stream) != 1)
    {
        free_json(&j);
        fclose(stream);
        return 1;
    }
    to_json(j);
    printf("\n");
    fclose(stream);
    return 0;
}