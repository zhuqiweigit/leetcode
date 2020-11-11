#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>
#include <list>
#include <unordered_map>
using namespace std;
class Solution {
public:
    int mybuf_size = 0, mybuf_ptr = 0;
    char mybuf[4];
    bool init = true;
    /**
     * @param buf Destination buffer
     * @param n   Number of characters to read
     * @return    The number of actual characters read
     */
    int read(char *buf, int n) {
        if(init){
            mybuf_ptr = read4(mybuf);
            init = false;
        }
        int idx = 0;
        while(idx < n){
            while(idx < n && mybuf_ptr < mybuf_size){
                buf[idx++] = mybuf[mybuf_ptr++];
            }
            if(mybuf_ptr == mybuf_size){
                mybuf_size = read4(mybuf);
                mybuf_ptr = 0;
                if(mybuf_size == 0){
                    return idx;
                }
            }
        }
        return n;
    }
};