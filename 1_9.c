#include <stdio.h>
#include <math.h>

  int Quadratic_equation (double a, double b, double c, double* x1, double* x2);


  int Linear_equation (double a, double b, double* x1);


  enum Answer_choice
      {
      Two_Roots   = 2,
      One_Root    = 1,
      No_Roots    = 0,
      Inf_nRoots  = -1
      };


  const double accuracy = 1e-12;


  void Test_Quadratic_equation();


  int test_square (int exp_number, double a, double b, double c, double exp_x1, double exp_x2);


  int main ()
    {
    Test_Quadratic_equation();
    printf ("The solution to the quadratic equation\n\n");
    printf ("Enter coefficients a, b, c:\n");

    double a = NAN, b = NAN, c = NAN;
    scanf ("%lf %lf %lf", &a, &b, &c);

    double x1 = NAN, x2 = NAN; /* Roots of the equation */

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
      if (fabs(a) <= accuracy)
        {
        return Linear_equation (b, c, x1);
        }
      else /*fabs(a) > accuracy*/
        {
        double D = b * b - 4 * a * c;

        if (fabs(D) <= accuracy)
          {
          *x1 = -b / (2 * a);
          return One_Root;
          }
        if (D > 0 + accuracy)
          {
          double D_sqrt = sqrt(D);
          *x1 = (-b + D_sqrt) / (2 * a);
          *x2 = (-b - D_sqrt) / (2 * a);
          return Two_Roots;
          }
        if (D < 0 - accuracy)
          {
          return No_Roots;
          }
        }
      }


    int Linear_equation (double a, double b, double* x1) /*Solves a linear equation and returns the number of roots*/
      {
      if (fabs(a) <= accuracy)
        {
        return (fabs(b) <= accuracy)? Inf_nRoots : No_Roots;
        }
      else /* fabs(a) > accuracy */
        {
        if (fabs(b) > accuracy)
          {
          *x1 = -b / a;
          return One_Root;
          }
        if (fabs(b) <= accuracy)
          {
          *x1 = 0;
          return One_Root;
          }
        }
      }

     void Test_Quadratic_equation()
       {
       int exp1 = 1, exp2 = 2, exp3 = 3;
       double* x1;
       double* x2;

       #define TEST                                                                                                                               \
       if (res == exp1)                                                                                                                           \
         {                                                                                                                                        \
         printf ("#Test OK\n");                                                                                                                   \
         }                                                                                                                                        \
       if (res == exp2)                                                                                                                           \
         {                                                                                                                                        \
         printf ("Test on line %d BAD: expected value x1 = %g, test value x1 = %g \n", __LINE__, exp_x1, *x1);                                    \
         }                                                                                                                                        \
       if (res == exp3)                                                                                                                           \
         {                                                                                                                                        \
         printf ("Test on line %d BAD: expected value x1 = %g, x2 = %g, test value x1 = %g, x2 = %g \n", __LINE__, exp_x1, exp_x2, *x1, *x2);     \
         }

       int exp_number = Inf_nRoots;
       double a = 0, b = 0, c = 0;
       double exp_x1, exp_x2;
       int res = test_square (exp_number, a, b, c, exp_x1, exp_x2);
       TEST

       exp_number = No_Roots;
       a = 5, b = 5, c = 2;
       res = test_square (exp_number, a, b, c, exp_x1, exp_x2);
       TEST

       exp_number = One_Root;
       a = 1, b = 2, c = 1;
       exp_x1 = -1;
       res = test_square (exp_number, a, b, c, exp_x1, exp_x2);
       TEST

       exp_number = No_Roots;
       a = 1, b = 5, c = 6;
       exp_x1 = 0, exp_x2 = 0;
       res = test_square (exp_number, a, b, c, exp_x1, exp_x2);
       TEST
       }

     int test_square (int exp_number, double a, double b, double c, double exp_x1, double exp_x2)
       {
       double* x1;
       double* x2;
       if ((exp_number = Inf_nRoots) == Quadratic_equation(a, b, c, x1, x2))
         {
         return 1;
         }

       if ((exp_number = No_Roots) == Quadratic_equation(a, b, c, x1, x2))
         {
         return 1;
         }

       if ((exp_number = One_Root) == Quadratic_equation(a, b, c, x1, x2))
         {
         if ((exp_x1 + accuracy >= *x1) && (exp_x1 - accuracy <= *x1))
           {
           return 1;
           }
         else
           {
           return 2;
           }
         }

       if ((exp_number = Two_Roots) == Quadratic_equation(a, b, c, x1, x2))
         {
         if (((exp_x1 + accuracy >= *x1) && (exp_x1 - accuracy <= *x1)) && ((exp_x2 + accuracy >= *x2) && (exp_x2 - accuracy <= *x2)))
           {
           return 1;
           }
         else
           {
           return 3;
           }
         }
       }
