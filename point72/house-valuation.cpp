* The function is expected to return a LONG_INTEGER.
 * The function accepts following parameters:
 *  1. LONG_INTEGER reqArea
 *  2. LONG_INTEGER_ARRAY area
 *  3. LONG_INTEGER_ARRAY price
 */
 
 void printAreaToPriceMap(unordered_map<long,long> umap)  {
     for (auto it: umap) cout << it.first << ": " << it.second << endl; 
 }
 
 pair<int,int> findClosestPrices(vector<long> arr, long k, unordered_map<long, long> umap) {
     sort(arr.begin(), arr.end());
     int left = 0;
     int right = arr.size() - 1;
     while(left <= right) {
         int mid = left + (right - left) / 2;
         if(arr[mid] == k) {
             int p1 = arr[mid-1], p2 = arr[mid+1];
             return pair<int,int>(p1,p2);
         }
         else if(arr[mid] < k) {
             left = mid + 1;
         }
         else {
             right = mid - 1;
         }
     }
     return pair<int,int>(arr[left], arr[right]);
 }
 
 long interExtraPolate(long x0, long y0, long x1, long y1, long x) {
     return y0 + (x - x0) * (y1 - y0) / (x1 - x0);
 }
 
long valuation(long reqArea, vector<long> area, vector<long> price) {
    if(area.size() == 0) return 1000;
    else if(area.size() == 1) return price[0];
    
    int n = area.size();
    
    unordered_map<long,long> areaToPriceMap {};
    for(int i = 0; i < area.size(); ++i) {
        areaToPriceMap[area[i]] = price[i];
    }
    
    // assume already within range
    pair<int,int> closest = findClosestPrices(area, reqArea, areaToPriceMap);
    long x0 = closest.first, x1 = closest.second;
    long y0 = areaToPriceMap[closest.first], y1 = areaToPriceMap[closest.second];
    
    long valuation = interExtraPolate(x0, y0, x1, y1, reqArea);
        cout << closest.first << ": " << closest.second << endl;
    return valuation;    
    

    return n;
}

int main()
