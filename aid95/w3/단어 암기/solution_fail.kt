fun main(args: Array<String>) = with(System.`in`.bufferedReader()) {
    val (n, m) = readLine().trim().split(" ").map(String::toInt)
    val one = 1

    val words = List(n) { readLine().trim() }
    val queries = List(m) { readLine().trim().split(" ") }

    val masks = Array(n) { 0 }
    for ((idx, word) in words.withIndex()) {
        masks[idx] =
            word.chars()
                .reduce { left, right -> left.or(one.shl(right.minus('a'.code))) }
                .orElse(-1)
    }

    var brain = 0
    for ((_, v) in queries) {
        brain = brain.xor(one.shl(v[0].code - 'a'.code))
        println(n - masks.count { it.and(brain) > 0 })
    }
}
