
/// @author    hasegawa
/// @copyright (C) 2023 Design Engineering Laboratory,
/// Saitama University All right reserved.

#include "latex_output.h"

#include <fstream>
#include <string>
#include <vector>

#include <filesystem>


namespace designlab
{

void LatexOutput::Output()
{
    const std::string filepath = "C:/Users/hasegawa/Desktop/main/program/DesignLab/DesignLab";

    // 拡張子
    const std::string extension_h = ".h";
    const std::string extension_cpp = ".cpp";

    // filepath 下のファイルの中で，拡張子が .h または .cpp のファイルを取得．
    std::vector<std::string> files;

    for (const auto& file : std::filesystem::directory_iterator(filepath))
    {
        if (file.path().extension() == extension_h ||
            file.path().extension() == extension_cpp)
        {
            files.push_back(file.path().filename().string());
        }
    }

    // 出力する．
    const std::string command = "\\lstinputlisting";

    const  std::string source_path = "source/";
    const std::string filename = "result.tex";
    const std::string test = "test";

    std::ofstream ofs(filename);

    for (const auto& file : files)
    {
        // testを名前に含むファイルは除外．
        if (file.find(test) != std::string::npos)
        {
            continue;
        }

        // このファイル自体も除外．
        if (file.find("latex_output") != std::string::npos)
        {
            continue;
        }

        ofs << command << "[caption=";

        // file の中身の '_' の前に '\\' を挿入する．
        std::string caption = file;
        for (int i = 0; i < caption.size(); ++i)
        {
            if (caption[i] == '_')
            {
                caption.insert(i, "\\");
                ++i;
            }
        }

        ofs << caption << ", label=" << file << "]{" << source_path + file << "}" << std::endl;
    }

    ofs.close();
}

}  // namespace designlab
