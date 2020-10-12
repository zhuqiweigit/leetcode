#include <iostream>
#include <vector>
#include <stack>
#include <sstream>
#include <cstdlib>
using namespace std;
/**
 * The read4 API is defined in the parent class Reader4.
 *     int read4(char *buf4);
 */
int read4(char *buf4);
class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Number of characters to read
     * @return    The number of actual characters read
     */
    int read(char *buf, int n) {
        int cnt = 0, len = 0;
        while(cnt < n && (len = read4(buf + cnt)) != 0){
            cnt += len;
        }
        if(cnt > n) {
            buf[n] = '\0';
            return n;
        }
        return cnt;
    }
};