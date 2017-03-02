class Solution {
public:
    string simplifyPath(string path) {
        string result = "";

        string tmp = "";
        int upCount = 0;
        for (int i = path.length() - 1; i >= 0; i--) {
            if (path[i] == '/') {
                if (tmp == "." || tmp == "") {

                } else if (tmp == "..") {
                    upCount++;
                } else {
                    if (upCount > 0) {
                        upCount--;
                    } else {
                        result = '/' + tmp + result;
                    }
                }
                tmp = "";
            } else {
                tmp = path[i] + tmp;
            }
        }

        if (result == "") {
            result = "/";
        }

        return result;
    }
};