#include <vector>
#include <iostream>
#include <algorithm>

using std::vector;
using std::cout;
using std::endl;


class TEST{
public:
    TEST(){
        for(int i = 0; i < 5 ; i ++){
            _key.push_back(i);
            vector<int> inside;
            for(int j = 0; j < 3; j++){
                inside.push_back(i*j*2);
            }
            _value.push_back(inside);
        }
    }
    int size(int key){
        vector<int>::iterator keyIt;
        keyIt = std::find (_key.begin(), _key.end(), key);
        if (keyIt == _key.end()) return -1;
        return _value[keyIt-_key.begin()].size();
    }
private:
    vector<int> _key;
    vector< vector<int> > _value;
};

int main(){
    vector< vector<int> > out;
    out.push_back(vector<int> ());
    out[0].push_back(1);

    TEST test;
    cout << "result -> "<<test.size(2) <<endl;

    /*

    vector<int> key;
    for (int i = 0; i < 5 ; i++) key.push_back(i*2);

    vector<int>::iterator it;
    it = std::find(key.begin(), key.end(), 4);

    cout << *it << endl;
    cout << "index -> "<<it - key.begin() << endl;

    for(int i = 0; i < key.size(); i++) cout << key[i] << endl;

    cout<<out[0][0]<<endl;
    */
}
