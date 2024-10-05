#include <bits/stdc++.h>
using namespace std;

int sum(vector<int> &arr)
{
  int total = 0;

  for (int n : arr)
  {
    total += n;
  }

  return total;
}

long long dividePlayers(vector<int> &skill)
{
  int total = sum(skill);
  int noOfTeam = skill.size() / 2;

  if (total % noOfTeam != 0)
  {
    return -1;
  }

  sort(skill.begin(), skill.end());
  int l = 0, r = skill.size() - 1;
  int target = total / noOfTeam;
  long long res = 0;

  while (l < r)
  {
    if (skill[l] + skill[r] != target)
    {
      return -1;
    }
    res += skill[l] * skill[r];
    l++;
    r--;
  }

  return res;
}

vector<int> readVector(){
  string input;
  getline(cin, input);

  // Remove the brackets
  input.erase(remove(input.begin(), input.end(), '['), input.end());
  input.erase(remove(input.begin(), input.end(), ']'), input.end());

  stringstream ss(input);
  vector<int> arr;
  int item;

  // Parse the input into the arr vector
  while (ss >> item)
  {
    arr.push_back(item);
    if (ss.peek() == ',')
    {
      ss.ignore(); // Skip the comma
    }
  }

  return arr;
}

int main()
{
  vector<int> skills = readVector();

  long long result = dividePlayers(skills);

  cout << result;
}