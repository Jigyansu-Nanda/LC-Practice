class Solution {
    public boolean isRectangleOverlap(int[] R1, int[] R2) {
        if (R2[0] >= R1[2] || R1[0] >= R2[2] || R2[1] >= R1[3] || R1[1] >= R2[3]) return false;
        return true;
    }
}