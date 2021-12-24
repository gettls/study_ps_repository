package boj

import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*

class FashionKing {
    private val hash = HashMap<String, Vector<String>>()

    fun addDress(type: String, name: String) {
        if (!hash.containsKey(type)) {
            hash[type] = Vector()
        }
        hash[type]!!.add(name)
    }

    fun solve(): Int =
        hash.keys
            .map { hash[it]!!.size }
            .fold(1) { acc: Int, kinds: Int -> acc.times(kinds + 1) }
            .minus(1)
}

fun main(args: Array<String>) {
    val br = BufferedReader(InputStreamReader(System.`in`))
    repeat(br.readLine().trim().toInt()) {
        val solver = FashionKing()
        repeat(br.readLine().trim().toInt()) {
            val (n, k) = br.readLine().trim().split(" ")
            solver.addDress(k, n)
        }
        println(solver.solve())
    }
}
