#include <cstdlib>
#include <iostream>
#include <ctime>
#include <vector>

void roll_single(int die_sides, int modifier);
int roll_many(int die_count, int die_sides, int modifier);

int main()
{
    int die_count, die_sides, modifier, raw;

    //seed rand
    std::srand(std::time(0));

    //inform user of functionality
    std::cout << "usage:\n> die_count die_sides modifier\n\n";

    long long unsigned int a[12];

    for(int i=0; i<12; i++)
    {
        a[i] = 0;
    }
        //reset variables
        die_count = die_sides = modifier = raw = 0;

        //prompt user, and then get input
        std::cout << "> ";
        std::cin >> die_count >> die_sides >> modifier;

    for(int i=0; i<1000000000; i++)
    {

        if(die_count == 1)
        {
            roll_single(die_sides, modifier);
        }
        else
        {
            a[roll_many(die_count, die_sides, modifier) - 1]++;
        }

    }

    for(int i=0; i<12; i++)
    {
        std::cout << i+1 << "\t" << a[i] << "\n";
    }
}

void roll_single(int die_sides, int modifier)
{
    //roll one die and display info about crits

    int raw = 0;

    //calculate roll
    raw = std::rand() % die_sides + 1;

    std::cout << (raw + modifier) << \
    " (" << raw << " + " << modifier << ")\n";

    if(raw == die_sides)
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

    return;
}

int roll_many(int die_count, int die_sides, int modifier)
{
    //roll many dice

    int raw = 0;
    std::vector<int> v;

    for(int i=0; i<die_count; i++)
    {
        //add some rolls to a vector
        v.push_back(std::rand() % die_sides + 1);
    }

    //std::cout << "( ";

    for(int i : v)
    {
        //iterate through vector
        raw += i;
        //std::cout << i << " ";
    }

    //std::cout << ")\n" << raw + modifier \
    << " (" << raw << " + " << modifier << ")\n\n";
    return(raw);
}
