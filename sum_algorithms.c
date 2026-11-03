#include <stdlib.h>
#include <math.h>
#include "sum_algorithms.h"

double do_sum(double* restrict var, long ncells)
{
   double sum = 0.0;
   for (long i = 0; i < ncells; i++){
      sum += var[i];
   }
   return sum;
}

double do_kahan_sum(double* restrict var, long ncells)
{
   double sum = 0.0;
   double correction = 0.0;

   for (long i = 0; i < ncells; i++) {
      double y = var[i] - correction;
      double t = sum + y;
      correction = (t - sum) - y;
      sum = t;
   }

   return sum;
}

double do_knuth_sum(double* restrict var, long ncells)
{
   double sum = 0.0;
   double correction = 0.0;

   for (long i = 0; i < ncells; i++) {
      double u = sum;
      double v = var[i] + correction;
      double t = u + v;
      double up = t - v;
      double vp = t - up;

      correction = (u - up) + (v - vp);
      sum = t;
   }

   return sum + correction;
}

long double do_ldsum(double* restrict var, long ncells)
{
   long double ldsum = 0.0;

   for (long i = 0; i < ncells; i++) {
      ldsum += var[i];
   }

   return ldsum;
}

double do_pairwise_sum(double* restrict var, long ncells)
{
   if (ncells == 0)
      return 0.0;

   if (ncells == 1)
      return var[0];

   long mid = ncells / 2;

   return do_pairwise_sum(var, mid) +
          do_pairwise_sum(var + mid, ncells - mid);
}