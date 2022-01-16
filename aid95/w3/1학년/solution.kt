class Freshman constructor(private val nums: List<Int>) {

    fun asd(): Long {
        val dp = Array(101) { Array(21) { 0L } }
        dp[0][nums[0]] = 1
        for (i in 1 until nums.size - 1) {
            for (j in 0..20) {
                if (dp[i - 1][j] != 0L) {
                    if (j.plus(nums[i]) <= 20) {
                        dp[i][j.plus(nums[i])] += dp[i - 1][j]
                    }
                    if (j.minus(nums[i]) >= 0) {
                        dp[i][j.minus(nums[i])] += dp[i - 1][j]
                    }
                }
            }
        }
        return dp[nums.size - 2][nums[nums.size - 1]]
    }
}

fun main(args: Array<String>) = with(System.`in`.bufferedReader()) {
    readLine()
    val nums = readLine().trim().split(" ").map { it.toInt() }
    print(Freshman(nums).asd())
}
