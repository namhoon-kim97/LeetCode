class Solution {
    List<String> result = new ArrayList<>();
    public List<String> restoreIpAddresses(String s) {
        dfs(s, 0, 0, new StringBuilder());
        return result;
    }

    void dfs(String s, int index, int count, StringBuilder current){
        if (count == 4){
            if (index == s.length()) {
                result.add(current.toString());
            }
            return;
        }

        int remaining = s.length() - index;
        int minNeeded = (4 - count);      // 최소 1자리씩
        int maxAllowed = (4 - count) * 3; // 최대 3자리씩
        if (remaining < minNeeded || remaining > maxAllowed) {
            return;
        }

        int len = current.length(); // 나중에 롤백용
        for (int l = 1; l <= 3; l++) {
            if (index + l > s.length()) break;
            String part = s.substring(index, index + l);
            // leading zero 처리
            if (part.charAt(0) == '0' && part.length() > 1) continue;
            int val = Integer.parseInt(part);
            if (val > 255) continue;
            if (count > 0) current.append('.');
            current.append(part);
            dfs(s, index + l, count + 1, current);
            current.setLength(len);
        }
    }


}