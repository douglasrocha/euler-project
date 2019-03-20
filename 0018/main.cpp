#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

typedef unsigned int uint;
typedef vector<vector<uint>> Matrix;
typedef vector<uint> Row;

const Matrix triangle = {
  {75},
  {95,64},
  {17,47,82},
  {18,35,87,10},
  {20,04,82,47,65},
  {19,01,23,75,03,34},
  {88,02,77,73,07,63,67},
  {99,65,04,28,06,16,70,92},
  {41,41,26,56,83,40,80,70,33},
  {41,48,72,33,47,32,37,16,94,29},
  {53,71,44,65,25,43,91,52,97,51,14},
  {70,11,33,28,77,73,17,78,39,68,17,57},
  {91,71,52,38,17,14,91,43,58,50,27,29,48},
  {63,66,04,68,89,53,67,30,73,16,69,87,40,31},
  {04,62,98,27,23, 9,70,98,73,93,38,53,60,04,23}
};

int main (void) {
  uint cols = triangle[triangle.size() - 1].size();
  uint last_row = triangle.size() - 1;
  vector<uint> result (cols, 0);
  
  for (uint j = 0; j < cols; j++) {
    result[j] += triangle[last_row][j];
    uint curr_col = j;
    
    cout << endl << endl << endl << result[j] << endl;
    
    for (uint i = last_row - 1; i >= 0; i--) {
      if (i == 0) {
        result[j] += triangle[0][0];
        cout << triangle[0][0] << "---" << result[j] << endl;
        break;
      }
      
      if (curr_col == 0) {
        result[j] += triangle[i][curr_col];
        cout << triangle[i][curr_col] << "---" << result[j] << endl;
        continue;
      }
      
      if (curr_col == triangle[i].size()) {
        result[j] += triangle[i][--curr_col];
        cout << triangle[i][curr_col] << "---" << result[j] << endl;
        continue;
      }

      cout << max(triangle[i][curr_col - 1], triangle[i][curr_col])
           << " ---  "
           << result[j] + max(triangle[i][curr_col - 1], triangle[i][curr_col])
           << endl;

      result[j] += max(triangle[i][curr_col - 1], triangle[i][curr_col]);
      curr_col = triangle[i][curr_col - 1] > triangle[i][curr_col]
        ? curr_col - 1
        : curr_col;
    }
  }

  for (auto& t : result) {
    cout << t << " ";
  }
  cout << endl << endl;
  
  cout << "Result: " << *max_element(result.begin(), result.end()) << endl;
  
  
  return 0;
}
