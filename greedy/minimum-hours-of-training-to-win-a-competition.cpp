class Solution {
public:
    int minNumberOfHours(int initialEnergy, int initialExperience, vector<int>& energy, vector<int>& experience) {
        int res = 0;
        int n = energy.size();
        for(int i = 0; i < n; i++) {
            if(energy[i] >= initialEnergy) {
                int diff = energy[i] - initialEnergy + 1;
                res += diff; initialEnergy += diff;
            }
            if(experience[i] >= initialExperience) {
                int diff = experience[i] - initialExperience + 1;
                res += diff; initialExperience += diff;
            }
            initialEnergy -= energy[i];
            initialExperience += experience[i];
        }
        return res;
    }
};
