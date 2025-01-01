#ifndef WEBHELPER_H
#define WEBHELPER_H
class WebHelper {
public:
    static void openURL(const std::string& url) {
        #ifdef _WIN32
            system(("start " + url).c_str());
        #elif __APPLE__
            system(("open " + url).c_str());
        #elif __linux__
            system(("xdg-open " + url).c_str());
        #endif
    }
};


#endif