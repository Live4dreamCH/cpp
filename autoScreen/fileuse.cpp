#include <fstream>
#include <iostream>
int main()
{
    std::fstream myfile;
    myfile.open("numbers.txt", std::ios::in | std::ios::out);
    if (!myfile)
    {
        std::cout << "fail to open the file!" << std::endl;
        return 0;
    }
    // myfile << -1 << ',';
    int i;
    myfile.seekg(0);
    myfile >> i;//123456789 //-1
    std::cout << i << std::endl;
    myfile >> i;//123456789 //-1
    std::cout << i << std::endl;
    std::string str;
    myfile.seekg(0);
    myfile >> str;//"123456789," //"-1,456789,"
    std::cout << str << std::endl;
    return 0;
}
