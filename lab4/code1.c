#include <stdio.h>
#include <string.h>

/* Function to perform backtracking and find combinations */
void backtracking(int *current_combo, int current_size, int current_sum, int starting_index, int target_sum,
                  int *each_score, const char **labels, int result[][10], int *result_sizes, int *result_count) {
    /* Check if the current sum matches the target sum */
    if (current_sum == target_sum) {
        /* Store the current combination in the result */
        for (int i = 0; i < current_size; i++) {
            result[*result_count][i] = current_combo[i];
        }
        result_sizes[*result_count] = current_size;
        (*result_count)++;
        return;
    }
    /* Return if the remaining sum is less than 2 */
    if (target_sum - current_sum < 2) {
        return;
    }
    /* Iterate through the possible scores */
    for (int i = starting_index; i < 5; i++) { // assuming there are always 5 scores
        current_combo[current_size] = each_score[i];
        /* Recursive call to continue building the combination */
        backtracking(current_combo, current_size + 1, current_sum + each_score[i], i, target_sum, each_score, labels, result, result_sizes, result_count);
    }
}

/* Function to initialize the backtracking process */
void all_combos(int target_sum, int *each_score, const char **labels, int result[][10], int *result_sizes, int *result_count) {
    *result_count = 0;
    int current_combo[10]; /* Temporary array to hold current combination */
    backtracking(current_combo, 0, 0, 0, target_sum, each_score, labels, result, result_sizes, result_count);
}

/* Main function to drive the program */
int main() {
    int TD = 6;        /* Touchdown score */
    int FG = 3;       /* Field Goal score */
    int SFTY = 2;     /* Safety score */
    int TD_XP = TD + 1; /* Touchdown with extra point */
    int TD_2P = TD + 2; /* Touchdown with two-point conversion */

    /* Array of each score type */
    int each_score[] = {TD_2P, TD_XP, TD, FG, SFTY};
    /* Corresponding labels for the scores */
    const char *labels[] = {"TD_2P", "TD_XP", "TD", "FG", "SFTY"};

    /* Static arrays to store results */
    int result[100][10]; /* Assuming a maximum of 100 combinations and 10 scores each */
    int result_sizes[100]; /* Array to hold sizes of combinations */
    int result_count;

    /* Main loop to take user input */
    while (1) {
        printf("Enter 0 or 1 to end the program: ");
        int user_score;
        scanf("%d", &user_score);
        /* Check for termination input */
        if (user_score == 0 || user_score == 1) {
            printf("You ended the program\n");
            break;
        }

        /* Find all combinations for the user score */
        all_combos(user_score, each_score, labels, result, result_sizes, &result_count);

        /* Display all found combinations */
        printf("Every combination:\n");
        for (int i = 0; i < result_count; i++) {
            for (int j = 0; j < result_sizes[i]; j++) {
                int score_index = 0;
                /* Find the label index for the score */
                while (score_index < 5 && each_score[score_index] != result[i][j]) {
                    score_index++;
                }
                printf("%s", labels[score_index]);
                /* Print separator if not the last score */
                if (j < result_sizes[i] - 1) {
                    printf(" + ");
                }
            }
            printf("\n");
        }
    }
    return 0; /* Exit the program */
}
