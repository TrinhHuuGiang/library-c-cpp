#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<int> vec_S;

    // push back and popback
    int a = 10;
    vec_S.push_back(a); // copy a and push the last of vector

    int b = vec_S.back();
    vec_S.pop_back();

    // vector size : return current number element
    const int size_expect = 10;
    for(int i = 0; i< 10; i++)
    {vec_S.push_back(a);}

    cout<<"Vecto size:"<< vec_S.size()<<endl; // number current element push into vector
    
    // vector resize: destruct some last element to fit with require, or append input value untill fill n slot
    vec_S.resize(20, 100);

    cout<<"Vector after resize "<< vec_S.size()<< ":\n";
    for(int i = 0 ; i < vec_S.size() ; i++)
    {
      cout << vec_S[i] << "| ";
    }
    cout<<endl;

    // vector .capacity, .reserve help check capacity until re alloc 

    // iterator
    vector<int>::iterator it = vec_S.begin(); // or v.end() if want browse reverse 

    cout<<"Vector print by iterator \n";

    for(it; it != vec_S.end() ; it ++)
    {
      cout << *it << "| ";
    }
    cout<<endl;

    cout<<"Vector print by iterator, reverse \n";

    vector<int>::reverse_iterator rit = vec_S.rbegin(); // :) design point to last element
    for(rit; rit != vec_S.rend() ; rit ++) // ++ is design for reverse direction
    {
      cout << *rit << "| ";
    }
    cout<<endl;

    // clear and shrink to fit
    vec_S.clear(); // Note
    vec_S.shrink_to_fit(); // clear not auto resize so need shrink to minimum size

    cout<<"Vector cleaned: \n -> ";
            
    for(it = vec_S.begin(); it != vec_S.end() ; it ++)
    {
      cout << *it << "| ";
    }
    cout<<endl;    

    
    // insert by iter
    vec_S.insert(vec_S.begin(), 2); // vector now empty so only insert to head

    vec_S.insert(vec_S.begin() + 1, 3);

    vec_S.insert(vec_S.begin(), 1);

    cout<<"Vector after insert: \n -> "; 

        
    for(it = vec_S.begin(); it != vec_S.end() ; it ++)
    {
      cout << *it << "| ";
    }
    cout<<endl;    



    // erase iter

    vec_S.erase(vec_S.begin(),vec_S.begin()+1 );
    cout<<"Vector after erase range [1,2): \n -> "; 

        
    for(it = vec_S.begin(); it != vec_S.end() ; it ++)
    {
      cout << *it << "| ";
    }
    cout<<endl;    



    vec_S.erase(vec_S.begin());
    cout<<"Vector after erase 1: \n -> "; 

        
    for(it = vec_S.begin(); it != vec_S.end() ; it ++)
    {
      cout << *it << "| ";
    }
    cout<<endl;    



	// ok
	return 0;
}

