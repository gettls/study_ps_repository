package boj

import java.util.*

data class UtilityPole constructor(val no: Int)

class PowerCord constructor(
    private val leftUtilityPole: UtilityPole,
    private val rightUtilityPole: UtilityPole
) : Comparable<PowerCord> {

    override fun compareTo(other: PowerCord): Int {
        return this.leftUtilityPole.no - other.leftUtilityPole.no
    }

    fun rightNo(): Int = rightUtilityPole.no
}

class PowerCordManager {
    private val powerCords: Vector<PowerCord> = Vector()

    fun add(powerCord: PowerCord) {
        this.powerCords.add(powerCord)
    }

    fun inspect(): Int {
        val sortedPowerCord = powerCords.sorted()
        val dp = Array(sortedPowerCord.size) { 0 }
        var maxL = 0
        for (i in sortedPowerCord.indices) {
            var l = 0
            for (j in sortedPowerCord.indices) {
                if (sortedPowerCord[j].rightNo() < sortedPowerCord[i].rightNo()) {
                    l = l.coerceAtLeast(dp[j])
                }
            }
            dp[i] = l.plus(1)
            maxL = maxL.coerceAtLeast(dp[i])
        }
        return sortedPowerCord.size - maxL
    }
}

fun main(args: Array<String>) = with(System.`in`.bufferedReader()) {
    val t = readLine().trim().toInt()
    val powerCordManager = PowerCordManager()
    repeat(t) {
        val (a, b) = readLine().trim().split(" ").map { UtilityPole(it.toInt()) }
        powerCordManager.add(PowerCord(a, b))
    }
    print(powerCordManager.inspect())
}
