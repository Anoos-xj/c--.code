#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

vector<string> read_file(const string &path)
{
    vector<string> lines;
    ifstream file(path);
    string line;
    while (getline(file, line))
    {
        lines.push_back(line);
    }
    return lines;
}

void compare_and_save(const string &file1, const string &file2, const string &output)
{
    auto lines1 = read_file(file1);
    auto lines2 = read_file(file2);
    ofstream out(output);

    int max_lines = max(lines1.size(), lines2.size());
    bool has_diff = false;

    for (int i = 0; i < max_lines; ++i)
    {
        string line1 = (i < lines1.size()) ? lines1[i] : "";
        string line2 = (i < lines2.size()) ? lines2[i] : "";

        if (line1 != line2)
        {
            has_diff = true;
            out << "Line " << i + 1 << ":\n<<< " << line1 << "\n>>> " << line2 << "\n\n";
        }
    }

    if (!has_diff)
    {
        out << "两个文件内容完全相同！";
    }
}

int main()
{
    compare_and_save("file1.txt", "file2.txt", "diff_output.txt");
    return 0;
}