class Solution {
    public int compareVersion(String version1, String version2) {
        String[] v1 = version1.split("\\.");
        String[] v2 = version2.split("\\.");
        int i = 0;
        int j = 0;
        while (i < v1.length && j < v2.length){
            int first = Integer.parseInt(v1[i]);
            int second = Integer.parseInt(v2[j]);
            System.out.println(first + " "  + second);
            if (first < second){
                return -1;
            } else if (first > second){
                return 1;
            }
            i++;
            j++;
        }
        if (i != v1.length) {
            for (int k = i; k < v1.length; k++)
                if (Integer.parseInt(v1[k]) != 0)
                    return 1;
            return 0;
        }
        if (j != v2.length) {
            for (int k = j; k < v2.length; k++)
                if (Integer.parseInt(v2[k]) != 0)
                    return -1;
            return 0;
        }
        
        return 0;
    }
}