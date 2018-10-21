#include <stdio.h>

#include "expint.h"


int main(void) {
    printf("test expint(n, x):\n"
           "* illegal cases (should all be NaN)\n");
    printf("  + expint(-1, 1.0) = %g\n", expint(-1, 1.));
    printf("  + expint(1, -1.0) = %g\n", expint(1, -1.));
    printf("  + expint(0, 0.0) = %g\n", expint(0, 0.));
    printf("  + expint(1, 0.0) = %g\n", expint(1, 0.));
    printf("  + expint(0, -1.0) = %g\n", expint(0, -1.));

    printf("* special cases:\n");
    printf("  + expint(0, 1.0) = %g (should be 1/e)\n", expint(0, 1.));
    printf("  + expint(2, 0.0) = %g (should be 1/(n-1))\n", expint(2, 0.));
    printf("  + expint(3, 0.0) = %g (should be 1/(n-1))\n", expint(3, 0.));

    printf("* general cases:\n");
    printf("  + expint(1, 1.0) = %.17g (should be 0.21938393439552027)\n",
           expint(1, 1.));
    printf("  + expint(1, 2.0) = %.17g (should be 0.04890051070806112)\n",
           expint(1, 2.));
    printf("  + expint(1, 0.5) = %.17g (should be 0.55977359477616084)\n",
           expint(1, 0.5));

    printf("  + expint(10, 1.0) = %.17g (should be 0.0363939940314164)\n",
           expint(10, 1.));
    printf("  + expint(10, 2.0) = %.17g (should be 0.0120920851364003)\n",
           expint(10, 2.));

    return 0;
}
