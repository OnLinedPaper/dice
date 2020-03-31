#include <cstdlib>
#include <iostream>
#include <ctime>
#include <vector>
#include <random>

void roll_single(int die_sides, int modifier);
void roll_many(int die_count, int die_sides, int modifier);

int main()
{
  int die_count, die_sides, modifier, raw;

  //seed rand

  //inform user of functionality
  std::cout << "usage:\n> die_count die_sides modifier\n\n";

  while(1)
  {
    //reset variables
    die_count = die_sides = modifier = raw = 0;


    //prompt user, and then get input
    std::cout << "> ";
    std::cin.clear();
    std::cin >> die_count >> die_sides >> modifier;


    if(die_count == 1)
    {
      roll_single(die_sides, modifier);
    }
    else
    {
      roll_many(die_count, die_sides, modifier);
    }

  }
}

void roll_single(int die_sides, int modifier)
{
  //roll one die and display info about crits

  static std::minstd_rand eng{std::random_device{}()};
  int raw = 0;

  //calculate roll
  raw = eng() % die_sides + 1;

  std::cout << (raw + modifier) << \
  " (" << raw << " + " << modifier << ")\n";

  if(raw == die_sides)
  {
    std::cout << "crit.\n\n";
  }
  else if(raw == 1)
  {
    std::cout << "S-H-I-T!\n\n";
  }
  else
  {
    std::cout << "\n";
  }

  return;
}

void roll_many(int die_count, int die_sides, int modifier)
{
  //roll many dice

  int raw = 0;
  std::vector<int> v;

  static std::minstd_rand eng{std::random_device{}()};
  for(int i=0; i<die_count; i++)
  {
      //add some rolls to a vector
      v.push_back(eng() % die_sides + 1);
  }

  std::cout << "( ";

  for(int i : v)
  {
      //iterate through vector
      raw += i;
      std::cout << i << " ";
  }

  std::cout << ")\n" << raw + modifier \
  << " (" << raw << " + " << modifier << ")\n\n";
  return;
}
