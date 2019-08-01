#include <iostream>
#include <experimental/filesystem>
#include "image.hpp"
#include "medianblurring.hpp"
#include "averaging.hpp"
#include "gaussianblurring.hpp"
#include "bilateralfiltering.hpp"


namespace fs = std::experimental::filesystem;

static std::vector<std::string> filesExtension { ".jpeg",
                                                 ".png"
                                                };

bool checkingExtension(const std::string& fileName) {
    std::string::size_type pos{};
    for(auto&& ext : filesExtension) {
        pos = fileName.rfind(ext);
        if(pos != std::string::npos)
            return ((pos + ext.size()) == fileName.size());
    }
    return false;
}

int main(int argc, char* argv[]) {

    try {  
        if(argc != 3) {
            std::cerr << "Usage: " << argv[0] << " <in_file> <out_file>\n";
            return 0;
        }

        if(!fs::exists(argv[1]))
            throw std::runtime_error("File " + std::string(argv[1]) + " not exist\n");

        if(!checkingExtension(argv[1])) {
            std::cerr << "Invalid input file extension\n";
            return 0;
        }

        if(!checkingExtension(argv[2])) {
            std::cerr << "Invalid output file extension\n";
            return 0;
        }

        Image image(argv[1]);
        image.smoothing(std::make_unique<MedianBlurring>());
        //image.smoothing(std::make_unique<Averaging>());
        //image.smoothing(std::make_unique<GaussianBlurring>());
        //image.smoothing(std::make_unique<BilateralFiltering>());
        image.outlineSelection();
        image.save(argv[2]);

    } catch (const std::exception& ex) {
        std::cerr << ex.what() << '\n';
    } catch( ... ) {
        std::cerr << "Unknown exception!!!\n";
    }

    return 0;
}
