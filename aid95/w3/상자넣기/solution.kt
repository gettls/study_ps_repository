class Matryoshka constructor(private val nums: Array<Int>) {
    fun solve(): Int {
        val dp = Array(nums.size) { 0 }
        var result = 0
        for (i in nums.indices) {
            var l = 0
            for (j in 0 until i) {
                if (nums[j] < nums[i]) {
                    l = l.coerceAtLeast(dp[j])
                }
            }
            dp[i] = l + 1;
            result = result.coerceAtLeast(dp[i])
        }
        return result
    }
}

fun main(args: Array<String>) = with(System.`in`.bufferedReader()) {
    readLine()
    val nums = readLine().trim().split(" ").map(String::toInt).toTypedArray()
    print(Matryoshka(nums).solve())
}
