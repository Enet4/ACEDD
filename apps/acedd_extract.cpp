#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>
#include "acedd.h"

using namespace ACEDD_DESC;

int main(int argc, const char * argv[]) {
    CEDD cedd;
    cv::Mat img_a, desc_a;
    if (argc < 2)
      std::cout << "Usage: ACEDD_EXTRACT img [img...]\n";

    for (auto i = 1u; i < argc; i++) {
      std::cerr << "Image: " << argv[i] << "\n";
      img_a = cv::imread(argv[i]);
      cedd.Apply(img_a, desc_a);
      for (auto it = desc_a.begin<unsigned char>(); it != desc_a.end<unsigned char>(); ++it) {
        std::cout << static_cast<unsigned int>(*it) << " ";
      }
      std::cout << std::endl;
    }
    return 0;
}
