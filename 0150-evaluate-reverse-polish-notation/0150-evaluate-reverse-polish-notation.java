class Solution {
    public int cal(int a, int b, String op){
        if (op.equals("+")) return a + b;
        if (op.equals("-")) return a - b;
        if (op.equals("*")) return a * b;
        return a / b;
    }
    public boolean isNumeric(String str) {
        return str != null && str.matches("-?\\d+(\\.\\d+)?");
    }
    public int evalRPN(String[] tokens) {
        Deque<Integer> nums = new ArrayDeque<>();
        //Deque<String> ops = new ArrayDeque<>();
        int ans = 0;
        for (String t : tokens){
            if (isNumeric(t)){
                nums.addLast(Integer.parseInt(t));
            } else {
                int a = nums.pollLast();
                int b = nums.pollLast();
                ans = cal(b,a,t);
                System.out.println(ans);
                nums.addLast(ans);
            }
        }
        return nums.pollLast();
    }
}