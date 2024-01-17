#include <stdio.h>
#include <string.h>

int computeHashCode(char* s, int m) {
    int k = strlen(s);
    int hashCode = 0;
    int power = 1;

    for (int i = k - 1; i >= 0; i--) {
        hashCode = (hashCode + s[i] * power) % m;
        power = (power * 256) % m;
    }

    return hashCode;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    for (int i = 0; i < n; i++) {
        char s[201];
        scanf("%s", s);

        int hashCode = computeHashCode(s, m);
        printf("%d\n", hashCode);
    }

    return 0;
}
