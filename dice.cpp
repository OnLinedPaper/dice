#include <cstdlib>
#include <iostream>
#include <ctime>

int main()
{
    int die, mod, raw = 0;

    std::srand(std::time(0));

    while(1)
    {
        std::cin >> die >> mod;

        raw = std::rand() % die + 1;

        std::cout << (raw + mod) << " (" << raw << " + " << mod << ")\n";
        if(raw == die)
        {
            std::cout << "crit.\n\n";
        }
        else if(raw == 1)
        {
            std::cout << "crit failure.\n\n";
        }
        else
        {
            std::cout << "\n";
        }
    }
}
