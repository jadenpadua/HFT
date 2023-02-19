using namespace std;

int minimumWaitingTime(vector<int> queries) {
  sort(queries.begin(), queries.end());
  int runningSum = 0, minTime = 0;
  for(int q: queries) {
    minTime += runningSum;
    runningSum += q;
  }
  return minTime;
}
