# Maps

- in an array, if you need to find if element n exists, you need to linearly look through the arrya (assuming it is not sorted)
- 



```
#include <map>

map<char, int> mp = {
  {'Key', Value},
  {'T', 4}

};
cout << mp['T'] << endl;

cout << mp['2'] << endl;  // will return 0 because it doens't exist

if you want to add the key you can do two options

mp['u'] = 9; // or
mp.insert(pair<char, int> p1 ('j', 5));

cout << mp['j'] << endl;


// you can use .first or .second to access the key or the value. 

//how to erase and element

mp.erase(p1.first) // now the key, which was 'j' will be 0

mp.clear, clears a map


calling mp.empty() returns a 1 if it is empty and 0 if it is not


mp.size() returns the number of pairs that are in the map


## how to iterate through elements in a map

for (auto itr = mp.begin(); itr != mp.end(); ++itr) { // itr will be equal to a ptr to each pair
  cout << (*itr).first << endl;
}
// this will print all the keys, .second would print all the nums

remember, this is probably better: itr->second/first

## count the number of times a letter appears


int main() {
  std::string test = "Hello world my name is tim! ttthhaa";
  map <char, int> freq;
  for (int i = 0; i < test.length(); ++i) {
    char letter = test[i];
    if (freq.find(letter) == freq.end()) { // check if it exists
      freq[letter] = 0;
    }
    freq[letter]++;
    cout << freq[letter] << ", " << letter << endl;
  }

  for (auto itr = freq.begin(); itr != freq.end(); ++itr) {
    cout << itr->first << ": " << itr->second << endl;  
    
  }

  this prints letter:count for all of the things
}

```