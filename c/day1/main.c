#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char** read_file_lines(char* file_path, int max_line_size, int* line_count);
void cleanup_array(char** src_array, int line_count);
int max_size(int* int_arr, int arr_size);
int compare_func(const void* a, const void* b);

int main() {
    int line_count = 0;
    char** lines = read_file_lines("../input.txt", 100, &line_count);

    int segment_count = 0;
    int running_total = 0;
    int* segments = malloc(sizeof(long) * 0);

    for(int i = 0; i < line_count; i++) {
        if(strcmp(lines[i], "") == 0) {
            segment_count++;
            segments = realloc(segments, sizeof(long) * segment_count);
            segments[segment_count - 1] = running_total;
            running_total = 0;
        } else {
            running_total += atoi(lines[i]);
        }
    }

    qsort(segments, segment_count, sizeof(int), compare_func);

    printf("%i\n", max_size(segments, segment_count));
    printf("%i\n", segments[0] + segments[1] + segments[2]);

    free(segments);
    cleanup_array(lines, line_count);

    return 0;
}

int max_size(int* int_arr, int arr_size) {
    int max = int_arr[0];
    for(int i = 0; i < arr_size; i++) {
        if(int_arr[i] > max) {
            max = int_arr[i];
        }
    }

    return max;
}

char** read_file_lines(char* file_path, int max_line_size, int* line_count) {
    FILE* input_file = fopen(file_path, "r");
    char current_line[max_line_size];
    int count = 0;
    char** results = malloc(sizeof(char*) * 0);

    while(fgets(current_line, max_line_size, input_file) != NULL) {
        char* new_line = malloc(sizeof(char) * strlen(current_line) + 1);
        strcpy(new_line, current_line);
        results = realloc(results, sizeof(char**) * (count + 1));
        new_line[strlen(new_line) - 1] = '\0';
        results[count] = new_line;
        count++;
    }

    fclose(input_file);

    *line_count = count;
    return results;
}

void cleanup_array(char** src_array, int line_count) {
    for(int i = 0; i < line_count; i++) {
        free(src_array[i]);
    }
    free(src_array);
}

int compare_func(const void* a, const void* b) {
    return (*(int*)b - *(int*)a);
}