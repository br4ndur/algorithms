#include <stdio.h>
#include <stdlib.h>

void longest_increasing_subsequence(int*, int);

int main(int argc, char * argv[])
{
        int seq[] = {9, 44, 32, 12, 7, 42, 34, 92, 35, 37, 41, 8, 20, 27, 83,
                     64, 61, 28, 39, 93, 29, 17, 13, 14, 55, 21, 66, 72, 23, 73,
                     99, 1, 2, 88, 77, 3, 65, 83, 84, 62, 5, 11, 74, 68, 76, 78,
                     67, 75, 69, 70, 22 };

        int n = sizeof(seq)/sizeof(seq[0]);
        longest_increasing_subsequence(seq, n);

        return 0;
}

/* Thanks to:
 * http://www.algorithmist.com/index.php/Longest_Increasing_Subsequence.cpp
 */
void longest_increasing_subsequence(int *seq, int size_seq)
{
        int size_b;
        int *p, *b, i, u, v;
        int c;
        p = (int*) malloc ( sizeof( int ) * size_seq );
        b = (int*) malloc ( sizeof( int ) * size_seq );
        size_b = 0;

        if (size_seq == 0)
                return;

        b[size_b++] = 0;


        //O(n log k) algorithm.
        for (i = 0; i < size_seq; i++) {

                if (seq[b[size_b-1]] < seq[i]) {
                        p[i] = b[size_b-1];
                        b[size_b++] = i;
                        continue;
                }

                for (u = 0, v = size_b-1; u < v;) {
                        c = (u + v) / 2;
                        if (seq[b[c]] < seq[i])
                                u=c+1;
                        else
                                v=c;
                }

                if (seq[i] < seq[b[u]]) {
                        if (u > 0) {
                                p[i] = b[u-1];
                        }

                        b[u] = i;
                }
        }

        for (u = size_b, v = b[size_b-1]; u--; v = p[v])
                b[u] = v;

        for (i = 0; i < size_b; i++)
                printf("%d ", seq[b[i]]);
        printf("\n");

        free(p);
        free(b);
}
