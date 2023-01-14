#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <cctype>
#include <ctype.h>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include<string.h>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>
 
using namespace std;
 
class Job {
    public:
        int job_id_;
        int runtime_;
        int next_job_id_;
        Job(int job_id, int runtime, int next_job_id): job_id_(job_id), runtime_(runtime), next_job_id_(next_job_id)
}

void putJobInChain(unordered_map<int, vector<vector<int>>>& chains, vector<int>job) {
   bool isNewChain = true;
   for(auto& it: chains) {
       int key = it.first;
      
       vector<vector<int>> chain = it.second;
       int n = chain.size();
       vector<int> lastJob = chain[n-1];
      
       if(job[0] == lastJob[2]) {
           chains[key].push_back(job);
           return;
       }
   }
   chains[chains.size() + 1] = {job};
}

void populateRuntimeMap(map<int,int> &rMap, unordered_map<int, vector<vector<int>>> chains) {
   for(auto& it: chains) {
       int key = it.first;
       vector<vector<int>> jobs = it.second;
       int avgRuntime = calcAverageRuntime(jobs);
       rMap[avgRuntime] = key;
   }
}

int calcAverageRuntime(vector<vector<int>> jobs) {
   int runtime {};
   for(vector<int> job: jobs) {
       runtime += job[1];
   }
   return runtime / jobs.size();
}
 
void printJobsInput (vector<vector<int>> jobs) {
   for(auto job: jobs) {
       for(int val: job) {
           cout << val << " ";
       }
       cout << endl;
   }  
}
 
bool is_digit(const string &s) {
   return !s.empty() && std::all_of(s.begin(), s.end(), ::isdigit);
}

void printChainMap(unordered_map<int, vector<vector<int>>> chains) {
   for(auto& it: chains) {
       vector<vector<int>> jobs = it.second;
       cout << it.first << ": ";
       for(auto& job: jobs) {
           cout << "[" << job[0] << "," << job[1] << "," << job[2] << "]" << " ";
       }
       cout << "\n";
   }
}

void printRuntimeMap(map<int,int> rMap) {
   for(auto& it: rMap) {
       cout << it.first << ":" << it.second << endl;
   }
}
 
void printChain(vector<vector<int>> chain) {
   int n = chain.size() - 1;
   cout << "start_job: " << chain[0][0] << endl;
   cout << "last_job: " << chain[n][2] << endl;
   cout << "job_chain_runtime: " << calcAverageRuntime(chain)*n << endl;
   cout << "average_job_time:" << calcAverageRuntime(chain) << endl;  
}
 
int main() {
   vector<vector<int>> jobs {};
   bool isMalformed = false;
  
   string header {};
   getline(cin, header);
  
   string line;
   while(getline(cin, line)) {
       stringstream ss(line);
       vector<int> job {};
      
       while(ss.good()) {
           string val;
           getline(ss, val, ',');
          
           if(!is_digit(val)) {
               isMalformed = true;
               break;
           }
           job.push_back(stoi(val));
       }
       jobs.push_back(job);
   }
  
   if(isMalformed || jobs.size() == 0) {
       cout << "Malformed Input";
   }
  
   unordered_map<int, vector<vector<int>>> chains;
   for(int i = 0; i < jobs.size(); ++i) {
       vector<int> job = jobs[i];
       putJobInChain(chains, job);
   }
  
   map<int,int> chainRuntimeMap {};
   populateRuntimeMap(chainRuntimeMap, chains);
  
   map<int,int>::reverse_iterator it;
   for(auto it = chainRuntimeMap.rbegin(); it != chainRuntimeMap.rend(); it++) {
       vector<vector<int>> chain = chains[it->second];
       cout << "-" << endl;
       printChain(chain);
       cout << "-" << endl;
   }

  printChainMap(chains);
  printRuntimeMap(chainRuntimeMap);
  return 0;
}
