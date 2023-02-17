#include <vector>
using namespace std;

string tournamentWinner(vector<vector<string>> competitions,
                        vector<int> results) {
  int maxScore {};
  string winner {};
  unordered_map<string, int> umap {};
  for(int i = 0; i < results.size(); ++i) {
    // away team wins
    if(results[i] == 0) {
      vector<string> comp = competitions[i];
      string awayTeam = comp[1];
      umap[awayTeam] += 3;
      
      if(umap[awayTeam] > maxScore) {
        maxScore = umap[awayTeam];
        winner = awayTeam;
      }
    }
    // home team wins
    else {
      vector<string> comp = competitions[i];
      string homeTeam = comp[0];
      umap[homeTeam] += 3;
      
      if(umap[homeTeam] > maxScore) {
        maxScore = umap[homeTeam];
        winner = homeTeam;
      }
    }
  }
  return winner;
}
