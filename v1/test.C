#include "LinearSuffixSort.h"
#include <cstring>

int main(int argc, char* argv[])
{
  char* myString;
  int* suffixArray;
  int stringLength;
  int i;
  ifstream inFile;
  inFile.open(argv[1]);
  Timing timehere;

  if (strcmp(argv[1], "test.dat") != 0) 
  {
    timehere.markbeg();
    if (strstr(argv[1], ".fas")[0] == '.')
    {
      read_fasta(inFile, myString, stringLength);
    }
    else
    {
      read_input(inFile, myString, stringLength);
    }
    timehere.markend();
    inFile.close();
    cout << "finish read "
	 << stringLength << " characters."<< endl;
    timehere.outtime();
  }
  else
  {
    read_input(inFile, myString, stringLength);
    inFile.close();
    cout << "finish read " 
	 << stringLength << " characters."<< endl;
  }

  timehere.markbeg();
  suffixArray = LinearSuffixSort(myString, stringLength);
  timehere.markend();
  timehere.outtime("finish suffix sort,");

  if (strcmp(argv[1], "test.dat") == 0) 
  {
    int result;
    bool pass = true;
    ifstream resultF;
    resultF.open("result.test.dat");

    cout << "Testing the Suffix Array" << endl;

    for (i = 0; i < stringLength; i++)
    {
      resultF >> result;
      if (result != suffixArray[i])
      {
	pass = false;
      }
    }
    if (pass == false)
    {
      cout << endl;
      cout << "***************" << endl;
      cout << "test has failed" << endl;
      cout << "***************" << endl;
    }
    else
    {
      cout << endl;
      cout << "******************" << endl;
      cout << "test is successful" << endl;
      cout << "******************" << endl;
    }
  }
 
  //  outsuffix(suffixArray, stringLength, myString, stringLength - 1, 10); 
 
  free(suffixArray);
  free(myString);

  return(0);
}
