/*
  We solved this problem using C# decimal because
  when using C++ with ULL, I realized an overflow
  was detected.

  To solve this problem I used a dynamic programming
  approach. First created a memoization grid with 
  right and bottom cells with a value of 1 and other
  cells with value of zero, then traversed the matrix
  from bottom-right to top-left with the number of steps
  from previous right/bottom value sums. This gives us
  a bottom-up approach with memoization (dynamic programming)
  though I know there is a combinatorics approach using
  binomial coefficient from what I researched on math sites.

  Combinatorics picture:
  https://www.mathblog.dk/wp-content/plugins/optimized-latex/image.php?image=tex_98be2247dba040dc318b2a4f9791b394.png

  Combinatorics solution:

    int gridSize = 20;
    long paths = 1;
 
    for (int i = 0; i < gridSize; i++) {
      paths *= (2 * gridSize) - i;
      paths /= i + 1;
    }
*/

using System;

namespace euler15
{
    class Program
    {
        static readonly int size = 20;
        
        static decimal[,] BuildEmpty()
        {
            var matrix = new decimal[size + 1, size + 1];
            for (int i = 0; i < size; i++)
                matrix[size, i] = matrix[i, size] = 1;
            return matrix;
        }
        
        static void Main(string[] args)
        {
            var matrix = BuildEmpty();
            for (var i = size - 1; i >= 0; i--)
                for (var j = size - 1; j >= 0; j--)
                    matrix[i, j] = matrix[i+1, j] + matrix[i, j+1];

            Console.WriteLine(matrix[0, 0]);
        }
    }
}
