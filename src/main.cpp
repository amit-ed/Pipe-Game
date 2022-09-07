#include "Controller.h"
int main()
{
    try
    {
        Controller y;
        y.run();
    }
    catch (std::exception& e) 
    {
        ofstream outfile;
        outfile.open("log.txt");
        outfile << e.what();
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}
