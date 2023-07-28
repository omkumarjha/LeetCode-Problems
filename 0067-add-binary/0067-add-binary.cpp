class Solution {
public:
    string addBinary(string a, string b) {
        // Jab hum decimal numbers ko add karte hai to % / 10 karte hai same abb hum isme binary ko add kar rahe hai to % / 2 se karenge 

        int aLen = a.length();
        int bLen = b.length();
        int carry = 0; 
        string result = "";

        // Abb hum dono binary strings ko same banane ki koshish karenge 

        if(aLen > bLen){
            b = result.append(aLen-bLen,'0')+b; // iska matlab b ke andar (alen - blen) number of 0s ko append karo 
        }
        if(bLen > aLen){
            a = result.append(bLen-aLen,'0')+a;
        }
        
        // Abb dono strings same hu chuki hogi 

        int i = a.size() - 1;  // yaha humne aLen isliye nhi use kara kyuki already abb uski length change ho chuki hogi 0s ko append karne ke baad isliye humne new length liya hai .
        result = "";
        
        while(i >= 0){
            int sum = (a[i] - '0') + (b[i] - '0') + carry;
            carry = sum / 2;
            sum = sum % 2;
            result = to_string(sum) + result;
            i--;
        }

        // agar carry exist kar rahi hai to hum carry ko bhi append kardenge 
        if(carry){
            result = "1" + result;
        }

        return result;
        
    }
    
    
};