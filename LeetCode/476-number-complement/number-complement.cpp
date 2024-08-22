class Solution {
public:
    int findComplement(int num) {
        bitset<32> bin(num);
        string b = bin.to_string();

        int pos = b.find_first_not_of('0');
        string bin_s = b.substr(pos);
        string comp = "";

        for(int i = 0; i < bin_s.size(); i++){
            if(bin_s[i] == '0')
                comp.push_back('1');
            else{
                comp.push_back('0');
            }
        }

        int number = stoi(comp, nullptr, 2);
        return number;
    }
};