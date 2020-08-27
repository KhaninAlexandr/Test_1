#include <stdio.h>
#include <math.h>

  int Quadratic_equation (double a, double b, double c, double* x1, double* x2)
    {
    if (a == 0)
      {
      if (b == 0)
        {
        return (c == 0)? -1 : 0;
        }
      else /* b != 0 */
        {
        if (c != 0)
          {
        *x1 = -c / b;
        return 1;
          }
          if (c == 0)
          {
        *x1 = 0;
        return 1;
          }
        }
      }
    else /* a != 0 */
      {
      double D = b * b - 4 * a * c;

      if (D == 0)
        {
        *x1 = -b / (2 * a);
        return 1;
        }
      if (D > 0)
        {
        *x1 = (-b + sqrt(D)) / (2 * a);
        *x2 = (-b - sqrt(D)) / (2 * a);
        return 2;
        }
      if (D < 0)
        {
        return 0;
        }
      }
    }


  int main ()
    {
    printf ("The solution to the quadratic equation\n\n");
    printf ("Enter coefficients a, b, c:\n");

    double a = 0, b = 0, c = 0;
    scanf ("%lf %lf %lf", &a, &b, &c);

    double x1 = 0, x2 = 0; /* корни уравнения */

    int solution = Quadratic_equation(a, b, c, &x1, &x2);

    switch (solution)
      {
      case 2: printf ("Two roots: x1 = %lf, x2 = %lf\n", x1, x2);
              break;

      case 1: printf ("One root: x1 = %lf\n", x1);
              break;

      case 0: printf ("No roots\n");
              break;

      case -1: printf ("Infinite number of roots");
              break;
      }
    }