#include <float.h>
#include <math.h>


/**
 * @brief  Calculate the exponential integral En(x).
 *
 * @param[in]  n    The order of the integral.
 * @param[in]  x    The argument in the integrand.
 * @return     res  The result.
 *
 * @note  Press, W. H. et al. (2007). *Numerical Recipes: The Art of Scientific
 * Programming* (3rd ed). Cambridge University Press, Cambridge, UK.
 */
double expint(int n, double x) {
    const int max_iter = 100;
    const double euler = 0.57721566490153286,
        eps = DBL_EPSILON,
        fpmax = DBL_MAX * DBL_EPSILON;
    int i, j, nm1 = n - 1;
    double a, b, c, d, del, fact, h, psi;
    double res;  // the result of the integral

    if (n < 0 || x < 0. || ((fabs(x) < DBL_EPSILON) && (n == 0 || n == 1))) {
        // illegal cases
        return NAN;
    } else if (n == 0) {
        // special case
        return exp(-x) / x;
    } else if (fabs(x) < DBL_EPSILON) {
        // another special case
        return 1. / nm1;
    } else if (x > 1.) {
        b = x + n;
        c = fpmax;
        d = 1. / b;
        h = d;
        for (i = 1; i <= max_iter; i++) {
            a = -i * (nm1 + i);
            b += 2.;
            d = 1. / (a * d + b);
            c = b + a / c;
            del = c * d;
            h *= del;
            if (fabs(del - 1.) <= eps) {
                return h * exp(-x);
            }
        }
        // continued fraction failed in expint
        return NAN;
    } else {
        // evaluate series
        res = (nm1 != 0) ? 1. / nm1 : -log(x) - euler;  // first term
        fact = 1.;
        for (i = 1; i <= max_iter; i++) {
            fact *= -x / i;
            if (i != nm1) {
                del = -fact / (i - nm1);
            } else {
                psi = -euler;
                for (j = 1; j <= nm1; j++) {
                    psi += 1. / j;
                }
                del = fact * (-log(x) + psi);
            }
            res += del;
            if (fabs(del) < fabs(res) * eps) {
                return res;
            }
        }
        // series failed in expint
        return NAN;
    }
}
