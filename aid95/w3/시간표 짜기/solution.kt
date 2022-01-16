fun main(args: Array<String>) = with(System.`in`.bufferedReader()) {
    val n = readLine().trim().toInt()

    val t = Array(n) { 0L }
    repeat(n) {
        val nums = readLine().trim().split(" ").map(String::toInt)
        for (idx in 1 until nums.size) {
            t[it] = t[it] or (1L shl nums[idx])
        }
    }

    val nn = readLine().trim().toInt()
    repeat(nn) {
        val nums = readLine().trim().split(" ").map(String::toInt)
        var tmp = 0L
        for (idx in 1 until nums.size) {
            tmp = tmp or (1L shl nums[idx])
        }

        var answer = 0
        for (idx in t.indices) {
            if ((tmp.inv() and t[idx]) == 0L) {
                answer++
            }
        }
        println(answer)
    }
}
