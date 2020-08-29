#include <stdio.h>
#include <math.h>

  int Quadratic_equation (double a, double b, double c, double* x1, double* x2);


  int Linear_equation (double a, double b, double* x1);


  enum Answer_choice
      {
      Two_Roots  = 2,
      One_Root   = 1,
      No_Roots   = 0,
      Inf_nRoots = -1
      };


  int main ()
    {
    printf ("The solution to the quadratic equation\n\n");
    printf ("Enter coefficients a, b, c:\n");

    double a = NaN, b = NaN, c = NaN;
    scanf ("%lf %lf %lf", &a, &b, &c);

    double x1 = NaN, x2 = NaN; /* корни уравнения */

    int solution = Quadratic_equation(a, b, c, &x1, &x2);

    switch (solution)
      {
      case Two_Roots: printf ("Two roots: x1 = %lf, x2 = %lf\n", x1, x2);
              break;

      case One_Root: printf ("One root: x1 = %lf\n", x1);
              break;

      case No_Roots: printf ("No roots\n");
              break;

      case Inf_nRoots: printf ("Infinite number of roots");
              break;

      default: printf ("ERROR!!!");
               return 1;
      }
    }


    int Quadratic_equation (double a, double b, double c, double* x1, double* x2)
      {
      if (a == 0)
        {
        return Linear_equation (b, c, x1);
        }
      else /* a != 0 */
        {
        double D = b * b - 4 * a * c;

        if (D == 0)
          {
          *x1 = -b / (2 * a);
          return One_Root;
          }
        if (D > 0)
          {
          double D_sqrt = sqrt(D);
          *x1 = (-b + D_sqrt) / (2 * a);
          *x2 = (-b - D_sqrt) / (2 * a);
          return Two_Roots;
          }
        if (D < 0)
          {
          return No_Roots;
          }
        }
      }


    int Linear_equation (double a, double b, double* x1) /*решает линейное уравнение и возвращает количество корней */
      {
      if (a == 0)
        {
        return (b == 0)? Inf_nRoots : No_Roots;
        }
      else /* a != 0 */
        {
        if (b != 0)
          {
          *x1 = -b / a;
          return One_Root;
          }
        if (b == 0)
          {
          *x1 = 0;
          return One_Root;
          }
        }
      }

