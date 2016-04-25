#include <iostream>
#include <cctype>
#include <cstring>
using namespace std;

int main()  
{
	int vowel = 0;
	int consonat = 0;
	int other = 0;
	char word[20];
	cout<<"Enter words (q to quit)"<<endl;
	cin>>word;
	while( !(word[0] == 'q' && strlen(word) == 1) )
	{
	  	if(!isalpha(word[0]))
	  		other++;
	  	else if(word[0] == 'a' || word[0] == 'e' || word[0] == 'i' || word[0] == 'o' || word[0] == 'u')
	  		vowel++;
	  	else 
	  		consonat++;
	  	cin>>word;
	}
	cout << vowel << " words beginning with vowels"<<endl;
	cout << consonat << " words beginning with consonats"<<endl;
	cout << other << " others"<<endl;
	return 0;
}  