class Solution {
    String add(String a, String b){
        StringBuilder sb = new StringBuilder();

        int i = a.length() - 1;
        int j = b.length() - 1;
        int carry = 0;
        
        while (i >= 0 || j >= 0 || carry > 0){
            int x = (i >= 0) ? a.charAt(i) - '0' : 0;
            int y = (j >= 0) ? b.charAt(j) - '0' : 0;
            int temp = x + y + carry;
            sb.append(temp % 10);
            carry = temp / 10;
            i--; j--;
        }

        return sb.reverse().toString();
    }

    String multiple(String s, int time, int idx){
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < idx - 1; i++)
            sb.append('0');
        
        int carry = 0;
        for (int i = s.length() - 1; i >=  0; i--){
           int cur = s.charAt(i) - '0';
           int temp = cur * time + carry;
           sb.append(temp % 10);
           carry = temp / 10;
        }
        if (carry != 0) sb.append(carry);
        return sb.reverse().toString();
    }
    
    public String multiply(String num1, String num2) {
        if (num1.equals("0") || num2.equals("0")) return "0";
        int n1 = num1.length();
        int n2 = num2.length();
        String res = "";
        for (int i = n1 - 1; i >= 0; i--){
            int digit = num1.charAt(i) - '0';
            if (digit == 0) continue;
            String part = multiple(num2, digit, n1 - i);
            res = res.isEmpty() ? part : add(res, part);
        }
        return res.isEmpty() ? "0" : res;
    }
}