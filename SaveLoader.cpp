#include "SaveLoader.h"


void SaveLoader::save(std::string filename, Sheet& mysheet) {
    std::ofstream output(filename, std::ios::out);

    for (int page_idx = 0; page_idx < 30; page_idx++) {
        for (int cursor_idx = 0; cursor_idx < 48; cursor_idx++) {
            Note mynote = mysheet.getNote(cursor_idx, page_idx);
            output << mynote.freq << ':' << mynote.length << std::endl;
        }
    }
}

void SaveLoader::load(std::string filename, Sheet& mysheet) {
    std::ifstream input(filename, std::ios::in);


}