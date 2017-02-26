#include <cstdlib>
#include <priority_queue>
#include <utility>
#include <vector>
#include <functional>

using namespace std;

typedef pair<int, int> coor;
typedef pair<float, coor> detection_coor;

typedef priority_queue<detection_coor, vector<detection_coor>, greater<detection_coor> location_comp;


