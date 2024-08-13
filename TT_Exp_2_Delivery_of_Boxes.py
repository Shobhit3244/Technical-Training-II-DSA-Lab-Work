def min_trips(boxes: list[list[int]], portsCount: int, maxBoxes: int, maxWeight: int) -> int:
    n = len(boxes)
    dp = [float('inf')] * (n + 1)
    dp[0] = 0

    for i in range(1, n + 1):
        box_count, weight_sum = 0, 0
        port_visited = [0] * portsCount
        trips = 0

        for j in range(i - 1, -1, -1):
            box = boxes[j]
            port, weight = box
            box_count += 1
            weight_sum += weight
            port_visited[port - 1] = 1

            if box_count > maxBoxes or weight_sum > maxWeight:
                break

            trips = max(trips, port_visited[port - 1])

            dp[i] = min(dp[i], dp[j] + trips + 1)

    return dp[n]


if __name__ == '__main__':
    boxes = [[1, 1], [2, 1], [1, 2], [2, 2], [3, 3]]
    portsCount = 3
    maxBoxes = 5
    maxWeight = 6
    result = min_trips(boxes, portsCount, maxBoxes, maxWeight)
    print("Minimum No of Trips: ", result)
