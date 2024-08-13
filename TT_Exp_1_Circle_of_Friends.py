def find_the_winner(n, k):
    if n == 1:
        return 1
    else:
        return (find_the_winner(n - 1, k) + k - 1) % n + 1


if __name__ == '__main__':
    n = int(input("Input  number of friends: "))
    k = int(input("Enter value of k: "))
    print("Winner: ", find_the_winner(n, k))
