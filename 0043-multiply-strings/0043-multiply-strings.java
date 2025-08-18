class Solution {
    public String multiply(String num1, String num2) {
       int n = num1.length(), m = num2.length();
       int[] prod = new int[n + m];
       for (int i = n - 1; i  >= 0; i--){
        int x = num1.charAt(i) - '0';
        for (int j = m - 1; j >= 0; j--){
            int y = num2.charAt(j) - '0';
            int temp = x * y + prod[i+j+1];
            prod[i+j+1] = temp % 10;
            prod[i+j] += temp / 10;
        }
       }
       StringBuilder sb = new StringBuilder();
       int k = 0;
       while(k < prod.length && prod[k] == 0) k++;
       for (; k < prod.length; k++) sb.append(prod[k]);
       return sb.length() == 0 ? "0" : sb.toString();
    }
}