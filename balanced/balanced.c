#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

// Struct to hold the open and close braces and the pointer to the next element.
struct element 
{
    // char open; // not needed
    char close;
    struct element* next;
};

// Append the new element to the start of the stack
// This is one potential way to write this function signature
struct element* push (struct element* stack, char close) 
{
    struct element* new_element = (struct element*) malloc(sizeof(struct element));
    if (!new_element)
    {
        return NULL;
    }
    new_element->close = close;
    new_element->next = stack;
    return new_element;
}

// Remove element from the top of the stack
char pop ( struct element** stack ) 
{
    if (*stack != NULL) 
    {
        char close = (*stack)->close;
        struct element* temp = *stack;
        *stack = (*stack)->next;
        free(temp);
        return close;
    } 
    else 
    {
        return '\0';
    }
}

int main(int argc, char* argv[]) 
{

    FILE* fp = fopen(argv[1], "r");
    if (!fp) {
        perror("fopen failed");
        return EXIT_FAILURE;
    }

    struct element* root = NULL;
    bool balanced = true;

    char buff;
    while ( fscanf(fp, "%c", &buff)==1 ) 
    {

        switch(buff) 
        {
            case '<' :
                root = push(root, '>');
                break;
            case '(' :
                root = push(root, ')');
                break;
            case '[' :
                root = push(root, ']');
                break;
            case '{' :
                root = push(root, '}');
                break;
            case '>' :
                if (pop (&root) != '>')
                {
                    balanced = false;
                    break;
                }
                break;
            case ')' :
                if (pop (&root) != ')')
                {
                    balanced = false;
                    break;
                }
                break;
            case ']' :
                if (pop (&root) != ']')
                {
                    balanced = false;
                    break;
                }
                break;
            case '}' :
                if (pop (&root) != '}')
                {
                    balanced = false;
                    break;
                }
                break;
            default :
                printf("Invalid character\n" );
        }
    }

    if (root != NULL)
    {
        balanced = false;
    }

    printf ( balanced ? "yes" : "no" );
    fclose(fp);
    return 0;
}
