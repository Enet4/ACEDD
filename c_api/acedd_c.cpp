#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include "acedd.h"
#include "acedd_c.h"
#include <cstdlib>
using namespace ACEDD_DESC;


extern "C" int acedd_extract(const char* filename, unsigned char* desc) {
    return acedd_extract_with_grid_size(filename, desc, 40);
}

extern "C" int acedd_extract_with_grid_size(const char* filename, unsigned char* desc, int grid_size) {
    try {
        CEDD cedd(grid_size);
        cv::Mat img_a, desc_a;

        img_a = cv::imread(filename);
        cedd.Apply(img_a, desc_a);

        if (desc_a.isContinuous()) {
            std::memcpy(desc, desc_a.ptr(), 128);
        } else {
            for (auto i = 0u; i < 128; i++) {
                desc[i] = desc_a.at<unsigned char>(i);
            }
        }

        return 0;
    } catch (...) {
        return -1;
    }
}