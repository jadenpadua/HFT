using namespace std;

bool isValidSubsequence(vector<int> array, vector<int> sequence) {
  int p1 {};
  for(int i = 0; i < array.size(); ++i) {
    if(p1 == sequence.size()) return true;
    if(array[i] == sequence[p1]) ++p1;
  }
  return p1 == sequence.size();
}
