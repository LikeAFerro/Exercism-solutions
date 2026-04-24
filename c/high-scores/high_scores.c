#include "high_scores.h"
#include <stdio.h>

int32_t latest(const int32_t *scores, size_t scores_len) {
    if (!scores || scores_len == 0)
        return -1;
    return scores[scores_len - 1];
}

int32_t personal_best(const int32_t *scores, size_t scores_len) {
    if (!scores || scores_len == 0)
        return -1;
    int32_t best = scores[0];
    for (size_t i = 0; i < scores_len; i++)
        if (scores[i] > best)
            best = scores[i];
    return best;
}

size_t personal_top_three(const int32_t *scores, size_t scores_len, int32_t *output) {
    size_t count = 0;
    for (size_t i = 0; i < 3; i++)
        output[i] = 0;
    for (size_t i = 0; i < scores_len; i++) {
        if (count < 3)
            count++;
        for (size_t j = 0; j < count; j++) {
            if (scores[i] > output[j]) {
                for (size_t k = count - 1; k > j; k--)
                    output[k] = output[k - 1];
                output[j] = scores[i];
                break;
            }
        }
    }
    return count;
}