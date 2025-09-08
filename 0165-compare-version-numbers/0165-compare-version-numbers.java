class Solution {
    public int compareVersion(String version1, String version2) {
        int n1 = version1.length();
        int n2 = version2.length();
        int i = 0;
        int j = 0;

        while (i < n1 || j < n2){
            int a = 0;
            int b = 0;
            while (i < n1 && version1.charAt(i) != '.'){
                a = a * 10 + (version1.charAt(i) - '0');
                i++;
            }
            while (j < n2 && version2.charAt(j) != '.'){
                b = b * 10 + (version2.charAt(j) - '0');
                j++;
            }
            if (a < b )return -1;
            if (a > b )return 1;
            if (i < n1 && version1.charAt(i) == '.') i++;
            if (j < n2 && version2.charAt(j) == '.') j++;
        }
        return 0;
    }
}